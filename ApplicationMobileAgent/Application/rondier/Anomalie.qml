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
    property alias emplacementPointeau: emplacementPointeau
    property alias textAreaDescriptionAnomalie : textAreaDescriptionAnomalie

    id: anomalie
    title: "Anomalie"
    padding: 10
    Text {
        id: titre
        width: parent.width
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
        y: titre.height+10
        width: parent.width
        text: qsTr("Veuillez indiquer le sujet de l'anomalie")
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.WordWrap
        font.bold: true
        font.pixelSize: 20
    }

    Text {
        id: nomRonde
        y: message.y+message.height+10
        width: parent.width
        font.underline: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 15
    }

    Text {
        id: emplacementPointeau
        y: nomRonde.y+nomRonde.height+10
        width: parent.width
        font.underline: true
        font.pixelSize: 12
    }
    Text {
        id: designationPointeau
        y: emplacementPointeau.y+emplacementPointeau.height+10
        width: parent.width
        font.underline: true
        font.pixelSize: 12
    }

    Text {
        id: descriptionAnomalie
        y: designationPointeau.y+designationPointeau.height+10
        text: qsTr("Description :")
        font.underline: true
        font.pixelSize: 12
    }

    TextArea {
        id: textAreaDescriptionAnomalie
        y: descriptionAnomalie.y+descriptionAnomalie.height+10
        width: parent.width/2
        height: parent.height/2
        placeholderText: qsTr("Description de l'anomalie")
    }

    Button {
        id: buttonValiderAnomalie
        y: textAreaDescriptionAnomalie.y+textAreaDescriptionAnomalie.height+10
        text: qsTr("Valider l'anomalie")
    }

    Button {
        id: buttonAnnuler
        x: textAreaDescriptionAnomalie.x+textAreaDescriptionAnomalie.width+10
        y: textAreaDescriptionAnomalie.y+textAreaDescriptionAnomalie.height+10
        text: qsTr("Annuler")
    }

    Button {
        id: buttonPhoto
        x: textAreaDescriptionAnomalie.x+textAreaDescriptionAnomalie.width+10
        y: textAreaDescriptionAnomalie.y+textAreaDescriptionAnomalie.height-buttonAnnuler.height
        text: qsTr("Photo")
    }



}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
