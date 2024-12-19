#include "Headers/user.h"


using namespace std;


int User::getCarListSize() const {
    return carList.size();
}

int User::getUserChosenCarId() const {
    return userChosenCarId;
}

void User::setUserChosenCarId(int newChosenCarId) {
    userChosenCarId = newChosenCarId;
}

int User::getNowDate(QString type) const {
    Date nowDate;
    nowDate.setNowDate();
    if (type == "day") return nowDate.getDay();
    else if (type == "month") return nowDate.getMonth() + 1;
    else if (type == "year") return nowDate.getYear();
    else if (type == "hour") return nowDate.getHour();
    else if (type == "minute") return nowDate.getMinute();
    return 0;
}

void User::updateChosenCarStatistics() {
    carList[userChosenCarId]->getCarStatistics().updateMoney(carList[userChosenCarId]->getEventList());
}

QString User::getInfoAboutCar(int carIndex, QString infoType) const {
    qDebug() << "-------------------: " << carIndex << " ------: " << infoType;
    if (carList.size() < 1) return "";
    if (infoType == "name") {
        return carList[carIndex]->getCarName();
    }
    else if (infoType == "carMoney") {
        return QString::number(carList[carIndex]->getCarStatistics().getCarMoneySpent());
    }
    else if (infoType == "carServiceMoney") {
        return QString::number(carList[carIndex]->getCarStatistics().getServiceMoney());
    }
    else if (infoType == "carFuelMoney") {
        return QString::number(carList[carIndex]->getCarStatistics().getFuelMoney());
    }
    else if (infoType == "carOtherMoney") {
        return QString::number(carList[carIndex]->getCarStatistics().getOtherMoney());
    }
    else if (infoType == "carServiceMaintenanceMoney") {
        return QString::number(carList[carIndex]->getCarStatistics().getServiceMaintenanceMoney());
    }
    else if (infoType == "carServiceRepairMoney") {
        return QString::number(carList[carIndex]->getCarStatistics().getServiceRepairMoney());
    }
    else if (infoType == "carServiceTuningMoney") {
        return QString::number(carList[carIndex]->getCarStatistics().getServiceTuningMoney());
    }
    else if (infoType == "carServiceDetailMoney") {
        return QString::number(carList[carIndex]->getCarStatistics().getServiceDetailMoney());
    }
    else if (infoType == "carServiceDiagnosticsMoney") {
        return QString::number(carList[carIndex]->getCarStatistics().getServiceDiagnosticsMoney());
    }
    else if (infoType == "carServiceTireFittingMoney") {
        return QString::number(carList[carIndex]->getCarStatistics().getServiceTireFittingMoney());
    }
    else if (infoType == "carServiceOtherMoney") {
        return QString::number(carList[carIndex]->getCarStatistics().getServiceOtherMoney());
    }
    else if (infoType == "mileage") {
        return QString::number(carList[carIndex]->getCarMileage());
    }
    else if (infoType == "year") {
        return QString::number(carList[carIndex]->getCarYear());
    }
    else if (infoType == "fuel") {
        return QString::number(std::to_underlying(carList[carIndex]->getCarFuelType()));
    }
    else if (infoType == "tank") {
        return QString::number(carList[carIndex]->getCarTankVolume());
    }
    else if (infoType == "imagePath") {
        return carList[carIndex]->getCarImageFilePath();
    }
    return "";
}

void User::editChosenCarInfo(QString newCarName, QString newCarYear, QString newCarMileage, QString newCarFuelType, QString newCarTankVolume) {
    carList[userChosenCarId]->setCarName(newCarName);
    carList[userChosenCarId]->setCarYear(newCarYear.toInt());
    carList[userChosenCarId]->setCarMileage(newCarMileage.toInt());
    carList[userChosenCarId]->setCarFuelType(static_cast<FUEL_TYPE>(newCarFuelType.toInt()));
    carList[userChosenCarId]->setCarTankVolume(newCarTankVolume.toInt());
}

