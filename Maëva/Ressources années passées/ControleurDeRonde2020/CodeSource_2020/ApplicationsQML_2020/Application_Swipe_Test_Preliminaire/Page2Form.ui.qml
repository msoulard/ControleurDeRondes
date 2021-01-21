import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.LocalStorage 2.12
import "Page2Form.js" as Fonction
Page {
    id: choixRonde
    width: 600
    height: 400
    property alias choixRonde: choixRonde
    property alias buttonRonde: buttonRonde

    header: Label {
        text: qsTr("Selection ronde")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }


    ComboBox {
        id: comboBoxSelectionnerRonde
        x: 29
        y: 44
        width: 300
        height: 40
    }

    Button {
        id: buttonRonde
        x: 29
        y: 215
        width: 300
        text: qsTr("Valider")

    }
}
