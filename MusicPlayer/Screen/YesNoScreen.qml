import QtQuick 2.0
import "../Component"

Rectangle {
    id: bgn
    width: 300
    height: 150
    color: "#ddd9d9"
    border.color: "black"
    border.width: 2
    Image {
        id: recycle
        source: "image://ImageProvider/recycle.png"
        width: 40
        height: 60
        anchors{
            left: parent.left
            leftMargin: 10
            top: parent.top
            topMargin: 20
        }
    }
//    Item{
//        id: warning
//        width: 150
//        height: 20

        Text {
            id: warningtxt
            text: qsTr("Do you want to remove it?")
            font.pixelSize: 20
//            anchors.centerIn: parent
            anchors{
                right: bgn.right
                rightMargin: 10
                top: bgn.top
                topMargin: 40
            }
        }
//    }
    Rectangle {
        id: yesbtn
        width: bgn.width/2
        height: 50
        color: "#ddd9d9"
        border.color: "black"
        border.width: 2
        anchors{
            bottom: parent.bottom
            left: parent.left
        }
        Text {
            id: yesbtntxt
            text: qsTr("YES")
            font.pixelSize: 20
            anchors.centerIn: parent
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                console.log("yes")
                SongModel.removeCurrentItem()
                Controller.setClearbtn(!Controller.clearbtn)
            }
        }
    }
    Rectangle {
        id: nobtn
        width: bgn.width/2
        height: 50
        color: "#ddd9d9"
        border.color: "black"
        border.width: 2
        anchors{
            bottom: parent.bottom
            right: parent.right
        }
        Text {
            id: nobtntxt
            text: qsTr("NO")
            font.pixelSize: 20
            anchors.centerIn: parent
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                Controller.setClearbtn(!Controller.clearbtn)
            }
        }
    }
}