QString User::getInfoAboutEvent(int carIndex, int eventIndex, QString infoType) const {
    if (carList.size() < 1) return "";
    if (carList[userChosenCarId]->getEventList().size() < 1) return "";
    if (infoType == "type") {
        return QString::number(std::to_underlying(carList[carIndex]->getEventList()[eventIndex]->getEventType()));
    }
    else if (infoType == "name") {
        return carList[carIndex]->getEventList()[eventIndex]->getEventName();
    }
    else if (infoType == "money") {
        return QString::number(carList[carIndex]->getEventList()[eventIndex]->getEventPrice());
    }
    else if (infoType == "eventYear") {
        return QString::number(carList[carIndex]->getEventList()[eventIndex]->getEventDate().getYear());
    }
    else if (infoType == "eventMonth") {
        return QString::number(carList[carIndex]->getEventList()[eventIndex]->getEventDate().getMonth() + 1);
    }
    else if (infoType == "eventDay") {
        return QString::number(carList[carIndex]->getEventList()[eventIndex]->getEventDate().getDay());
    }
    else if (infoType == "eventHour") {
        return QString::number(carList[carIndex]->getEventList()[eventIndex]->getEventDate().getHour());
    }
    else if (infoType == "eventMinute") {
        return QString::number(carList[carIndex]->getEventList()[eventIndex]->getEventDate().getMinute());
    }
    else if (infoType == "eventDateAndTimeNow") {
        carList[carIndex]->getEventList()[eventIndex]->getEventDate().setNowDate();
        return "";
    }
    else if (infoType == "mileage") {
        return QString::number(carList[carIndex]->getEventList()[eventIndex]->getEventMileage());
    }
    else if (infoType == "comment") {
        return carList[carIndex]->getEventList()[eventIndex]->getEventComment();
    }
    else if (infoType == "fuelType") {
        return QString::number(static_cast<float>(carList[carIndex]->getEventList()[eventIndex]->getFuelType()));
    }
    else if (infoType == "litres") {
        return QString::number(carList[carIndex]->getEventList()[eventIndex]->getAmountOfLitres());
    }
    else if (infoType == "pricePerLitre") {
        return QString::number(carList[carIndex]->getEventList()[eventIndex]->getPricePerLitre());
    }
    else if (infoType == "serviceType") {
        return QString::number(std::to_underlying(carList[carIndex]->getEventList()[eventIndex]->getServiceType()));
    }
    return "";
}

void User::editChosenEventInfo(int chosenEventId, int eventType, QString newEventName, QString newEventMoney, QString newEventDate, QString newEventMileage, QString newEventComment,
                               QString newEventLitres, QString newEventPricePerLitre, QString newEventServiceType) {

    carList[userChosenCarId]->eventList[chosenEventId]->eventName = newEventName;
    carList[userChosenCarId]->eventList[chosenEventId]->eventPrice = newEventMoney.toFloat();
    carList[userChosenCarId]->eventList[chosenEventId]->eventDate = Date::VariantToDate(newEventDate);
    carList[userChosenCarId]->eventList[chosenEventId]->eventMileage = newEventMileage.toInt();
    carList[userChosenCarId]->eventList[chosenEventId]->eventComment = newEventComment;
    if (static_cast<CONSUMPTION_NAME>(eventType) == CONSUMPTION_NAME::REFUELING) {
        carList[userChosenCarId]->getEventList()[chosenEventId]->setAmountOfLitres(newEventLitres.toFloat());
        carList[userChosenCarId]->getEventList()[chosenEventId]->setPricePerLitre(newEventPricePerLitre.toFloat());
    }
    else if (static_cast<CONSUMPTION_NAME>(eventType) == CONSUMPTION_NAME::SERVICE) {
        carList[userChosenCarId]->getEventList()[chosenEventId]->setServiceType(static_cast<SERVICE_NAME>(newEventServiceType.toInt()));
    }
}

void User::addCar(QString newCarName, QString newCarYear, QString newCarMileage, QString newCarFuelType, QString newCarTankVolume) {
    std::shared_ptr<Car> newCar {std::make_shared<Car>()};
    newCar->setCar(newCarName, newCarYear, newCarMileage, newCarFuelType, newCarTankVolume);
    carList.push_back(newCar);
}

