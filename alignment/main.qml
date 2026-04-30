import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 400
    height: 400
    title: qsTr("Alignment")
    //Alignment
//    Rectangle
//    {
//        id: bg
//        width: 400;height: 200
//        color: "lightblue"

//        Image{

//            id:clock;source: "qrc:/new/prefix1/pics/icons8-circle-100.png"
//            anchors
//            {

//                left: bg.left
//                leftMargin: bg.width/16
//                verticalCenter: bg.verticalCenter
//            }
//        }

//        Text{

//            text: "clock";font.pixelSize: 32
//            anchors
//            {
//                left: clock.right
//                leftMargin: 32
//                baseline: clock.verticalCenter
//            }
//        }


//    }
    //Anchors helpers
    Rectangle
    {
        width: 400;height: 400
        color: "lightblue"

        Rectangle
        {
            //width: 50;height: 50
            color: "green"
            //anchors.centerIn: parent
            anchors{
                fill: parent
                margins: 10
            }


        }
    }
}
