pragma ComponentBehavior: Bound

import QtQuick
import QtQuick.Layouts 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15


ApplicationWindow {
    width: 420
    height: 780
    visible: true
    color: "#000000"

    property var status: new Object({isEditCar: true},
                                    {isEditEvent: true},
                                    {isEditService: true},
                                    {isEditRefueling: true},
                                    {chosenCarId: 0},
                                    {chosenEventId: 0},
                                    {fromWindow: "main"});

    Loader {
        id: _loader
        function reload() {
            source = "";
            $QmlEngine.clearCache();
            source = "CarCard.qml";
        }
        anchors.fill: parent

        source: "CarCard.qml"
    }


}


