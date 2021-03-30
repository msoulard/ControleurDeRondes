import QtQuick 2.12
import QtQuick.Controls 2.5

import "main.js" as Fonction

Page {
    property alias buttonValider: buttonValider

    Text {
        id: titre
        x: 0
        y: 0
        width: 400
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
        x: 8
        y: 70
        width: 392
        height: 45
        text: qsTr("Bonjour " +bdd.obtenirAgent("1B4DBE53")+", veuillez choisir votre ronde")
        wrapMode: Text.WordWrap
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        font.wordSpacing: 0
        renderType: Text.QtRendering
        font.bold: true
        font.pixelSize: 20
    }

    Button {
        id: buttonValider
        x: 150
        y: 267
        text: qsTr("Valider")
    }

    ComboBox {
        id: comboBoxListeRondes
        x: 73
        y: 169
        width: 262
        height: 40
        model : Fonction.obtenirNomRondes();
    }
}
