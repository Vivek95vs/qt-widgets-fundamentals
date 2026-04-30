#include <QCoreApplication>
#include<QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString mst= "Hello world!";

    qDebug()<<mst;

    return a.exec();
}

