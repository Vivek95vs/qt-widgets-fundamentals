import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 300
    height: 100
    title: qsTr("Anchor lines")
    color: "lightgrey"

//    Rectangle{

//        id: background
//        width: 300;height: 100
//        color: "lightblue"

//        Rectangle{

//            color: "green"
//            y: 25
//            height: 50; width: 50
//            anchors
//            {
//            right: background.right
//            top: background.top
//            }
//        }

//    }

    Rectangle{

        id: background
        width: 300;height: 100
        color: "lightblue"

        Rectangle{

            color: "green"
            height: 50
            anchors
            {
            left: background.left
            right: background.right
            top: background.top
            }
        }

    }
}
