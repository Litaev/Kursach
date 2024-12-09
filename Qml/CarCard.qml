pragma ComponentBehavior: Bound

import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
ApplicationWindow{
    color: "#000000"
    width: 420
    height: 780
    visible: true
    onClosing:{
        close.accepted = false;
    }
    Component.onCompleted: {
        if (user.getCarListSize() == 0){
            stackView.push("qrc:/test11/Qml/ChooseCarWindow.qml")
        }
        else{
            user.updateChosenCarStatistics();
            status.chosenCarID = user.getChosenCarId();
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
                width: parent.height - 20
                height: width
                onClicked: {
                    user.setChosenCarImage(status.chosenCarId);
                    user.saveUserData();
                    _loader.reload();
                }
                background: Image {
                    id: carImageIcon
                    sourceSize: Qt.size(width, width)
                    fillMode: Image.PreserveAspectCrop
                    source: user.getInfoAboutCar(status.chosenCarId, "imagePath");
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
                    status.fromWindow = "main";
                    status.isEditCar = true;
                    status.chosenCarId = user.getChosenCarId();
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
                    status.fromWindow = "main";
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
            height: 40
            color: "#495057"
            Text{
                anchors.fill: parent
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





