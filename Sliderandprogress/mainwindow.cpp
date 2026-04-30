#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->progressBar1->setValue(ui->horizontalSlider->value());
    ui->progressBar2->setValue(ui->horizontalSlider->value());

    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->progressBar1,SLOT(setValue(int)));
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->progressBar2,SLOT(setValue(int)));

    disconnect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->progressBar2,SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
