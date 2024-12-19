#ifndef CARSERVICE_H
#define CARSERVICE_H

#include "Headers/event.h"

class User;

class CarService : public Event, public Presaveable, public Preloadable{
    friend User;
    SERVICE_NAME serviceType;
public:
    SERVICE_NAME getServiceType() const override;
    void setServiceType(SERVICE_NAME serviceType) override;

    QVariantMap preSaveData() const override;
    void preLoadData(QVariantMap &map) override;

    FUEL_TYPE getFuelType() const override{return FUEL_TYPE::DIESEL;};
    void setFuelType(FUEL_TYPE carFuelType) override {};
    float getAmountOfLitres() const override {return 1;};
    void setAmountOfLitres(float amountOfLitres) override {};
    float getPricePerLitre() const override {return 1;};
    void setPricePerLitre(float pricePerLitre) override {};

};

#endif // CARSERVICE_H
