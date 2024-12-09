#include "Headers/user.h"


using namespace std;


int User::getCarListSize() const {
    return car_list.size();
}
int User::getChosenCarId() const
{
    return chosen_car_id;
}

void User::setChosenCarId(int newChosen_car_id)
{
    chosen_car_id = newChosen_car_id;
}

QString User::getNowDate() const{
    Date now_date;
    now_date.setNowDate();
    return now_date.DateToVariant(now_date).toString();
}

void User::updateChosenCarStatistics(){
    car_list[chosen_car_id]->getCarStatistics().updateMoney(car_list[chosen_car_id]->getEventList());
}

QString User::getInfoAboutCar(int car_index, QString info_type) const{
    if (car_list.size() < 1) return "";
    if (info_type == "name"){ return car_list[car_index]->getCarName(); }
    else if (info_type == "CarMoney") { return QString::number(car_list[car_index]->getCarStatistics().getCarMoneySpent()); }
    else if (info_type == "CarServiceMoney") { return QString::number(car_list[car_index]->getCarStatistics().getServiceMoney()); }
    else if (info_type == "CarFuelMoney") { return QString::number(car_list[car_index]->getCarStatistics().getFuelMoney()); }
    else if (info_type == "CarOtherMoney") { return QString::number(car_list[car_index]->getCarStatistics().getOtherMoney()); }
    else if (info_type == "CarServiceMaintenanceMoney") { return QString::number(car_list[car_index]->getCarStatistics().getServiceMaintenanceMoney()); }
    else if (info_type == "CarServiceRepairMoney") { return QString::number(car_list[car_index]->getCarStatistics().getServiceRepairMoney()); }
    else if (info_type == "CarServiceTuningMoney") { return QString::number(car_list[car_index]->getCarStatistics().getServiceTuningMoney()); }
    else if (info_type == "CarServiceDetailMoney") { return QString::number(car_list[car_index]->getCarStatistics().getServiceDetailMoney()); }
    else if (info_type == "CarServiceDiagnosticsMoney") { return QString::number(car_list[car_index]->getCarStatistics().getServiceDiagnosticsMoney()); }
    else if (info_type == "CarServiceTireFittingMoney") { return QString::number(car_list[car_index]->getCarStatistics().getServiceTireFittingMoney()); }
    else if (info_type == "CarServiceOtherMoney") { return QString::number(car_list[car_index]->getCarStatistics().getServiceOtherMoney()); }
    else if (info_type == "mileage") { return QString::number(car_list[car_index]->getCarMileage()); }
    else if (info_type == "year") { return QString::number(car_list[car_index]->getCarYear()); }
    else if (info_type == "fuel") { return QString::number(static_cast<int>(car_list[car_index]->getCarFuelType())); }
    else if (info_type == "tank") { return QString::number(car_list[car_index]->getCarTankVolume()); }

    return "";
}

void User::editChosenCarInfo(int chosen_car_id, QString new_car_name, QString new_car_year, QString new_car_mileage, QString new_car_fuel_type, QString new_car_tank_volume){
    car_list[chosen_car_id]->setCarName(new_car_name);
    car_list[chosen_car_id]->setCarYear(new_car_year.toInt());
    car_list[chosen_car_id]->setCarMileage(new_car_mileage.toInt());
    car_list[chosen_car_id]->setCarFuelType(static_cast<FUEL_TYPE>(new_car_fuel_type.toInt()));
    car_list[chosen_car_id]->setCarTankVolume(new_car_tank_volume.toInt());
}

QString User::getInfoAboutEvent(int car_index, int event_index, QString info_type) const{
    if (car_list.size() < 1) return "";
    if (car_list[chosen_car_id]->getEventList().size() < 1) return "";
    if (info_type == "type") {return QString::number(static_cast<int>(car_list[car_index]->getEventList()[event_index]->getEventType())); }
    else if (info_type == "name") {return QString::fromStdString(car_list[car_index]->getEventList()[event_index]->getEventName());}
    else if (info_type == "money") {return QString::number(car_list[car_index]->getEventList()[event_index]->getMoneyValue());}
    else if (info_type == "date") {return Date::DateToVariant(car_list[car_index]->getEventList()[event_index]->getEventDate()).toString();}
    else if (info_type == "mileage") {return QString::number(car_list[car_index]->getEventList()[event_index]->getCarMileage());}
    else if (info_type == "comment") {return QString::fromStdString(car_list[car_index]->getEventList()[event_index]->getEventComment());}
    else if (info_type == "fuelType") {return QString::number(static_cast<float>(car_list[car_index]->getEventList()[event_index]->getFuelType()));}
    else if (info_type == "litres") {return QString::number(car_list[car_index]->getEventList()[event_index]->getAmountOfLitres());}
    else if (info_type == "pricePerLitre") {return QString::number(static_cast<float>(car_list[car_index]->getEventList()[event_index]->getPricePerLitre()));}
    else if (info_type == "serviceType") {return QString::number(static_cast<int>(car_list[car_index]->getEventList()[event_index]->getServiceType()));}
    return "";
}

