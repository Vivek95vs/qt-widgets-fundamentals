#ifndef VTKQUICKITEM_H
#define VTKQUICKITEM_H

#include <QQuickItem>
#include <QTimer>
#include <QElapsedTimer>
#include <vtkSmartPointer.h>
#include <vtkFixedPointVolumeRayCastMapper.h>

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkRenderingVolumeOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)

// Forward declarations
class vtkRenderer;
class vtkGenericOpenGLRenderWindow;
class vtkVolume;
class vtkGPUVolumeRayCastMapper;
class vtkImageData;

class VTKQuickItem : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString dicomFolder READ dicomFolder WRITE setDicomFolder NOTIFY dicomFolderChanged)
    Q_PROPERTY(bool volumeLoaded READ volumeLoaded NOTIFY volumeLoadedChanged)
    Q_PROPERTY(bool rendering READ rendering WRITE setRendering NOTIFY renderingChanged)
    Q_PROPERTY(QString status READ status NOTIFY statusChanged)

public:
    VTKQuickItem(QQuickItem *parent = nullptr);
    ~VTKQuickItem();

    QString dicomFolder() const;
    void setDicomFolder(const QString &folder);

    bool volumeLoaded() const;
    bool rendering() const;
    void setRendering(bool render);

    QString status() const;

    Q_INVOKABLE void loadDicomVolume();
    Q_INVOKABLE void resetCamera();
    Q_INVOKABLE void stopRendering();

signals:
    void dicomFolderChanged();
    void volumeLoadedChanged();
    void renderingChanged();
    void statusChanged();
    void errorOccurred(const QString &message);

protected:
    void geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private slots:
    void handleWindowChanged(QQuickWindow *window);
    void renderFrame();

private:
    bool initVTK();
    void cleanupVTK();
    void createVolumeRenderer(vtkImageData* imageData);
    void updateCamera();

    QString m_dicomFolder;
    bool m_volumeLoaded = false;
    bool m_rendering = false;
    bool m_initialized = false;
    QString m_status;

    vtkSmartPointer<vtkGenericOpenGLRenderWindow> m_renderWindow;
    vtkSmartPointer<vtkRenderer> m_renderer;
    vtkSmartPointer<vtkVolume> m_volume;
    vtkSmartPointer<vtkFixedPointVolumeRayCastMapper> m_volumeMapper;

    QTimer m_renderTimer;
    QElapsedTimer m_frameTimer;

    QPoint m_lastMousePos;
    bool m_mousePressed = false;

    QQuickWindow *m_window = nullptr;

    void setStatus(const QString &status);
};

#endif // VTKQUICKITEM_H
