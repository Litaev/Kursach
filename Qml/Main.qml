pragma ComponentBehavior: Bound

import QtQuick
import QtQuick.Layouts 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15


ApplicationWindow {
    id: initWindow
    width: 1080
    height: 1920
    visible: true
    color: "#000000"

    property var status: new Object({isEditCar: true},
                                    {isEditEvent: true},
                                    {isEditService: true},
                                    {isEditRefueling: true},
                                    {chosenEventId: 0},
                                    {isSortFromNewest: true});

    Loader {
        id: _loader
        function reload() {
            source = "";
            $QmlEngine.clearCache();
            source = "qrc:/test11/Qml/CarCard.qml";
        }
        anchors.fill: parent

        source: "qrc:/test11/Qml/CarCard.qml"
    }


}


