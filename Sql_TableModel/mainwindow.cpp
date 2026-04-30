#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->tableView);
    db=QSqlDatabase::addDatabase("QODBC");
    db.setHostName("VIVEK-VS-WS");
    db.setDatabaseName("master");
    db.open();

    model=new QSqlTableModel(this);
    model->setTable("spt_fallback_db");
    model->select();
    qDebug()<<model->lastError().text();
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}
