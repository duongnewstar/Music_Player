import QtQuick 2.0
import QtQuick.Controls 2.12
import "../Component"
import AppEnums 1.0

Image {
    id: menubarbgn
    source: "image://ImageProvider/darkbg.png"
    BaseButton{
        id: backbtn
        anchors{
            top: menubarbgn.top
            topMargin: 5
            left: parent.left
            leftMargin: 10
        }
        source: "image://ImageProvider/backBtn.png"
        onBtnClicked: {
            SCREEN_CTRL.pushScreen(AppEnums.SCREEN_ID_MUSIC_PLAYER)
        }
    }
    Rectangle{
        id: recmenu
        height: 26
        width: 100
        anchors{
            top: parent.top
            topMargin: 5
            right: parent.right
            rightMargin: 25
        }
        color: "transparent"
        BaseButton{
            id: roundedrectbtn
            height: 24
            width: 24
            anchors.left: parent.left
            source: "image://ImageProvider/RoundedRect.png"
            onBtnClicked: {
                SCREEN_CTRL.pushScreen(AppEnums.SCREEN_ID_MUSIC_LIST)
            }
        }
        BaseButton{
            id: settingbtn
            height: 24
            width: 28
            anchors.left: roundedrectbtn.right
            anchors.leftMargin: 20
            source: "image://ImageProvider/settingBtn.png"
            onBtnClicked: {
                settingmenu.open()
            }
        }
        BaseButton{
            id: menubtn
            height: 24
            width: 6
            anchors.right: parent.right
            source: "image://ImageProvider/MenuBtn.png"
            onBtnClicked: {
                addmenu.open()
            }
        }

    }
    Menu{
        id:settingmenu
        width: 125
        x: recmenu.x
        y: recmenu.y+25

        RadioButton{
            text: qsTr("ENGLISH")+QmlTranslator.emptytxt
            checked: true
            onClicked: {
                console.log("en")
                QmlTranslator.setTranslation("en")
            }
        }
        RadioButton{
            text: qsTr("VIETNAMESE")+QmlTranslator.emptytxt
            onClicked: {
                console.log("vi")
                QmlTranslator.setTranslation("vi")
            }
        }
        RadioButton{
            text: qsTr("KOREAN")+QmlTranslator.emptytxt
            onClicked: {
                console.log("ko")
                QmlTranslator.setTranslation("ko")
            }
        }
    }
    Menu{
        id: addmenu
        width: 125
        x: recmenu.x
        y: recmenu.y+25
        MenuItem{
            text: qsTr("ADD FOLDER")+QmlTranslator.emptytxt
            onClicked: {
                console.log("ADD FOLDER")
//                Controller.addFolder()
                Controller.process(AppEnums.ADD_FOLDER)
            }
        }
        MenuItem{
            text: qsTr("ADD SONG")+QmlTranslator.emptytxt
            onClicked: {
                console.log("ADD SONG")
//                Controller.addSong()
                Controller.process(AppEnums.ADD_SONG)
            }
        }
    }
}
