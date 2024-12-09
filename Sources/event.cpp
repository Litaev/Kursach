
#include "Headers/event.h"
using namespace std;



void Event::setEvent(int new_event_type, QString new_event_name, QString new_event_money_value, QString new_event_date, QString new_event_mileage,
                     QString new_event_comment){
    event_type = static_cast<CONSUMPTION_NAME>(new_event_type);
    event_name = new_event_name.toStdString();
    moneyValue = new_event_money_value.toFloat();
    event_date = Date::VariantToDate(new_event_date);
    car_mileage = new_event_mileage.toInt();
    event_comment = new_event_comment.toStdString();

}


std::string Event::getEventName() const
{
    return event_name;
}

void Event::setEventName(const std::string &newEvent_name)
{
    event_name = newEvent_name;
}

void Event::setEventId(int id) {
    event_id = id;
}
int Event::getEventId() const{
    return event_id;
}

float Event::getMoneyValue() const {
    return moneyValue;
}
void Event::setMoneyValue(float newMoneyValue) {
    moneyValue = newMoneyValue;
}
Date Event::getEventDate() const {
    return event_date;
}

void Event::setEventDate(const QVariant& var){
    event_date = Date::VariantToDate(var);
}

void Event::setEventDateNow() {
    event_date.setNowDate();
}
unsigned int Event::getCarMileage() const {
    return car_mileage;
}
void Event::setCarMileage(unsigned int carMileage) {
    car_mileage = carMileage;
}
void Event::setEventType(CONSUMPTION_NAME consumption) {
    event_type = consumption;
}

CONSUMPTION_NAME Event::getEventType() const {
    return event_type;
}
void Event::setEventComment(const string comment) {
    event_comment = comment;
}
string Event::getEventComment() const {
    return event_comment;
}








