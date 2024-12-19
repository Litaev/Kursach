#ifndef EVENT_H
#define EVENT_H

#include "enums.h"
#include "date.h"
#include "Headers/Presaveable.h"
#include "Headers/Preloadable.h"
class User;


class Event{
    friend User;
    CONSUMPTION_NAME eventType;
    QString eventName;
    float eventPrice;
    Date eventDate;
    unsigned int eventMileage;
    QString eventComment;
public:

    QString getEventName() const;
    void setEventName(const QString &newEventName);
    float getEventPrice() const;
    void setEventPrice(float newEventPrice);
    Date getEventDate() const;
    void setEventDate(const QVariant& var);
    void setEventDateNow();
    unsigned int getEventMileage() const;
    void setEventMileage(unsigned int newEventMileage);
    void setEventType(CONSUMPTION_NAME consumption);
    CONSUMPTION_NAME getEventType() const;
    void setEventComment(const QString &comment);
    QString getEventComment() const;

    void setEvent(int newEventType, QString newEventName, QString newEventMoneyValue, QString newEventDate, QString newEventMileage,
                  QString newEventComment);

    virtual void setFuelType(FUEL_TYPE carFuelType) = 0;
    virtual FUEL_TYPE getFuelType() const = 0;
    virtual void setAmountOfLitres(float amountOfLitres) = 0;
    virtual float getAmountOfLitres() const = 0;
    virtual void setPricePerLitre(float pricePerLitre) = 0;
    virtual float getPricePerLitre() const = 0;
    virtual void setServiceType(SERVICE_NAME serviceType) = 0;
    virtual SERVICE_NAME getServiceType() const = 0;

    virtual ~Event() = default;

    virtual QVariantMap preSaveData() const = 0;
    virtual void preLoadData(QVariantMap &map) = 0;


};

#endif // EVENT_H
