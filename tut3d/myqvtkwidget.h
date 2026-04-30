#ifndef MYQVTKWIDGET_H
#define MYQVTKWIDGET_H

#include <QVTKOpenGLWidget.h>

class MyQvtkWidget : public QVTKOpenGLWidget
{
    Q_OBJECT
public:
    explicit MyQvtkWidget(QWidget *parent = nullptr);
};

#endif
