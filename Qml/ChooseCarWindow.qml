
import QtQuick
import QtQuick.Layouts 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Item {
    id: chooseCarItem
    visible: true
    clip: false
    width: parent.width
    height: parent.height


    Component.onCompleted: {
        if (user.getCarListSize() == 0){
            backButton.visible = false;
            status.isEditCar = false;
        }
        else{
            backButton.visible = true;
        }
    }

    Rectangle{
        id: yourCarsText
        anchors.top: parent.top
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        radius: 5
        height: 50
        color: "#495057"
        Text{
            anchors.fill: parent
            text: "Garage"
            color: "#ffffff"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 20
        }

        Button{
            id: backButton
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.margins: 7
            width: parent.height - 14
            height: width
            onClicked: stackView.pop()
            background: Image {
                id: backIcon
                sourceSize: Qt.size(width, width)
                fillMode: Image.PreserveAspectFit
                source: "qrc:/test11/icons/back_white_icon.png"
            }
        }
    }

    Button{
        id: newCarButton
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 15
        height: 50
        hoverEnabled: false
        onClicked: {
            status.isEditCar = false;
            stackView.push("qrc:/test11/Qml/CarWindow.qml");

        }
        background: Rectangle{
            anchors.fill: parent
            color: newCarButton.down ? "#01497c" : "#D90429"
            radius: 16

            Text{
                anchors.fill: parent
               text: "ADD NEW CAR"
               color: "#FFFFFF"
               font.pointSize: 16
               horizontalAlignment: Text.AlignHCenter
               verticalAlignment: Text.AlignVCenter
            }
        }
    }

    ListView{
        id: carsListView
        anchors.top: yourCarsText.bottom
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.bottom: newCarButton.top
        spacing: 5
        model: carListElementModel
        clip: true

        delegate: Rectangle {
            anchors.left: parent.left
            anchors.right: parent.right
            height: 150
            color: "#ADB5BD"
            radius: 20

            Image {
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.margins: 10
                width: 130
                height: width
                id: carImageInList
                sourceSize: Qt.size(width, width)
                fillMode: Image.PreserveAspectCrop
                source: imagePath == "" ? "qrc:/test11/icons/car_white_icon.png": imagePath;

            }

            Text{
                id: carNameText
                anchors.top: parent.top
                anchors.topMargin: 5
                anchors.left: carImageInList.right
                anchors.leftMargin: 5
                text: name
                font.pointSize: 24
            }
            Text{
                id: carYearText
                anchors.top: carNameText.bottom
                anchors.topMargin: 5
                anchors.left: carImageInList.right
                anchors.leftMargin: 5
                text: year + " year"
                font.pointSize: 20
            }
            Text{
                id: carMileageText
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 5
                anchors.left: carImageInList.right
                anchors.leftMargin: 5
                text: mileage + " km"
                font.pointSize: 18
                color: "#ffffff"
            }
            Button{
                id: selectButton
                anchors.right: parent.right
                anchors.rightMargin: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 5
                hoverEnabled: false
                width: 150
                height: 50
                onClicked: {
                    user.setUserChosenCarId(index);
                    user.saveUserData();
                    _loader.reload();
                    stackView.pop();

                }
                background: Rectangle{
                    anchors.fill: parent
                    color: selectButton.down ? "#01497c" : "#008000"
                    radius: 10
                    Text{
                        anchors.fill: parent
                       text: "SELECT"
                       color: "#ffffff"
                       font.pointSize: 28
                       horizontalAlignment: Text.AlignHCenter
                       verticalAlignment: Text.AlignVCenter
                    }
                }
            }
            Button{
                id: editInfoButton
                anchors.right: parent.right
                anchors.rightMargin: 5
                anchors.top: parent.top
                anchors.topMargin: 5
                width: 80
                height: 40
                hoverEnabled: false
                onClicked: {
                    status.isEditCar = true;
                    user.setUserChosenCarId(index)
                    stackView.push("qrc:/test11/Qml/CarWindow.qml");
                }

                background: Rectangle{
                    anchors.fill: parent
                    color: editInfoButton.down ? "#01497c" : "#E9ECEF"
                    radius: 16
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
                id: deleteCarButton
                anchors.top: editInfoButton.bottom
                anchors.topMargin: 5
                anchors.right: parent.right
                anchors.rightMargin: 5
                hoverEnabled: false
                height: 40
                width: 80
                onClicked: {
                    confirmationDialog.open();

                }
                background: Rectangle{
                    anchors.fill: parent
                    color: deleteCarButton.down ? "#01497c" : "#D90429"
                    radius: 10
                    Text{
                       anchors.fill: parent
                       text: "DELETE"
                       color: "#ffffff"
                       font.pointSize: 16
                       horizontalAlignment: Text.AlignHCenter
                       verticalAlignment: Text.AlignVCenter
                    }
                }
            }

            Dialog {
                id: confirmationDialog
                x: (parent.width - width) / 2
                y: (parent.height - height) / 2
                modal: true
                title: "Confirmation"
                standardButtons: Dialog.Yes | Dialog.No
                Text {
                    text: "Are you sure to DELETE this car?"
                }
                onAccepted: {
                    user.deleteChosenCar(index);
                    user.saveUserData();
                    eventsWindow.updateModel();
                    chooseCarWindow.updateModel();
                    _loader.reload();
                }
                onRejected: confirmationDialog.close()
            }



        }

    }


}
