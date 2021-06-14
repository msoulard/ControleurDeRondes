import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11

Page{
    id: identification
    padding: 10
    GridLayout {
        id: gridLayoutIdentification
        width: parent.width
        height: parent.height
        rows: 3
        columns: 2

        Text {
            id: titre
            Layout.row: 0
            Layout.columnSpan: 2
            width: parent.width
            font.pixelSize: parent.height/15
            color: "#9c0101"
            font.italic: true
            font.bold: true
            //horizontalAlignment: Text.AlignHCenter
            text: qsTr("IDENTIFICATION")
        }

        Text {
            id: message
            Layout.row: 1
            Layout.columnSpan: 2
            width: parent.width
            font.pixelSize: parent.height/25
            font.bold: true
//            wrapMode: Text.WordWrap
//            horizontalAlignment: Text.AlignHCenter
            text: qsTr("Veuillez scanner votre badge avec votre smartphone pour vous identifier")
        }

        Image {
            id: image1
            Layout.row:3
            Layout.column: 0
            //width: parent.width/2
            //height: parent.height/6
            rotation: -180
            source: "qrc:/img/Logo_NFC.jpg"
        }

        Image {
            id: image
            Layout.row: 3
            Layout.column: 1
            //width: parent.width/2
            //height: parent.height/6
            source: "qrc:/img/Logo_NFC.jpg"
        }
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
