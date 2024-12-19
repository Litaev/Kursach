import QtQuick
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Item{
    id: serviceWindowItem
    visible: true
    clip: false
    width: parent.width
    height: parent.height

    property string errorMessage: ""
    property int isEventNameGood: 0
    property int isEventPriceGood: 0
    property int isEventMileageGood: 0
    property int isEventDateGood: 0
    property int isEventTimeGood: 0


    function confirmAction(){
        if (isEventNameGood + isEventPriceGood + isEventMileageGood + isEventDateGood + isEventTimeGood == 0){
            if (status.isEditService == false){
                user.addEvent(0, serviceNameTextField.text, servicePriceTextField.text, serviceDateButton.text + "-" + serviceTimeButton.text, serviceMileageTextField.text, serviceCommentTextField.text, serviceTypeComboBox.currentIndex, "", "");
            }
            else{
                user.editChosenEventInfo(status.chosenEventId, 0, serviceNameTextField.text, servicePriceTextField.text, serviceDateButton.text + "-" + serviceTimeButton.text, serviceMileageTextField.text, serviceCommentTextField.text, "", "", "", serviceTypeComboBox.currentIndex);
            }
            user.saveUserData();
            eventsWindow.updateModel();
            _loader.reload();
            stackView.pop();
        }
        else{
            errorDialog.open();
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
    ToolTip{
        id: toolTip
        text: "ERROR"
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
                currentIndex: status.isEditService ? parseInt(user.getInfoAboutEvent(user.getUserChosenCarId(), status.chosenEventId, "serviceType")) : 0;
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
                text: status.isEditService ? user.getInfoAboutEvent(user.getUserChosenCarId(), status.chosenEventId, "name") : ""
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 16
                onEditingFinished:{
                    serviceWindowItem.errorMessage = myValidator.validateEventWindow("eventName", serviceNameTextField.text);
                    if (serviceWindowItem.errorMessage != ""){
                        serviceWindowItem.isEventNameGood = 1;
                        toolTip.timeout = 5000;
                        toolTip.visible = true;
                        toolTip.text = serviceWindowItem.errorMessage;
                        toolTip.open();
                        serviceNameTextField.color = "#da2c38"
                    }
                    else{
                        serviceWindowItem.isEventNameGood = 0;
                        serviceNameTextField.color = "#000000"
                    }
                }
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
                text: status.isEditService ? user.getInfoAboutEvent(user.getUserChosenCarId(), status.chosenEventId, "money") : ""
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 16
                inputMethodHints: Qt.ImhDigitsOnly

                onEditingFinished:{
                    serviceWindowItem.errorMessage = myValidator.validateEventWindow("eventPrice", servicePriceTextField.text);
                    if (serviceWindowItem.errorMessage != ""){
                        serviceWindowItem.isEventPriceGood = 1;
                        toolTip.timeout = 5000;
                        toolTip.visible = true;
                        toolTip.text = serviceWindowItem.errorMessage;
                        toolTip.open();
                        servicePriceTextField.color = "#da2c38"
                    }
                    else{
                        serviceWindowItem.isEventPriceGood = 0;
                        servicePriceTextField.color = "#000000"
                    }
                }
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
                text: status.isEditService ? user.getInfoAboutEvent(user.getUserChosenCarId(), status.chosenEventId, "mileage") : ""
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 16
                inputMethodHints: Qt.ImhDigitsOnly

                onEditingFinished:{
                    serviceWindowItem.errorMessage = myValidator.validateEventWindow("eventMileage", serviceMileageTextField.text);
                    if (serviceWindowItem.errorMessage != ""){
                        serviceWindowItem.isEventMileageGood = 1;
                        toolTip.timeout = 5000;
                        toolTip.visible = true;
                        toolTip.text = serviceWindowItem.errorMessage;
                        toolTip.open();
                        serviceMileageTextField.color = "#da2c38"
                    }
                    else{
                        serviceWindowItem.isEventMileageGood = 0;
                        serviceMileageTextField.color = "#000000"
                    }
                }
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
                text: status.isEditService ? user.getInfoAboutEvent(user.getUserChosenCarId(), status.chosenEventId, "comment") : ""
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
        Button{
            id: serviceDateButton
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: serviceDateImage.right
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            text: {
                if (mainWindow.day < 10){
                    if(mainWindow.month < 10){
                        "0" + mainWindow.day + "-" + "0" + mainWindow.month + "-" + mainWindow.year
                    }
                    else {
                        "0" + mainWindow.day + "-" + mainWindow.month + "-" + mainWindow.year
                    }
                }
                else{
                    if(mainWindow.month < 10){
                        mainWindow.day + "-" + "0" + mainWindow.month + "-" + mainWindow.year
                    }
                    else {
                        mainWindow.day + "-" + mainWindow.month + "-" + mainWindow.year
                    }
                }
            }
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 16
            onClicked:{
                datePicker.open();
            }
            onTextChanged:{
                serviceWindowItem.errorMessage = myValidator.validateEventWindow("eventDate", serviceDateButton.text + "-" + serviceTimeButton.text);
                if (serviceWindowItem.errorMessage != ""){
                    serviceWindowItem.isEventDateGood = 1;
                    toolTip.timeout = 5000;
                    toolTip.visible = true;
                    toolTip.text = serviceWindowItem.errorMessage;
                    toolTip.open();

                }
                else{
                    serviceWindowItem.isEventDateGood = 0;

                }
            }

        }
        DatePicker{
            id: datePicker
        }

    }

    Rectangle{
        id: serviceTimeRect
        anchors.top: serviceDateRect.bottom
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        height: 70
        color: "#6C757D"
        radius: 10
        Image {
            id: serviceTimeImage
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.top: parent.top
            anchors.topMargin: 5
            width: 60
            height: width
            sourceSize: Qt.size(width, width)
            fillMode: Image.PreserveAspectFit
            source: "qrc:/test11/icons/time_white_icon.png"
        }
        Button{
            id: serviceTimeButton
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: serviceTimeImage.right
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            text: {
                if (mainWindow.hour < 10){

                    if(mainWindow.minute < 10){
                        "0" + mainWindow.hour + ":" + "0" + mainWindow.minute
                    }
                    else {
                        "0" + mainWindow.hour + ":" + mainWindow.minute
                    }
                }
                else{
                    if(mainWindow.minute < 10){
                        mainWindow.hour + ":" + "0" + mainWindow.minute
                    }
                    else {
                        mainWindow.hour + ":" + mainWindow.minute
                    }
                }

            }
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 16
            onClicked:{
                timePicker.open();
            }

        }

        TimePicker{
            id: timePicker
        }

    }



}
