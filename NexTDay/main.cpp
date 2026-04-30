#include <QCoreApplication>
#include<iostream>
#include<QDebug>

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int date,month,year;
    qDebug()<<"Enter the date:";
    std::cin>>date;
    qDebug()<<"Enter the month:";
    std::cin>>month;
    qDebug()<<"Enter the year:";
    std::cin>>year;
    if(date>0 && date<28)
    {
            date=date + 1;
        }
    else if (date == 28)
    {
        if (month == 2)	//checking for feb
        {
            if (year % 4 == 0 && year %100!=0 || year % 400==0)	//leap year check in case of feb
            {
                date = 29;
            }
            else
            {
                date = 1;
                month = 3;
            }
        }
        else	//when its not feb
            date = date + 1;
    }

    else if (date == 29)	//last day check for feb
    {
        if (month == 2)
        {
            date = 1;
            month = 3;
        }
        else
            date = date + 1;
    }

    else if (date == 30)	//last day check for april,june,September,November
    {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            date= date + 1;
        }
        else
        {
            date = 1;
            month = month + 1;
        }
    }
    else if (date == 31)	//last day of the month
    {
        date = 1;
        if (month == 12)	//checking for last day of the year
        {
            year = year + 1;
            month = 1;
        }
        else
            month = month + 1;
    }

    qDebug()<<"The next day date is:"<<endl;
    qDebug()<<date<<" ";
    qDebug()<<month<<" ";
    qDebug()<<year<<endl;

    return a.exec();
}

