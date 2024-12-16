#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <QObject>
#include "Headers/date.h"
#include "Headers/exception.h"
#include "Headers/car.h"
#include "QDebug"

class Validator : public QObject
{
    Q_OBJECT
public:


    Q_INVOKABLE QString validateCarWindow(QString resultType, QString fieldType, QString fieldData) {
        Date nowDate;
        nowDate.setNowDate();
        if (fieldType == "carName"){
            if (fieldData.length() > 15){
                if (resultType == "0") return "1";
                else if (resultType == "1"){
                    return Exception::callException("carWindowException", "carName");
                }
            }
            else{
                return "0";
            }
        }
        else if (fieldType == "carYear"){
            if (fieldData.toInt() > nowDate.getYear() || fieldData.toInt() < 1950){
                if (resultType == "0") return "1";
                else if (resultType == "1") return Exception::callException("carWindowException", "carYear");
            }
            else{
                return "0";
            }
        }
        else if (fieldType == "carMileage"){
            if (fieldData.toInt() < 0 || fieldData.toInt() > 2000000){
                if (resultType == "0") return "1";
                else if (resultType == "1") return Exception::callException("carWindowException", "carMileage");
            }
            else{
                return "0";
            }

        }
        else if (fieldType == "carTankVolume"){
            if (fieldData.toInt() < 1 || fieldData.toInt() > 1000){
                if (resultType == "0") return "1";
                else if (resultType == "1") return Exception::callException("carWindowException", "carTankVolume");

            }
            else{
                return "0";
            }
        }
        return "0";
    }

    Q_INVOKABLE QString validateEventWindow(QString resultType, QString fieldType, QString fieldData, int chosenCarTankVolume){
        Date nowDate;
        nowDate.setNowDate();
        if (fieldType == "eventName"){
            if (fieldData.length() > 15){
                if (resultType == "0") return "1";
                else if (resultType == "1"){
                    return Exception::callException("eventWindowException", "eventName");
                }
            }
            else{
                return "0";
            }
        }
        else if (fieldType == "eventPrice"){
            if (fieldData.toInt() < 0 || fieldData.toInt() > 1000000){
                if (resultType == "0") return "1";
                else if (resultType == "1"){
                    return Exception::callException("eventWindowException", "eventPrice");
                }
            }
            else{
                return "0";
            }
        }

        else if (fieldType == "eventMileage"){
            if (fieldData.toInt() < 0 || fieldData.toInt() > 3000000){
                if (resultType == "0") return "1";
                else if (resultType == "1"){
                    return Exception::callException("eventWindowException", "eventMileage");
                }
            }
            else{
                return "0";
            }
        }
        else if (fieldType == "eventDate"){
            Date chosenDate;
            chosenDate = Date::VariantToDate(fieldData);
            chosenDate.setMonth(chosenDate.getMonth());
            if (chosenDate.getYear() > nowDate.getYear()){
                if (resultType == "0") return "1";
                else if (resultType == "1"){
                    return Exception::callException("eventWindowException", "eventDate");
                }
            }
            else if (chosenDate.getYear() == nowDate.getYear()){
                if (chosenDate.getMonth() > nowDate.getMonth()){
                    if (resultType == "0") return "1";
                    else if (resultType == "1"){
                        return Exception::callException("eventWindowException", "eventDate");
                    }
                }
                else if (chosenDate.getMonth() == nowDate.getMonth()){
                    if (chosenDate.getDay() > nowDate.getDay()){
                        if (resultType == "0") return "1";
                        else if (resultType == "1"){
                            return Exception::callException("eventWindowException", "eventDate");
                        }
                    }
                    else{
                        return "0";
                    }
                }
                else{
                    return "0";
                }
            }
            else{
                return "0";
            }
        }

        else if (fieldType == "eventLitreAmount"){
            if (fieldData.toInt() > chosenCarTankVolume || fieldData.toInt() < 0){
                if (resultType == "0") return "1";
                else if (resultType == "1"){
                    return Exception::callException("eventWindowException", "eventLitreAmount");
                }
            }
            else{
                return "0";
            }
        }
    return "0";
    }


};

#endif // VALIDATOR_H
