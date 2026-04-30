#include <QCoreApplication>
#include <QMap>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc,argv);

    QMap<int,QString>student;

    student.insert(1,"Vivek");
    student.insert(2,"Sam");
    student.insert(3,"Aravinth");

    foreach(int i,student.keys())
    {
        qDebug()<<student[i];
    }
    QMapIterator<int,QString>Iter(student);

    while(Iter.hasNext())
    {

        Iter.next();
        qDebug()<<Iter.key()<<"="<<Iter.value();
    }

    return a.exec();
}

