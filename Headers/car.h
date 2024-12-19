#ifndef CAR_H
#define CAR_H

#include <vector>
#include <QObject>
#include <memory>
#include "enums.h"
#include "event.h"
#include "service.h"
#include "refueling.h"
#include "statistics.h"
#include "Headers/Presaveable.h"
#include "Headers/Preloadable.h"


class User;

class Car : public Presaveable, public Preloadable{
    friend User;
    QString carName;
    QString carImageFilePath = "";
    QString carGovNumber;
    int carYear = 1950;
    int carMileage = 0;
    int carTankVolume = 0;;
    FUEL_TYPE carFuelType;
    std::vector<std::shared_ptr<Event>> eventList;
    Statistics carStatistics;
public:
    void setCar(QString newCarName, QString newCarYear, QString newCarMileage, QString newCarFuelType, QString newCarTankVolume);
    QString getCarName() const;
    void setCarName(QString newCarName);
    void setCarFuelType(FUEL_TYPE newFuelType);
    FUEL_TYPE getCarFuelType() const;
    Statistics &getCarStatistics();
    QString getCarGovNumber() const;
    void setCarGovNumber(QString newCarGovNumber);
    int getCarMileage() const;
    void setCarMileage(unsigned int newCarMileage);

    void operator == (int); //Update money spent
    //void updateCarMoneySpent();
    void updateCarMileage();



    void addEvent();
    void operator-- (int); // Delete event by ID
    std::vector<std::shared_ptr<Event>> &getEventList();
    void deleteEventList();
    void deleteEventListElement();

    void addEvent(int newEventType, QString newEventName, QString newEventMoneyValue, QString newEventDate, QString newEventMileage,
                  QString newEventComment, int newEventServiceType, int newEventFuelType, QString newEventAmountOfLitres, QString newEventPricePerLitre);

    void printEventList() const;
    void saveCarInDataBase();
    void loadCarFromDatabase();
    void clearCarData();
    void setCarId(int id);
    int getCarId() const;
    int getCarYear() const;
    void setCarYear(int newCarYear);
    int getCarTankVolume() const;
    void setCarTankVolume(int newCarTankVolume);

    QString getCarImageFilePath() const;
    void setCarImageFilePath(const QString &newCarImageFilePath);

    QVariantMap preSaveData() const override;
    void preLoadData(QVariantMap &map) override;

};

#endif // CAR_H
