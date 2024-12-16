#ifndef EVENTLISTELEMENTMODEL_H
#define EVENTLISTELEMENTMODEL_H
#include <QString>
#include <QAbstractListModel>
#include <QList>
#include "user.h"
#include "eventlistelement.h"


class EventListElementModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum class EventListElementRoles{
        EventTypeRole = Qt::UserRole + 1,
        EventNameRole,
        EventPriceRole,
        EventMileageRole,
        EventDateRole,
        EventServiceTypeRole
    };
    explicit EventListElementModel(QObject *parent = nullptr);

    void addEventListElement(const EventListElement EventListElement);
    Q_INVOKABLE void removeEventListElement(int index, int count = 1);
    Q_INVOKABLE void pushEventListElement(const int &event_type, const QString &name, const float &price, const int &mileage, const QString &date, const int &service_type);
    Q_INVOKABLE void resetEventsModel(User *user);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    Q_INVOKABLE QVariantList getEventListForQML() const;
protected:
    QHash<int, QByteArray> roleNames() const override;
private:
    QList<EventListElement> eventList;
};





#endif // EVENTLISTELEMENTMODEL_H
