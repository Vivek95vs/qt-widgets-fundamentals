#ifndef MYTHEAD_H
#define MYTHEAD_H

#include <QThread>
class MyThead : public QThread
{
    Q_OBJECT
public:
    explicit MyThead(QObject *parent=0);
    void run();
    bool stop;

signals:
    void NumberChanged(int);
};

#endif // MYTHEAD_H
