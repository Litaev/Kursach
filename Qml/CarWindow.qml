import QtQuick
import QtQuick.Layouts 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs

Item {
    id: carWindowItem
    visible: true
    clip: false
    width: parent.width
    height: parent.height


    property string errorMessage: ""
    property int isCarNameGood: 0
    property int isCarYearGood: 0
    property int isCarMileageGood: 0
    property int isCarTankVolumeGood: 0

    function confirmAction(){
        if (isCarNameGood + isCarYearGood + isCarMileageGood + isCarTankVolumeGood == 0){
            if (status.isEditCar == false){
                user.addCar(carNameTextField.text, carYearTextField.text, carMileageTextField.text, carFuelTypeComboBox.currentIndex, carTankTextField.text);
                chooseCarWindow.updateModel();
            }
            else{
                user.editChosenCarInfo(carNameTextField.text, carYearTextField.text, carMileageTextField.text, carFuelTypeComboBox.currentIndex, carTankTextField.text);
                chooseCarWindow.updateModel();
                _loader.reload();
            }
            stackView.pop();
            user.saveUserData();
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
            id: errorDialogLabel
            text: qsTr("Data is INCORRECT")
        }
    }
    ToolTip{
        id: toolTip
        text: "ERROR"
    }

    Rectangle{
        id: carRect
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
            id: carText
            anchors.fill: parent
            text: status.isEditCar ? "Edit Car" : "Add New Car"
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
        id: carNameRect
        anchors.top: carRect.bottom
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        height: 70
        color: "#6C757D"
        radius: 10
        Image {
            id: carNameImage
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.top: parent.top
            anchors.topMargin: 5
            width: 60
            height: width
            sourceSize: Qt.size(width, width)
            fillMode: Image.PreserveAspectFit
            source: "qrc:/test11/icons/car_white_icon.png"
        }
        Rectangle{
            id: carNameTextRect
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: carNameImage.right
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            color: "#ADB5BD"
            radius: 10
            TextField{
                id: carNameTextField
                anchors.fill: parent
                color: "#000000"
                placeholderText: "Enter Car Name"
                text: status.isEditCar ? user.getInfoAboutCar(user.getUserChosenCarId(), "name") : ""
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 16
                onEditingFinished:{
                    carWindowItem.errorMessage = myValidator.validateCarWindow("carName", carNameTextField.text);
                    if (carWindowItem.errorMessage != ""){
                        carWindowItem.isCarNameGood = 1;
                        toolTip.timeout = 5000;
                        toolTip.visible = true;
                        toolTip.text = carWindowItem.errorMessage;
                        toolTip.open();
                        carNameTextField.color = "#da2c38"
                    }
                    else{
                        carWindowItem.isCarNameGood = 0;
                        carNameTextField.color = "#000000"
                    }
                }
            }
        }

    }
    Rectangle{
        id: carYearRect
        anchors.top: carNameRect.bottom
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        width: (parent.width - 15) / 2
        height: 70
        color: "#6C757D"
        radius: 10
        Image {
            id: carYearImage
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.top: parent.top
            anchors.topMargin: 5
            width: 60
            height: width
            sourceSize: Qt.size(width, width)
            fillMode: Image.PreserveAspectFit
            source: "qrc:/test11/icons/year_white_icon.png"
        }
        Rectangle{
            id: carYearTextRect
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: carYearImage.right
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            color: "#F8F9FA"
            radius: 10
            TextField{
                id: carYearTextField
                anchors.fill: parent
                color: "#000000"
                placeholderText: "Car Year"
                text: status.isEditCar ? user.getInfoAboutCar(user.getUserChosenCarId(), "year") : ""
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 16
                inputMethodHints: Qt.ImhDigitsOnly
                onEditingFinished:{
                    carWindowItem.errorMessage = myValidator.validateCarWindow("carYear", carYearTextField.text);
                    if (carWindowItem.errorMessage != ""){
                        carWindowItem.isCarYearGood = 1;
                        toolTip.timeout = 5000;
                        toolTip.visible = true;
                        toolTip.text = carWindowItem.errorMessage;
                        toolTip.open();
                        carYearTextField.color = "#da2c38"
                    }
                    else{
                        carWindowItem.isCarYearGood = 0;
                        carYearTextField.color = "#000000"
                    }
                }
            }
        }
    }
    Rectangle{
        id: carMileageRect
        anchors.top: carNameRect.bottom
        anchors.topMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        width: (parent.width - 15) / 2
        height: 70
        color: "#495057"
        radius: 10
        Image {
            id: carMileageImage
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
            id: carMileageTextRect
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: carMileageImage.right
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            color: "#ADB5BD"
            radius: 10
            TextField{
                id: carMileageTextField
                anchors.fill: parent
                color: "#000000"
                placeholderText: "Car Mileage"
                text: status.isEditCar ? user.getInfoAboutCar(user.getUserChosenCarId(), "mileage") : ""
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 16
                inputMethodHints: Qt.ImhDigitsOnly
                onEditingFinished:{
                    carWindowItem.errorMessage = myValidator.validateCarWindow("carMileage", carMileageTextField.text);
                    if (carWindowItem.errorMessage != ""){
                        carWindowItem.isCarMileageGood = 1;
                        toolTip.timeout = 5000;
                        toolTip.visible = true;
                        toolTip.text = carWindowItem.errorMessage;
                        toolTip.open();
                        carMileageTextField.color = "#da2c38"
                    }
                    else{
                        carWindowItem.isCarMileageGood = 0;
                        carMileageTextField.color = "#000000"
                    }
                }
            }
        }

    }

    Rectangle{
        id: carFuelRect
        anchors.top: carYearRect.bottom
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        width: (parent.width - 15) / 2
        height: 70
        color: "#495057"
        radius: 10
        Image {
            id: carFuelImage
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.top: parent.top
            anchors.topMargin: 5
            width: 60
            height: width
            sourceSize: Qt.size(width, width)
            fillMode: Image.PreserveAspectFit
            source: "qrc:/test11/icons/fuel_white_icon.png"
        }
        Rectangle{
            id: carFuelTextRect
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: carFuelImage.right
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            color: "#CED4DA"
            radius: 10
            ComboBox{
                id: carFuelTypeComboBox
                width: parent.width
                model: ["petrol", "diesel", "propane", "methane", "electrycity"]
                currentIndex: status.isEditCar ? parseInt(user.getInfoAboutCar(user.getUserChosenCarId(), "fuel")) : 0;
            }
        }

    }

    Rectangle{
        id: carTankRect
        anchors.top: carMileageRect.bottom
        anchors.topMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        width: (parent.width - 15) / 2
        height: 70
        color: "#6C757D"
        radius: 10
        Image {
            id: carTankImage
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
            id: carTankTextRect
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: carTankImage.right
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            color: "#F8F9FA"
            radius: 10
            TextField{
                id: carTankTextField
                anchors.fill: parent
                color: "#000000"
                placeholderText: "Tank Volume"
                text: status.isEditCar ? user.getInfoAboutCar(user.getUserChosenCarId(), "tank") : ""
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 16
                inputMethodHints: Qt.ImhDigitsOnly
                onEditingFinished:{
                    carWindowItem.errorMessage = myValidator.validateCarWindow("carTankVolume", carTankTextField.text);
                    if (carWindowItem.errorMessage != ""){
                        carWindowItem.isCarTankVolumeGood = 1;
                        toolTip.timeout = 5000;
                        toolTip.visible = true;
                        toolTip.text = carWindowItem.errorMessage;
                        toolTip.open();
                        carTankTextField.color = "#da2c38"
                    }
                    else{
                        carWindowItem.isCarTankVolumeGood = 0;
                        carTankTextField.color = "#000000"

                    }
                }
            }
        }

    }

}
