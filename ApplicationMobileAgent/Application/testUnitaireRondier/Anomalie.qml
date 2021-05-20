import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import QtQml.Models 2.15

import "main.js" as Fonction

Page {
    property alias buttonAnnuler: buttonAnnuler
    property alias buttonPhoto: buttonPhoto
    property alias buttonValiderAnomalie: buttonValiderAnomalie
    property alias nomRonde : nomRonde
    property alias designationPointeau : designationPointeau
    property alias textAreaDescriptionAnomalie : textAreaDescriptionAnomalie

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
        x: 6
        y: 43
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
        x: 3
        y: 90
        width: 400
        height: 15
        font.underline: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 15
        text: Fonction.obtenirNomRondeCourante();
    }

    Text {
        id: designationPointeau
        x: 9
        y: 115
        width: 56
        height: 15
        font.underline: true
        font.pixelSize: 12
    }

    Text {
        id: descriptionAnomalie
        x: 10
        y: 135
        text: qsTr("Description :")
        font.underline: true
        font.pixelSize: 12
    }

    Button {
        id: buttonAnnuler
        x: 254
        y: 298
        text: qsTr("Annuler")
    }

    Button {
        id: buttonPhoto
        x: 254
        y: 241
        text: qsTr("Photo")
    }

    Button {
        id: buttonValiderAnomalie
        x: 78
        y: 298
        text: qsTr("Valider l'anomalie")
    }

    TextArea {
        id: textAreaDescriptionAnomalie
        x: 7
        y: 154
        width: 237
        height: 135
        placeholderText: qsTr("Description de l'anomalie")
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
