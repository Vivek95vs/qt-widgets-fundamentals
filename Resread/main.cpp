#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QString>

void Read(QString Filename){

    QFile mFile(Filename);

    if(!mFile.open(QFile::ReadOnly | QFile::Text)){

    qDebug()<<"could not open the file for read";

        return;
    }


    QTextStream in(&mFile);

    QString mText= in.readAll();

    qDebug()<<mText;


    mFile.close();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString mFilename=":/Filename/Resread.pro";

    Read(mFilename);

    return a.exec();
}

