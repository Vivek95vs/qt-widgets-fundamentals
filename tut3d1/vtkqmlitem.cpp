#include "vtkqmlitem.h"

#include <QOpenGLFramebufferObject>
#include <QOpenGLFramebufferObjectFormat>

#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRTAnalyticSource.h>
#include <vtkGPUVolumeRayCastMapper.h>
#include <vtkVolume.h>
#include <vtkVolumeProperty.h>
#include <vtkColorTransferFunction.h>
#include <vtkPiecewiseFunction.h>

class VTKRenderer : public QQuickFramebufferObject::Renderer
{
public:
    QOpenGLFramebufferObject *createFramebufferObject(const QSize &size) override
    {
        if (!rw)
        {
            rw = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
            ren = vtkSmartPointer<vtkRenderer>::New();
            rw->AddRenderer(ren);

            auto src = vtkSmartPointer<vtkRTAnalyticSource>::New();
            src->Update();

            auto mapper = vtkSmartPointer<vtkGPUVolumeRayCastMapper>::New();
            mapper->SetInputConnection(src->GetOutputPort());

            auto ctf = vtkSmartPointer<vtkColorTransferFunction>::New();
            ctf->AddRGBPoint(0, 0, 0, 0);
            ctf->AddRGBPoint(255, 1, 1, 1);

            auto otf = vtkSmartPointer<vtkPiecewiseFunction>::New();
            otf->AddPoint(0, 0.0);
            otf->AddPoint(255, 1.0);

            auto prop = vtkSmartPointer<vtkVolumeProperty>::New();
            prop->SetColor(ctf);
            prop->SetScalarOpacity(otf);

            auto volume = vtkSmartPointer<vtkVolume>::New();
            volume->SetMapper(mapper);
            volume->SetProperty(prop);

            ren->AddVolume(volume);
            ren->ResetCamera();
        }

        rw->SetSize(size.width(), size.height());

        QOpenGLFramebufferObjectFormat format;
        format.setAttachment(QOpenGLFramebufferObject::Depth);
        return new QOpenGLFramebufferObject(size, format);
    }

    void render() override
    {
        rw->Render();
        update();
    }

private:
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> rw;
    vtkSmartPointer<vtkRenderer> ren;
};

QQuickFramebufferObject::Renderer *VTKQmlItem::createRenderer() const
{
    return new VTKRenderer();
}
