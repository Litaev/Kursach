#ifndef EVENTLISTELEMENT_H
#define EVENTLISTELEMENT_H

#include <QObject>
#include <utility>


class EventListElement
{
public:
    EventListElement(int event_type, QString name, float price, int mileage, QString date, int service_type)
        : m_event_type(event_type), m_name(std::move(name)), m_price(price), m_mileage(mileage), m_date(std::move(date)), m_service_type(service_type) {}


    int getEventType() const{
        return m_event_type;
    }
    QString getEventName() const{
        return m_name;
    }

    float getPrice() const{
        return m_price;
    }

    float getMileage() const{
        return m_mileage;
    }

    QString getDate() const{
        return m_date;
    }

    int getServiceType() const{
        return m_service_type;
    }


private:
    int m_event_type;
    QString m_name;
    float m_price;
    int m_mileage;
    QString m_date;
    int m_service_type;
};



#endif // EVENTLISTELEMENT_H
