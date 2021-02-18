import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import QtQml.Models 2.15

import "main.js" as Fonction

ApplicationWindow {
    flags: Qt.WindowFullScreen
    visible: true
    width: 640

    title: qsTr("Rondier")

    SwipeView {
        id: leRondier
        anchors.fill: parent
        //currentIndex: tabBar.currentIndex

        Identification {
            id: identification
            boutonSelectionRonde.onClicked: {
                Fonction.changerPage();
            }
        }

        SelectionRonde {
            id: selectionRonde
            buttonValider.onClicked: {
                Fonction.changerPage();
            }
        }

        DeroulementRonde{
            id: deroulementRonde
            buttonAnomalie.onClicked: {
                Fonction.changerPage();
            }
        }

        Anomalie{
            id: anomalie
            buttonAnnuler.onClicked: {
                leRondier.currentIndex = leRondier.currentIndex-1;
            }
            buttonPhoto.onClicked: {
                Fonction.changerPage();
            }
            buttonValiderAnomalie.onClicked: {
                leRondier.currentIndex = leRondier.currentIndex-1;
            }
        }

        Photo{
            id: photo
        }
    }

//    footer: TabBar {
//        id: tabBar
//        currentIndex: swipeView.currentIndex
//    }
}
