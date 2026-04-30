#ifndef VTKWIDGETCONTAINER_H
#define VTKWIDGETCONTAINER_H

#include <QWidget>
#include <QVBoxLayout>
#include "myqvtkwidget.h"

class VtkWidgetContainer : public QWidget
{
    Q_OBJECT
public:
    explicit VtkWidgetContainer(QWidget *parent = nullptr);

    Q_INVOKABLE void startRender();

private:
    MyQvtkWidget *vtkWidget;
};

#endif
