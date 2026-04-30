#include "college.h"
#include "person.h"

college::college(QObject *parent) : QObject(parent)
{
    person sam;
    person vivek;
    person grace;

    sam.Name="chatty sam";
    vivek.Name="Poor vivek";
    grace.Name="silly grace";


    connect(&sam,SIGNAL(speak(QString)),&vivek,SLOT(listen(QString)));
    connect(&sam,SIGNAL(speak(QString)),&grace,SLOT(listen(QString)));
    sam.Gossip("I heard aravinth have X-Girlfriend");
}

