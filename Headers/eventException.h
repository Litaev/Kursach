#ifndef EVENTEXCEPTION_H
#define EVENTEXCEPTION_H
#include <QString>

class EventException{

public:
    static QString eventNameError() {return "Event Name is TOO Long";}
    static QString eventPriceError() {return "Event Price is INVALID";}
    static QString eventMileageError() {return "Event Mileage is INVALID";}
    static QString eventDateError() {return "Event Date is INVALID";}
    static QString eventTimeError() {return "Event Time is INVALID";}
    static QString eventTankVolumeError() {return "Event Litre Amount is Bigger than your Car Tank";}
};

#endif // EVENTEXCEPTION_H
