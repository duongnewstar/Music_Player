import QtQuick 2.0
import QtQuick.Controls 2.0

import "../Component"
Image {

    id: volumeBar
    source: "image://ImageProvider/VolumeBar.png"
    height: 200
    Image {
        id: statusVolume
        source: "image://ImageProvider/status-volume.png"
        height: -(volumeBtn.y) + 200

        anchors {
            bottom: volumeBar.bottom
        }
    }
    Connections{
        ignoreUnknownSignals: true
        target: volumeBtn
        onYChanged: {
            if(volumeBtn.y%2==0) return
            Controller.setVolume(100-(volumeBtn.y+15)/2)
            console.log("Y=",volumeBtn.y)
            console.log("volume=",Controller.volume)
        }
    }
    BaseButton {
        id: volumeBtn
        property bool vsb: true
        source: "image://ImageProvider/VolumnButton.png"
        anchors{
            horizontalCenter: volumeBar.horizontalCenter
        }
        Rectangle{
            id: normal_volBtn
            width: 30
            height: 30
            radius: 15
            anchors.fill: parent
            visible: volumeBtn.vsb
            opacity: 0.9
        }
        MouseArea {
            //            acceptedButtons: Qt.LeftButton|Qt.MiddleButton
            anchors.fill: volumeBtn
            drag.target: volumeBtn
            drag.axis: Drag.YAxis
            drag.minimumY: -15
            drag.maximumY: 185
            onPressed: {
                volumeBtn.vsb=false
            }
            onReleased: {
                volumeBtn.vsb=true
            }
        }
    }
    Column {
        id: column
        anchors {
            left: volumeBar.right
            leftMargin: 13
        }
        spacing: 14
        Repeater {

            model: 10
            Rectangle {
                width: 7;
                height: 7;
                radius: 7;
                border.width: 1;
                border.color:  "black";
                color: index < (10 - statusVolume.height/20) ? "black" : "lightgreen"
            }
        }
    }
    Component.onCompleted: {
        volumeBtn.y=(100-Controller.volume)*2-15
    }
}

