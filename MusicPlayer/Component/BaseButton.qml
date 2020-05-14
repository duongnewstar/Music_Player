import QtQuick 2.0

Image {
    id: img
    property string imgsource: ""
    signal btnClicked
    signal btnPressed
    signal btnReleased
    signal btnPressAndHold
    source: imgsource
    MouseArea{
        anchors.fill: parent
        onClicked: {
           img.btnClicked()
        }
        onPressed: {
            img.btnPressed()
        }
        onReleased: {
            img.btnReleased()
        }
        onPressAndHold: {
            img.btnPressAndHold()
        }
    }
}

