#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QHttp>
#include <QTcpServer>
#include <QFile>
#include <QDebug>

class downloader : public QObject
{
    Q_OBJECT
public:
    explicit downloader(QObject *parent = 0);
    void Do_Download();

signals:

public slots:
    void statechanged(int state);
    void responseHeaderReceived(const )
};

#endif // DOWNLOADER_H
