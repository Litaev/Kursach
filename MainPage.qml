import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Item {
    id: mainPage
    width: 420
    height: 780
    visible: true

    Rectangle{
        id: carMainRectangle
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 5
        height: 170
        color: "#212529"
        radius: 10
        Rectangle{
            id: carImageRectangle
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.margins: 10
            width: 150
            height: width
            radius: 10
            color: "#adb5bd"
            Image {
                id: carImage
                anchors.fill: parent
                anchors.margins: 10
                sourceSize: Qt.size(width, width)
                fillMode: Image.PreserveAspectFit
                source: "passatB5.jpeg"

            }
        }
        Rectangle{
            id: carInfoRectangle
            anchors.top: parent.top
            anchors.left: carImageRectangle.right
            anchors.right: parent.right
            anchors.margins: 10
            height: 50
            color: "#495057"
            radius: 10
            Text {
                id: carInfo
                anchors.fill: parent
                anchors.margins: 2
                width: parent.width
                height: parent.width
                color: "#ffffff"
                text: "Passat is a legendary car!"
                verticalAlignment: Text.AlignVCenter

            }
        }


        Rectangle{
            id: carMileageRectangle
            anchors.top: carInfoRectangle.bottom
            anchors.bottom: parent.bottom
            anchors.left: carImageRectangle.right
            anchors.leftMargin: 10
            anchors.topMargin: 10
            anchors.bottomMargin: 10
            width: (parent.width - carImage.width - 60)/2
            radius: 10
            color: "#6c757d"
            Rectangle{
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right
                height: 30
                color: "#495057"
                radius: 10
                Text {
                    anchors.fill: parent
                    id: carMileageText
                    color: "#ffffff"
                    text: "Car mileage"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.pointSize: 18

                }
            }
            Text {
                id: carMileageEdit
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottomMargin: 20
                color: "#ffffff"
                text: "999999"
                font.pointSize: 20
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter

            }

        }

        Rectangle{
            id: carMoneySpentRectangle
            anchors.left: carMileageRectangle.right
            anchors.right: parent.right
            anchors.top: carInfoRectangle.bottom
            anchors.bottom: parent.bottom
            anchors.margins: 10
            radius: 10
            color: "#adb5bd"
            Rectangle{
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right
                height: 30
                color: "#6c757d"
                radius: 10
                Text {
                    anchors.fill: parent
                    anchors.topMargin: 5
                    id: carMoneySpentText
                    color: "#ffffff"
                    text: "Car money spent"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.pointSize: 12

                }
            }
            Text {
                id: carMoneySpentEdit
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottomMargin: 20
                color: "#ffffff"
                text: "0"
                font.pointSize: 20
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter


            }
        }
    }
    Rectangle{
        id: listEventsTextRectangle
        anchors.top: carMainRectangle.bottom
        anchors.left: parent.left
        anchors.right: addNewEventButtonRectangle.left
        anchors.topMargin: 5
        anchors.leftMargin: 5
        radius: 10
        height: 30
        color: "#343a40"
        Text {
            id: listEventsText
            anchors.fill: parent
            color: "#ffffff"
            text: qsTr("Last Events")
            font.pointSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

        }

    }
    Rectangle{
        id: addNewEventButtonRectangle
        anchors.top: carMainRectangle.bottom
        anchors.right: parent.right
        anchors.topMargin: 5
        width: 30
        height: width
        radius: 10
        color: "#dee2e6"
        Button{
            id: addNewEventButtonButton
            anchors.fill: parent

            onClicked: {var page = secondPageComponent.createObject(stackView);
                stackView.push(page);}
        }

        Image{
            id: addNewEventButtonImage
            anchors.fill: parent
            anchors.margins: 6
            sourceSize: Qt.size(30, 30)
            fillMode: Image.PreserveAspectFit
            source: "addNewEvent.png"
        }
    }



}


