#ifndef CAREXCEPTION_H
#define CAREXCEPTION_H
#include <QString>
#include <QDebug>

class CarException{

public:
    static QString carNameError() {
        qDebug() << "W " << "carWindowError: " << "Car Name is TOO Long (Max characters 15)";
        return "Car Name is TOO Long (Max characters 15)";
    }
    static QString carYearError() {
        qDebug() << "W " << "carWindowError: " << "Car Year is INCORRECT";
        return "Car Year is INCORRECT";
    }
    static QString carMileageError() {
        qDebug() << "W " << "carWindowError: " << "Car Mileage is INCORRECT";
        return "Car Mileage is INCORRECT";
    }
    static QString carTankVolumeError() {
        qDebug() << "W " << "carWindowError: " << "Car Tank Volume is INCORRECT";
        return "Car Tank Volume is INCORRECT";
    }
};

#endif // CAREXCEPTION_H

