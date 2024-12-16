#ifndef CAREXCEPTION_H
#define CAREXCEPTION_H
#include <QString>

class CarException{

public:
    static QString carNameError() {return "Car Name is TOO Long";}
    static QString carYearError() {return "Car Year is INCORRECT";}
    static QString carMileageError() {return "Car Mileage is INCORRECT";}
    static QString carTankVolumeError() {return "Car Tank Volume is INCORRECT";}
};

#endif // CAREXCEPTION_H

