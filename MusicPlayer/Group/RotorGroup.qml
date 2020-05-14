import QtQuick 2.0

Image {
    id: rotorbgn
    source: "image://ImageProvider/TrackRotor.png"
    height: 80
    width: 80
    Image {
        id: rotorlight
        source: "image://ImageProvider/RotorLight.png"
        height: 80
        width: 80
        anchors{
            top: rotorbgn.top
            left: rotorbgn.left
        }
        RotationAnimation{
            id: ra1
            target: rotorlight
            from: 0
            to: 360
            duration: 5000
            direction: RotationAnimation.Clockwise
            running: !Controller.playbtn
            loops: Animation.Infinite
        }
    }
    Image {
        id: needle
        source: "image://ImageProvider/Needle2.png"
        width: 55
        height: 150
        anchors{
            top: rotorbgn.top
            topMargin: 20
            right: rotorbgn.right
            rightMargin: 15
        }
        transform: Rotation{
            origin.x:34
            origin.y:15
            RotationAnimation on angle{
                id: ra2
                from: 0
                to: 30
                duration: 2000
                direction: RotationAnimation.Clockwise
//                running: !Controller.playbtn
                running: Controller.rotorStatus==1

            }
            RotationAnimation on angle{
                id: ra3
                from: 30
                to: 0
                duration: 2000
                direction: RotationAnimation.Counterclockwise
                running: Controller.rotorStatus==2
            }
        }
    }

}
