import QtQuick 2.14
import QtQuick.Window 2.14

// ⚠ REQUIRED for QWidget embedding
import QtQuick.Controls 1.4

Window {
    width: 1000
    height: 800
    visible: true
    title: "VTK in QML"

    Rectangle {
        anchors.fill: parent
        color: "black"

        // ✅ QWidget embedded here
        Widget {
            id: vtkWidget
            anchors.fill: parent
            widget: vtkContainer
        }
    }
}
