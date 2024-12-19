#include <iostream>
#include "Headers/refueling.h"
using namespace std;


FUEL_TYPE Refueling::getFuelType() const{
    return fuelType;
}
void Refueling::setFuelType(FUEL_TYPE carFuelType) {
    fuelType = carFuelType;
}
float Refueling::getAmountOfLitres() const{
    return amountOfLitres;
}
void Refueling::setAmountOfLitres(float newAmountOfLitres) {
    amountOfLitres = newAmountOfLitres;
}
float Refueling::getPricePerLitre() const{
    return pricePerLitre;
}
void Refueling::setPricePerLitre(float newPricePerLitre) {
    pricePerLitre = newPricePerLitre;
}

QVariantMap Refueling::preSaveData() const{

    QVariantMap refuelingMap;
    qDebug() << "------11";

    refuelingMap["fuelType"] = std::to_underlying(fuelType);
    refuelingMap["litreAmount"] = amountOfLitres;
    refuelingMap["pricePerLitre"] = pricePerLitre;
    refuelingMap["eventName"] = getEventName();
    refuelingMap["eventType"] = std::to_underlying(getEventType());
    refuelingMap["eventPrice"] = getEventPrice();
    refuelingMap["eventDate"] = Date::DateToVariant(getEventDate());
    refuelingMap["eventMileage"] = getEventMileage();
    refuelingMap["eventComment"] = getEventComment();

    return refuelingMap;

}
void Refueling::preLoadData(QVariantMap &map){
    fuelType = static_cast<FUEL_TYPE>(map["fuelType"].toInt());
    amountOfLitres = map["litreAmount"].toFloat();
    pricePerLitre = map["pricePerLitre"].toFloat();
    setEventName(map["eventName"].toString());
    setEventType(CONSUMPTION_NAME::REFUELING);
    setEventPrice(map["eventPrice"].toFloat());
    setEventDate(map["eventDate"]);
    setEventMileage(map["eventMileage"].toUInt());
    setEventComment(map["eventComment"].toString());
    qDebug() << "------12";
}


