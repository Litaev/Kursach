
#include "Headers/car.h"

using namespace std;


void Car::operator-- (int){
    event_list.clear();
}

void Car::operator== (int){
    carStatistics.updateMoney(event_list);
}
QString Car::getCarName() const{
    return car_name;
}
void Car::setCarName(QString new_car_name) {
    this->car_name = new_car_name;
}
void Car::setCarFuelType(FUEL_TYPE new_fuel_type){
    car_fuel_type = new_fuel_type;
}

Statistics& Car::getCarStatistics(){
    return carStatistics;
}

FUEL_TYPE Car::getCarFuelType() const{
    return car_fuel_type;
}
string Car::getCarGovNumber() const{
    return car_gov_number;
}
void Car::setCarGovNumber(string_view new_car_gov_number) {
    car_gov_number = new_car_gov_number;
}
int Car::getCarMileage() const{
    return car_mileage;
}
void Car::setCarMileage(unsigned int new_car_mileage) {
    car_mileage = new_car_mileage;
}


int Car::getCarYear() const
{
    return car_year;
}

void Car::setCarYear(int newCar_year)
{
    car_year = newCar_year;
}

// void Car::updateCarMoneySpent(){
//     car_money_spent = 0;
//     for (auto& event: event_list){
//         car_money_spent += event->getMoneyValue();
//     }
// }

void Car::updateCarMileage(){
    for (auto& event: event_list){
        if (event->getCarMileage() > car_mileage){
            car_mileage = event->getCarMileage();
        }
    }
}



int Car::getCarTankVolume() const
{
    return car_tank_volume;
}

void Car::setCarTankVolume(int newCar_tank_volume)
{
    car_tank_volume = newCar_tank_volume;
}

QString Car::getCarImageFilePath() const
{
    return carImageFilePath;
}

void Car::setCarImageFilePath(const QString &newCarImageFilePath)
{
    carImageFilePath = newCarImageFilePath;
}

void Car::setCar(QString new_car_name, QString new_car_year, QString new_car_mileage, QString new_car_fuel_type, QString new_car_tank_volume) {
    car_name = new_car_name;
    car_year = new_car_year.toInt();
    car_mileage = new_car_mileage.toInt();
    car_fuel_type = static_cast<FUEL_TYPE>(new_car_fuel_type.toInt());
    car_tank_volume = new_car_tank_volume.toInt();

}
void Car::addEvent(int new_event_type, QString new_event_name, QString new_event_money_value, QString new_event_date, QString new_event_mileage,
                   QString new_event_comment, int new_event_service_type, int new_event_fuel_type, QString new_event_amount_of_litres, QString new_event_price_per_litre){
    shared_ptr<Event> newEvent;
    if (static_cast<CONSUMPTION_NAME>(new_event_type) == CONSUMPTION_NAME::SERVICE){
        newEvent = std::make_shared<CarService>();
        newEvent->setServiceType(static_cast<SERVICE_NAME>(new_event_service_type));
    }
    else if (static_cast<CONSUMPTION_NAME>(new_event_type) == CONSUMPTION_NAME::REFUELING){
        newEvent = std::make_shared<Refueling>();
        newEvent->setFuelType(static_cast<FUEL_TYPE>(new_event_fuel_type));
        newEvent->setAmountOfLitres(new_event_amount_of_litres.toFloat());
        newEvent->setPricePerLitre(new_event_price_per_litre.toFloat());
    }
    else newEvent = std::make_shared<Event>();

    newEvent->setEvent(new_event_type, new_event_name, new_event_money_value, new_event_date, new_event_mileage, new_event_comment);
    event_list.push_back(newEvent);
}
vector<std::shared_ptr<Event>>& Car::getEventList(){
    return event_list;
}
void Car::deleteEventList(){
    // pqxx::connection database_connect("dbname=postgres user=postgres password=Sosi_jopy host=localhost port=5432");
    // if (!database_connect.is_open()) {
    //     std::cerr << "Database connection error" << std::endl;
    //     exit(111);
    // }
    // pqxx::work database_work(database_connect);
    // for (int i = 0; i < event_list.size(); i++) {
    //     if (event_list[i]->getEventType() == CONSUMPTION_NAME::SERVICE) {
    //         database_work.exec0("DELETE FROM service WHERE fk_event_id = " + database_work.quote(event_list[i]->getEventId()));

    //     }
    //     else if (event_list[i]->getEventType() == CONSUMPTION_NAME::REFUELING) {
    //         database_work.exec0("DELETE FROM refueling WHERE fk_event_id = " + database_work.quote(event_list[i]->getEventId()));

    //     }
    // }
    // database_work.exec0("DELETE FROM events WHERE fk_car_id = " + database_work.quote(car_id));
    // database_work.commit();
    event_list.clear();
};
void Car::deleteEventListElement(){
    // pqxx::connection database_connect("dbname=postgres user=postgres password=Sosi_jopy host=localhost port=5432");
    // if (!database_connect.is_open()) {
    //     std::cerr << "Database connection error" << std::endl;
    //     exit(111);
    // }
    // pqxx::work database_work(database_connect);
    // unsigned int chosen_id;
    // cout << "Choose id of event to delete:" << endl;
    // for (unsigned int element_id = 0; element_id < event_list.size(); element_id++){
    //     cout << "ID: " << element_id << " Event name: " <<
    //         Event::consumptionNameToStringFun(event_list[element_id]->getEventType()) << endl;
    // }
    // cout << "Your choice: ";
    // cin >> chosen_id;
    // if (event_list[chosen_id]->getEventType() == CONSUMPTION_NAME::SERVICE) {
    //     database_work.exec0("DELETE FROM service WHERE fk_event_id = " + database_work.quote(event_list[chosen_id]->getEventId()));

    // }
    // else if (event_list[chosen_id]->getEventType() == CONSUMPTION_NAME::REFUELING) {
    //     database_work.exec0("DELETE FROM refueling WHERE fk_event_id = " + database_work.quote(event_list[chosen_id]->getEventId()));

    // }
    // database_work.exec0("DELETE FROM events WHERE event_id = " + database_work.quote(event_list[chosen_id]->getEventId()));
    // database_work.commit();
    // event_list.erase(event_list.begin()+chosen_id);
    (*this) == 1;
}


// void Car::updateCarMoneySpent(){
//     // pqxx::connection database_connect("dbname=postgres user=postgres password=Sosi_jopy host=localhost port=5432");
//     // if (!database_connect.is_open()) {
//     //     std::cerr << "Database connection error" << std::endl;
//     //     exit(111);
//     // }
//     // pqxx::work database_work(database_connect);
//     // car_money_spent = 0;
//     // for (const auto & event : event_list){
//     //     car_money_spent += event->getMoneyValue();
//     // }
//     // cout << "----------------------------";
//     // database_work.exec0("UPDATE cars SET money_spent = " + database_work.quote(car_money_spent) + " WHERE car_id = " + database_work.quote(car_id));
//     // database_work.commit();
// }

void Car::clearCarData() {
    event_list.clear();
}







