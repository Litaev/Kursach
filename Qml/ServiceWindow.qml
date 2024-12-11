import QtQuick
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Item{
    id: serviceWindowItem
    visible: true
    clip: false
    width: parent.width
    height: parent.height


    function confirmAction(){
        if (status.isEditService == false){
            if (serviceNameTextField.text != "" && servicePriceTextField.text != "" && serviceMileageTextField.text != "" && serviceDateTextField.text != ""){
                user.addEvent(0, serviceNameTextField.text, servicePriceTextField.text, serviceDateTextField.text, serviceMileageTextField.text, serviceCommentTextField.text, serviceTypeComboBox.currentIndex, "", "");

                eventsWindow.updateModel();
                _loader.reload();
                stackView.pop();
            }
            else{
                errorDialog.open();
            }
        }
        else{
            if (serviceNameTextField.text != "" && servicePriceTextField.text != "" && serviceMileageTextField.text != "" && serviceDateTextField.text != ""){

                user.editChosenEventInfo(status.chosenEventId, 0, serviceNameTextField.text, servicePriceTextField.text, serviceDateTextField.text, serviceMileageTextField.text, serviceCommentTextField.text, "", "", "", serviceTypeComboBox.currentIndex);

                eventsWindow.updateModel();
                _loader.reload();
                stackView.pop();
            }
            else{
                errorDialog.open();
            }
        }

    }

    Dialog {
        id: errorDialog
        x: (parent.width - width) / 2
        y: (parent.height - height) / 2
        title: qsTr("ERROR")
        Label {
            text: qsTr("Data is not full")
        }
    }

    Rectangle{
        id: serviceRect
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
            id: serviceText
            anchors.fill: parent
            text: status.isEditService ? "Edit Service" : "Add Service Event"
            color: "#ffffff"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 20
        }

        Button{
            id: backButton
            visible: true
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.margins: 7
            width: parent.height - 14
            height: width
            onClicked: stackView.pop();
            background: Image {
                id: backIcon
                sourceSize: Qt.size(width, width)
                fillMode: Image.PreserveAspectFit
                source: "qrc:/test11/icons/back_white_icon.png"
            }
        }
        Button{
            id: confirmButton
            visible: true
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.margins: 7
            width: parent.height - 14
            height: width
            onClicked: confirmAction()

            background: Image {
                id: confirmIcon
                sourceSize: Qt.size(width, width)
                fillMode: Image.PreserveAspectFit
                source: "qrc:/test11/icons/confirm_white_icon.png"
            }
        }

    }

    Rectangle{
        id: serviceTypeRect
        anchors.top: serviceRect.bottom
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        height: 70
        color: "#6C757D"
        radius: 10
        Image {
            id: serviceTypeImage
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.top: parent.top
            anchors.topMargin: 5
            width: 60
            height: width
            sourceSize: Qt.size(width, width)
            fillMode: Image.PreserveAspectFit
            source: "qrc:/test11/icons/eventType_white_icon.png"
        }
        Rectangle{
            id: serviceTypeTextRect
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: serviceTypeImage.right
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            color: "#ADB5BD"
            radius: 10
            ComboBox{
                id: serviceTypeComboBox
                width: parent.width
                model: ["maintenance", "repair", "tuning", "detail", "diagnostics", "tire fitting", "other service"]
                currentIndex: status.isEditService ? parseInt(user.getInfoAboutEvent(user.getChosenCarId(), status.chosenEventId, "serviceType")) : 0;
            }
        }

    }

    Rectangle{
        id: serviceNameRect
        anchors.top: serviceTypeRect.bottom
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        height: 70
        color: "#ADB5BD"
        radius: 10
        Image {
            id: serviceNameImage
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.top: parent.top
            anchors.topMargin: 5
            width: 60
            height: width
            sourceSize: Qt.size(width, width)
            fillMode: Image.PreserveAspectFit
            source: "qrc:/test11/icons/text_white_icon.png"
        }
        Rectangle{
            id: serviceNameTextRect
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: serviceNameImage.right
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            color: "#E9ECEF"
            radius: 10
            TextField{
                id: serviceNameTextField
                anchors.fill: parent
                color: "#000000"
                placeholderText: "Event name"
                text: status.isEditService ? user.getInfoAboutEvent(user.getChosenCarId(), status.chosenEventId, "name") : ""
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 16
            }
        }
    }
    Rectangle{
        id: servicePriceRect
        anchors.top: serviceNameRect.bottom
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        width: (parent.width - 15) / 2
        height: 70
        color: "#6C757D"
        radius: 10
        Image {
            id: servicePriceImage
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.top: parent.top
            anchors.topMargin: 5
            width: 60
            height: width
            sourceSize: Qt.size(width, width)
            fillMode: Image.PreserveAspectFit
            source: "qrc:/test11/icons/price_white_icon.png"
        }
        Rectangle{
            id: servicePriceTextRect
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: servicePriceImage.right
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            color: "#CED4DA"
            radius: 10
            TextField{
                id: servicePriceTextField
                anchors.fill: parent
                color: "#000000"
                placeholderText: "Price"
                text: status.isEditService ? user.getInfoAboutEvent(user.getChosenCarId(), status.chosenEventId, "money") : ""
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 16
                inputMethodHints: Qt.ImhDigitsOnly
            }
        }

    }

    Rectangle{
        id: serviceMileageRect
        anchors.top: serviceNameRect.bottom
        anchors.topMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        width: (parent.width - 15) / 2
        height: 70
        color: "#495057"
        radius: 10
        Image {
            id: serviceMileageImage
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.top: parent.top
            anchors.topMargin: 5
            width: 60
            height: width
            sourceSize: Qt.size(width, width)
            fillMode: Image.PreserveAspectFit
            source: "qrc:/test11/icons/mileage_white_icon.png"
        }
        Rectangle{
            id: serviceMileageTextRect
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: serviceMileageImage.right
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            color: "#ADB5BD"
            radius: 10
            TextField{
                id: serviceMileageTextField
                anchors.fill: parent
                color: "#000000"
                placeholderText: "Mileage"
                text: status.isEditService ? user.getInfoAboutEvent(user.getChosenCarId(), status.chosenEventId, "mileage") : ""
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 16
                inputMethodHints: Qt.ImhDigitsOnly
            }
        }
    }
    Rectangle{
        id: serviceCommentRect
        anchors.top: serviceMileageRect.bottom
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        height: 70
        color: "#ADB5BD"
        radius: 10
        Image {
            id: serviceCommentImage
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.top: parent.top
            anchors.topMargin: 5
            width: 60
            height: width
            sourceSize: Qt.size(width, width)
            fillMode: Image.PreserveAspectFit
            source: "qrc:/test11/icons/comment_white_icon.png"
        }
        Rectangle{
            id: serviceCommentTextRect
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: serviceCommentImage.right
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            color: "#E9ECEF"
            radius: 10
            TextField{
                id: serviceCommentTextField
                anchors.fill: parent
                color: "#000000"
                placeholderText: "Event comment"
                text: status.isEditService ? user.getInfoAboutEvent(user.getChosenCarId(), status.chosenEventId, "comment") : ""
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 16
            }
        }
    }

    Rectangle{
        id: serviceDateRect
        anchors.top: serviceCommentRect.bottom
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        height: 70
        color: "#6C757D"
        radius: 10
        Image {
            id: serviceDateImage
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.top: parent.top
            anchors.topMargin: 5
            width: 60
            height: width
            sourceSize: Qt.size(width, width)
            fillMode: Image.PreserveAspectFit
            source: "qrc:/test11/icons/date_white_icon.png"
        }
        Rectangle{
            id: serviceDateTextRect
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: serviceDateImage.right
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            color: "#DEE2E6"
            radius: 10
            TextField{
                id: serviceDateTextField
                anchors.fill: parent
                color: "#000000"
                placeholderText: "Date"
                text: status.isEditService ? user.getInfoAboutEvent(user.getChosenCarId(), status.chosenEventId, "date") : user.getNowDate();
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 16
            }
        }
    }



}
