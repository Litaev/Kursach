#ifndef EVENTSWINDOW_H
#define EVENTSWINDOW_H


#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QStringList>
#include "eventListElementModel.h"
#include <QDebug>
#include "user.h"


class EventsWindow : public QObject
{
    Q_OBJECT
public:
    EventsWindow(EventListElementModel *event_model = nullptr, User *user = nullptr);
    Q_INVOKABLE void updateModel();

private:
    EventListElementModel *event_model;
    User *user;

};


#endif // EVENTSWINDOW_H
