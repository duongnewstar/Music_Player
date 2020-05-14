import QtQuick 2.0
import "../Group"
import AppEnums 1.0

Item{
    id: playerscreen
    Image {
        id: statusbar
        anchors.top: parent.top
        anchors.left: parent.left
        height: 10
        width: 480
        source: "image://ImageProvider/status-bar.png"
    }
    Image {
        id: screenbgn
        anchors.top: statusbar.bottom
        anchors.left: parent.left
        height: 310
        width: 480
        source: "image://ImageProvider/bg.png"

    }
//    SystemBar{
//        id: systembar
//        height: 25
//        width: 480
//        anchors.bottom: screenbgn.bottom
//        anchors.left: parent.left
//    }
    MenuBar{
        id: menubar
        height: 30
        width: 480
        anchors.top: screenbgn.top
    }
    PlayerBtnBar{
        id: playerbtnbar
        anchors.bottom: playerscreen.bottom
    }
    MusicTimeBar{
        id: musictimebar
        anchors{
            bottom: playerbtnbar.top
            horizontalCenter: parent.horizontalCenter
        }
    }
    RunningTextBar{
        id: runningtextbar
        anchors{
            bottom: musictimebar.top
            horizontalCenter: parent.horizontalCenter
        }
    }
    VolumeBar{
        id: volumebar
        anchors{
            bottom: playerscreen.bottom
            bottomMargin: 20
            right: parent.right
            rightMargin: 40
        }
    }  
    CdGroup{
        id: cdgroup
        anchors{
            top: menubar.bottom
            topMargin: 10
            left: playerscreen.left
            leftMargin: -100
        }
    }
    RotorGroup{
        id:rotorgroup
        anchors{
            left: parent.left
            leftMargin: 100
            top: menubar.bottom
            topMargin: 10
        }
    }
}
