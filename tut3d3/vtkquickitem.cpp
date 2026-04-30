#include "vtkquickitem.h"
#include "dicomreader.h"
#include <QOpenGLContext>
#include <QQuickWindow>
#include <QTimer>
#include <QElapsedTimer>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QDebug>
#include <QSGRendererInterface>
#include "volumeprocessor.h"
#include "QThread"
#include "QDir"

// VTK Includes - add only essential ones
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkVolume.h>
#include <vtkGPUVolumeRayCastMapper.h>
#include <vtkColorTransferFunction.h>
#include <vtkPiecewiseFunction.h>
#include <vtkVolumeProperty.h>
#include <vtkImageGaussianSmooth.h>
#include <vtkCamera.h>


VTKQuickItem::VTKQuickItem(QQuickItem *parent)
    : QQuickItem(parent)
    , m_status("Initializing...")
{
    setFlag(ItemHasContents, true);
    setAcceptedMouseButtons(Qt::AllButtons);
    setAcceptHoverEvents(true);

    // Connect to window changed signal
    connect(this, &QQuickItem::windowChanged, this, &VTKQuickItem::handleWindowChanged);

    // Set up render timer
    m_renderTimer.setInterval(16); // ~60 FPS
    connect(&m_renderTimer, &QTimer::timeout, this, &VTKQuickItem::renderFrame);

    m_frameTimer.start();

    setStatus("Ready");
}

VTKQuickItem::~VTKQuickItem()
{
    stopRendering();
    cleanupVTK();
}

void VTKQuickItem::handleWindowChanged(QQuickWindow *window)
{
    if (m_window == window)
        return;

    m_window = window;
    if (m_window) {
        // Ensure we have an OpenGL context
        m_window->setSurfaceType(QSurface::OpenGLSurface);

        // Connect to before/after rendering signals
        connect(m_window, &QQuickWindow::beforeSynchronizing,
                this, &VTKQuickItem::renderFrame, Qt::DirectConnection);

        qDebug() << "Window connected, OpenGL available:"
                 << (m_window->rendererInterface()->graphicsApi() == QSGRendererInterface::OpenGL);
    }
}

bool VTKQuickItem::initVTK()
{
    if (m_initialized)
        return true;

    try {
        qDebug() << "Initializing VTK...";

        // Create render window
        m_renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
        if (!m_renderWindow) {
            setStatus("Failed to create VTK render window");
            return false;
        }

        // Create renderer
        m_renderer = vtkSmartPointer<vtkRenderer>::New();
        if (!m_renderer) {
            setStatus("Failed to create VTK renderer");
            return false;
        }

        m_renderer->SetBackground(0.1, 0.1, 0.1);
        m_renderWindow->AddRenderer(m_renderer);
        m_renderWindow->SetMultiSamples(0); // Disable multisampling for compatibility

        // Set initial size
        m_renderWindow->SetSize(width(), height());

        m_initialized = true;
        setStatus("VTK initialized");
        qDebug() << "VTK initialization successful";

        return true;
    }
    catch (const std::exception& e) {
        qDebug() << "VTK initialization exception:" << e.what();
        setStatus(QString("VTK init error: %1").arg(e.what()));
        return false;
    }
    catch (...) {
        qDebug() << "Unknown VTK initialization exception";
        setStatus("Unknown VTK initialization error");
        return false;
    }
}

void VTKQuickItem::cleanupVTK()
{
    qDebug() << "Cleaning up VTK resources";

    // Stop rendering first
    stopRendering();

    // Remove volume from renderer
    if (m_renderer && m_volume) {
        m_renderer->RemoveVolume(m_volume);
    }

    // Release VTK objects
    m_volume = nullptr;
    m_volumeMapper = nullptr;
    m_renderer = nullptr;
    m_renderWindow = nullptr;

    m_initialized = false;
    m_volumeLoaded = false;
    m_rendering = false;

    setStatus("Cleaned up");
}

QString VTKQuickItem::dicomFolder() const
{
    return m_dicomFolder;
}

void VTKQuickItem::setDicomFolder(const QString &folder)
{
    if (m_dicomFolder == folder)
        return;

    m_dicomFolder = folder;
    emit dicomFolderChanged();
}

bool VTKQuickItem::volumeLoaded() const
{
    return m_volumeLoaded;
}

bool VTKQuickItem::rendering() const
{
    return m_rendering;
}

void VTKQuickItem::setRendering(bool render)
{
    if (m_rendering == render)
        return;

    m_rendering = render;

    if (m_rendering) {
        if (!m_initialized) {
            if (!initVTK()) {
                m_rendering = false;
                return;
            }
        }
        m_renderTimer.start();
        setStatus("Rendering started");
    } else {
        m_renderTimer.stop();
        setStatus("Rendering stopped");
    }

    emit renderingChanged();
}

