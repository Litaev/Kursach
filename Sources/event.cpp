
#include "Headers/event.h"
using namespace std;



void Event::setEvent(int newEventType, QString newEventName, QString newEventPrice, QString newEventDate, QString newEventMileage,
                     QString newEventComment){
    eventType = static_cast<CONSUMPTION_NAME>(newEventType);
    eventName = newEventName;
    eventPrice = newEventPrice.toFloat();
    eventDate = Date::VariantToDate(newEventDate);
    eventMileage = newEventMileage.toInt();
    eventComment = newEventComment;

}


QString Event::getEventName() const
{
    return eventName;
}

void Event::setEventName(const QString &newEventName)
{
    eventName = newEventName;
}


float Event::getEventPrice() const {
    return eventPrice;
}
void Event::setEventPrice(float newEventPrice) {
    eventPrice = newEventPrice;
}
Date Event::getEventDate() const {
    return eventDate;
}

void Event::setEventDate(const QVariant& var){
    eventDate = Date::VariantToDate(var);
}

void Event::setEventDateNow() {
    eventDate.setNowDate();
}
unsigned int Event::getEventMileage() const {
    return eventMileage;
}
void Event::setEventMileage(unsigned int newEventMileage) {
    eventMileage = newEventMileage;
}
void Event::setEventType(CONSUMPTION_NAME consumption) {
    eventType = consumption;
}

CONSUMPTION_NAME Event::getEventType() const {
    return eventType;
}
void Event::setEventComment(const QString &comment) {
    eventComment = comment;
}
QString Event::getEventComment() const {
    return eventComment;
}








