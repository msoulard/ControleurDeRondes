import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    property alias message: message
    property alias comboBoxListeRondes: comboBoxListeRondes
    property alias buttonValider: buttonValider

    id: selectionRonde
    padding: 10
    Text {
        id: titre
        x: 0
        y: 0
        width: parent.width
        height: 46
        color: "#9c0101"
        text: qsTr("SELECTION DE LA RONDE")
        verticalAlignment: Text.AlignVCenter
        font.italic: true
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 25
    }

    Text {
        id: message
        y: titre.height+10
        width: parent.width
        text: qsTr("Bonjour, veuillez choisir votre ronde")
        wrapMode: Text.WordWrap
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        font.bold: true
        font.pixelSize: 20
    }

    Button {
        id: buttonValider
        x: parent.width/3
        y: parent.height/2
        text: qsTr("Valider")
    }
    ComboBox {
        id: comboBoxListeRondes
        x: parent.width/3-30
        y: parent.height/3
        width: parent.width/2
    }
}
