#include "sockettest.h"

socketTest::socketTest(QObject *parent) : QObject(parent)
{

}

void socketTest::connect()
{
    socket= new QTcpSocket(this);
    socket->connectToHost("www.programiz.com",80);
    if(socket->waitForConnected(3000))
    {
        qDebug()<<"connected!";
        socket->write("hello server \r\n\r\n\r\n\r\n");
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);
        qDebug()<<"Reading:"<<socket->bytesAvailable();
        qDebug()<<socket->readAll();
        socket->close();
    }
    else
    {
        qDebug()<<"Not Connected!";
    }
}

