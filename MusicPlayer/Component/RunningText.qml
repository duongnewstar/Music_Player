import QtQuick 2.0

//Rectangle{
//    height: 20
//    width: 340
//    color: "lightblue"
//    opacity: 0.5
Text {
    id: rText
    font.pixelSize: 14
    property int dur: 0
    property int des : 0
    property int delay: 0
    Text {
        id: childT
        text: parent.text
        color: parent.color
        visible: rText.contentWidth>200
        anchors.left: parent.right
        anchors.leftMargin: 150
        font.pixelSize: parent.font.pixelSize
    }
    Component.onCompleted: {
        if(rText.contentWidth > 200){
            rText.dur = (rText.contentWidth + 120)*20
            childT.visible = true
            rText.des = -rText.contentWidth - 150
            rText.delay = 1000
        }else {
            rText.dur = 0
            childT.visible = false
            rText.des = 0
            rText.delay = 0
        }
    }
}
//}
