#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore>
#include <QtGui>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this,"Notification","Personal details");
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"Notification","Do you love watching Youtube",QMessageBox::Yes | QMessageBox::No);

    if(reply==QMessageBox::Yes){

        QMessageBox::information(this,"Pop","I like to watch youtube");
    }
    else{

        QMessageBox::information(this,"Pop","I don't like to watch youtube");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::warning(this,"Notification","System crash");
}

void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"Notification","Do you love watching Youtube",QMessageBox::Yes | QMessageBox::YesAll | QMessageBox::No | QMessageBox::NoAll);

    if(reply==QMessageBox::Yes){

        QMessageBox::information(this,"Pop","I like to watch youtube");
    }
    else if(reply==QMessageBox::No){

        QMessageBox::information(this,"Pop","I don't like to watch youtube");
    }
    else{

        QMessageBox::information(this,"Pop","No response");
    }

}
