#include "mainwindow.h"
#include <QApplication>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *w=new QWidget();
    w->setWindowTitle("My App");

    QPushButton *button1=new QPushButton("one");
    QPushButton *button2=new QPushButton("Two");
    QPushButton *button3=new QPushButton("Three");

    //QHBoxLayout *hlayout=new QHBoxLayout;

    QVBoxLayout *vlayout=new QVBoxLayout;

    vlayout->addWidget(button1);
    vlayout->addWidget(button2);
    vlayout->addWidget(button3);

    w->setLayout(vlayout);

    w->show();

    return a.exec();
}
