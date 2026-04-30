#include "timeree.h"
#include<QTimer>
#include <QDebug>

timeree::timeree()
{
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(MySlot()));
    timer->start(5000);
}
void timeree::MySlot()
{
    qDebug()<<"Timer to be executed";
}
