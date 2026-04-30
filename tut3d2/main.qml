import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import com.vtk 1.0

Window {
    width: 1280
    height: 720
    visible: true
    title: qsTr("VTK 3D Rendering in QML")

    Column {
        anchors.fill: parent
        spacing: 10

        // Toolbar
        Rectangle {
            width: parent.width
            height: 50
            color: "#2c3e50"

            Row {
                anchors.centerIn: parent
                spacing: 10

                Button {
                    text: "Load DICOM"
                    onClicked: {
                        // You'll need to implement file dialog
                        // or pass data from C++
                        loadDicomData()
                    }
                }

                Button {
                    text: "Test Render"
                    onClicked: {
                        vtkItem.renderExample()
                    }
                }

                Button {
                    text: "Reset Camera"
                    onClicked: {
                        // Add reset functionality if needed
                    }
                }
            }
        }

        // VTK 3D View
        VTKQuickItem {
            id: vtkItem
            width: parent.width
            height: parent.height - 60
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    function loadDicomData() {
        // This function should:
        // 1. Use FileDialog to select DICOM folder
        // 2. Read DICOM using your existing code
        // 3. Convert data to format needed by VTKQuickItem
        // 4. Call vtkItem.setVolumeData()
    }
}
