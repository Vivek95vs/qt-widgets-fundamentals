#include "newtimer.h"
#include<QtCore>
#include<QDebug>

NewTimer::NewTimer()
{

timer = new QTimer(this);
connect(timer,SIGNAL(timeout()),this,SLOT(mySlot()));
        timer->start(1000);

}
void NewTimer::mySlot(){

    qDebug()<<"Run the Timer";
}
