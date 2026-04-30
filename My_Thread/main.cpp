#include <QCoreApplication>
#include "my_thread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    My_Thread mthread1;
    mthread1.name="mthread1";

    My_Thread mthread2;
    mthread2.name="mthread2";

    My_Thread mthread3;
    mthread3.name="mthread3";

    My_Thread mthread4;
    mthread4.name="mthread4";

    My_Thread mthread5;
    mthread5.name="mthread5";


    mthread1.start(QThread::HighestPriority);
    mthread2.start(QThread::LowPriority);
    mthread3.start(QThread::HighPriority);
    mthread4.start(QThread::NormalPriority);
    mthread5.start(QThread::LowestPriority);
    return a.exec();
}

