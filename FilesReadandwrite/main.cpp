#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QTextStream>
#include <QFile>

void write(QString filename){

    QFile mfile(filename);

    if(!mfile.open(QFile::WriteOnly | QFile::Text)){

        qDebug()<<"Could not open the file for write";
        return;
    }

    QTextStream out(&mfile);

    out<<"Hello world:";

    mfile.flush();
    mfile.close();


}

void read(QString filename){

    QFile mfile(filename);

    if(!mfile.open(QFile::ReadOnly | QFile::Text)){

        qDebug()<<"Could not open the file for Read";
        return;
    }

    QTextStream in(&mfile);

    QString mText=in.readAll();

    qDebug()<<mText;


    mfile.close();


}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString mfilename= "D:/Workflow/vivek.txt";

    write(mfilename);
    read(mfilename);

    return a.exec();
}