void VTKQuickItem::stopRendering()
{
    m_renderTimer.stop();
    m_rendering = false;
    setStatus("Rendering stopped");
}

QString VTKQuickItem::status() const
{
    return m_status;
}

void VTKQuickItem::setStatus(const QString &status)
{
    if (m_status == status)
        return;

    m_status = status;
    qDebug() << "Status:" << status;
    emit statusChanged();
}

void VTKQuickItem::loadDicomVolume()
{
    qDebug() << "=== loadDicomVolume() called ===";

    if (m_dicomFolder.isEmpty()) {
        qDebug() << "Error: DICOM folder is empty";
        setStatus("Error: No DICOM folder specified");
        emit errorOccurred("DICOM folder not specified");
        return;
    }

    qDebug() << "DICOM folder path:" << m_dicomFolder;

    // Check if folder exists
    QDir dir(m_dicomFolder);
    if (!dir.exists()) {
        qDebug() << "Error: DICOM folder does not exist:" << m_dicomFolder;
        setStatus("Error: Folder does not exist");
        emit errorOccurred(QString("DICOM folder does not exist: %1").arg(m_dicomFolder));
        return;
    }

    // Initialize VTK if not already
    if (!m_initialized) {
        qDebug() << "VTK not initialized, initializing now...";
        if (!initVTK()) {
            qDebug() << "Failed to initialize VTK";
            setStatus("Error: Failed to initialize VTK");
            emit errorOccurred("Failed to initialize VTK rendering engine");
            return;
        }
    }

    setStatus("Loading DICOM files...");
    qDebug() << "Creating DicomReader...";

    try {
        DicomReader reader;
        qDebug() << "Reading DICOM series from:" << m_dicomFolder;

        vtkSmartPointer<vtkImageData> imageData = reader.readDicomSeries(m_dicomFolder);

        if (!imageData) {
            QString error = reader.getErrorMessage();
            qDebug() << "Failed to load DICOM:" << error;
            setStatus("Error: " + error);
            emit errorOccurred(error.isEmpty() ? "Failed to load DICOM series" : error);
            return;
        }

        qDebug() << "DICOM loaded successfully, creating renderer...";
        setStatus("Creating 3D volume...");

        // Create the volume renderer
        createVolumeRenderer(imageData);

        if (!m_volume) {
            qDebug() << "Failed to create volume";
            setStatus("Error: Failed to create 3D volume");
            emit errorOccurred("Failed to create 3D volume from DICOM data");
            return;
        }

        m_volumeLoaded = true;
        setStatus("3D Volume Ready");
        qDebug() << "=== Volume loaded successfully! ===";

        emit volumeLoadedChanged();

        // Auto-start rendering
        setRendering(true);

    } catch (const std::exception& e) {
        qDebug() << "Exception in loadDicomVolume:" << e.what();
        setStatus(QString("Error: %1").arg(e.what()));
        emit errorOccurred(QString("Exception: %1").arg(e.what()));
    } catch (...) {
        qDebug() << "Unknown exception in loadDicomVolume";
        setStatus("Unknown error loading volume");
        emit errorOccurred("Unknown error occurred while loading DICOM");
    }
}

