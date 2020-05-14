import QtQuick 2.12
import QtQuick.Window 2.12
import "Screen"
import AppEnums 1.0

Window {
    visible: true
    width: 480
    height: 320
    title: qsTr("Music Player")+QmlTranslator.emptytxt
    property var layer_base: layer_base_1

    function reloadScreen() {
        layer_base.source = ""
        layer_base.source = SCREEN_MODEL.currentScreen
    }

    function switchLayerBase(from, to) {
        console.log("switchLayerBase");
        if (from.item !== null) {
            from.item.visible = false
            from.source = ""
        }
        if (to.item !== null) {
            to.item.visible = true
        }
        layer_base = from
    }

    // common screen loader
    Loader {
        id: layer_base_1
        anchors.fill: parent

        onLoaded: {
            switchLayerBase(layer_base_2, layer_base_1);
        }
    }

    Loader {
        id: layer_base_2
        anchors.fill: parent

        onLoaded: {
            switchLayerBase(layer_base_1, layer_base_2);
        }
    }
    Component.onCompleted: {
        Controller.process(AppEnums.LOAD_LAST_STATE)
    }
}

