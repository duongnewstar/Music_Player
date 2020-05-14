import QtQuick 2.0

Rectangle {
    id: rec1
    width: 200
    height: 20
    //    property int aTime: 3000
    color: "transparent"
    clip: true
    Text {
        id: rText
        color: "white"
        font.pixelSize: 20
        property int dur: 0
        property int des : 0
        property int delay: 0
        text: Controller.title
        Text {
            id: childT
            text: parent.text
            color: parent.color
            anchors.left: parent.right
            anchors.leftMargin: 50
            visible: rText.contentWidth>200
            font.pixelSize: parent.font.pixelSize

        }
        PropertyAnimation{
            id: pa1
            target: rText
            property: "x"
            from: 0
            to:  rText.des
            duration: rText.dur
            running: Controller.title.contentWidth>200
            loops: Animation.Infinite
        }
        Connections{
            target: Controller
            ignoreUnknownSignals: true
            onTitleChanged:{
                console.debug(Controller.title.contentWidth)
                if(rText.contentWidth > 120){
                    rText.dur = (rText.contentWidth + 120)*20
                    childT.visible = true
                    rText.des = -rText.contentWidth - 50
                    rText.delay = 1000
                    pa1.restart()
                    console.log("long")
                }else {
                    pa1.stop()
                    rText.x=0
                    rText.dur = 0
                    childT.visible = false
                    rText.des = 0
                    rText.delay = 0
                    console.log("short")
                }
            }
        }
    }
    Component.onCompleted: {
        console.debug(Controller.title.contentWidth)
        if(rText.contentWidth > 120){
            rText.dur = (rText.contentWidth + 120)*20
            childT.visible = true
            rText.des = -rText.contentWidth - 50
            rText.delay = 1000
            pa1.restart()
            console.log("long")
        }else {
            pa1.stop()
            rText.x=0
            rText.dur = 0
            childT.visible = false
            rText.des = 0
            rText.delay = 0
            console.log("short")
        }
    }
}
