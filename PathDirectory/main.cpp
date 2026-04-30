/*#include <QCoreApplication>
#include<QDebug>
#include<QDir>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir mdir("D:/Workflow/QT Video tutorials");

    qDebug()<<mdir.exists();

    return a.exec();
}*/

/*#include <QCoreApplication>
#include<QDebug>
#include<QDir>
#include<QFileInfo>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir mdir;

    foreach (QFileInfo itm, mdir.drives()){

        qDebug()<<itm.absoluteFilePath();
    }

    return a.exec();
}*/

/*#include <QCoreApplication>
#include<QDebug>
#include<QDir>
#include<QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc,argv);

    QDir mdir;

    QString mpath= "D:/Workflow/viv";

    if(mdir.exists(mpath)){

        qDebug()<<"Already exist";
}
    else{
        mdir.mkpath(mpath);
        qDebug()<<"Created Successfully";
    }

    return a.exec();
}*/

/*#include <QCoreApplication>
#include<QDebug>
#include<QDir>
#include<QString>
#include<QFileInfo>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc,argv);

    QDir mdir="D:/Workflow";

    foreach(QFileInfo itm, mdir.entryInfoList()){

        qDebug()<<itm.absoluteFilePath();
    }

    return a.exec();
}*/

#include <QCoreApplication>
#include<QDebug>
#include<QDir>
#include<QString>
#include<QFileInfo>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc,argv);

    QDir mdir="D:/Workflow";

    foreach(QFileInfo itm, mdir.entryInfoList()){


        if(itm.isDir()) qDebug()<<"Dir :"<<itm.absoluteFilePath();
        if(itm.isFile()) qDebug()<<"File :"<<itm.absoluteFilePath();
    }

    return a.exec();
}

