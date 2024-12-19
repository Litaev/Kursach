import QtQuick 2.12
import QtQuick.Controls 2.15

ListView{
    id: eventsListView
    anchors.fill: parent
    spacing: 5
    model: eventListElementModel
    clip: true

    delegate: Rectangle {
        anchors.left: parent.left
        anchors.right: parent.right
        height: 150
        color: event_type == 0 ? "#ADB5BD" : "#6C757D"
        radius: 10
        Image {
            id: eventImage
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.top: parent.top
            anchors.topMargin: 5
            width: 40
            height: width
            sourceSize: Qt.size(width, width)
            fillMode: Image.PreserveAspectFit
            source: event_type == 0 ? "qrc:/test11/icons/service_white_icon.png" : "qrc:/test11/icons/fuel_white_icon.png"
        }

        Button{
            id: editEventButton
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            hoverEnabled: false
            height: 40
            width: 70
            onClicked: {
                status.chosenEventId = index;
                mainWindow.hour = parseInt(user.getInfoAboutEvent(user.getUserChosenCarId(), status.chosenEventId, "eventHour"));
                mainWindow.minute = parseInt(user.getInfoAboutEvent(user.getUserChosenCarId(), status.chosenEventId, "eventMinute"));
                mainWindow.year = parseInt(user.getInfoAboutEvent(user.getUserChosenCarId(), status.chosenEventId, "eventYear"));
                mainWindow.month = parseInt(user.getInfoAboutEvent(user.getUserChosenCarId(), status.chosenEventId, "eventMonth"));
                mainWindow.day = parseInt(user.getInfoAboutEvent(user.getUserChosenCarId(), status.chosenEventId, "eventDay"));
                if (event_type == 0){
                    status.isEditService = true;
                    stackView.push("qrc:/test11/Qml/ServiceWindow.qml");
                }
                else if (event_type == 1){
                    status.isEditRefueling = true;
                    stackView.push("qrc:/test11/Qml/RefuelingWindow.qml");
                }
            }
            background: Rectangle{
                anchors.fill: parent
                color: editEventButton.down ? "#01497c" : "#E9ECEF"
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
            id: deleteEventButton
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
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
                color: deleteEventButton.down ? "#01497c" : "#D90429"
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
                text: "Are you sure to DELETE this event?"
            }
            onAccepted: {
                user.deleteChosenEvent(index);
                user.saveUserData();
                eventsWindow.updateModel();
                _loader.reload();
            }
            onRejected: confirmationDialog.close()
        }



        Rectangle{
            id: eventNameRect
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.left: eventImage.right
            anchors.leftMargin: 5
            anchors.right: editEventButton.left
            anchors.rightMargin: 5
            height: 40
            color: "#DEE2E6"
            radius: 10
            Text{
                anchors.fill: parent
                color: "#000000"
                font.pointSize: 20
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: event_name
            }
        }
        Rectangle{
            id: eventMileageRect
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 5
            width: 140
            height: 40
            color: "#343A40"
            radius: 10
            Text{
                anchors.fill: parent
                color: "#ffffff"
                font.pointSize: 20
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: event_mileage + " km"
            }
        }

        Rectangle{
            id: eventPriceRect
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: eventMileageRect.right
            anchors.leftMargin: 5
            width: 150
            height: 40
            color: "#CED4DA"
            radius: 10
            Text{
                anchors.fill: parent
                color: "#000000"
                font.pointSize: 16
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: event_price.toFixed(2) + " BYN"
            }
        }
        Rectangle{
            id: eventDataRect
            anchors.top: eventImage.bottom
            anchors.topMargin: 5
            anchors.bottom: eventMileageRect.top
            anchors.bottomMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 5
            width: 200
            color: "#CED4DA"
            radius: 10
            Text{
                anchors.fill: parent
                color: "#000000"
                font.pointSize: 20
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: event_date
            }
        }


    }
}

