#include "Headers/service.h"



SERVICE_NAME CarService::getServiceType() const{
    return serviceType;
}
void CarService::setServiceType(SERVICE_NAME newServiceType) {
    serviceType = newServiceType;
}

QVariantMap CarService::preSaveData() const{

    QVariantMap serviceMap;
    qDebug() << "------21";
    serviceMap["serviceName"] = std::to_underlying(serviceType);
    serviceMap["eventName"] = getEventName();
    serviceMap["eventType"] = std::to_underlying(getEventType());
    serviceMap["eventPrice"] = getEventPrice();
    serviceMap["eventDate"] = Date::DateToVariant(getEventDate());
    serviceMap["eventMileage"] = getEventMileage();
    serviceMap["eventComment"] = getEventComment();

    return serviceMap;
}

void CarService::preLoadData(QVariantMap &map){
    serviceType = static_cast<SERVICE_NAME>(map["serviceName"].toInt());
    qDebug() << "------22";
    setEventName(map["eventName"].toString());
    setEventType(CONSUMPTION_NAME::SERVICE);
    setEventPrice(map["eventPrice"].toFloat());
    setEventDate(map["eventDate"]);
    setEventMileage(map["eventMileage"].toUInt());
    setEventComment(map["eventComment"].toString());
}
