#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db=QSqlDatabase ::addDatabase("QODBC");
    db.setHostName("VIVEK-VS-WS");
    db.setDatabaseName("myDSN32");
    db.open();

    model=new QSqlRelationalTableModel(this);
    model->setTable("spt_fallback_db");
    model->setRelation(0,QSqlRelation("wages","id","salary"));
    model->select();
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}
