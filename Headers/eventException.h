#ifndef EVENTEXCEPTION_H
#define EVENTEXCEPTION_H
#include <QString>
#include <QDebug>

class EventException{

public:
    static QString eventNameError() {
        qDebug() << "W " << "eventWindowError: " << "Event Name is TOO Long (Max characters 15)";
        return "Event Name is TOO Long (Max characters 15)";
    }
    static QString eventPriceError() {
        qDebug() << "W " << "eventWindowError: " << "Event Price is INVALID";
        return "Event Price is INVALID";
    }
    static QString eventMileageError() {
        qDebug() << "W " << "eventWindowError: " << "Event Mileage is INVALID";
        return "Event Mileage is INVALID";
    }
    static QString eventDateError() {
        qDebug() << "W " << "eventWindowError: " << "Event Date is INVALID";
        return "Event Date is INVALID";
    }
    static QString eventTimeError() {
        qDebug() << "W " << "eventWindowError: " << "Event Time is INVALID";
        return "Event Time is INVALID";
    }
    static QString eventTankVolumeError() {
        qDebug() << "W " << "eventWindowError: " << "Event Litre Amount is Bigger than your Car Tank";
        return "Event Litre Amount is Bigger than your Car Tank";
    }
};

#endif // EVENTEXCEPTION_H
