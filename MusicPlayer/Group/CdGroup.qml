import QtQuick 2.0
import QtGraphicalEffects 1.0

Rectangle{
    id:dia
//    x: -159
//    y: 10
    Image {
        id: dia1
        width: 200
        height: 200
        source: "image://ImageProvider/cdmask.png"
    }

    Rectangle {
        id: mask
        width: dia1.height
        height: width
        radius: width
        anchors {
            right: dia1.right
        }
    }
    Image {
        id: dia2
        width: 200
        height: 200
//        source: "image://ImageProvider/defaultCD.png"
        source: Controller.cover
        fillMode: Image.PreserveAspectCrop
        layer.enabled: true
        layer.effect: OpacityMask {
            maskSource: mask
        }
        transform: Rotation{
            id: rot1
            origin.x:100
            origin.y:100
            RotationAnimation on angle{
                from: 0
                to: 360
                duration: 8000
                direction: RotationAnimation.Clockwise
                running: !Controller.playbtn
                loops: Animation.Infinite
            }
        }
    }
//    Image {
//        id: dia3
//        width: 194
//        height: 362
//        source: "image://ImageProvider/cd-core.png"
//    }
}


