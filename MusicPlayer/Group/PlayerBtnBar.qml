import QtQuick 2.0
import "../Component"
import AppEnums 1.0

Item {
    id: rec
    height: 50
    width: 480
    BaseButton{
        id: playbtn
        anchors.centerIn: rec
        source: Controller.playbtn?"image://ImageProvider/playBtn.png":"image://ImageProvider/pauseBtn.png"
        onBtnClicked: {
            console.log(" Playbtn clicked")
            Controller.process(AppEnums.PLAY_SONG)
        }
    }
    BaseButton{
        id: prevbtn
        anchors{
            right: playbtn.left
            rightMargin: 20
            verticalCenter: rec.verticalCenter
        }
        source: Controller.prevbtn?"image://ImageProvider/preBtn.png":"image://ImageProvider/preBtnPressed.png"
        onBtnClicked: {
            Controller.process(AppEnums.PREV_SONG)
        }
        onBtnPressed: {
            Controller.setPrevbtn(!Controller.prevbtn)
        }
        onBtnReleased: {
            Controller.setPrevbtn(!Controller.prevbtn)
            Controller.changePlayRate(1)
        }
        onBtnPressAndHold: {
            Controller.changePlayRate(0.5)
        }
    }
    BaseButton{
        id: nextbtn
        anchors{
            left: playbtn.right
            leftMargin: 20
            verticalCenter: rec.verticalCenter
        }
        source: Controller.nextbtn?"image://ImageProvider/nextBtn.png":"image://ImageProvider/nextBtnPressed.png"

        onBtnClicked: {
            Controller.process(AppEnums.NEXT_SONG)
        }
        onBtnPressed: {
            Controller.setNextbtn(!Controller.nextbtn)
        }
        onBtnReleased: {
            Controller.setNextbtn(!Controller.nextbtn)
            Controller.changePlayRate(1)
        }
        onBtnPressAndHold: {
            Controller.changePlayRate(2)
        }
    }
    BaseButton{
        id: shufflebtn
        anchors{
            right: prevbtn.left
            rightMargin: 20
            verticalCenter:  rec.verticalCenter
        }
        source: "image://ImageProvider/shuffle.png"
        Image {
            id: shufflebtnclk
            anchors.fill: shufflebtn
            visible: !Controller.shufflebtn
            source: "image://ImageProvider/focusBtn.png"
        }
        onBtnClicked: {
            console.log(" Shuffle clicked")
            Controller.process(AppEnums.SHUFFLE_SONG)
        }
    }
    BaseButton{
        id: repeatbtn
        anchors{
            left: nextbtn.right
            leftMargin: 20
            verticalCenter: rec.verticalCenter
        }
        source: "image://ImageProvider/RepeatBtn.png"
        Image {
            id: repeatbtnclk
            anchors.fill: parent
            visible: !Controller.repeatbtn
            source: "image://ImageProvider/focusBtn.png"
        }
        onBtnClicked: {
            console.log(" Repeat clicked")
            Controller.process(AppEnums.REPEAT_SONG)
        }
    }
}