void VTKQuickItem::createVolumeRenderer(vtkImageData* imageData)
{
    if (!imageData || !m_renderer) {
        qDebug() << "Cannot create volume renderer: null image data or renderer";
        return;
    }

    setStatus("Processing volume for rendering...");

    try {
        // Remove existing volume if any
        if (m_volume) {
            m_renderer->RemoveVolume(m_volume);
            m_volume = nullptr;
        }

        // Process the volume for better compatibility
        VolumeProcessor processor;
        vtkSmartPointer<vtkImageData> processedVolume;

        int dims[3];
        imageData->GetDimensions(dims);
        qDebug() << "Original volume dimensions:" << dims[0] << dims[1] << dims[2];

        // Strategy 1: Downsample large volumes
        if (dims[0] > 256 || dims[1] > 256 || dims[2] > 256) {
            qDebug() << "Volume too large, downsampling...";
            processedVolume = processor.downsampleVolume(imageData, 2);
            setStatus("Downsampled to 256^3 for compatibility");
        } else {
            processedVolume = imageData;
            setStatus("Using original volume size");
        }

        // Strategy 2: Try CPU mapper first (most compatible)
        vtkSmartPointer<vtkFixedPointVolumeRayCastMapper> cpuMapper =
            vtkSmartPointer<vtkFixedPointVolumeRayCastMapper>::New();
        cpuMapper->SetInputData(processedVolume);
        cpuMapper->SetSampleDistance(1.5);
        cpuMapper->SetNumberOfThreads(QThread::idealThreadCount());

        m_volumeMapper = cpuMapper;

        // Create optimized color map
        vtkSmartPointer<vtkColorTransferFunction> colorFunc =
            vtkSmartPointer<vtkColorTransferFunction>::New();
        vtkSmartPointer<vtkPiecewiseFunction> alphaFunc =
            vtkSmartPointer<vtkPiecewiseFunction>::New();

        // CT Hounsfield unit color map
        // Air: -1000 HU, Water: 0 HU, Bone: 400+ HU
        colorFunc->AddRGBPoint(-1000, 0.0, 0.0, 0.0);      // Black for air
        colorFunc->AddRGBPoint(-800, 0.0, 0.0, 0.2);       // Dark blue
        colorFunc->AddRGBPoint(-600, 0.0, 0.2, 0.5);       // Blue
        colorFunc->AddRGBPoint(-400, 0.0, 0.5, 0.8);       // Light blue (lung)
        colorFunc->AddRGBPoint(-200, 0.2, 0.8, 0.8);       // Cyan
        colorFunc->AddRGBPoint(0, 0.8, 0.8, 0.8);          // Gray (water/soft tissue)
        colorFunc->AddRGBPoint(100, 0.9, 0.7, 0.6);        // Light brown
        colorFunc->AddRGBPoint(200, 0.9, 0.5, 0.3);        // Brown
        colorFunc->AddRGBPoint(400, 1.0, 0.7, 0.4);        // Orange (bone)
        colorFunc->AddRGBPoint(800, 1.0, 0.9, 0.8);        // Light orange
        colorFunc->AddRGBPoint(1200, 1.0, 1.0, 1.0);       // White (dense bone)

        // Opacity function - make air transparent, tissue semi-transparent, bone opaque
        alphaFunc->AddPoint(-1000, 0.0);
        alphaFunc->AddPoint(-800, 0.01);
        alphaFunc->AddPoint(-600, 0.02);
        alphaFunc->AddPoint(-400, 0.05);   // Lung tissue
        alphaFunc->AddPoint(-200, 0.1);
        alphaFunc->AddPoint(0, 0.2);       // Water/soft tissue
        alphaFunc->AddPoint(100, 0.3);
        alphaFunc->AddPoint(200, 0.5);     // Muscle
        alphaFunc->AddPoint(400, 0.7);     // Bone
        alphaFunc->AddPoint(800, 0.9);
        alphaFunc->AddPoint(1200, 1.0);

        // Create volume property
        vtkSmartPointer<vtkVolumeProperty> volumeProperty =
            vtkSmartPointer<vtkVolumeProperty>::New();
        volumeProperty->SetColor(colorFunc);
        volumeProperty->SetScalarOpacity(alphaFunc);
        volumeProperty->SetInterpolationTypeToLinear();
        volumeProperty->ShadeOff();        // Turn off for performance
        volumeProperty->SetAmbient(0.4);   // Increase ambient for better visibility
        volumeProperty->SetDiffuse(0.6);
        volumeProperty->SetSpecular(0.0);

        // Create volume
        m_volume = vtkSmartPointer<vtkVolume>::New();
        m_volume->SetMapper(m_volumeMapper);
        m_volume->SetProperty(volumeProperty);

        // Add volume to renderer
        m_renderer->AddVolume(m_volume);

        // Set up optimized camera
        vtkCamera *camera = m_renderer->GetActiveCamera();
        double bounds[6];
        processedVolume->GetBounds(bounds);

        double center[3] = {
            (bounds[0] + bounds[1]) / 2.0,
            (bounds[2] + bounds[3]) / 2.0,
            (bounds[4] + bounds[5]) / 2.0
        };

        double maxBound = qMax(bounds[1] - bounds[0],
                             qMax(bounds[3] - bounds[2],
                                  bounds[5] - bounds[4]));

        camera->SetPosition(center[0], center[1], center[2] + maxBound * 2.0);
        camera->SetFocalPoint(center[0], center[1], center[2]);
        camera->SetViewUp(0, 1, 0);
        camera->SetParallelProjection(0);
        camera->SetParallelScale(maxBound / 2.0);

        m_renderer->ResetCamera();

        m_volumeLoaded = true;
        qDebug() << "Volume renderer created successfully with CPU mapper";
        setStatus("Ready - Using CPU rendering");

    } catch (const std::exception& e) {
        qDebug() << "Exception creating volume renderer:" << e.what();
        setStatus(QString("Error: %1").arg(e.what()));
        emit errorOccurred(QString("Failed to create renderer: %1").arg(e.what()));
    } catch (...) {
        qDebug() << "Unknown exception creating volume renderer";
        setStatus("Failed to create volume renderer");
        emit errorOccurred("Unknown error creating renderer");
    }
}

