import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 1000
    height: 1000
    title: qsTr("Images")
//    color: "#00a3fc"

//    Image{
//        x:150;y:150
//        source: "qrc:/new/prefix1/logo_pmt.png"
//        width: sourceSize.width*2
//        height: sourceSize.height*2
//        Component.onCompleted: console.log(width,height,sourceSize)
//    }

    Image {
        id: image
        width: 1000; height: 1000
        source: "file:///D:/1. PMT Logo.jpg"
        fillMode: Image.PreserveAspectFit
        Rectangle{
            color: "red"
            x:0;y:950;
            height: 50;
            width: 1000* image.progress
            visible: image.progress!=1
        }

        onStatusChanged: console.log(sourceSize)
    }

}
