import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

Page {
    Grid {
        id: grid
        width: parent.width
        height: parent.height

        Text {
            id: element
            Layout.row: 1
            width: parent.width
            text: qsTr("Text")
            font.pixelSize: 12
        }

        Text {
            id: element1
            Layout.row: 2
            width: parent.width
            text: qsTr("Text")
            font.pixelSize: 12
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
