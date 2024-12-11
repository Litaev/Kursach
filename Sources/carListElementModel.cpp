#include "Headers/carListElementModel.h"

CarListElementModel::CarListElementModel(QObject *parent)
    : QAbstractListModel(parent){ }

void CarListElementModel::addCarListElement(CarListElement CarListElement){
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    carList << std::move(CarListElement);
    qDebug() << "66666666666";
    endInsertRows();
    qDebug() << "777777777";
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
    qDebug() << "33333333333";
    std::vector<std::shared_ptr<Car>> this_car_list = user->getCarList();

    for(int i  = 0; i < user->getCarListSize(); i++){
        qDebug() << "Iteration " << i;
        QString this_car_name = this_car_list[i]->getCarName();
        QString this_image_path = this_car_list[i]->getCarImageFilePath();
        qDebug() << "FILEPATH: " << this_image_path;
        int this_car_year = this_car_list[i]->getCarYear();
        int this_car_mileage = this_car_list[i]->getCarMileage();
        qDebug() << this_car_name << "-" << this_car_year << "-" << this_car_mileage;
        addCarListElement(CarListElement(this_car_name, this_image_path, this_car_year, this_car_mileage));
        qDebug() << "endIter " << i;
    }

    endResetModel();
}

QHash<int, QByteArray> CarListElementModel::roleNames() const{

    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[ImagePathRole] = "imagePath";
    roles[YearRole] = "year";
    roles[MileageRole] = "mileage";
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
