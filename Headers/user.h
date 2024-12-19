#ifndef USER_H
#define USER_H

#include <iostream>
#include <QSettings>
#include <QObject>
#include <vector>
#include <QFileDialog>
#include "car.h"

class User : public QObject{

    Q_OBJECT

    std::vector<std::shared_ptr<Car>> carList;
    int userChosenCarId = 0;

public:

    Q_INVOKABLE void addCar(QString newCarName, QString newCarYear, QString newCarMileage, QString newCarFuelType, QString newCarTankVolume);

    Q_INVOKABLE void addEvent(QString newEventType, QString newEventName, QString newEventMoneyValue, QString newEventDate, QString newEventMileage,
                              QString newEventComment, QString newEventServiceType, QString newEventAmountOfLitres, QString newEventPricePerLitre);

    Q_INVOKABLE void editChosenCarInfo(QString newCarName, QString newCarYear, QString newCarMileage, QString newCarFuelType, QString newCarTankVolume);

    Q_INVOKABLE void editChosenEventInfo(int chosenEventId, int eventType, QString newEventName, QString newEventMoney, QString newEventDate, QString newEventMileage,
                                         QString newEventComment, QString newEventLitres, QString newEventPricePerLitre, QString newEventServiceType);

    Q_INVOKABLE void updateChosenCarStatistics();

    Q_INVOKABLE QString getInfoAboutCar(int carIndex, QString infoType) const;

    Q_INVOKABLE QString getInfoAboutEvent(int carIndex, int eventIndex, QString infoType) const;

    Q_INVOKABLE void deleteChosenCar(int chosenDeleteCarId);

    Q_INVOKABLE void deleteChosenEvent(int chosenEventId);


    Q_INVOKABLE int getUserChosenCarId() const;
    Q_INVOKABLE void setUserChosenCarId(int newUserChosenCarId);

    Q_INVOKABLE std::vector<std::shared_ptr<Car>> &getCarList();
    Q_INVOKABLE int getCarListSize() const;

    Q_INVOKABLE void setChosenCarImage(int chosenCarId);

    Q_INVOKABLE void saveUserData() const;
    Q_INVOKABLE void loadUserData();

    Q_INVOKABLE int getNowDate(QString type) const;

    Q_INVOKABLE std::vector<std::shared_ptr<Event>> &getChosenCarEventList();

    Q_INVOKABLE int getChosenCarTankVolume();

    float getUserMoneySpent() const;

    static bool compEventListMinByDate(const std::shared_ptr<Event> &event1, const std::shared_ptr<Event> &event2);
    static bool compEventListMaxByDate(const std::shared_ptr<Event> &event1, const std::shared_ptr<Event> &event2);
    static bool compEventListMinByPrice(const std::shared_ptr<Event> &event1, const std::shared_ptr<Event> &event2);
    static bool compEventListMaxByPrice(const std::shared_ptr<Event> &event1, const std::shared_ptr<Event> &event2);
    Q_INVOKABLE void sortChosenCarEventListMin(QString sortType);
    Q_INVOKABLE void sortChosenCarEventListMax(QString sortType);
};

#endif // USER_H
