#include <QCoreApplication>
#include <QDebug>
#include <QLinkedList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QLinkedList<int>list;

    list<< 3 << 3<< 5<< 8<< 9<< 82<<33;

    foreach(int i, list)
    {
        qDebug()<<i;
    }

    return a.exec();
}

