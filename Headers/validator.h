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


    Q_INVOKABLE QString validateCarWindow(QString resultType, QString fieldType, QString fieldData) const{
        Date nowDate;
        nowDate.setNowDate();
        if (fieldType == "carName"){
            try {
                if (fieldData.length() > 15){
                    if (resultType == "0") return "1";
                    else if (resultType == "1"){
                        throw CustomException();
                    }
                }
                else{
                    return "0";
                }
            }
            catch (CustomException &e) {
                return e.what("carWindowException", "carName");
            }
        }
        else if (fieldType == "carYear"){
            try {
                if (fieldData.toInt() > nowDate.getYear() || fieldData.toInt() < 1950){
                    if (resultType == "0") return "1";
                    else if (resultType == "1") throw CustomException();
                }
                else{
                    return "0";
                }
            }
            catch(CustomException &e) {
                return e.what("carWindowException", "carYear");
            }
        }
        else if (fieldType == "carMileage"){
            try{
                if (fieldData.toInt() < 0 || fieldData.toInt() > 2000000){
                    if (resultType == "0") return "1";
                    else if (resultType == "1") throw CustomException();
                }
                else{
                    return "0";
                }
            }
            catch(CustomException &e) {
                return e.what("carWindowException", "carMileage");
            }

        }
        else if (fieldType == "carTankVolume"){
            try{
                if (fieldData.toInt() < 1 || fieldData.toInt() > 1000){
                    if (resultType == "0") return "1";
                    else if (resultType == "1") throw CustomException();

                }
                else{
                    return "0";
                }
            }
            catch(CustomException &e) {
                return e.what("carWindowException", "carTankVolume");
            }
        }
        return "0";
    }

    Q_INVOKABLE QString validateEventWindow(QString resultType, QString fieldType, QString fieldData, int chosenCarTankVolume) const{
        Date nowDate;
        nowDate.setNowDate();
        if (fieldType == "eventName"){
            try{
                if (fieldData.length() > 15){
                    if (resultType == "0") return "1";
                    else if (resultType == "1"){
                        throw CustomException();
                    }
                }
                else{
                    return "0";
                }
            }
            catch(CustomException &e) {
                return e.what("eventWindowException", "eventName");
            }
        }
        else if (fieldType == "eventPrice"){
            try {
                if (fieldData.toFloat() < 0.1 || fieldData.toFloat() > 1000000){
                    if (resultType == "0") return "1";
                    else if (resultType == "1"){
                        throw CustomException();
                    }
                }
                else{
                    return "0";
                }
            }
            catch(CustomException &e) {
                return e.what("eventWindowException", "eventPrice");
            }
        }

        else if (fieldType == "eventMileage"){
            try{
                if (fieldData.toInt() < 0 || fieldData.toInt() > 3000000){
                    if (resultType == "0") return "1";
                    else if (resultType == "1"){
                        throw CustomException();
                    }
                }
                else{
                    return "0";
                }
            }
            catch(CustomException &e) {
                return e.what("eventWindowException", "eventMileage");
            }
        }
        else if (fieldType == "eventDate"){
            Date chosenDate;
            chosenDate = Date::VariantToDate(fieldData);
            chosenDate.setMonth(chosenDate.getMonth());
            if (chosenDate.getYear() > nowDate.getYear()){
                try{
                    if (resultType == "0") return "1";
                    else if (resultType == "1"){
                        throw CustomException();
                    }
                }
                catch (CustomException &e) {
                    return e.what("eventWindowException", "eventDate");
                }
            }
            else if (chosenDate.getYear() == nowDate.getYear()){
                if (chosenDate.getMonth() > nowDate.getMonth()){
                    try{
                        if (resultType == "0") return "1";
                        else if (resultType == "1"){
                            throw CustomException();
                        }
                    }
                    catch(CustomException &e) {
                        return e.what("eventWindowException", "eventDate");
                    }
                }
                else if (chosenDate.getMonth() == nowDate.getMonth()) {
                    try{
                        if (chosenDate.getDay() > nowDate.getDay()){
                            if (resultType == "0") return "1";
                            else if (resultType == "1"){
                                throw CustomException();
                            }
                        }
                        else{
                            return "0";
                        }
                    }
                    catch (CustomException &e) {
                        return e.what("eventWindowException", "eventDate");
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
            try{
                if (fieldData.toInt() > chosenCarTankVolume || fieldData.toInt() < 0){
                    if (resultType == "0") return "1";
                    else if (resultType == "1"){
                        throw CustomException();
                    }
                }
                else{
                    return "0";
                }
            }
            catch(CustomException &e) {
                return e.what("eventWindowException", "eventLitreAmount");
            }
        }
    return "0";
    }
};

#endif // VALIDATOR_H
