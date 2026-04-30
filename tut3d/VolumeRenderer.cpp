#include "VolumeRenderer.h"

#include <vtkRTAnalyticSource.h>
#include <vtkColorTransferFunction.h>
#include <vtkPiecewiseFunction.h>
#include <vtkVolumeProperty.h>

void VolumeRenderer::render(vtkRenderWindow *window)
{
    auto source = vtkSmartPointer<vtkRTAnalyticSource>::New();
    source->Update();

    auto mapper = vtkSmartPointer<vtkGPUVolumeRayCastMapper>::New();
    mapper->SetInputConnection(source->GetOutputPort());

    auto color = vtkSmartPointer<vtkColorTransferFunction>::New();
    color->AddRGBPoint(0, 0, 0, 0);
    color->AddRGBPoint(255, 1, 1, 1);

    auto opacity = vtkSmartPointer<vtkPiecewiseFunction>::New();
    opacity->AddPoint(0, 0.0);
    opacity->AddPoint(255, 1.0);

    auto prop = vtkSmartPointer<vtkVolumeProperty>::New();
    prop->SetColor(color);
    prop->SetScalarOpacity(opacity);

    auto volume = vtkSmartPointer<vtkVolume>::New();
    volume->SetMapper(mapper);
    volume->SetProperty(prop);

    auto renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddVolume(volume);
    renderer->ResetCamera();

    window->AddRenderer(renderer);
    window->Render();
}