void User::editChosenEventInfo(int chosen_event_id, int event_type, QString new_event_name, QString new_event_money, QString new_event_date, QString new_event_mileage, QString new_event_comment,
                               QString new_event_litres, QString new_event_price_per_litre, QString new_event_service_type){


    car_list[chosen_car_id]->event_list[chosen_event_id]->event_name = new_event_name.toStdString();
    car_list[chosen_car_id]->event_list[chosen_event_id]->moneyValue = new_event_money.toFloat();
    car_list[chosen_car_id]->event_list[chosen_event_id]->event_date = Date::VariantToDate(new_event_date);
    car_list[chosen_car_id]->event_list[chosen_event_id]->car_mileage = new_event_mileage.toInt();
    car_list[chosen_car_id]->event_list[chosen_event_id]->event_comment = new_event_comment.toStdString();
    if (static_cast<CONSUMPTION_NAME>(event_type) == CONSUMPTION_NAME::REFUELING){
        car_list[chosen_car_id]->getEventList()[chosen_event_id]->setAmountOfLitres(new_event_litres.toFloat());
        car_list[chosen_car_id]->getEventList()[chosen_event_id]->setPricePerLitre(new_event_price_per_litre.toFloat());
    }
    else if (static_cast<CONSUMPTION_NAME>(event_type) == CONSUMPTION_NAME::SERVICE){
        car_list[chosen_car_id]->getEventList()[chosen_event_id]->setServiceType(static_cast<SERVICE_NAME>(new_event_service_type.toInt()));
    }

}

void User::addCar(QString new_car_name, QString new_car_year, QString new_car_mileage, QString new_car_fuel_type, QString new_car_tank_volume){

    std::shared_ptr<Car> newCar {std::make_shared<Car>()};

    newCar->setCar(new_car_name, new_car_year, new_car_mileage, new_car_fuel_type, new_car_tank_volume);
    car_list.push_back(newCar);
}

void User::addEvent(QString new_event_type, QString new_event_name, QString new_event_money_value, QString new_event_date, QString new_event_mileage,
                    QString new_event_comment, QString new_event_service_type, QString new_event_amount_of_litres, QString new_event_price_per_litre){


    std::shared_ptr<Event> newEvent;
    if (static_cast<CONSUMPTION_NAME>(new_event_type.toInt()) == CONSUMPTION_NAME::SERVICE){
        newEvent = std::make_shared<CarService>();
        newEvent->setServiceType(static_cast<SERVICE_NAME>(new_event_service_type.toInt()));
    }
    else if (static_cast<CONSUMPTION_NAME>(new_event_type.toInt()) == CONSUMPTION_NAME::REFUELING){
        newEvent = std::make_shared<Refueling>();
        newEvent->setFuelType(static_cast<FUEL_TYPE>(car_list[chosen_car_id]->getCarFuelType()));
        newEvent->setAmountOfLitres(new_event_amount_of_litres.toFloat());
        newEvent->setPricePerLitre(new_event_price_per_litre.toFloat());
    }
    else newEvent = std::make_shared<Event>();

    newEvent->setEvent(new_event_type.toInt(), new_event_name, new_event_money_value, new_event_date, new_event_mileage, new_event_comment);
    car_list[chosen_car_id]->getEventList().push_back(newEvent);

}

void User::deleteChosenEvent(int chosen_event_id){
    car_list[chosen_car_id]->getEventList().erase(car_list[chosen_car_id]->getEventList().begin() + chosen_event_id);
}
void User::deleteChosenCar(int chosen_car_id){
    (*car_list[chosen_car_id])--;
    car_list.erase(car_list.begin() + chosen_car_id);
}

// void User::deleteCar() {
//     // pqxx::connection database_connect("dbname=postgres user=postgres password=Sosi_jopy host=localhost port=5432");
//     // if (!database_connect.is_open()) {
//     //     std::cerr << "Database connection error" << std::endl;
//     //     exit(111);
//     // }
//     // pqxx::work database_work(database_connect);
//     // system("cls");
//     // unsigned int chosen_id;
//     // cout << "Choose id of car to delete:" << endl;
//     // for (unsigned int element_id = 0; element_id < car_list.size(); element_id++) {
//     //     cout << "ID: " << element_id << " Car name: " << car_list[element_id]->getCarName() << endl;
//     // }
//     // cout << "Your choice: ";
//     // cin >> chosen_id;
//     // car_list[chosen_id]->deleteEventList();

