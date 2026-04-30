#include "mydialog.h"
#include "ui_mydialog.h"

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
    ui->plainTextEdit1->show();
    ui->pushButton->show();
}

MyDialog::~MyDialog()
{
    delete ui;
}
