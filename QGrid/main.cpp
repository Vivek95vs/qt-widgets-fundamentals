#include "mainwindow.h"
#include <QCoreApplication>
#include <QtGui>
#include <QtCore>
#include <QGridLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //MainWindow w;

    QWidget *w=new QWidget();
    w->setWindowTitle("Info");

    QGridLayout *layout=new QGridLayout;

    QLabel *label1= new QLabel("Name");
    QTextEdit *txtName= new QTextEdit;


    layout->addWidget(label1,0,0);
    layout->addWidget(txtName,0,1);

    w->setLayout(layout);

    w->show();

    return a.exec();
}
