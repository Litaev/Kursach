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

// bool checkPermission()
// {
//     auto r = QtAndroidPrivate::checkPermission(QtAndroidPrivate::).result();
//     if (r == QtAndroidPrivate::Denied)
//     {
//         r = QtAndroidPrivate::requestPermission(QtAndroidPrivate::Storage).result();
//         if (r == QtAndroidPrivate::Denied)
//             return false;
//     }
//     return true;
// }


// #include <QAndroidJniObject>
// #include <QtAndroid>

// void openFilePicker() {
//     QAndroidJniObject intent("android/content/Intent", "(Ljava/lang/String;)V",
//                              QAndroidJniObject::getStaticObjectField<jstring>("android/content/Intent", "ACTION_PICK"));
//     intent.callObjectMethod("setType", "(Ljava/lang/String;)V", QAndroidJniObject::fromString("image/*").object<jstring>());
//     QtAndroid::startActivity(intent, 0);
// }


int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    EnhancedQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("$QmlEngine", &engine);

    User user;
    user.loadUserData();
    //qmlRegisterType<User>("userInfo", 1, 0, "CarListElementModel");
    CarListElementModel carListModel(&app);
    EventListElementModel eventListModel(&app);
    ChooseCarWindow chooseCarWindow(&carListModel, &user);
    EventsWindow serviceWindow(&eventListModel, &user);
    engine.rootContext()->setContextProperty("user", &user);
    engine.rootContext()->setContextProperty("chooseCarWindow", &chooseCarWindow);
    engine.rootContext()->setContextProperty("eventsWindow", &serviceWindow);
    engine.rootContext()->setContextProperty("carListElementModel", QVariant::fromValue(&carListModel));
    engine.rootContext()->setContextProperty("eventListElementModel", QVariant::fromValue(&eventListModel));



    //QObject* listView = parent->findChild<QObject*>("listView");
    //lisView->setProperty("model", QVariant::fromValue(&modell));
    // engine.rootContext()->setContextProperty("carList", QVariant::fromValue(&carList));
    engine.load(QStringLiteral("qrc:/test11/Qml/Main.qml"));
    return app.exec();

}
