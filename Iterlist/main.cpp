#include <QCoreApplication>
#include<QList>
#include<QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int>List;
    for(int i=0;i<20;i++)
    {
        List.append(i);
    }
    QListIterator<int>Iter(List);
    Iter.toBack();

    while(Iter.hasPrevious())
    {
        qDebug()<<Iter.previous();

        if(Iter.hasPrevious()){

            qDebug()<<"Next"<<Iter.peekPrevious();
        }
    }
    return a.exec();
}

