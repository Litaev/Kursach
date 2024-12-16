#ifndef EXCEPTION_H
#define EXCEPTION_H


#include "Headers/carException.h"
#include "Headers/eventException.h"

class Exception : public CarException, public EventException{

public:
    static QString callException(QString exceptionType, QString exceptionFieldError){
        if (exceptionType == "carWindowException"){
            if (exceptionFieldError == "carName") {return carNameError();}
            else if (exceptionFieldError == "carYear") {return carYearError();}
            else if (exceptionFieldError == "carMileage") {return carMileageError();}
            else if (exceptionFieldError == "carTankVolume") {return carTankVolumeError();}

        }
        else if (exceptionType == "eventWindowException"){
            if (exceptionFieldError == "eventName"){return eventNameError();}
            else if (exceptionFieldError == "eventPrice"){return eventPriceError();}
            else if (exceptionFieldError == "eventMileage"){return eventMileageError();}
            else if (exceptionFieldError == "eventDate"){return eventDateError();}
            else if (exceptionFieldError == "eventTime"){return eventTimeError();}
            else if (exceptionFieldError == "eventLitreAmount"){return eventTankVolumeError();}
        }
        return "UNKNOWN ERROR";
    }
};

#endif // EXCEPTION_H
