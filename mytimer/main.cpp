#include <QCoreApplication>

#include "mytimer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    mytimer ntimer;

    return a.exec();
}

