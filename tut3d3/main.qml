import QtQuick 2.14
import QtQuick.Window 2.14
import VTK3D 1.0

Window {
    width: 800
    height: 600
    visible: true
    title: "VTK Test"

    Rectangle {
        anchors.fill: parent
        color: "black"

        VTKQuickItem {
            id: vtkViewer
            anchors.fill: parent
            dicomFolder: "D:/DICOM_SERIES"

            Component.onCompleted: {
                console.log("Testing VTK component...");
                // Don't auto-load, we'll use a button
            }
        }

        Rectangle {
            anchors.centerIn: parent
            width: 200
            height: 100
            color: "#AA000000"
            radius: 10

            Column {
                anchors.centerIn: parent
                spacing: 10

                Text {
                    text: "VTK 3D Test"
                    color: "white"
                    font.bold: true
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Rectangle {
                    width: 150
                    height: 40
                    color: "#007ACC"
                    radius: 5
                    anchors.horizontalCenter: parent.horizontalCenter

                    Text {
                        anchors.centerIn: parent
                        text: "LOAD NOW"
                        color: "white"
                        font.bold: true
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            console.log("Manual load triggered");
                            vtkViewer.loadDicomVolume();
                        }
                    }
                }
            }
        }

        Text {
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.margins: 10
            text: "Status: " + vtkViewer.status
            color: "white"
            font.pixelSize: 12
        }
    }

    Component.onCompleted: {
        console.log("=== MINIMAL TEST ===");
        console.log("Path: D:/DICOM_SERIES");
        console.log("Click the LOAD NOW button to test");
    }
}
