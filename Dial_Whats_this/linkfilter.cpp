#include "linkfilter.h"

Linkfilter::Linkfilter(QObject *parent) : QObject(parent)
{

}
bool Linkfilter::eventFilter(QObject *object, QEvent *event)
{

   if(event->type()==QEvent::WhatsThisClicked)
   {
       QWhatsThisClickedEvent *wtcEvent=static_cast<QWhatsThisClickedEvent*>(event);
       emit linkClicked(wtcEvent->href());
       return true;
   }
   return false;
}
