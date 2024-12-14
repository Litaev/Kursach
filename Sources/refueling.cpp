#include <iostream>
#include "Headers/refueling.h"
using namespace std;

int Refueling::getRefuelingId() const{
    return refueling_id;
}
FUEL_TYPE Refueling::getFuelType() const{
    return fuel_type;
}
void Refueling::setFuelType(FUEL_TYPE carFuelType) {
    fuel_type = carFuelType;
}
float Refueling::getAmountOfLitres() const{
    return amount_of_litres;
}
void Refueling::setAmountOfLitres(float amountOfLitres) {
    amount_of_litres = amountOfLitres;
}
float Refueling::getPricePerLitre() const{
    return price_per_litre;
}
void Refueling::setPricePerLitre(float pricePerLitre) {
    price_per_litre = pricePerLitre;
}


