import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Item transformation-scaling")

    color: "#00a3fc"
//    Rectangle
//    {
//        color: "red"
//        width: img.width
//        height: img.height
//        x:150;y:150
////        clip: true
//        Image{
//            id:img
//            source: "qrc:/new/prefix1/pics/logo_pmt.png"
//            //        width: sourceSize.width*2
//            //        height: sourceSize.height*2
//            //        Component.onCompleted: console.log(width,height,sourceSize)
//            scale: 2.0
//        }

//    }
    Image{
        x:50;y:50
        source: "qrc:/new/prefix1/pics/logo_pmt.png"
        //        width: sourceSize.width*2
        //        height: sourceSize.height*2
        //        Component.onCompleted: console.log(width,height,sourceSize)
        rotation: 45.0
        transformOrigin: Item.TopLeft
    }


}
