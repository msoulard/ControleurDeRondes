import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11

Page {
    property alias boutonSelectionRonde: boutonSelectionRonde
    id: identification
    anchors.fill: parent
    layer.textureMirroring: ShaderEffectSource.MirrorVertically
    layer.wrapMode: ShaderEffectSource.ClampToEdge
    wheelEnabled: false
    spacing: 0
    focusPolicy: Qt.NoFocus
    title: "Identification"
    Text {
        id: titre
        x: 0
        y: 0
        width: 640
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
        width: 624
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
        x: 329
        y: 173
        width: 122
        height: 134
        fillMode: Image.PreserveAspectFit
        source: "qrc:/img/Logo_NFC.jpg"
    }

    Image {
        id: image1
        x: 201
        y: 173
        width: 122
        height: 134
        rotation: -180
        fillMode: Image.PreserveAspectFit
        source: "qrc:/img/Logo_NFC.jpg"
    }

    Button {
        id: boutonSelectionRonde
        x: 242
        y: 356
        text: qsTr("Sélection de la ronde")
        //onClicked: SelectionRonde
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
