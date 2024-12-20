#include "Headers/eventListElementModel.h"

EventListElementModel::EventListElementModel(QObject *parent)
    : QAbstractListModel(parent) {}


void EventListElementModel::addEventListElement(EventListElement EventListElement){
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    eventList << std::move(EventListElement);
    endInsertRows();
}


int EventListElementModel::rowCount(const QModelIndex &parent) const{

    Q_UNUSED(parent)

    return eventList.count();
}



QVariant EventListElementModel::data(const QModelIndex &index, int role) const{
    if (index.row() < 0 || index.row() >= eventList.count())
        return {};
    const EventListElement &eventListElement = eventList[index.row()];


    switch (static_cast<EventListElementRoles>(role)) {
        using enum EventListElementRoles;
    case EventTypeRole:
        return eventListElement.getEventType();
    case EventNameRole:
        return eventListElement.getEventName();
    case EventPriceRole:
        return eventListElement.getPrice();
    case EventMileageRole:
        return eventListElement.getMileage();
    case EventDateRole:
        return eventListElement.getDate();
    case EventServiceTypeRole:
        return eventListElement.getServiceType();
    default:
        return {};
    }
}




void EventListElementModel::removeEventListElement(int index, int count){
    beginRemoveRows(QModelIndex(), index, index + count - 1);
    for (int row = 0; row < count; ++row) {
        eventList.removeAt(index);
    }
    endRemoveRows();
}


void EventListElementModel::resetEventsModel(User *user){
    beginResetModel();
    eventList.clear();
    if (user->getCarListSize() > 0){
        std::vector<std::shared_ptr<Event>> this_event_list = user->getCarList()[user->getUserChosenCarId()]->getEventList();
        for(const auto &event : this_event_list){

            int this_event_type = std::to_underlying(event->getEventType());
            QString this_name = event->getEventName();
            float this_price = event->getEventPrice();
            int this_mileage = event->getEventMileage();
            QString this_date = Date::DateToVariant(event->getEventDate()).toString();
            int this_service_type = 0;
            if (static_cast<CONSUMPTION_NAME>(this_event_type) == CONSUMPTION_NAME::SERVICE){
                this_service_type = std::to_underlying(event->getServiceType());
            }

            addEventListElement(EventListElement(this_event_type, this_name, this_price, this_mileage, this_date, this_service_type));
        }
    }
    endResetModel();
}


QHash<int, QByteArray> EventListElementModel::roleNames() const{

    QHash<int, QByteArray> roles;
    using enum EventListElementRoles;
    roles[std::to_underlying(EventTypeRole)] = "event_type";
    roles[std::to_underlying(EventNameRole)] = "event_name";
    roles[std::to_underlying(EventPriceRole)] = "event_price";
    roles[std::to_underlying(EventMileageRole)] = "event_mileage";
    roles[std::to_underlying(EventDateRole)] = "event_date";
    roles[std::to_underlying(EventServiceTypeRole)] = "event_service_type";
    return roles;
}




void EventListElementModel::pushEventListElement(const int &event_type, const QString &name, const float &price, const int &mileage, const QString &date, const int &service_type) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    eventList << EventListElement(event_type, name, price, mileage, date, service_type);
    endInsertRows();
}



QVariantList EventListElementModel::getEventListForQML() const {
    QVariantList event_list;
    for (const EventListElement &element : eventList) {
        QVariantMap EventListElementMap;
        EventListElementMap["event_type"] = element.getEventType();
        EventListElementMap["name"] = element.getEventName();
        EventListElementMap["price"] = element.getPrice();
        EventListElementMap["mileage"] = element.getMileage();
        EventListElementMap["date"] = element.getDate();
        EventListElementMap["service_type"] = element.getServiceType();
        event_list.append(EventListElementMap);
    }
    return event_list;
}













