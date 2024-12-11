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
        statisticsPieSeries.append("Service<br>" + user.getInfoAboutCar(user.getChosenCarId(), "CarServiceMoney") + " BYN", parseFloat(user.getInfoAboutCar(user.getChosenCarId(), "CarServiceMoney")));
        statisticsPieSeries.append("Fuel<br>" + user.getInfoAboutCar(user.getChosenCarId(), "CarFuelMoney") + " BYN", parseFloat(user.getInfoAboutCar(user.getChosenCarId(), "CarFuelMoney")));
        statisticsPieSeries.append("Other<br>" + user.getInfoAboutCar(user.getChosenCarId(), "CarOtherMoney") + " BYN", parseFloat(user.getInfoAboutCar(user.getChosenCarId(), "CarOtherMoney")));

        serviceStatisticsPieSeries.append("Maintenance<br>" + user.getInfoAboutCar(user.getChosenCarId(), "CarServiceMaintenanceMoney") + " BYN", parseFloat(user.getInfoAboutCar(user.getChosenCarId(), "CarServiceMaintenanceMoney")));
        serviceStatisticsPieSeries.append("Repair<br>" + user.getInfoAboutCar(user.getChosenCarId(), "CarServiceRepairMoney") + " BYN", parseFloat(user.getInfoAboutCar(user.getChosenCarId(), "CarServiceRepairMoney")));
        serviceStatisticsPieSeries.append("Tuning<br>" + user.getInfoAboutCar(user.getChosenCarId(), "CarServiceTuningMoney") + " BYN", parseFloat(user.getInfoAboutCar(user.getChosenCarId(), "CarServiceTuningMoney")));
        serviceStatisticsPieSeries.append("Details<br>" + user.getInfoAboutCar(user.getChosenCarId(), "CarServiceDetailMoney") + " BYN", parseFloat(user.getInfoAboutCar(user.getChosenCarId(), "CarServiceDetailMoney")));
        serviceStatisticsPieSeries.append("Diagnostics<br>" + user.getInfoAboutCar(user.getChosenCarId(), "CarServiceDiagnosticsMoney") + " BYN", parseFloat(user.getInfoAboutCar(user.getChosenCarId(), "CarServiceDiagnosticsMoney")));
        serviceStatisticsPieSeries.append("Tire Fitting<br>" + user.getInfoAboutCar(user.getChosenCarId(), "CarServiceTireFittingMoney") + " BYN", parseFloat(user.getInfoAboutCar(user.getChosenCarId(), "CarServiceTireFittingMoney")));
        serviceStatisticsPieSeries.append("Other<br>" + user.getInfoAboutCar(suser.getChosenCarId(), "CarServiceOtherMoney") + " BYN", parseFloat(user.getInfoAboutCar(user.getChosenCarId(), "CarServiceOtherMoney")));
    }




}
