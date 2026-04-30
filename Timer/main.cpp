#include <QCoreApplication>
#include "newtimer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    NewTimer nTimer;

    return a.exec();
}

