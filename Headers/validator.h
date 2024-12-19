#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <QObject>
#include "Headers/user.h"
#include "Headers/customException.h"
#include "Headers/car.h"
#include "Headers/appDebugLogger.h"



class Validator : public QObject, public CustomException, public AppDebugLogger
{
    Q_OBJECT
    const int maxEnterLength = 15;
    const int maxMileage = 2000000;
    const int maxCarTankVolume = 100;
    const float maxEventPrice = 1000000;
    const float minEventPrice = 0.1;
    const int minCarYear = 1950;
    User *valUser;
    AppDebugLogger *valAppDebugLogger;

    QString validateTextField(QString text) const{
        try{
            if (text.length() > maxEnterLength || text.length() == 0){
                valAppDebugLogger->newError("NAME is INCORRECT");
                throw CustomException("NAME is INCORRECT");
            }
        }
        catch(CustomException &e){
            return e.what();
        }
        return "";
    }

    QString validateCarYear(int carYear) const{
        Date nowDate;
        nowDate.setNowDate();
        try{
            if (carYear < minCarYear || carYear > nowDate.getYear()){
                valAppDebugLogger->newError("YEAR is INCORRECT");
                throw CustomException("YEAR is INCORRECT");
            }
        }
        catch(CustomException &e){
            return e.what();
        }
        return "";
    }

    QString validateMileage(int mileage) const{
        try{
            if (mileage < 0 || mileage > maxMileage){
                valAppDebugLogger->newError("MILEAGE is INCORRECT");
                throw CustomException("MILEAGE is INCORRECT");
            }
        }
        catch(CustomException &e){
            return e.what();
        }
        return "";
    }
    QString validateTankVolume(int tankVolume) const{
        try{
            if (tankVolume < 1 || tankVolume > maxCarTankVolume){
                valAppDebugLogger->newError("CAR TANK is INCORRECT");
                throw CustomException("CAR TANK is INCORRECT");
            }
        }
        catch(CustomException &e) {
            return e.what();
        }
        return "";
    }
    QString validateEventPrice(float price) const{
        try {
            if (price < minEventPrice || price > maxEventPrice){
                valAppDebugLogger->newError("EVENT PRICE is INCORRECT");
                throw CustomException("EVENT PRICE is INCORRECT");
            }
        }
        catch(CustomException &e) {
            return e.what();
        }
        return "";
    }
    QString validateEventDate(QString date) const{
        Date nowDate;
        nowDate.setNowDate();
        Date chosenDate;
        chosenDate = Date::VariantToDate(date);
        try{
            if (chosenDate > nowDate){
                valAppDebugLogger->newError("EVENT DATE is INCORRECT");
                throw CustomException("EVENT DATE is INCORRECT");
            }
        }
        catch (CustomException &e) {
            return e.what();
        }
        return "";
    }

    QString validateEventLitresAmount(float litresAmount) const{
        try{
            if (litresAmount > valUser->getChosenCarTankVolume() || litresAmount < 0){
                valAppDebugLogger->newError("AMOUNT OF LITRES is INCORRECT");
                throw CustomException("AMOUNT OF LITRES is INCORRECT");
            }
        }
        catch(CustomException &e) {
            return e.what();
        }
        return "";
    }

public:
    Validator(User *user, AppDebugLogger *appDebugLogger){
        valUser = user;
        valAppDebugLogger = appDebugLogger;
    }

    Q_INVOKABLE QString validateCarWindow(QString fieldType, QString fieldData) const{
        if (fieldType == "carName"){
            return validateTextField(fieldData);
        }
        else if (fieldType == "carYear"){
            return validateCarYear(fieldData.toInt());
        }
        else if (fieldType == "carMileage"){
            return validateMileage(fieldData.toInt());

        }
        else if (fieldType == "carTankVolume"){
            return validateTankVolume(fieldData.toInt());
        }
        return "";
    }

    Q_INVOKABLE QString validateEventWindow(QString fieldType, QString fieldData) const{

        if (fieldType == "eventName"){
            return validateTextField(fieldData);
        }
        else if (fieldType == "eventPrice"){
            return validateEventPrice(fieldData.toFloat());
        }
        else if (fieldType == "eventMileage"){
            return validateMileage(fieldData.toInt());
        }
        else if (fieldType == "eventDate"){
            return validateEventDate(fieldData);
        }
        else if (fieldType == "eventLitresAmount"){
            return validateEventLitresAmount(fieldData.toFloat());
        }
    return "0";
    }
};

#endif // VALIDATOR_H
