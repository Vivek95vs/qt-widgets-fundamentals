#ifndef TIMEREE_H
#define TIMEREE_H
#include<QTimer>


class timeree : public QObject
{
    Q_OBJECT

public:
    timeree();
    QTimer  *timer;

public slots:
    void MySlot();
};

#endif // TIMEREE_H
