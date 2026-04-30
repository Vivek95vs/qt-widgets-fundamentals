#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore>
#include <QtGui>
#include <QLabel>
#include <QProgressBar>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    statlabel = new QLabel(this);
    statprogress = new QProgressBar(this);

    ui->statusBar->addPermanentWidget(statlabel);
    ui->statusBar->addPermanentWidget(statprogress);

    statlabel->setText("Good day");
    statprogress->setTextVisible(false);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{

     ui->statusBar->showMessage("Nice Day");
     statprogress->setValue();

}
