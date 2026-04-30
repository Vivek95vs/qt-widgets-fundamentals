#include <QCoreApplication>
#include<QList>
#include<QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int>List;

   for(int i=0;i<39;i++)
   {
       List.append(i);
   }

   List.removeAll(34);

   foreach (int Number, List) {

       qDebug()<<Number;

   }

    return a.exec();
}