void User::addEvent(QString newEventType, QString newEventName, QString newEventMoneyValue, QString newEventDate, QString newEventMileage,
                    QString newEventComment, QString newEventServiceType, QString newEventAmountOfLitres, QString newEventPricePerLitre) {


    std::shared_ptr<Event> newEvent;
    if (static_cast<CONSUMPTION_NAME>(newEventType.toInt()) == CONSUMPTION_NAME::SERVICE) {
        newEvent = std::make_shared<CarService>();
        newEvent->setServiceType(static_cast<SERVICE_NAME>(newEventServiceType.toInt()));
    }
    else if (static_cast<CONSUMPTION_NAME>(newEventType.toInt()) == CONSUMPTION_NAME::REFUELING) {
        newEvent = std::make_shared<Refueling>();
        newEvent->setFuelType(carList[userChosenCarId]->getCarFuelType());
        newEvent->setAmountOfLitres(newEventAmountOfLitres.toFloat());
        newEvent->setPricePerLitre(newEventPricePerLitre.toFloat());
    }

    newEvent->setEvent(newEventType.toInt(), newEventName, newEventMoneyValue, newEventDate, newEventMileage, newEventComment);
    carList[userChosenCarId]->getEventList().push_back(newEvent);
}

void User::setChosenCarImage(int chosenCarId) {
    QString newFilePath = QFileDialog::getOpenFileName(nullptr, "Open File", "", "Images (*.png *.jpeg *.jpg);;All files (*)");
    if (newFilePath != "") carList[chosenCarId]->setCarImageFilePath(newFilePath);
}

void User::deleteChosenEvent(int chosenEventId) {
    carList[userChosenCarId]->getEventList().erase(carList[userChosenCarId]->getEventList().begin() + chosenEventId);
}

void User::deleteChosenCar(int carId) {
    (*carList[carId])--;
    carList.erase(carList.begin() + carId);
    if (carId == this->userChosenCarId) userChosenCarId = 0;
}


vector<std::shared_ptr<Car>>& User::getCarList() {
    return carList;
}


void User::saveUserData() const{

    QSettings settings("LitAEvCompany", "CarExpenses");
    QVariantMap userMap;
    userMap["userChosenCarId"] = userChosenCarId;
    QVariantList forMapCarList;
    for (const auto& car : carList) {
        forMapCarList.append(car->preSaveData());
    }
    userMap["carList"] = forMapCarList;
    settings.setValue("userData", userMap);
}

void User::loadUserData() {

    QSettings settings("LitAEvCompany", "CarExpenses");
    QVariant var = settings.value("userData");
    if (var.isNull()) return;
    QVariantMap userMap = var.toMap();
    userChosenCarId = userMap["userChosenCarId"].toInt();
    QVariantList forMapCarList = userMap["carList"].toList();
    for (const QVariant& carVar : forMapCarList) {
        QVariantMap carMap = carVar.toMap();
        std::shared_ptr<Car> car {std::make_shared<Car>()};
        car->preLoadData(carMap);
        (*car) == 1;
        car->updateCarMileage();
        carList.push_back(car);
    }

}



bool User::compEventListMinByDate(const std::shared_ptr<Event> &event1, const std::shared_ptr<Event> &event2){

    return event1->getEventDate().getDateForSort() < event2->getEventDate().getDateForSort();
}
bool User::compEventListMaxByDate(const std::shared_ptr<Event> &event1, const std::shared_ptr<Event> &event2){

    return event1->getEventDate().getDateForSort() > event2->getEventDate().getDateForSort();
}

bool User::compEventListMinByPrice(const std::shared_ptr<Event> &event1, const std::shared_ptr<Event> &event2){

    return event1->getEventPrice() < event2->getEventPrice();

}
bool User::compEventListMaxByPrice(const std::shared_ptr<Event> &event1, const std::shared_ptr<Event> &event2){

    return event1->getEventPrice() > event2->getEventPrice();

}



void User::sortChosenCarEventListMin(QString sortType){
    if (sortType == "date"){
        std::ranges::sort(carList[userChosenCarId]->getEventList(), compEventListMinByDate);
    }
    else if (sortType == "price"){
        std::ranges::sort(carList[userChosenCarId]->getEventList(), compEventListMinByPrice);
    }

}
void User::sortChosenCarEventListMax(QString sortType){
    if (sortType == "date"){
        std::ranges::sort(carList[userChosenCarId]->getEventList(), compEventListMaxByDate);
    }
    else if (sortType == "price"){
        std::ranges::sort(carList[userChosenCarId]->getEventList(), compEventListMaxByPrice);
    }

}


std::vector<std::shared_ptr<Event>> &User::getChosenCarEventList(){
    return carList[userChosenCarId]->getEventList();
}

int User::getChosenCarTankVolume(){
    return carList[userChosenCarId]->getCarTankVolume();
}


