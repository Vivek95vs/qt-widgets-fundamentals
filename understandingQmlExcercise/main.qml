import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    id:root
    width: 400
    height: 400
    title: qsTr("Rectangle Excercise")
    color: "grey"

    Rectangle{
        id:blue
        x:50;y:50
        width: root.width-100; height: root.height/2-50
        color: "lightblue"

        Rectangle{

            x:50;y:50
            width: 50; height: 50
            color: "white"
        }
    }

    Rectangle{

        x:50;y:blue.x+blue.height
        width: 300; height: 150
        color: "green"

        Rectangle{

            x:100;y:50
            width: 150; height: 50
            color: "blue"
        }
    }
}
