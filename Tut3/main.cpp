#include "mainwindow.h"
#include <QApplication>
#include<QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel *label=new QLabel("<b>Hello</b> <font color=red> <i>world</i>");

    label->show();

    return a.exec();
}
