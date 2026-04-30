#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include <QApplication>
//#include <QCoreApplication>
#include <QtGui>
#include <QtCore>
#include <QGridLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>

MainWindow::MainWindow()/*(QWidget *parent) :
    QMainWindow(parent)//,
    //ui(new Ui::MainWindow)*/
{
    //ui->setupUi(this);
    QWidget *w=new QWidget();
    w->setWindowTitle("Info");

    QGridLayout *layout=new QGridLayout();

    QLabel *label1= new QLabel("Name");
    QTextEdit *txtName= new QTextEdit("Vivek");

    QLabel *label2= new QLabel("Address");
    QTextEdit *txtName2= new QTextEdit("Malur");


    layout->addWidget(label1,0,0);
    layout->addWidget(txtName,0,1);
    layout->addWidget(label2,1,0);
    layout->addWidget(txtName2,1,1);

    QPushButton *button=new QPushButton("Ok");

    layout->addWidget(button,2,0,1,2);

    w->setLayout(layout);

    w->show();
    this->close();
}

MainWindow::~MainWindow()
{
   // delete ui;
}
