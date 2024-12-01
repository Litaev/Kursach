#ifndef CHOOSECARWINDOW_H
#define CHOOSECARWINDOW_H

#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QStringList>
#include "carListElementModel.h"
#include <QDebug>
#include "user.h"


class ChooseCarWindow : public QObject
{
    Q_OBJECT
public:
    ChooseCarWindow(CarListElementModel *car_model = nullptr, User *user = nullptr);
    Q_INVOKABLE void updateModel();

private:
    CarListElementModel *car_model;
    User *user;

};


#endif // CHOOSECARWINDOW_H
