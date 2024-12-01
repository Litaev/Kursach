#ifndef CARLISTELEMENT_H
#define CARLISTELEMENT_H
#include <QObject>
#include <utility>

class CarListElement
{
public:
    CarListElement(const QString name, const int year, const int mileage){
        m_name = std::move(name);
        m_year = std::move(year);
        m_mileage = std::move(mileage);
    };
    QString getName() const{
        return m_name;
    };
    int getYear() const{
        return m_year;
    };
    int getMileage() const{
        return m_mileage;
    };

private:
    QString m_name;
    int m_year;
    int m_mileage;

};

#endif // CARLISTELEMENT_H

