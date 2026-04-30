#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    mthread=new MyThead(this);
    connect(mthread,SIGNAL(NumberChanged(int)),this,SLOT(onNumberChanged(int)));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::onNumberChanged(int Number)
{
    ui->label->setText(QString::number(Number));
}

void Dialog::on_pushButton_clicked()
{

    mthread->start();
}

void Dialog::on_pushButton_2_clicked()
{
    mthread->terminate();
}
