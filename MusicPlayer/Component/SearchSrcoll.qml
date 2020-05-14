import QtQuick 2.0
import QtQuick.Controls 2.12

Rectangle{
    width: 40
    height: 450

    ListView {
        model: ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W"]
        delegate: ItemDelegate {
            Text {
                id: detxt
                font.pixelSize: 30
                text: modelData
            }
        }
    }
    ScrollIndicator.vertical: ScrollIndicator{}
}
