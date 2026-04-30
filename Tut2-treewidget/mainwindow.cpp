#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore>
#include <QtGui>
#include <QString>
#include <QTreeWidgetItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(3);
    AddRoot("Name","Types","Nature");


    AddRoot("Name","Types","Nature");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::AddRoot(QString name,QString description,QString function){

    QTreeWidgetItem *itm=new QTreeWidgetItem(ui->treeWidget);

    itm->setText(0,name);
    itm->setText(1,description);
    itm->setText(2,function);

    AddChild(itm,"Dog","Mammal","Domestic");
    AddChild(itm,"Cat","Mammal","Domestic");

}

void MainWindow::AddChild(QTreeWidgetItem *parent, QString name,QString description,QString function){

    QTreeWidgetItem *itm=new QTreeWidgetItem();

    itm->setText(0,name);
    itm->setText(1,description);
    itm->setText(2,function);

    parent->addChild(itm);

}
