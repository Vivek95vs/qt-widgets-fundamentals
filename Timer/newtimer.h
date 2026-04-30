#ifndef NEWTIMER_H
#define NEWTIMER_H

#include<QtCore>
#include<QTimer>

class NewTimer : public QObject
{

    Q_OBJECT

public:
    NewTimer();
    QTimer *timer;

public slots:
    void mySlot();
};

#endif // NEWTIMER_H
