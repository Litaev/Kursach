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

void Refueling::saveRefuelingInDatabase() {
    // pqxx::connection database_connect("dbname=postgres user=postgres password=Sosi_jopy host=localhost port=5432");
    // if (!database_connect.is_open()) {
    //     std::cerr << "Database connection error" << std::endl;
    //     exit(111);
    // }
    // pqxx::work database_work(database_connect);

    // pqxx::result database_refueling_id = database_work.exec_params("INSERT INTO refueling (fk_event_id, litre_amount, price_per_litre, fuel_type) VALUES (" +
    //                                                                database_work.quote(getEventId()) + ", " + database_work.quote(amount_of_litres) + ", " + database_work.quote(price_per_litre) + ", " +
    //                                                                database_work.quote(static_cast<int>(fuel_type)) + ") RETURNING event_refueling_id");
    // refueling_id = database_refueling_id[0][0].as<int>();
    // database_work.commit();
}
void Refueling::loadRefuelingFromDatabase() {
    // pqxx::connection database_connect("dbname=postgres user=postgres password=Sosi_jopy host=localhost port=5432");
    // if (!database_connect.is_open()) {
    //     std::cerr << "Database connection error" << std::endl;
    //     exit(111);
    // }
    // pqxx::work database_work(database_connect);

    // pqxx::row refueling_info = database_work.exec1("SELECT * FROM refueling WHERE fk_event_id = " + database_work.quote(getEventId()));
    // refueling_id = refueling_info["event_refueling_id"].as<int>();
    // amount_of_litres = refueling_info["litre_amount"].as<float>();
    // price_per_litre = refueling_info["price_per_litre"].as<float>();
    // fuel_type = static_cast<FUEL_TYPE>(refueling_info["fuel_type"].as<int>());
    // database_work.commit();
}
