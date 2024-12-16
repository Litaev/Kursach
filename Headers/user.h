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

    std::vector<std::shared_ptr<Car>> car_list;
    int chosen_car_id = 0;
    float user_money_spent = 0;

public:

    Q_INVOKABLE void addCar(QString new_car_name, QString new_car_year, QString new_car_mileage, QString new_car_fuel_type, QString new_car_tank_volume);

    Q_INVOKABLE void addEvent(QString new_event_type, QString new_event_name, QString new_event_money_value, QString new_event_date, QString new_event_mileage,
                              QString new_event_comment, QString new_event_service_type, QString new_event_amount_of_litres, QString new_event_price_per_litre);

    Q_INVOKABLE void editChosenCarInfo(QString new_car_name, QString new_car_year, QString new_car_mileage, QString new_car_fuel_type, QString new_car_tank_volume);

    Q_INVOKABLE void editChosenEventInfo(int chosen_event_id, int event_type, QString new_event_name, QString new_event_money, QString new_event_date, QString new_event_mileage,
                                         QString new_event_comment, QString new_event_litres, QString new_event_price_per_litre, QString new_event_service_type);

    Q_INVOKABLE void updateChosenCarStatistics();

    Q_INVOKABLE QString getInfoAboutCar(int car_index, QString info_type) const;

    Q_INVOKABLE QString getInfoAboutEvent(int car_index, int event_index, QString info_type) const;

    Q_INVOKABLE void deleteChosenCar(int chosen_delete_car_id);

    Q_INVOKABLE void deleteChosenEvent(int chosen_event_id);

    Q_INVOKABLE int getChosenCarId() const;
    Q_INVOKABLE void setChosenCarId(int newChosen_car_id);

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
