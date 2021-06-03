import QtQuick 2.0
import QtQuick.Layouts 1.11
import QtQuick.Controls 2.15

import "main.js" as Fonction

Page {
    property alias textFieldBadge: textFieldBadge
    property alias buttonValiderBadge: buttonValiderBadge
    property alias connectionNFC: connectionNFC

    id: identification
    title: "Identification"
    padding: 10
    Text {
        id: titre
        width: parent.width
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
        y: titre.height+10
        width: parent.width
        text: qsTr("Veuillez scanner votre badge avec votre smartphone pour vous identifier")
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.WordWrap
        font.bold: true
        font.pixelSize: 20
    }

    Image {
        id: image
        x: parent.width/2-10
        y: parent.height/3
        width: 122
        height: 134
        fillMode: Image.PreserveAspectFit
        source: "qrc:/img/Logo_NFC.jpg"
    }

    Image {
        id: image1
        x: parent.width/6
        y: parent.height/3
        width: 122
        height: 134
        rotation: -180
        fillMode: Image.PreserveAspectFit
        source: "qrc:/img/Logo_NFC.jpg"
    }

    TextField {
        id: textFieldBadge
        y: parent.height/3*2
        placeholderText: qsTr("Numéro de badge")
    }

    Button{
        id: buttonValiderBadge
        x: parent.width/5*3
        y: parent.height/3*2
        text: qsTr("S'identifier")
    }
    Connections {
        id: connectionNFC
        target: lecteurNFC
    }
}




/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:1;anchors_height:400;anchors_width:400;anchors_x:120;anchors_y:46}
D{i:2;anchors_x:98;anchors_y:7}
}
##^##*/
