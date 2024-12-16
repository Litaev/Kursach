#ifndef CARLISTELEMENTMODEL_H
#define CARLISTELEMENTMODEL_H

#include <QString>
#include <QAbstractListModel>
#include <QList>
#include "carlistelement.h"
#include "user.h"


class CarListElementModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum class CarListElementRoles{
        NameRole = Qt::UserRole + 1,
        ImagePathRole,
        YearRole,
        MileageRole
    };
    explicit CarListElementModel(QObject *parent = nullptr);

    void addCarListElement(const CarListElement CarListElement);

    Q_INVOKABLE QVariantList getCarListForQML() const;

    Q_INVOKABLE void removeCarListElement(int index, int count = 1);

    Q_INVOKABLE void pushCarListElement(const QString &name, const QString &imagePath, const int &year, const int &mileage);

    Q_INVOKABLE void resetModel(User *user);


    int rowCount(const QModelIndex &parent = QModelIndex())  const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
protected:
    QHash<int, QByteArray> roleNames() const override;
private:
    QList<CarListElement> carList;
};


#endif // CARLISTELEMENTMODEL_H
