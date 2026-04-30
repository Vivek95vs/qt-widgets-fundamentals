#ifndef VTKQMLITEM_H
#define VTKQMLITEM_H

#include <QQuickFramebufferObject>
#include <vtkSmartPointer.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderer.h>

class VTKQmlItem : public QQuickFramebufferObject
{
    Q_OBJECT
public:
    Renderer *createRenderer() const override;

    vtkSmartPointer<vtkRenderer> renderer;
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> renderWindow;
};

#endif
