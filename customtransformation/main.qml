import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    id: root
    color: "lightgrey"
    width: 500
    height: 500
    title: qsTr("custom transformation")

//    Image{
//        x:50;y:50
//        source: "qrc:/pic/pics/logo_pmt.png"
//        rotation: 45.0
//        transformOrigin: Item.TopLeft
//    }
    Item{
        property int _minside: Math.min(root.width,root.height)
        x: 10+ (root.width- _minside)/2
        y: 10+ (root.height- _minside)/2
        width: _minside-20
        height: _minside-20

        scale: Math.min(width/background.sourceSize.width,height/background.sourceSize.height)
        transformOrigin: Item.TopLeft

        Image{

            id: background
            source: "qrc:/pic/pics/icons8-circle-100.png"
        }

        Image {
            id: smallArm
            source: "qrc:/pic/pics/icons8-line-25.png"
            x:background.width/2-width/2
            y:background.height/2-12.5

            transform: Rotation{

                origin.x:smallArm.width/2
                origin.y:12.5

                RotationAnimation on angle{

                    from: 0
                    to: 360*2
                    duration: 60000
                    loops: Animation.Infinite
                }
            }
        }

         Image {
            id: largeArm
            source: "qrc:/pic/pics/icons8-line-50.png"
            x:background.width/2-width/2
            y:background.height/2-25


            transform: Rotation{

                origin.x:largeArm.width/2
                origin.y:25
                angle:90

                RotationAnimation on angle{

                    from: 0
                    to: 360*24
                    duration: 60000
                    loops: Animation.Infinite
                }
            }
        }

    }


}
