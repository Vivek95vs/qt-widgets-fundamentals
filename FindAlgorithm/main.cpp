#include <QCoreApplication>
#include <QList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int>List;

    List << 3 << 5 << 8 << 5 <<6;

    QList<int>::const_iterator Iter=qFind(List.begin(),List.end(),5);

    if(Iter!=List.end()){

        qDebug()<<"Found:"<<*Iter;
    }
    else{

        qDebug()<<"Not Found:";

    }

    return a.exec();
}

