#include "my_thread.h"
#include <QtCore>
#include <QDebug>

My_Thread::My_Thread()
{

}

void My_Thread::run()
{
       qDebug()<<this->name<<"Running";
       for(int i=0;i<100;i++)
       {
           qDebug()<<this->name<<i;
       }
}

