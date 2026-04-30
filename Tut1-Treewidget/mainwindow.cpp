#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore>
#include <QtGui>
#include <QTreeWidgetItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->treeWidget->setHeaderLabels(QStringList()<<"col a"<<"col b");

    ui->treeWidget->setColumnCount(2);
    AddRoot("hello 1","world 1");
    AddRoot("hello 2","world 2");
    AddRoot("hello 3","world 3");
    //qDebug()<<"hello 1","world 1";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddRoot(QString name,QString description){

    QTreeWidgetItem *itm=new QTreeWidgetItem(ui->treeWidget);

    itm->setText(0,name);
    itm->setText(1,description);

    AddChild(itm,"one","hello");
    AddChild(itm,"two","world");
    //qDebug()<<"one";
}

void MainWindow::AddChild(QTreeWidgetItem *parent, QString name, QString description){

    QTreeWidgetItem *itm=new QTreeWidgetItem();

    itm->setText(0,name);
    itm->setText(1,description);
    parent->addChild(itm);
    //qDebug()<<"hello";


}

void MainWindow::on_pushButton_clicked()
{

   ui->treeWidget->currentItem()->setBackgroundColor(0,Qt::red);
   ui->treeWidget->currentItem()->setBackgroundColor(1,Qt::green);
}
