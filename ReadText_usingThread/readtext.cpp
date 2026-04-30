#include "readtext.h"

ReadText::ReadText(QObject *parent) : QObject(parent)
{
    this->moveToThread(&mThread);
    connect(&mThread,SIGNAL(started()),this,SLOT(ReadSTDIN()));
    connect(this,SIGNAL(OnReadLine(QString)),this,SLOT(HandleSTDIN(QString)));
    mThread.start();
}

void ReadText::ReadSTDIN()
{
    QTextStream Stream(stdin);
    QString Line=Stream.readLine();
    emit OnReadLine(Line);
    ReadSTDIN();
}

void ReadText::HandleSTDIN(QString Line)
{
//    qDebug()<<Line;
    WriteSTDOUT(Line);
}

void ReadText::WriteSTDOUT(QString Line)
{
    QTextStream Stream(stdout);
    Stream<<Line;
}

