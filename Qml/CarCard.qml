pragma ComponentBehavior: Bound

import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
ApplicationWindow{
    id: mainWindow
    color: "#000000"
    width: 420
    height: 780
    visible: true

    property int hour: parseInt(user.getInfoAboutEvent(user.getChosenCarId(), status.chosenEventId, "eventHour"));
    property int minute: parseInt(user.getInfoAboutEvent(user.getChosenCarId(), status.chosenEventId, "eventMinute"));
    property int year: parseInt(user.getInfoAboutEvent(user.getChosenCarId(), status.chosenEventId, "eventYear"));
    property int month: parseInt(user.getInfoAboutEvent(user.getChosenCarId(), status.chosenEventId, "eventMonth"));
    property int day: parseInt(user.getInfoAboutEvent(user.getChosenCarId(), status.chosenEventId, "eventDay"));

    onClosing:{
        close.accepted = false;
    }
    Component.onCompleted: {
        if (user.getCarListSize() == 0){
            stackView.push("qrc:/test11/Qml/ChooseCarWindow.qml")
        }
        else{
            user.updateChosenCarStatistics();
            chooseCarWindow.updateModel();
            eventsWindow.updateModel();
        }

    }
    StackView{
        id: stackView
        anchors.fill: parent
        initialItem: mainScreen

    }
    Item{
        id: mainScreen
        width: parent.width
        height: parent.height
        Rectangle{
            id: carMainRectangle
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.margins: 5
            height: 150
            color: "#212529"
            radius: 10

            Button{
                id: carImageButton
                visible: true
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.margins: 10
                width: 130
                height: width
                onClicked: {
                    user.setChosenCarImage(user.getChosenCarId());
                    user.saveUserData();
                    _loader.reload();
                }
                background: Image {
                    id: carImageIcon
                    anchors.fill: parent
                    sourceSize: Qt.size(width, width)
                    fillMode: Image.PreserveAspectCrop
                    source: user.getInfoAboutCar(user.getChosenCarId(), "imagePath") == "" ? "qrc:/test11/icons/car_white_icon.png": user.getInfoAboutCar(user.getChosenCarId(), "imagePath");
                }
            }



            Rectangle{
                id: carInfoRectangle
                anchors.top: parent.top
                anchors.left: carImageButton.right
                anchors.margins: 5
                width: parent.width - parent.height - 80
                height: 65
                color: "#495057"
                radius: 10
                Text {
                    id: carNameText
                    anchors.left: parent.left
                    anchors.leftMargin: 5
                    anchors.right: parent.right
                    anchors.rightMargin: 5
                    anchors.top: parent.top
                    anchors.topMargin: 5
                    height: 30
                    color: "#ffffff"
                    text: user.getInfoAboutCar(user.getChosenCarId(), "name")
                    font.pointSize: 16
                    verticalAlignment: Text.AlignVCenter
                }
                Text{
                    id: carYearText
                    anchors.left: parent.left
                    anchors.leftMargin: 5
                    anchors.right: parent.right
                    anchors.rightMargin: 5
                    anchors.top: carNameText.bottom
                    anchors.topMargin: 5
                    height: 30
                    color: "#ffffff"
                    text: user.getInfoAboutCar(user.getChosenCarId(), "year") + " year"
                    font.pointSize: 14
                    verticalAlignment: Text.AlignVCenter
                }

            }

            Rectangle{
                id: carMileageRectangle
                anchors.top: carInfoRectangle.bottom
                anchors.bottom: parent.bottom
                anchors.left: carImageButton.right
                anchors.leftMargin: 5
                anchors.topMargin: 5
                anchors.bottomMargin: 10
                width: (carInfoRectangle.width)/2
                radius: 10
                color: "#ADB5BD"
                Rectangle{
                    id: carMileageLabelRect
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.right: parent.right
                    height: 20
                    color: "#6C757D"
                    radius: 10
                    Text {
                        id: carMileageLabel
                        anchors.fill: parent
                        color: "#ffffff"
                        text: "Mileage"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pointSize: 12

                    }
                }
                Text {
                    id: carMileageEdit
                    anchors.top: carMileageLabelRect.bottom
                    anchors.bottom: parent.bottom
                    anchors.left: parent.left
                    anchors.right: parent.right
                    color: "#000000"
                    text: user.getInfoAboutCar(user.getChosenCarId(), "mileage") + " km"
                    font.pointSize: 14
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter

                }

            }
            Rectangle{
                id: carMoneySpentRectangle
                anchors.left: carMileageRectangle.right
                anchors.right: carInfoRectangle.right
                anchors.top: carInfoRectangle.bottom
                anchors.bottom: parent.bottom
                anchors.leftMargin: 5
                anchors.topMargin: 5
                anchors.bottomMargin: 10
                radius: 10
                color: "#adb5bd"
                Rectangle{
                    id: carMoneySpentRect
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.right: parent.right
                    height: 20
                    color: "#6c757d"
                    radius: 10
                    Text {
                        id: carMoneySpentText
                        anchors.fill: parent
                        color: "#000000"
                        text: "Money spent"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pointSize: 12

                    }
                }
                Text {
                    id: carMoneySpentEdit
                    anchors.top: carMoneySpentRect.bottom
                    anchors.bottom: parent.bottom
                    anchors.left: parent.left
                    anchors.right: parent.right
                    color: "#ffffff"
                    text: user.getInfoAboutCar(user.getChosenCarId(), "CarMoney") + " BYN"
                    font.pointSize: 16
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }

            Button{
                id: editCarButton
                anchors.top: parent.top
                anchors.topMargin: 5
                anchors.left: carInfoRectangle.right
                anchors.leftMargin: 5
                anchors.right: parent.right
                anchors.rightMargin: 5
                hoverEnabled: false
                height: 50
                onClicked: {
                    status.isEditCar = true;
                    stackView.push("qrc:/test11/Qml/CarWindow.qml");

                }
                background: Rectangle{
                    anchors.fill: parent
                    color: editCarButton.down ? "#01497c" : "#ADB5BD"
                    radius: 10
                    Text{
                       anchors.fill: parent
                       text: "EDIT"
                       color: "#000000"
                       font.pointSize: 16
                       horizontalAlignment: Text.AlignHCenter
                       verticalAlignment: Text.AlignVCenter
                    }
                }
            }
            Button{
                id: toGarageButton
                anchors.top: editCarButton.bottom
                anchors.topMargin: 5
                anchors.left: carInfoRectangle.right
                anchors.leftMargin: 5
                anchors.right: parent.right
                anchors.rightMargin: 5
                hoverEnabled: false
                height: 50
                onClicked: {
                    chooseCarWindow.updateModel();

                    stackView.push("qrc:/test11/Qml/ChooseCarWindow.qml");
                }
                background: Rectangle{
                    anchors.fill: parent
                    color: toGarageButton.down ? "#01497c" : "#6C757D"
                    radius: 10
                    Text{
                       anchors.fill: parent
                       text: "Garage"
                       color: "#ffffff"
                       font.pointSize: 14
                       horizontalAlignment: Text.AlignHCenter
                       verticalAlignment: Text.AlignVCenter
                    }
                }
            }

        }

        Rectangle{
            id: eventsTextRect
            anchors.top: carMainRectangle.bottom
            anchors.topMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            height: 50
            color: "#495057"

            Rectangle{
                id: eventsSortComboboxRect
                anchors.right: parent.right
                anchors.rightMargin: 5
                anchors.top: parent.top
                anchors.topMargin: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 5
                width: 110
                radius: 5
                ComboBox {
                    id: eventsSortCombobox
                    anchors.fill: parent
                    model: ["date","money"]
                    //currentIndex: status.isEditCar ? parseInt(user.getInfoAboutCar(user.getChosenCarId(), "fuel")) : 0;
                }

            }

            Button{
                id: eventsSortButton
                visible: true
                anchors.top: parent.top
                anchors.right: eventsSortComboboxRect.left
                anchors.margins: 5
                width: 40

                height: width
                onClicked: {
                    if (status.isSortFromNewest == true){
                        status.isSortFromNewest = false;
                        if (eventsSortCombobox.currentIndex == 0){
                            user.sortChosenCarEventListMax("date");
                        }
                        else if (eventsSortCombobox.currentIndex == 1){
                            user.sortChosenCarEventListMax("price");
                        }
                        eventsWindow.updateModel();
                        eventsSortImageIcon.source = "qrc:/test11/icons/sortBigger_white_icon.png";

                    }
                    else{
                        status.isSortFromNewest = true;
                        if (eventsSortCombobox.currentIndex == 0){
                            user.sortChosenCarEventListMin("date");
                        }
                        else if (eventsSortCombobox.currentIndex == 1){
                            user.sortChosenCarEventListMin("price");
                        }

                        eventsWindow.updateModel();
                        eventsSortImageIcon.source = "qrc:/test11/icons/sortSmaller_white_icon.png";

                    }


                }
                background: Image {
                    id: eventsSortImageIcon
                    anchors.fill: parent
                    sourceSize: Qt.size(width, width)
                    fillMode: Image.PreserveAspectCrop
                    source: status.isSortFromNewest ? "qrc:/test11/icons/sortSmaller_white_icon.png": "qrc:/test11/icons/sortBigger_white_icon.png";
                }
            }

            Text{
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                anchors.right: eventsSortButton.left
                text: "Last Events"
                color: "#ffffff"
                font.pointSize: 20
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

        }
        Rectangle{
            id: addButtonsRect
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            height: 40
            color: "#343A40"
            Button{
                id: addServiceButton
                visible: true
                anchors.right: parent.right
                anchors.rightMargin: 40
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.margins: 7
                width: 40
                height: width
                onClicked: {
                    status.isEditService = false;
                    mainWindow.hour = parseInt(user.getNowDate("hour"));
                    mainWindow.minute = parseInt(user.getNowDate("minute"));
                    mainWindow.year = parseInt(user.getNowDate("year"));
                    mainWindow.month = parseInt(user.getNowDate("month"));
                    mainWindow.day = parseInt(user.getNowDate("day"));
                    stackView.push("qrc:/test11/Qml/ServiceWindow.qml");
                }
                background: Image {
                    id: addServiceIcon
                    anchors.fill: parent
                    sourceSize: Qt.size(width, width)
                    fillMode: Image.PreserveAspectFit
                    source: "qrc:/test11/icons/add_service_white_icon.png"
                }
            }
            Rectangle{
                id: statsRect
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                width: 50
                height: width
                radius: 25
                color: "#ffffff"
                Button{
                    id: statsButton
                    visible: true
                    anchors.fill: parent
                    width: parent.width
                    height: width
                    onClicked: {
                        user.updateChosenCarStatistics();
                        stackView.push("qrc:/test11/Qml/StatisticsWindow.qml");
                    }
                    background: Image {
                        id: statsIcon
                        anchors.fill: parent
                        anchors.margins: 13
                        sourceSize: Qt.size(width, width)
                        fillMode: Image.PreserveAspectFit
                        source: "qrc:/test11/icons/stats_black_icon.png"
                    }
                }
            }


            Button{
                id: addRefuelingButton
                visible: true
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 40
                anchors.bottom: parent.bottom
                anchors.margins: 7
                width: 40
                height: width
                onClicked: {
                    status.isEditRefueling = false;

                    mainWindow.hour = parseInt(user.getNowDate("hour"));
                    mainWindow.minute = parseInt(user.getNowDate("minute"));
                    mainWindow.year = parseInt(user.getNowDate("year"));
                    mainWindow.month = parseInt(user.getNowDate("month"));
                    mainWindow.day = parseInt(user.getNowDate("day"));

                    stackView.push("qrc:/test11/Qml/RefuelingWindow.qml");
                }
                background: Image {
                    id: addRefuelingIcon
                    anchors.fill: parent
                    sourceSize: Qt.size(width, width)
                    fillMode: Image.PreserveAspectFit
                    source: "qrc:/test11/icons/add_refueling_white_icon.png"
                }
            }
        }

        ScrollView{
            id: eventListScrollview
            anchors.top: eventsTextRect.bottom
            anchors.topMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            anchors.bottom: addButtonsRect.top
            anchors.bottomMargin: 10
            EventsList{
                anchors.fill: parent

            }
        }
    }

}





