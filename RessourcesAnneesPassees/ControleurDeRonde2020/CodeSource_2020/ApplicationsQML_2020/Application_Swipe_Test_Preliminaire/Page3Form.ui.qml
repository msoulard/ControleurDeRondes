import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQml 2.12
import QtNfc 5.11

import "Page3Form.js" as Fonction

Page {
    id: deroulementRonde
    width: 600
    height: 600
    property alias buttonScannerPointeau: buttonScannerPointeau
    property alias deroulementRonde: deroulementRonde
    property alias buttonIgnorer: buttonIgnorer
    property alias buttonAnomalie: buttonAnomalie


    header: Label {
        text: qsTr("Déroulement de la ronde")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    NearField {
            filter: [ NdefFilter { type: "U"; typeNameFormat: NdefRecord.NfcRtd; minimum: 1; maximum: 1 } ]
            orderMatch: false
    }

    Button {
        id: buttonAnomalie
        x: 139
        y: 263
        width: 150
        text: qsTr("Anomalie")
    }

    Button {
        id: buttonIgnorer
        x: 132
        y: 381
        width: 150
        text: qsTr("Ignorer le pointeau")
    }

    TextField {
        id: textFieldErreur
        x: 139
        y: 63
        width: 150
        height: 40
        text: qsTr("Bravo bibi")
    }

    Button {
        id: buttonRapport
        x: 27
        y: 462
        width: 256
        text: qsTr("Envoyer rapport")
    }

    Button {
        id: buttonScannerPointeau
        x: 139
        y: 159
        width: 150
        height: 40
        text: qsTr("Scanner Pointeau")
    }

    ComboBox {
        id: comboBoxPointeau
        x: 0
        y: 113
    }
}
