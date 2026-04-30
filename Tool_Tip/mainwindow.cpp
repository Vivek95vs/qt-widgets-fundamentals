#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QtGui>
#include<QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton1->setToolTip("Good <font color='green'><b>Afternoon</b></font>"
                                "<ul>"
                                "<li>Take lunch</li>"
                                "<li>Study QT</li>"
                                "<li>Do Coding</li>"
                                "</ul>");

    ui->pushButton2->setToolTip("<img src=':/files/1-SG(32).png'>Good Afternoon");
}

MainWindow::~MainWindow()
{
    delete ui;
}
