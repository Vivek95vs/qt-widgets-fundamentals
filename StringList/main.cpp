#include <QCoreApplication>
#include <QStringList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList List;

    //List.append("Hello");

    QString Line = "a,b,c,d,e,f,g";

    List= Line.split(",");

    //List.replace("c","catch");
    QString After= List.join(",");

    qDebug()<<After;


//    foreach(QString itm,List)
//    {

//        qDebug()<<itm;
//    }


    return a.exec();
}

