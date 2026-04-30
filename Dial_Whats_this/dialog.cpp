#include "dialog.h"
#include "ui_dialog.h"
#include<QtGui>
#include<QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    Linkfilter *filter=new Linkfilter(this);
    this->installEventFilter(filter);
    connect(filter,SIGNAL(linkClicked(QString)),this,SLOT(showLink(QString)));
    ui->Popup_PB->setWhatsThis("for more information <a href='www.google.com'>click here</a>");

}
void Dialog::showLink(const QString &Link)
{
    QMessageBox::information(this,"Link clicked",Link);
}

Dialog::~Dialog()
{
    delete ui;
}
