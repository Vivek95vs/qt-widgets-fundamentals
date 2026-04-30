#include "mytimer.h"
//#include<QtCore>
#include<QTimer>

mytimer::mytimer()
{
timer= new QTimer(this);
connect(timer,SIGNAL(timeout()),this,SLOT(MySlot()));
timer->start(2000);
}

void mytimer::MySlot(){

    qDebug()<<"Run the timer";
}
