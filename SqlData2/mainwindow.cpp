#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QtSql/QSqlDatabase>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QODBC" , "PANACEAMEDICAL\\Vivek.VS");
    db.setDatabaseName("DRIVER={SQL Server};SERVER=VIVEK-VS-WS;DATABASE=master");

    db.setUserName("sa");
    db.setPassword("");
    if(!db.open())
     {
     qDebug() << "Can't Connect to DB !";
     }
     else
     {
     qDebug() << "Connected to db";
}
}

MainWindow::~MainWindow()
{
    delete ui;
}
