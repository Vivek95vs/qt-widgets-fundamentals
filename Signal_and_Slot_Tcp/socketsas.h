#ifndef SOCKETSAS_H
#define SOCKETSAS_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QAbstractSocket>

class socketSAS : public QObject
{
    Q_OBJECT
public:
    explicit socketSAS(QObject *parent = 0);
    void Test();

signals:

public slots:
    void connected();
    void disconnected();
    void BytesWritten(qint64 bytes);
    void ReadyRead();

private:
    QTcpSocket *socket;
};

#endif // SOCKETSAS_H
