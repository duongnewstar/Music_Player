import QtQuick 2.0

Item{
    property int sec: Controller.position/1000%60
    property int min: Controller.position/1000/60
    property int maxsec: Controller.duration/1000%60
    property int maxmin: Controller.duration/1000/60

    height: 20
    width: 322
    Image {
        id: timebarbgn
        anchors{
            bottom: parent.bottom
            left: parent.left
        }
        source: "image://ImageProvider/MusicTimeBar.png"
        MouseArea{
            anchors.fill: timebarbgn
            onClicked: {
                Controller.setSongPosition((maxmin*60+maxsec)*mouseX*1000/timebarbgn.width)
            }
        }

    }
    Image {
        id: statusTime
        source: "image://ImageProvider/SliderStatus.png"
        width: musicbtn.x
        anchors.top: timebarbgn.top
        anchors.left: timebarbgn.left
    }
        Item{
            id: runtime
//            color: "transparent"
            height: 10
            width: runtimetxt.contentWidth
            anchors{
                top: parent.top
                left: parent.left
            }
            Text {
                id: runtimetxt
                anchors.centerIn: runtime
                text: Controller.converttime(min)+":"+Controller.converttime(sec)
                color: "white"
            }
        }
        Item{
            id: maxtime
//            color: "transparent"
            height: 10
            width: maxtimetxt.contentWidth
            anchors{
                top: parent.top
                right: timebarbgn.right
            }
            Text {
                id: maxtimetxt
                anchors.centerIn: maxtime
                color: "white"
                text: Controller.converttime(maxmin)+":"+Controller.converttime(maxsec)
            }
        }

        Rectangle
        {
            property bool reccolor: true
            id: musicbtn
            color: "white"
            height: 10;
            width: 10;
            radius: 10;
            x: timebarbgn.width*(min*60+sec)/(maxmin*60+maxsec)
            anchors.verticalCenter: timebarbgn.verticalCenter

        }
}
