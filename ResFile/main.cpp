#include <QCoreApplication>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>

void Read(QString Filename){
    QFile mfile(Filename);
    if(!mfile.open(QFile::ReadOnly | QFile::Text){

        qDebug()<<"Could not open the file for read";
        return;s
    }

    QTextStream in(&mfile);

    QString mText=in.readAll();

    qDebug()<<mText

    mfile.close();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Read(":/Filename/ResFile.pro")

    return a.exec();
}

