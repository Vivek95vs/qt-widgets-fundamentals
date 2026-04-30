import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Binding loops")

    Rectangle{
        color: "black"
//        width: child.width
//        height: child.height

        Image{
            id: child
            source: "qrc:/new/prefix1/pics/logo_pmt.png"
            anchors
            {
                fill:parent
                margins:5
            }
        }

        width: child.implicitWidth
        height: child.implicitHeight

        Component.onCompleted: console.log("Img width", width,height)

    }
}
