import QtQuick 2.0
import "../Component"
Image {
    id: clearbarbgn
    source: "image://ImageProvider/darkbg.png"
    Text {
        id: clearbartxt
        text: qsTr("Song List")
        font.pixelSize: 25
        anchors{
            left: clearbarbgn.left
            verticalCenter: clearbarbgn.verticalCenter
        }
        color: "white"
    }
    BaseButton{
        id: clearbtn
        source: Controller.clearbtn?"image://ImageProvider/clearBtn.png":"image://ImageProvider/btnClearPressed.png"
        anchors{
            right: clearbarbgn.right
            rightMargin: 25
            verticalCenter: clearbarbgn.verticalCenter
        }
        onBtnClicked: {
            Controller.setClearbtn(!Controller.clearbtn)
        }
    }
}
