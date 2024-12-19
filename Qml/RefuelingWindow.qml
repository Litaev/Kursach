import QtQuick
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Item {
    id: refuelingWindowItem
    visible: true
    clip: false
    width: parent.width
    height: parent.height

    property string errorMessage: ""
    property int isEventPriceGood: 0
    property int isEventLitreAmountGood: 0
    property int isEventDateGood: 0
    property int isEventTimeGood: 0
    property int isEventMileageGood: 0

    function confirmAction(){
        if (isEventPriceGood + isEventLitreAmountGood + isEventDateGood + isEventTimeGood + isEventMileageGood == 0){
            if (status.isEditRefueling == false){
                user.addEvent(1, "Refueling", refuelingPriceTextField.text, refuelingDateButton.text + "-" + refuelingTimeButton.text, refuelingMileageTextField.text, refuelingCommentTextField.text, 0, refuelingLitreAmountTextField.text, pricePerLitreTextField.text);
            }
            else{
                user.editChosenEventInfo(status.chosenEventId, 1, "Refueling", refuelingPriceTextField.text, refuelingDateButton.text + "-" + refuelingTimeButton.text, refuelingMileageTextField.text, refuelingCommentTextField.text, refuelingLitreAmountTextField.text, pricePerLitreTextField.text, 0);
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
        id: refuelingRect
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
            id: refuelingText
            anchors.fill: parent
            text: status.isEditRefueling ? "Edit Refueling" : "Add Refueling"
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
        id: refuelingLitreAmountRect
        anchors.top: refuelingRect.bottom
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        width: (parent.width - 15) / 2
        height: 70
        color: "#6C757D"
        radius: 10
        Image {
            id: refuelingLitreAmountImage
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.top: parent.top
            anchors.topMargin: 5
            width: 60
            height: width
            sourceSize: Qt.size(width, width)
            fillMode: Image.PreserveAspectFit
            source: "qrc:/test11/icons/fuelTank_white_icon.png"
        }
        Rectangle{
            id: refuelingLitreAmountTextRect
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: refuelingLitreAmountImage.right
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            color: "#F8F9FA"
            radius: 10
            TextField{
                id: refuelingLitreAmountTextField
                anchors.fill: parent
                color: "#000000"
                placeholderText: "Litre amount"
                text: status.isEditRefueling ? user.getInfoAboutEvent(user.getUserChosenCarId(), status.chosenEventId, "litres") : ""
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 16
                inputMethodHints: Qt.ImhDigitsOnly
                onEditingFinished: {
                    if (pricePerLitreTextField.text != ""){
                        if (!isNaN(parseFloat(refuelingLitreAmountTextField.text)*parseFloat(pricePerLitreTextField.text))){
                            refuelingPriceTextField.text = (parseFloat(refuelingLitreAmountTextField.text)*parseFloat(pricePerLitreTextField.text)).toFixed(2)

                        }


                    }
                    else if (refuelingPriceTextField.text != ""){
                        if (!isNaN(parseFloat(refuelingPriceTextField.text)/parseFloat(refuelingLitreAmountTextField.text))){
                            pricePerLitreTextField.text = (parseFloat(refuelingPriceTextField.text)/parseFloat(refuelingLitreAmountTextField.text)).toFixed(2)
                        }
                    }
                    refuelingWindowItem.errorMessage = myValidator.validateEventWindow("eventLitresAmount", refuelingLitreAmountTextField.text);
                    if (refuelingWindowItem.errorMessage != ""){
                        refuelingWindowItem.isEventLitreAmountGood = 1;
                        toolTip.timeout = 5000;
                        toolTip.visible = true;
                        toolTip.text = refuelingWindowItem.errorMessage;
                        toolTip.open();
                        refuelingLitreAmountTextField.color = "#da2c38"
                    }
                    else{
                        refuelingWindowItem.isEventLitreAmountGood = 0;
                        refuelingLitreAmountTextField.color = "#000000"
                    }

                }


            }
        }

    }

    Rectangle{
        id: pricePerLitreRect
        anchors.top: refuelingRect.bottom
        anchors.topMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        width: (parent.width - 15) / 2
        height: 70
        color: "#ADB5BD"
        radius: 10
        Image {
            id: pricePerLitreImage
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.top: parent.top
            anchors.topMargin: 5
            width: 60
            height: width
            sourceSize: Qt.size(width, width)
            fillMode: Image.PreserveAspectFit
            source: "qrc:/test11/icons/fuelPistol_white_icon.png"
        }
        Rectangle{
            id: pricePerLitreTextRect
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: pricePerLitreImage.right
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            color: "#F8F9FA"
            radius: 10
            TextField{
                id: pricePerLitreTextField
                anchors.fill: parent
                color: "#000000"
                placeholderText: "Price per litre"
                text: status.isEditRefueling ? user.getInfoAboutEvent(user.getUserChosenCarId(), status.chosenEventId, "pricePerLitre") : ""
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 16
                inputMethodHints: Qt.ImhDigitsOnly
                onEditingFinished: {
                    if (refuelingLitreAmountTextField.text != ""){
                        if (!isNaN(parseFloat(refuelingLitreAmountTextField.text)*parseFloat(pricePerLitreTextField.text))){
                           refuelingPriceTextField.text = (parseFloat(refuelingLitreAmountTextField.text)*parseFloat(pricePerLitreTextField.text)).toFixed(2)
                        }

                    }
                    else if (refuelingPriceTextField.text != ""){
                        if (!isNaN(parseFloat(refuelingPriceTextField.text)/parseFloat(pricePerLitreTextField.text))){
                            refuelingLitreAmountTextField.text = (parseFloat(refuelingPriceTextField.text)/parseFloat(pricePerLitreTextField.text)).toFixed(2)
                        }


                    }
                }
            }
        }
    }

    Rectangle{
        id: refuelingMileageRect
        anchors.top: refuelingLitreAmountRect.bottom
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        width: (parent.width - 15) / 2
        height: 70
        color: "#495057"
        radius: 10
        Image {
            id: refuelingMileageImage
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
            id: refuelingMileageTextRect
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: refuelingMileageImage.right
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            color: "#ADB5BD"
            radius: 10
            TextField{
                id: refuelingMileageTextField
                anchors.fill: parent
                color: "#000000"
                placeholderText: "Mileage"
                text: status.isEditRefueling ? user.getInfoAboutEvent(user.getUserChosenCarId(), status.chosenEventId, "mileage") : ""
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 16
                inputMethodHints: Qt.ImhDigitsOnly
                onEditingFinished:{
                    refuelingWindowItem.errorMessage = myValidator.validateEventWindow("eventMileage", refuelingMileageTextField.text);
                    if (refuelingWindowItem.errorMessage != ""){
                        refuelingWindowItem.isEventMileageGood = 1;
                        toolTip.timeout = 5000;
                        toolTip.visible = true;
                        toolTip.text = refuelingWindowItem.errorMessage;
                        toolTip.open();
                        refuelingMileageTextField.color = "#da2c38"
                    }
                    else{
                        refuelingWindowItem.isEventMileageGood = 0;
                        refuelingMileageTextField.color = "#000000"
                    }
                }
            }
        }

    }

    Rectangle{
        id: refuelingPriceRect
        anchors.top: pricePerLitreRect.bottom
        anchors.topMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        width: (parent.width - 15) / 2
        height: 70
        color: "#6C757D"
        radius: 10
        Image {
            id: refuelingPriceImage
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
            id: refuelingPriceTextRect
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: refuelingPriceImage.right
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            color: "#CED4DA"
            radius: 10
            TextField{
                id: refuelingPriceTextField
                anchors.fill: parent
                color: "#000000"
                placeholderText: "Price"
                text: status.isEditRefueling ? user.getInfoAboutEvent(user.getUserChosenCarId(), status.chosenEventId, "money") : ""
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 16
                inputMethodHints: Qt.ImhDigitsOnly
                onEditingFinished: {
                    if (refuelingLitreAmountTextField.text != ""){
                        if (!isNaN(parseFloat(refuelingPriceTextField.text)/parseFloat(refuelingLitreAmountTextField.text))){
                            pricePerLitreTextField.text = (parseFloat(refuelingPriceTextField.text)/parseFloat(refuelingLitreAmountTextField.text)).toFixed(2)
                        }
                    }
                    else if (pricePerLitreTextField.text != ""){
                        if (!isNaN(parseFloat(refuelingPriceTextField.text)/parseFloat(pricePerLitreTextField.text))){
                            refuelingLitreAmountTextField.text = (parseFloat(refuelingPriceTextField.text)/parseFloat(pricePerLitreTextField.text)).toFixed(2)
                        }
                    }
                    refuelingWindowItem.errorMessage = myValidator.validateEventWindow("eventPrice", refuelingPriceTextField.text);
                    if (refuelingWindowItem.errorMessage != ""){
                        refuelingWindowItem.isEventPriceGood = 1;
                        toolTip.timeout = 5000;
                        toolTip.visible = true;
                        toolTip.text = refuelingWindowItem.errorMessage;
                        toolTip.open();
                        refuelingPriceTextField.color = "#da2c38"
                    }
                    else{
                        refuelingWindowItem.isEventPriceGood = 0;
                        refuelingPriceTextField.color = "#000000"
                    }
                }

            }
        }
    }

    Rectangle{
        id: refuelingCommentRect
        anchors.top: refuelingMileageRect.bottom
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        height: 70
        color: "#ADB5BD"
        radius: 10
        Image {
            id: refuelingCommentImage
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
            id: refuelingCommentTextRect
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: refuelingCommentImage.right
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            color: "#F8F9FA"
            radius: 10
            TextField{
                id: refuelingCommentTextField
                anchors.fill: parent
                color: "#000000"
                placeholderText: "Refueling comment"
                text: status.isEditRefueling ? user.getInfoAboutEvent(user.getUserChosenCarId(), status.chosenEventId, "comment") : ""
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 16
            }
        }
    }

    Rectangle{
        id: refuelingDateRect
        anchors.top: refuelingCommentRect.bottom
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        height: 70
        color: "#6C757D"
        radius: 10
        Image {
            id: refuelingDateImage
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
            id: refuelingDateButton
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: refuelingDateImage.right
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5

            text: {
                if (mainWindow.day < 10){
                    if(mainWindow.month  < 10){
                        "0" + mainWindow.day + "-" + "0" + mainWindow.month + "-" + mainWindow.year
                    }
                    else {
                        "0" + mainWindow.day + "-" + mainWindow.month + "-" + mainWindow.year
                    }
                }
                else{
                    if((mainWindow.month + 1) < 10){
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
                refuelingWindowItem.errorMessage = myValidator.validateEventWindow("eventDate", refuelingDateButton.text + "-" + refuelingTimeButton.text);
                if (refuelingWindowItem.errorMessage != ""){
                    refuelingWindowItem.isEventDateGood = 1;
                    toolTip.timeout = 5000;
                    toolTip.visible = true;
                    toolTip.text = refuelingWindowItem.errorMessage;
                    toolTip.open();

                }
                else{
                    refuelingWindowItem.isEventDateGood = 0;

                }
            }
        }
        DatePicker{
            id: datePicker
        }

    }

    Rectangle{
        id: refuelingTimeRect
        anchors.top: refuelingDateRect.bottom
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        height: 70
        color: "#6C757D"
        radius: 10
        Image {
            id: refuelingTimeImage
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
            id: refuelingTimeButton
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: refuelingTimeImage.right
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
