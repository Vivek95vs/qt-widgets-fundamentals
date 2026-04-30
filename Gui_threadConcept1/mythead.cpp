#include "mythead.h"

#include <QtCore>
MyThead::MyThead(QObject *parent) : QThread(parent)
{

}

void MyThead::run()
{
    for(int i=0;i<=1000;++i)
    {

//        if(this->stop)break;

        emit NumberChanged(i);
        this->msleep(100);
    }
}
