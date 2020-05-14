import QtQuick 2.0
import "../Component"
import AppEnums 1.0


Image {
    id: systembarbgn
    source: "image://ImageProvider/system-bar.png"
    BaseButton{
        id: homebtn
        anchors.centerIn: systembarbgn
        imgsource: "image://ImageProvider/homeBtn.png"
        onBtnClicked: {
            SCREEN_CTRL.popScreen()
        }
    }
    BaseButton{
        id: backbtn
        anchors.top: homebtn.top
        anchors.right: parent.right
        anchors.rightMargin: 65
        source: "image://ImageProvider/backBtn.png"
        onBtnClicked: {
            SCREEN_CTRL.pushScreen(AppEnums.SCREEN_ID_MUSIC_PLAYER)
        }
    }
    BaseButton{
        id: recentbtn
        anchors.top: homebtn.top
        anchors.left: parent.left
        anchors.leftMargin: 65
        source: "image://ImageProvider/recentBtn.png"

    }
}
