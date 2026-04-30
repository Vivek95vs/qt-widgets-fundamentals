#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QCoreApplication>
#include <QtCore>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->label->setText("Hello");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   QMessageBox::information(this,"PoP up","Me");
}
