#ifndef REFUELING_H
#define REFUELING_H

#include "event.h"

class User;

class Refueling : public Event {
    friend User;
    int refueling_id;
    FUEL_TYPE fuel_type;
    float amount_of_litres;
    float price_per_litre;
public:
    int getRefuelingId() const;
    FUEL_TYPE getFuelType() const override;
    void setFuelType(FUEL_TYPE carFuelType) override;
    float getAmountOfLitres() const override;
    void setAmountOfLitres(float amountOfLitres) override;
    float getPricePerLitre() const override;
    void setPricePerLitre(float pricePerLitre) override;
    void saveRefuelingInDatabase() override;
    void loadRefuelingFromDatabase() override;
};

#endif // REFUELING_H
