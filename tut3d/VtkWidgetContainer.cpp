#include "VtkWidgetContainer.h"
#include "VolumeRenderer.h"

VtkWidgetContainer::VtkWidgetContainer(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMargin(0);

    vtkWidget = new MyQvtkWidget(this);
    layout->addWidget(vtkWidget);
}

void VtkWidgetContainer::startRender()
{
    VolumeRenderer::render(vtkWidget->GetRenderWindow());
}
