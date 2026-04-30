#include <QCoreApplication>
#include "readtext.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ReadText cCLI;

    return a.exec();
}

