#include "myobject.h"

MyObject::MyObject(QObject *parent) : QObject(parent)
{

}

void MyObject::doSetup(QThread &vThread)
{
  connect(&vThread,SIGNAL(started()),this,SLOT(doWork()));
}

void MyObject::doWork()
{
    for(int i=0;i<10000;i++)
    {
        qDebug()<<i;
    }
}

