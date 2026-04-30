#include "VTKQuickItem.h"
#include <QSGSimpleTextureNode>
#include <QQuickWindow>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOffscreenSurface>
#include <QOpenGLFramebufferObject>
#include <QOpenGLFramebufferObjectFormat>

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)

VTKQuickItem::VTKQuickItem()
{
    setFlag(ItemHasContents, true);
    connect(this, &QQuickItem::windowChanged, this, [this](QQuickWindow* window) {
        if (window) {
            initializeVTK();
        }
    });
}

VTKQuickItem::~VTKQuickItem()
{
    // Clean up
    if (m_volumeData) {
        delete[] m_volumeData;
    }
}

void VTKQuickItem::initializeVTK()
{
    if (m_initialized) return;

    // Create VTK render window
    m_renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    m_renderer = vtkSmartPointer<vtkRenderer>::New();
    m_interactor = vtkSmartPointer<QVTKInteractor>::New();

    m_renderWindow->AddRenderer(m_renderer);
    m_renderWindow->SetInteractor(m_interactor);
    m_interactor->SetRenderWindow(m_renderWindow);

    // Set up renderer
    m_renderer->SetBackground(0.1, 0.2, 0.3);

    m_initialized = true;
    emit initializedChanged();

    // Request an update
    update();
}

QSGNode* VTKQuickItem::updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData*)
{
    if (!m_initialized || width() <= 0 || height() <= 0) {
        return oldNode;
    }

    // Resize render window if needed
    if (m_renderWindow) {
        m_renderWindow->SetSize(width(), height());
    }

    // Create or reuse texture node
    QSGSimpleTextureNode* node = static_cast<QSGSimpleTextureNode*>(oldNode);
    if (!node) {
        node = new QSGSimpleTextureNode();
    }

    // Get current FBO
    QOpenGLContext* context = QOpenGLContext::currentContext();
    if (!context) return node;

    // Create offscreen surface for VTK rendering
    QOffscreenSurface surface;
    surface.setFormat(context->format());
    surface.create();

    // Make the offscreen surface current
    context->makeCurrent(&surface);

    // Ensure VTK render window uses our context
    m_renderWindow->SetOffScreenRendering(true);
    m_renderWindow->SetSize(width(), height());

    // Render VTK scene
    m_renderWindow->Render();

    // Read pixels from framebuffer
    QOpenGLFramebufferObjectFormat format;
    format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);

    QOpenGLFramebufferObject fbo(width(), height(), format);
    fbo.bind();

    glReadPixels(0, 0, width(), height(), GL_RGBA, GL_UNSIGNED_BYTE, fbo.toImage().bits());

    fbo.release();
    context->doneCurrent();

    // Create texture from image
    QImage image = fbo.toImage().mirrored(false, true); // Flip vertically
    QSGTexture* texture = window()->createTextureFromImage(image);

    node->setTexture(texture);
    node->setRect(boundingRect());
    node->markDirty(QSGNode::DirtyMaterial | QSGNode::DirtyGeometry);

    return node;
}

void VTKQuickItem::geometryChange(const QRectF& newGeometry, const QRectF& oldGeometry)
{
    QQuickItem::geometryChange(newGeometry, oldGeometry);
    update();
}

void VTKQuickItem::setVolumeData(float* volume, const int* dim, double* pixPitch)
{
    if (!m_initialized) return;

    // Store volume data
    if (m_volumeData) {
        delete[] m_volumeData;
    }

    int totalSize = dim[0] * dim[1] * dim[2];
    m_volumeData = new float[totalSize];
    memcpy(m_volumeData, volume, totalSize * sizeof(float));

    for (int i = 0; i < 3; i++) {
        m_dim[i] = dim[i];
        m_pixPitch[i] = pixPitch[i];
    }

    // Create volume import
    m_volumeImport = vtkSmartPointer<vtkImageImport>::New();
    m_volumeImport->SetWholeExtent(0, dim[0]-1, 0, dim[1]-1, 0, dim[2]-1);
    m_volumeImport->SetDataExtentToWholeExtent();
    m_volumeImport->SetDataScalarTypeToFloat();
    m_volumeImport->SetNumberOfScalarComponents(1);
    m_volumeImport->SetImportVoidPointer(volume);
    m_volumeImport->SetDataSpacing(pixPitch[0], pixPitch[1], pixPitch[2]);
    m_volumeImport->Update();

    // Create mapper
    m_volumeMapper = vtkSmartPointer<vtkGPUVolumeRayCastMapper>::New();
    m_volumeMapper->SetInputConnection(m_volumeImport->GetOutputPort());
    m_volumeMapper->SetBlendModeToComposite();

    // Create volume property
    vtkSmartPointer<vtkVolumeProperty> volumeProperty =
        vtkSmartPointer<vtkVolumeProperty>::New();

    vtkSmartPointer<vtkColorTransferFunction> colorFunc =
        vtkSmartPointer<vtkColorTransferFunction>::New();
    vtkSmartPointer<vtkPiecewiseFunction> alphaFunc =
        vtkSmartPointer<vtkPiecewiseFunction>::New();

    // Add your transfer functions here (from your skinOnBlueMap)
    double skinOnBlueMap[8][5] = {
        {-923, 0.987853825092316, 1.0, 1.0, 0.0},
        {-733, 0.987853825092316, 1.0, 1.0, 0.00750770070067319},
        {-531, 0.987853825092316, 1.0, 1.0, 0.0733569149832789},
        {-372, 0.987853825092316, 1.0, 1.0, 0.0},
        {142, 0.0, 0.0, 0.0, 0.0},
        {332, 1.0, 0.0, 0.0, 0.132020258336102},
        {534, 1.0, 0.999206542968750, 0.0, 0.317781232734010},
        {679, 1.0, 1.0, 1.0, 0.940655276334784}
    };

    for (int i = 0; i < 8; i++) {
        colorFunc->AddRGBPoint(skinOnBlueMap[i][0],
                              skinOnBlueMap[i][1],
                              skinOnBlueMap[i][2],
                              skinOnBlueMap[i][3]);
        alphaFunc->AddPoint(skinOnBlueMap[i][0], skinOnBlueMap[i][4]);
    }

    volumeProperty->SetColor(colorFunc);
    volumeProperty->SetScalarOpacity(alphaFunc);
    volumeProperty->SetInterpolationTypeToLinear();
    volumeProperty->ShadeOn();
    volumeProperty->SetAmbient(0.1);
    volumeProperty->SetDiffuse(0.9);
    volumeProperty->SetSpecular(0.2);
    volumeProperty->SetSpecularPower(10.0);

    // Create volume actor
    m_volumeActor = vtkSmartPointer<vtkVolume>::New();
    m_volumeActor->SetMapper(m_volumeMapper);
    m_volumeActor->SetProperty(volumeProperty);

    // Add to renderer
    m_renderer->RemoveAllViewProps();
    m_renderer->AddVolume(m_volumeActor);
    m_renderer->ResetCamera();

    update();
}

void VTKQuickItem::renderExample()
{
    if (!m_initialized) return;

    // Simple cone for testing
    vtkSmartPointer<vtkConeSource> cone =
        vtkSmartPointer<vtkConeSource>::New();
    cone->SetHeight(3.0);
    cone->SetRadius(1.0);
    cone->SetResolution(50);

    vtkSmartPointer<vtkPolyDataMapper> mapper =
        vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(cone->GetOutputPort());

    vtkSmartPointer<vtkActor> actor =
        vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

    m_renderer->AddActor(actor);
    m_renderer->ResetCamera();

    update();
}
