#ifndef READTEXT_H
#define READTEXT_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QTextStream>

class ReadText : public QObject
{
    Q_OBJECT
public:
    explicit ReadText(QObject *parent = 0);

signals:
    void OnReadLine(QString Line);

public slots:
    void ReadSTDIN();
    void HandleSTDIN(QString Line);
    void WriteSTDOUT(QString Line);

private:
    QThread mThread;
};

#endif // READTEXT_H
