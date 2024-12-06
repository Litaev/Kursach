#include "Headers/carListElementModel.h"

CarListElementModel::CarListElementModel(QObject *parent)
    : QAbstractListModel(parent){ }

void CarListElementModel::addCarListElement(CarListElement CarListElement){

    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    carList << std::move(CarListElement);
    endInsertRows();
}
int CarListElementModel::rowCount(const QModelIndex &parent) const{

    Q_UNUSED(parent);
    return carList.count();
}
QVariant CarListElementModel::data(const QModelIndex &index, int role) const{

    if (index.row() < 0 || index.row() >= carList.count())
        return {};

    const CarListElement &carListElement = carList[index.row()];
    switch (role) {
    case NameRole:
        return carListElement.getName();
    case YearRole:
        return carListElement.getYear();
    case MileageRole:
        return carListElement.getMileage();
    default:
        return {};
    }

}
void CarListElementModel::removeCarListElement(int index, int count){
    beginRemoveRows(QModelIndex(), index, index + count - 1);
    for (int row = 0; row < count; ++row) {
        carList.removeAt(index);
    }
    endRemoveRows();
}
void CarListElementModel::resetModel(User *user){
    beginResetModel();
    carList.clear();
    std::vector<std::shared_ptr<Car>> this_car_list = user->getCarList();
    for(int i  = 0; i < user->getCarListSize(); i++){
        QString this_car_name = this_car_list[i]->getCarName();
        int this_car_year = this_car_list[i]->getCarYear();
        int this_car_mileage = this_car_list[i]->getCarMileage();
        addCarListElement(CarListElement(this_car_name, this_car_year, this_car_mileage));
    }
    endResetModel();
}

QHash<int, QByteArray> CarListElementModel::roleNames() const{

    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[YearRole] = "year";
    roles[MileageRole] = "mileage";
    return roles;
}

void CarListElementModel::pushCarListElement(const QString &name, const int &year, const int &mileage) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    carList << CarListElement(name, year, mileage);
    endInsertRows();
}

QVariantList CarListElementModel::getCarListForQML() const {
    QVariantList car_list;
    for (const CarListElement &element : carList) {
        QVariantMap CarListElementMap;
        CarListElementMap["name"] = element.getName();
        CarListElementMap["year"] = element.getYear();
        CarListElementMap["mileage"] = element.getMileage();
        car_list.append(CarListElementMap);
    }
    return car_list;
}
