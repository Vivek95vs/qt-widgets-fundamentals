#include <QCoreApplication>
#include <QHash>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

   QHash<int,QString>student;

   student.insert(1,"Vivek");
   student.insert(2,"Sam");

   qDebug()<<"3="<<student.value(3);

//   foreach(int i,student.keys())
//   {
//       qDebug()<<student[i];

//   }

//   QHashIterator<int,QString>Iter(student);

//   while(Iter.hasNext())
//   {
//       Iter.next();
//       qDebug()<<Iter.key()<<"="<<Iter.value();
//   }

    return a.exec();
}

