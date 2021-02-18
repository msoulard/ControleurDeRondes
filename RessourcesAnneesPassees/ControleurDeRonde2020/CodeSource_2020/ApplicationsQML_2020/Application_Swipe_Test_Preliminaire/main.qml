import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Window 2.12
import QtMultimedia 5.12
import QtNfc 5.12
import "main.js" as Fonction
ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Tabs")

    SwipeView{
        id: leRondier
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1Form {
            id: identification
        }

        Page2Form {
            id: choixRonde
            buttonRonde.onClicked: {
                Fonction.changerPage();
            }
        }

        Page3Form{
            id : deroulementRonde
            buttonAnomalie.onClicked: {
                Fonction.changerPage();
            }

            buttonIgnorer.onClicked: {
                Fonction.changerPage();
                if(anomalie.textFieldAnomalie.text = "Description de l'anomalie"){
                    anomalie.textFieldAnomalie.text = "Pointeau ignoré";
                }
            }
            buttonScannerPointeau.onClicked: {

            }
            }
        Page4Form{
            id: anomalie
            buttonPhoto.onClicked: {
                Fonction.changerPage();
            }
            buttonValiderPhoto.onClicked: {
                leRondier.currentIndex = leRondier.currentIndex-1;
                anomalie.textFieldAnomalie.text = "Description de l'anomalie"
            }
        }
        Page5Form{
            id: appareil
            toolButton.onClicked: {
                Fonction.prendrePhoto()
            }
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: leRondier.currentIndex
        TabButton {
            text: qsTr("Identification")
        }
        TabButton {
            text: qsTr("Selection")
        }
        TabButton {
            text: qsTr("Déroulement")
        }
        TabButton {
            text: qsTr("Anomalie")
        }
        TabButton {
            text: qsTr("Photo")
        }
    }
}
