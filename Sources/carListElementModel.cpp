#include "Headers/carListElementModel.h"

CarListElementModel::CarListElementModel(QObject *parent)
    : QAbstractListModel(parent){ }

void CarListElementModel::addCarListElement(CarListElement CarListElement){
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    carList << std::move(CarListElement);
    endInsertRows();
}
int CarListElementModel::rowCount(const QModelIndex &parent) const{

    Q_UNUSED(parent)

    return carList.count();
}
QVariant CarListElementModel::data(const QModelIndex &index, int role) const{

    if (index.row() < 0 || index.row() >= carList.count())
        return {};

    const CarListElement &carListElement = carList[index.row()];
    switch (static_cast<CarListElementRoles>(role)) {
        using enum CarListElementRoles;
    case NameRole:
        return carListElement.getName();
    case ImagePathRole:
        return carListElement.getImagePath();
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

    for(const auto &car : this_car_list){
        QString this_car_name = car->getCarName();
        QString this_image_path = car->getCarImageFilePath();
        int this_car_year = car->getCarYear();
        int this_car_mileage = car->getCarMileage();
        addCarListElement(CarListElement(this_car_name, this_image_path, this_car_year, this_car_mileage));
    }

    endResetModel();
}

QHash<int, QByteArray> CarListElementModel::roleNames() const{

    QHash<int, QByteArray> roles;
    using enum CarListElementRoles;
    roles[std::to_underlying(NameRole)] = "name";
    roles[std::to_underlying(ImagePathRole)] = "imagePath";
    roles[std::to_underlying(YearRole)] = "year";
    roles[std::to_underlying(MileageRole)] = "mileage";
    return roles;
}

void CarListElementModel::pushCarListElement(const QString &name, const QString &imagePath, const int &year, const int &mileage) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    carList << CarListElement(name, imagePath, year, mileage);
    endInsertRows();
}

QVariantList CarListElementModel::getCarListForQML() const {
    QVariantList car_list;
    for (const CarListElement &element : carList) {
        QVariantMap CarListElementMap;
        CarListElementMap["name"] = element.getName();
        CarListElementMap["imagePath"] = element.getImagePath();
        CarListElementMap["year"] = element.getYear();
        CarListElementMap["mileage"] = element.getMileage();
        car_list.append(CarListElementMap);
    }
    return car_list;
}
