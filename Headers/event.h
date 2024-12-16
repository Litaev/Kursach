#ifndef EVENT_H
#define EVENT_H

#include "enums.h"
#include "date.h"

class User;


class Event {
    friend User;
    int event_id;
    CONSUMPTION_NAME event_type;
    std::string event_name;
    float moneyValue;
    Date event_date;
    unsigned int car_mileage;
    std::string event_comment;
public:
    void setEventId(int id);
    int getEventId() const;
    float getMoneyValue() const;
    void setMoneyValue(float newMoneyValue);
    Date getEventDate() const;
    void setEventDate(const QVariant& var);
    void setEventDateNow();
    unsigned int getCarMileage() const;
    void setCarMileage(unsigned int carMileage);
    void setEventType(CONSUMPTION_NAME consumption);
    CONSUMPTION_NAME getEventType() const;
    void setEventComment(const std::string comment);
    std::string getEventComment() const;
    void saveEventinDatabase();
    void loadEventFromDatabase();

    void setEvent(int new_event_type, QString new_event_name, QString new_event_money_value, QString new_event_date, QString new_event_mileage,
                  QString new_event_comment);

    virtual void setFuelType(FUEL_TYPE carFuelType) {/*VIRTUAL*/};
    virtual FUEL_TYPE getFuelType() const { return FUEL_TYPE::DIESEL;};
    virtual void setAmountOfLitres(float amountOfLitres) {/*VIRTUAL*/ };
    virtual float getAmountOfLitres() const {return 0;}
    virtual void setPricePerLitre(float pricePerLitre) {/*VIRTUAL*/ };
    virtual float getPricePerLitre() const {return 0;}
    virtual void setServiceType(SERVICE_NAME serviceType) {/*VIRTUAL*/ };
    virtual SERVICE_NAME getServiceType() const { return SERVICE_NAME::OTHER_SERVICE; };
    virtual void setServiceTypeAsString(std::string& serviceName) {/*VIRTUAL*/ };

    std::string getEventName() const;
    void setEventName(const std::string &newEvent_name);
};

#endif // EVENT_H
