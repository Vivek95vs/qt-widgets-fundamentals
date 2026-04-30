#include <QCoreApplication>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>

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
        db.close();
    }
    else
    {
        qDebug()<<"Error ="<<db.lastError().text();
    }

    return a.exec();
}

