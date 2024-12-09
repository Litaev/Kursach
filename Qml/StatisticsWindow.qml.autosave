import QtQuick 2.12
import QtQuick.Controls 2.12
import QtCharts 2.12


Item {
    visible: true
    clip: false
    width: parent.width
    height: parent.height


    Rectangle{
        id: statisticsRect
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
            id: statisticsText
            anchors.fill: parent
            text: "Car Statistics"
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
    }

    ChartView {
        id: statisticsChart
        anchors.top: statisticsRect.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        title: "Money Distribution"
        height: 250
        legend.alignment: Qt.AlignRight
        backgroundColor: "#adb5bd"
        antialiasing: true
        PieSeries {
            id: statisticsPieSeries
            size: 1

        }
    }

    ChartView {
        id: serviceStatisticsChart
        anchors.top: statisticsChart.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        title: "Service Money Spent"
        height: 400
        legend.alignment: Qt.AlignRight
        backgroundColor: "#ced4da"
        antialiasing: true
        PieSeries {
            id: serviceStatisticsPieSeries
            size: 1

        }
    }
    Component.onCompleted: {
        statisticsPieSeries.append("Service<br>" + user.getInfoAboutCar(status.chosenCarId, "CarServiceMoney") + " BYN", parseFloat(user.getInfoAboutCar(status.chosenCarId, "CarServiceMoney")));
        statisticsPieSeries.append("Fuel<br>" + user.getInfoAboutCar(status.chosenCarId, "CarFuelMoney") + " BYN", parseFloat(user.getInfoAboutCar(status.chosenCarId, "CarFuelMoney")));
        statisticsPieSeries.append("Other<br>" + user.getInfoAboutCar(status.chosenCarId, "CarOtherMoney") + " BYN", parseFloat(user.getInfoAboutCar(status.chosenCarId, "CarOtherMoney")));

        serviceStatisticsPieSeries.append("Maintenance<br>" + user.getInfoAboutCar(status.chosenCarId, "CarServiceMaintenanceMoney") + " BYN", parseFloat(user.getInfoAboutCar(status.chosenCarId, "CarServiceMaintenanceMoney")));
        serviceStatisticsPieSeries.append("Repair<br>" + user.getInfoAboutCar(status.chosenCarId, "CarServiceRepairMoney") + " BYN", parseFloat(user.getInfoAboutCar(status.chosenCarId, "CarServiceRepairMoney")));
        serviceStatisticsPieSeries.append("Tuning<br>" + user.getInfoAboutCar(status.chosenCarId, "CarServiceTuningMoney") + " BYN", parseFloat(user.getInfoAboutCar(status.chosenCarId, "CarServiceTuningMoney")));
        serviceStatisticsPieSeries.append("Details<br>" + user.getInfoAboutCar(status.chosenCarId, "CarServiceDetailMoney") + " BYN", parseFloat(user.getInfoAboutCar(status.chosenCarId, "CarServiceDetailMoney")));
        serviceStatisticsPieSeries.append("Diagnostics<br>" + user.getInfoAboutCar(status.chosenCarId, "CarServiceDiagnosticsMoney") + " BYN", parseFloat(user.getInfoAboutCar(status.chosenCarId, "CarServiceDiagnosticsMoney")));
        serviceStatisticsPieSeries.append("Tire Fitting<br>" + user.getInfoAboutCar(status.chosenCarId, "CarServiceTireFittingMoney") + " BYN", parseFloat(user.getInfoAboutCar(status.chosenCarId, "CarServiceTireFittingMoney")));
        serviceStatisticsPieSeries.append("Other<br>" + user.getInfoAboutCar(status.chosenCarId, "CarServiceOtherMoney") + " BYN", parseFloat(user.getInfoAboutCar(status.chosenCarId, "CarServiceOtherMoney")));
    }




}
