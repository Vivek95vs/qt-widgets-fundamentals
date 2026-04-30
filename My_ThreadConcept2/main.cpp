#include <QCoreApplication>
#include "mythread.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyThread mthread;
    mthread.start();

    mthread.wait();
    qDebug()<<"Done";

    return a.exec();
}

