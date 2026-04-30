#include <QCoreApplication>
#include <QStringList>
#include <QString>
#include <QVector>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList List;

    List << "a" << "f" << "d" << "v";


    QVector<QString>vect(3);

    qCopy(List.begin(),List.end(),vect.begin());

    foreach (QString itm, vect) {

        qDebug()<<itm;
    }

    return a.exec();
}

