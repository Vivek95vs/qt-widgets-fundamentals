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
    this->model=new QSqlQueryModel();
    model->setQuery("SELECT [xserver_name],[xdttm_ins],[xdttm_last_ins_upd],[xfallback_dbid],[name],[dbid],[status],[version] FROM [dbo].[spt_fallback_db]");
    ui->tableView->setModel(model);

}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}
