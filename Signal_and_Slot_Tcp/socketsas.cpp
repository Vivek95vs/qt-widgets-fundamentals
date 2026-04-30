#include "socketsas.h"

socketSAS::socketSAS(QObject *parent) : QObject(parent)
{

}

void socketSAS::Test()
{
  socket=new QTcpSocket(this);
connect(socket,SIGNAL(connected()),this,SLOT(connected()));
connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
connect(socket,SIGNAL(readyRead()),this,SLOT(ReadyRead()));
connect(socket,SIGNAL(bytesWritten(qint64)),this,SLOT(BytesWritten(qint64)));

qDebug()<<"Connecting...";
socket->connectToHost("www.google.com",80);
if(!socket->waitForConnected(1000))
{
    qDebug()<<"Error:"<<socket->errorString();
}
}

void socketSAS::connected()
{
    qDebug()<<"connected!";
    socket->write("HEAD/HTTP/1.0 \r\n\r\n\r\n");
}

void socketSAS::disconnected()
{
    qDebug()<<"Disconnected!";
}

void socketSAS::BytesWritten(qint64 bytes)
{
    qDebug()<<"We Wrote:"<<bytes;
}

void socketSAS::ReadyRead()
{
    qDebug()<<"Reading....";
    qDebug()<<socket->readAll();
}
