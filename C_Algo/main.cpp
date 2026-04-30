#include <QCoreApplication>
#include <QStringList>
#include <QVector>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QStringList List;

    List << "a" << "f" << "d" << "v";


    QVector<QString>Vect(3);

    qCopy(List.begin(),List.end(),Vect.begin());

    foreach (QString itm, Vect) {

        qDebug()<<itm;
    }

    return app.exec();
}