//     // database_work.exec0("DELETE FROM cars WHERE car_id = " + database_work.quote(car_list[chosen_id]->getCarId()));
//     // database_work.commit();
//     // car_list.erase(car_list.begin() + chosen_id);
// }


float User::getUserMoneySpent() const{
    return user_money_spent;
}


vector<std::shared_ptr<Car>>& User::getCarList(){
    return car_list;
}

void User::saveUserData() const{

    QSettings settings("MyCompany", "CarApp");

    QVariantMap userMap;
    userMap["chosen_car_id"] = chosen_car_id;
    userMap["user_money_spent"] = user_money_spent;

    QVariantList carList;
    for (const auto& car : car_list) {
        QVariantMap carMap;
        carMap["car_name"] = car->getCarName();
        carMap["car_gov_number"] = QString::fromStdString(car->getCarGovNumber());
        carMap["car_year"] = car->getCarYear();
        carMap["car_mileage"] = car->getCarMileage();
        carMap["car_tank_volume"] = car->getCarTankVolume();
        carMap["car_fuel_type"] = static_cast<int>(car->getCarFuelType());

        QVariantList eventList;
        for (const auto& event : car->getEventList()) {
            QVariantMap eventMap;
            if (event->getEventType() == CONSUMPTION_NAME::SERVICE){
                eventMap["service_name"] = static_cast<int>(event->getServiceType());
            }
            else if (event->getEventType() == CONSUMPTION_NAME::REFUELING){
                eventMap["fuel_type"] = static_cast<int>(event->getFuelType());
                eventMap["litre_amount"] = event->getAmountOfLitres();
                eventMap["price_per_litre"] = event->getPricePerLitre();
            }
            eventMap["event_id"] = event->getEventId();
            eventMap["event_name"] = QString::fromStdString(event->getEventName());
            eventMap["event_type"] = static_cast<int>(event->getEventType());
            eventMap["money_value"] = event->getMoneyValue();
            eventMap["event_date"] = Date::DateToVariant(event->getEventDate());
            eventMap["event_mileage"] = event->getCarMileage();
            eventMap["event_comment"] = QString::fromStdString(event->getEventComment());
            eventList.append(eventMap);
        }
        carMap["event_list"] = eventList;
        carList.append(carMap);
    }
    userMap["car_list"] = carList;

    settings.setValue("user_data", userMap);
}

void User::loadUserData() {

    QSettings settings("MyCompany", "CarApp");
    QVariant var = settings.value("user_data");
    if (var.isNull()) return;

    QVariantMap map1 = var.toMap();
    chosen_car_id = map1["chosen_car_id"].toInt();
    user_money_spent = map1["user_money_spent"].toFloat();
    QVariantList carList = map1["car_list"].toList();
    for (const QVariant& carVar : carList) {
        QVariantMap map2 = carVar.toMap();
        std::shared_ptr<Car> car {std::make_shared<Car>()};
        car->setCarName(map2["car_name"].toString());
        car->setCarGovNumber(map2["car_gov_number"].toString().toStdString());
        car->setCarYear(map2["car_year"].toInt());
        car->setCarMileage(map2["car_mileage"].toInt());
        car->setCarTankVolume(map2["car_tank_volume"].toInt());
        car->setCarFuelType(static_cast<FUEL_TYPE>(map2["car_fuel_type"].toInt()));

        QVariantList eventList = map2["event_list"].toList();
        for (const QVariant& eventVar : eventList) {
            QVariantMap map3 = eventVar.toMap();
            CONSUMPTION_NAME eventType = static_cast<CONSUMPTION_NAME>(map3["event_type"].toInt());
            std::shared_ptr<Event> event;
            if (eventType == CONSUMPTION_NAME::SERVICE){
                event = std::make_shared<CarService>();
                event->setServiceType(static_cast<SERVICE_NAME>(map3["service_name"].toInt()));
            }
            else if (eventType == CONSUMPTION_NAME::REFUELING){
                event = std::make_shared<Refueling>();
                event->setFuelType(static_cast<FUEL_TYPE>(map3["fuel_type"].toInt()));
                event->setAmountOfLitres(map3["litre_amount"].toFloat());
                event->setPricePerLitre(map3["price_per_litre"].toFloat());
            }
            else event = std::make_shared<Event>();
            event->setEventId(map3["event_id"].toInt());
            event->setEventName(map3["event_name"].toString().toStdString());
            event->setEventType(eventType);
            event->setMoneyValue(map3["money_value"].toFloat());
            event->setEventDate(map3["event_date"]);
            event->setCarMileage(map3["event_mileage"].toUInt());
            event->setEventComment(map3["event_comment"].toString().toStdString());
            car->getEventList().push_back(event);
        }

        (*car) == 1;
        car->updateCarMileage();

        car_list.push_back(car);
    }

}




