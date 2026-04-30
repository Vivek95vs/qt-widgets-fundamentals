#include <QCoreApplication>
#include<QDebug>
#include<QtSql/QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
#include<QString>

int main(int argc, char *argv[])
{
        QCoreApplication a(argc, argv);

        QSqlDatabase db=QSqlDatabase ::addDatabase("QODBC");

        db.setHostName("VIVEK-VS-WS");

        db.setDatabaseName("myDSN32");

        if(db.open())
        {
            qDebug()<<"Connected to SQL";
        }
        else
        {
            qDebug()<<"Error ="<<db.lastError().text();
        }

        return a.exec();
    }

