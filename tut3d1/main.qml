import QtQuick 2.14
import QtQuick.Window 2.14
import VTK 1.0

Window {
    visible: true
    width: 800
    height: 600

    VTKView {
        anchors.fill: parent
    }
}
