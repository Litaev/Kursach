#ifndef CARLISTELEMENT_H
#define CARLISTELEMENT_H
#include <QObject>
#include <utility>

class CarListElement
{
public:
    CarListElement(QString name, QString imagePath, int year, int mileage)
        : m_name(std::move(name)), m_imagePath(std::move(imagePath)), m_year(year), m_mileage(mileage) {}

    QString getName() const{
        return m_name;
    };
    QString getImagePath() const{
        return m_imagePath;
    };
    int getYear() const{
        return m_year;
    };
    int getMileage() const{
        return m_mileage;
    };

private:
    QString m_name;
    QString m_imagePath;
    int m_year;
    int m_mileage;

};

#endif // CARLISTELEMENT_H

