#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QString>
#include <QDebug>

class person : public QObject
{
    Q_OBJECT
public:
    explicit person(QObject *parent = 0);
    QString Name;
    void Gossip(QString words);

signals:
    void speak(QString words);

public slots:
    void listen(QString words);
};

#endif // PERSON_H
