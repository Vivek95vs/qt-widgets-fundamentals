import QtQuick 2.12
import QtQuick.Window 2.12

//Window {
//    visible: true
//    width: 640
//    height: 480
//    title: qsTr("Hello World")
//}

Window {

    visible: true
    width: 300; height: 115
    title: qsTr("property bind")

    TextInput{

        id: textelement
        x:50;y:25
        text: "QT QUICK"
        font.family:"Helvetica"; font.pixelSize: 50
    }

    Rectangle{

        x:50; y:75; height: 5
        width: textelement.width
        color: "lightblue"
    }

}
