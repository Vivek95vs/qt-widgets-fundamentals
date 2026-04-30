#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(int i=0;i<12;i++){

        ui->listWidget->addItem("items "+ QString::number(i));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QListWidgetItem *itm= ui->listWidget->currentItem();
    itm->setText("good boy");
    itm->setTextColor(Qt::green);
    itm->setBackground(Qt::red);

}
