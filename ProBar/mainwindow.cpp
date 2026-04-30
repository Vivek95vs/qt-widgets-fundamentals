#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   connect(ui->verticalSlider,SIGNAL(valueChanged(int)),ui->progressBar,SLOT(setValue(int)));

   connect(ui->verticalSlider,SIGNAL(valueChanged(int)),ui->progressBar_2,SLOT(setValue(int)));

   disconnect(ui->verticalSlider,SIGNAL(valueChanged(int)),ui->progressBar_2,SLOT(setValue(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}