void VTKQuickItem::resetCamera()
{
    if (!m_renderer || !m_volume)
        return;

    try {
        m_renderer->ResetCamera();
        setStatus("Camera reset");
        if (window()) window()->update();
    } catch (...) {
        qDebug() << "Error resetting camera";
    }
}

void VTKQuickItem::updateCamera()
{
    if (!m_renderer)
        return;

    vtkCamera *camera = m_renderer->GetActiveCamera();
    if (!camera)
        return;

    camera->SetPosition(0, 0, 500);
    camera->SetFocalPoint(0, 0, 0);
    camera->SetViewUp(0, 1, 0);
    camera->SetParallelProjection(0);
    camera->SetParallelScale(1.0);
}

void VTKQuickItem::renderFrame()
{
    if (!m_rendering || !m_initialized || !m_renderWindow || !m_window)
        return;

    try {
        // Check if window is valid
        if (!m_window->isVisible())
            return;

        // Ensure render window size matches item size
        int w = static_cast<int>(width());
        int h = static_cast<int>(height());

        if (w > 0 && h > 0) {
            if (m_renderWindow->GetSize()[0] != w || m_renderWindow->GetSize()[1] != h) {
                m_renderWindow->SetSize(w, h);
                m_renderer->ResetCameraClippingRange();
            }

            // Make the context current
            m_window->beginExternalCommands();

            // Render the frame
            m_renderWindow->Render();

            // Request update
            m_window->update();

            m_window->endExternalCommands();

            // Update status periodically
            static int frameCount = 0;
            frameCount++;
            if (frameCount % 60 == 0) {
                setStatus(QString("Rendering: %1 FPS").arg(1000.0 / m_frameTimer.restart()));
            }
        }
    } catch (const std::exception& e) {
        qDebug() << "Render exception:" << e.what();
        stopRendering();
        setStatus(QString("Render error: %1").arg(e.what()));
    } catch (...) {
        qDebug() << "Unknown render exception";
        stopRendering();
        setStatus("Unknown render error");
    }
}

void VTKQuickItem::geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry)
{
    QQuickItem::geometryChanged(newGeometry, oldGeometry);

    if (m_initialized && m_renderWindow && width() > 0 && height() > 0) {
        try {
            m_renderWindow->SetSize(static_cast<int>(width()), static_cast<int>(height()));
            if (m_renderer) {
                m_renderer->ResetCameraClippingRange();
            }
        } catch (...) {
            qDebug() << "Error resizing render window";
        }
    }
}

void VTKQuickItem::mousePressEvent(QMouseEvent *event)
{
    m_lastMousePos = event->pos();
    m_mousePressed = true;
    event->accept();
}

void VTKQuickItem::mouseReleaseEvent(QMouseEvent *event)
{
    m_mousePressed = false;
    event->accept();
}

void VTKQuickItem::mouseMoveEvent(QMouseEvent *event)
{
    if (!m_mousePressed || !m_renderer || !m_volume)
        return;

    QPoint delta = event->pos() - m_lastMousePos;
    m_lastMousePos = event->pos();

    try {
        vtkCamera *camera = m_renderer->GetActiveCamera();
        if (!camera)
            return;

        if (event->buttons() & Qt::LeftButton) {
            // Rotate
            camera->Azimuth(-delta.x() * 0.3);
            camera->Elevation(-delta.y() * 0.3);
            camera->OrthogonalizeViewUp();
        } else if (event->buttons() & Qt::RightButton) {
            // Pan
//            camera->Pan(delta.x() * 0.005, -delta.y() * 0.005, 0);
        }

        // Request render
        if (window()) window()->update();

    } catch (...) {
        qDebug() << "Error handling mouse move";
    }

    event->accept();
}

void VTKQuickItem::wheelEvent(QWheelEvent *event)
{
    if (!m_renderer || !m_volume)
        return;

    try {
        vtkCamera *camera = m_renderer->GetActiveCamera();
        if (!camera)
            return;

        double zoomFactor = 1.1;

        if (event->angleDelta().y() > 0) {
            camera->Zoom(zoomFactor);
        } else {
            camera->Zoom(1.0 / zoomFactor);
        }

        // Request render
        if (window()) window()->update();

    } catch (...) {
        qDebug() << "Error handling wheel event";
    }

    event->accept();
}
