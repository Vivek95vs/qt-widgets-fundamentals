#include <QCoreApplication>
#include "myobject.h"
#include <QThread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QThread vThread;
    MyObject vObject;
    vObject.doSetup(vThread);
    vObject.moveToThread(&vThread);
    vThread.start();

    return a.exec();
}

