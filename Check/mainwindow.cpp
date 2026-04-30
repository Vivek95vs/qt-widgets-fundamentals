#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->checkBox->setChecked("false");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
if(ui->checkBox->isChecked()){

    QMessageBox::information(this,"Picnic","Everything is checked");

}
else{

    QMessageBox::information(this,"Picnic","Everything is not checked");
}
}
