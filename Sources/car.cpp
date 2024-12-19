
#include "Headers/car.h"




void Car::operator-- (int){
    eventList.clear();
}

void Car::operator== (int){
    carStatistics.updateMoney(eventList);
}
QString Car::getCarName() const{
    return carName;
}
void Car::setCarName(QString newCarName) {
    carName = newCarName;
}
void Car::setCarFuelType(FUEL_TYPE newFuelType){
    carFuelType = newFuelType;
}

Statistics& Car::getCarStatistics(){
    return carStatistics;
}

FUEL_TYPE Car::getCarFuelType() const{
    return carFuelType;
}
QString Car::getCarGovNumber() const{
    return carGovNumber;
}
void Car::setCarGovNumber(QString newCarGovNumber) {
    carGovNumber = newCarGovNumber;
}
int Car::getCarMileage() const{
    return carMileage;
}
void Car::setCarMileage(unsigned int newCarMileage) {
    carMileage = newCarMileage;
}


int Car::getCarYear() const
{
    return carYear;
}

void Car::setCarYear(int newCarYear)
{
    carYear = newCarYear;
}



void Car::updateCarMileage(){
    for (const auto& event: eventList){
        if (event->getEventMileage() > carMileage){
            carMileage = event->getEventMileage();
        }
    }
}



int Car::getCarTankVolume() const
{
    return carTankVolume;
}

void Car::setCarTankVolume(int newCarTankVolume)
{
    carTankVolume = newCarTankVolume;
}

QString Car::getCarImageFilePath() const
{
    return carImageFilePath;
}

void Car::setCarImageFilePath(const QString &newCarImageFilePath)
{
    carImageFilePath = newCarImageFilePath;
}

void Car::setCar(QString newCarName, QString newCarYear, QString newCarMileage, QString newCarFuelType, QString newCarTankVolume) {
    carName = newCarName;
    carYear = newCarYear.toInt();
    carMileage = newCarMileage.toInt();
    carFuelType = static_cast<FUEL_TYPE>(newCarFuelType.toInt());
    carTankVolume = newCarTankVolume.toInt();

}
void Car::addEvent(int new_event_type, QString new_event_name, QString new_event_money_value, QString new_event_date, QString new_event_mileage,
                   QString new_event_comment, int new_event_service_type, int new_event_fuel_type, QString new_event_amount_of_litres, QString new_event_price_per_litre){

    std::shared_ptr<Event> newEvent;

    if (static_cast<CONSUMPTION_NAME>(new_event_type) == CONSUMPTION_NAME::SERVICE) {
        newEvent = std::make_shared<CarService>();
        newEvent = std::make_shared<CarService>();
        newEvent->setServiceType(static_cast<SERVICE_NAME>(new_event_service_type));
    }
    else if (static_cast<CONSUMPTION_NAME>(new_event_type) == CONSUMPTION_NAME::REFUELING) {
        newEvent = std::make_shared<Refueling>();
        newEvent->setFuelType(static_cast<FUEL_TYPE>(new_event_fuel_type));
        newEvent->setAmountOfLitres(new_event_amount_of_litres.toFloat());
        newEvent->setPricePerLitre(new_event_price_per_litre.toFloat());
    }


    newEvent->setEvent(new_event_type, new_event_name, new_event_money_value, new_event_date, new_event_mileage, new_event_comment);
    eventList.push_back(newEvent);
}
std::vector<std::shared_ptr<Event>>& Car::getEventList(){
    return eventList;
}
void Car::deleteEventList(){

    eventList.clear();
};
void Car::deleteEventListElement(){

    (*this) == 1;
}


void Car::clearCarData() {
    eventList.clear();
}

QVariantMap Car::preSaveData() const{
    QVariantMap carMap;
    carMap["carName"] = carName;
    carMap["carGovNumber"] = carGovNumber;
    carMap["carImagePath"] = carImageFilePath;
    carMap["carYear"] = carYear;
    carMap["carMileage"] = carMileage;
    carMap["carTankVolume"] = carTankVolume;
    carMap["carFuelType"] = std::to_underlying(carFuelType);

    QVariantList forMapEventList;

    for (const auto& event : eventList){
        forMapEventList.append(event->preSaveData());
    }
    carMap["eventList"] = forMapEventList;

    return carMap;
}

void Car::preLoadData(QVariantMap &map){
    carName = map["carName"].toString();
    carGovNumber = map["carGovNumber"].toString();
    carImageFilePath = map["carImagePath"].toString();
    carYear = map["carYear"].toInt();
    carMileage = map["carMileage"].toInt();
    carTankVolume = map["carTankVolume"].toInt();
    carFuelType = static_cast<FUEL_TYPE>(map["carFuelType"].toInt());

    QVariantList forMapEventList = map["eventList"].toList();

    for (const QVariant& eventVar : forMapEventList) {
        QVariantMap eventMap = eventVar.toMap();
        auto eventType = static_cast<CONSUMPTION_NAME>(eventMap["eventType"].toInt());
        std::shared_ptr<Event> event;
        if (eventType == CONSUMPTION_NAME::SERVICE){
            event = std::make_shared<CarService>();
        }
        else if (eventType == CONSUMPTION_NAME::REFUELING){
            event = std::make_shared<Refueling>();
        }
        event->preLoadData(eventMap);
        eventList.push_back(event);
    }
}






