#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QtCore>
//#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mydelegate=new Delegate(this);

    model=new QStandardItemModel(5,3,this);
    for(int row=0;row<5;row++)
    {
        for(int col=0;col<3;col++)
        {
            QModelIndex index=model->index(row,col,QModelIndex());
            model->setData(index,1);
        }
    }
    ui->tableView->setModel(model);
    ui->tableView->setItemDelegate(mydelegate);
}

MainWindow::~MainWindow()
{
    delete ui;
}
