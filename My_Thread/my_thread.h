#ifndef MY_THREAD_H
#define MY_THREAD_H
#include <QtCore>

class My_Thread : public QThread
{
public:
    My_Thread();
    void run();
    QString name;
};

#endif // MY_THREAD_H
