import QtQuick 2.0
import QtQuick.Controls 2.12

Rectangle{
    width: 30
    height: 200
    radius: 20
    color: "gray"
    ListView {
        id: list
        width: 30
        height: 200
        model: ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]
        delegate: ItemDelegate {
            Text {
                id: detxt
                font.pixelSize: 30
                color: "white"
                text: modelData
                anchors.centerIn: parent
            }
            MouseArea{
                anchors.fill: parent

            }
            width: parent.width
        }
//        ScrollIndicator.vertical: ScrollIndicator{}
    }

}
