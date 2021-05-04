import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11

Page {
//    property alias boutonSelectionRonde: boutonSelectionRonde
    width: 600
    height: 400
    id: identification
    focusPolicy: Qt.NoFocus
    title: "Identification"
    Text {
        id: titre
        x: 0
        y: 0
        width: 400
        height: 46
        color: "#9c0101"
        text: qsTr("IDENTIFICATION")
        verticalAlignment: Text.AlignVCenter
        font.italic: true
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 25
    }

    Text {
        id: message
        x: 8
        y: 70
        width: 386
        height: 45
        text: qsTr("Veuillez scanner votre badge avec votre smartphone pour vous identifier")
        wrapMode: Text.WordWrap
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        font.wordSpacing: 0
        renderType: Text.QtRendering
        font.bold: true
        font.pixelSize: 20
    }

    Image {
        id: image
        x: 187
        y: 155
        width: 122
        height: 134
        fillMode: Image.PreserveAspectFit
        source: "qrc:/img/Logo_NFC.jpg"
    }

    Image {
        id: image1
        x: 59
        y: 155
        width: 122
        height: 134
        rotation: -180
        fillMode: Image.PreserveAspectFit
        source: "qrc:/img/Logo_NFC.jpg"
    }
}
