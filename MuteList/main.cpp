#include <QCoreApplication>
#include<QList>
#include<QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int>List;

    for(int i=0;i<10;i++)
    {

        List.append(i);
    }

    QMutableListIterator<int>iter(List);

    while(iter.hasNext())
    {

        int i=iter.next();
        if(i==5){
            iter.remove();
        }
    }
    iter.toFront();
    while(iter.hasNext())
    {
        qDebug()<<iter.next();
    }
    return a.exec();
}

