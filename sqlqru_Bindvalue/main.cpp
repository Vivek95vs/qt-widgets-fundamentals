#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
//#include <QHostInfo>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString servername="VIVEK-VS-WS";
    QString dbname="master";

    QSqlDatabase db=QSqlDatabase ::addDatabase("QODBC");

    db.setConnectOptions();

    //QString dsn =("DRIVER={SQL Native Client};SERVER=%1;DATABASE=%2;UID=sa;PWD=;").arg(servername).arg(dbname);
    QString dsn=("DRIVER={SQL Native Client 11.0};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(servername).arg(dbname);

    db.setDatabaseName(dsn);

    if(db.open())
    {
        qDebug()<<"Connected to SQL";

        QString sQuery="INSERT INTO [test].[dbo].[People] ([FirstName],[LastName]) VALUES(:first,:last)";
        QSqlQuery qry;
        qry.prepare(sQuery);
        qry.bindValue(":first","Vivek");
        qry.bindVlaue(":last","VS");
        if(qry.exec())
        {
                qDebug()<< "Record Inserted";
        }
        qDebug()<<"Closed";
        db.close();
    }
    else
    {
        qDebug()<<"Error ="<<db.lastError().text();
    }

    return a.exec();
}


