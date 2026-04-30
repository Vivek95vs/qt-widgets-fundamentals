#include "person.h"

person::person(QObject *parent) : QObject(parent)
{

}
void person::listen(QString words)
{
    qDebug()<<Name<<"say someone told me..."<<words;
}
void person::Gossip(QString words)
{
    qDebug()<<Name<<"says"<<words;
    emit speak(words);
}
