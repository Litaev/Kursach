#ifndef CAR_H
#define CAR_H

#include <vector>
#include <QObject>
#include "enums.h"
#include "event.h"
#include "date.h"
#include "service.h"
#include "refueling.h"
#include "statistics.h"
class User;

class Car : public Statistics{
    friend User;
    Q_OBJECT
    QString car_name;
    std::string car_gov_number;
    int car_year;
    int car_mileage = 0;
    int car_tank_volume;
    float car_money_spent = 0;
    FUEL_TYPE car_fuel_type;
    std::vector<std::shared_ptr<Event>> event_list;
public:
    void setCar(QString new_car_name, QString new_car_year, QString new_car_mileage, QString new_car_fuel_type, QString new_car_tank_volume);
    Q_INVOKABLE QString getCarName() const;
    void setCarName(QString new_car_name);
    void setCarFuelType(FUEL_TYPE new_fuel_type);
    FUEL_TYPE getCarFuelType() const;
    std::string getCarGovNumber() const;
    void setCarGovNumber(std::string_view new_car_gov_number);
    int getCarMileage() const;
    void setCarMileage(unsigned int new_car_mileage);
    float getCarMoneySpent() const;
    void setCarMoneySpent(float carMoneySpent);

    void operator == (int); //Update money spent
    //void updateCarMoneySpent();
    void updateCarMileage();

    auto operator <=> (const Car & car1) const = default;

    void addEvent();
    void operator-- (int); // Delete event by ID
    std::vector<std::shared_ptr<Event>> &getEventList();
    void deleteEventList();
    void deleteEventListElement();
    std::string FuelTypeToStringFun(FUEL_TYPE name);

    Q_INVOKABLE void addEvent(int new_event_type, QString new_event_name, QString new_event_money_value, QString new_event_date, QString new_event_mileage,
                                   QString new_event_comment, int new_event_service_type, int new_event_fuel_type, QString new_event_amount_of_litres, QString new_event_price_per_litre);

    void printEventList() const;
    void saveCarInDataBase();
    void loadCarFromDatabase();
    void clearCarData();
    void setCarId(int id);
    int getCarId() const;
    int getCarYear() const;
    void setCarYear(int newCar_year);
    int getCarTankVolume() const;
    void setCarTankVolume(int newCar_tank_volume);

};

#endif // CAR_H
