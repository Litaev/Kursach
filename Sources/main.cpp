#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtQuickWidgets/QtQuickWidgets>
#include "Headers/carListElementModel.h"
#include "Headers/eventListElementModel.h"
#include "Headers/chooseCarWindow.h"
#include "Headers/eventsWindow.h"
#include "Headers/user.h"
#include "Headers/enhancedqmlapplicationengine.h"
#include <QDebug>
#include <QFileDialog>
#include <QtCore/private/qandroidextras_p.h>

#include "Headers/validator.h"



int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    EnhancedQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("$QmlEngine", &engine);
    User user;
    Validator validator;
    user.loadUserData();
    CarListElementModel carListModel(&app);
    EventListElementModel eventListModel(&app);
    ChooseCarWindow chooseCarWindow(&carListModel, &user);
    EventsWindow serviceWindow(&eventListModel, &user);
    engine.rootContext()->setContextProperty("user", &user);
    engine.rootContext()->setContextProperty("chooseCarWindow", &chooseCarWindow);
    engine.rootContext()->setContextProperty("eventsWindow", &serviceWindow);
    engine.rootContext()->setContextProperty("myValidator", &validator);
    engine.rootContext()->setContextProperty("carListElementModel", QVariant::fromValue(&carListModel));
    engine.rootContext()->setContextProperty("eventListElementModel", QVariant::fromValue(&eventListModel));


    engine.load(QStringLiteral("qrc:/test11/Qml/Main.qml"));

    app.exec();

    user.saveUserData();

    return 0;

}
