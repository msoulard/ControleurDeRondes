import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import QtQml.Models 2.15

Page {
    property alias buttonAnnuler: buttonAnnuler
    property alias buttonPhoto: buttonPhoto
    property alias buttonValiderAnomalie: buttonValiderAnomalie
    property alias nomRonde : nomRonde

    title: "Anomalie"
    Text {
        id: titre
        x: 0
        y: 0
        width: 400
        height: 46
        color: "#9c0101"
        text: qsTr("ANOMALIE")
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
        width: 624
        height: 45
        text: qsTr("Veuillez indiquer le sujet de l'anomalie")
        wrapMode: Text.WordWrap
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        font.wordSpacing: 0
        renderType: Text.QtRendering
        font.bold: true
        font.pixelSize: 20
    }

    Text {
        id: nomRonde
        x: 0
        y: 121
        width: 400
        height: 15
        font.underline: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 15
    }

    Text {
        id: designationPointeau
        x: 8
        y: 142
        width: 56
        height: 15
        text: qsTr("Pointeau :")
        font.underline: true
        font.pixelSize: 12
    }

    Text {
        id: descriptionAnomalie
        x: 8
        y: 163
        text: qsTr("Description :")
        font.underline: true
        font.pixelSize: 12
    }

    Button {
        id: buttonAnnuler
        x: 255
        y: 335
        text: qsTr("Annuler")
    }

    Button {
        id: buttonPhoto
        x: 255
        y: 279
        text: qsTr("Photo")
    }

    Button {
        id: buttonValiderAnomalie
        x: 75
        y: 335
        text: qsTr("Valider l'anomalie")
    }

}
