#include <QCoreApplication>
#include "socketsas.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    socketSAS mTest;
    mTest.Test();

    return a.exec();
}

