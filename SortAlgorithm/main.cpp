#include <QCoreApplication>
#include <QDebug>
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int>List;

    List<< 4<<5<<7<<2<<6<<8<<9<<34<<56<<23<<23<<45<<67<<4<<3<<4;

    //qSort(List);

    qSort(List.begin()+1,List.end()-1);

    foreach(int i,List){

        qDebug()<<i;
    }

    return a.exec();
}

