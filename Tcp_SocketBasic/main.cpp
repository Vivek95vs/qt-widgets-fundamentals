#include <QCoreApplication>
#include "sockettest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    socketTest cTest;
    cTest.connect();

    return a.exec();
}

