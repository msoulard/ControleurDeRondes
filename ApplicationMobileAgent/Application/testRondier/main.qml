import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import QtQml.Models 2.15

import "main.js" as Fonction

ApplicationWindow {
    //flags: Qt.WindowFullScreen
    visible: true
    width: 640
    height: 400
    title: qsTr("Rondier")

    SwipeView {
        id: leRondier
        anchors.fill: parent

        SelectionRonde {
            id: selectionRonde
            buttonValider.onClicked: {
                Fonction.changerPage();
                var index = comboBoxListeRondes.currentIndex;
                ronde.mettreAJourIndexCourant(index);
                deroulementRonde.nomRonde.text = Fonction.obtenirNomRondeCourante();
                anomalie.nomRonde.text = Fonction.obtenirNomRondeCourante();
                //deroulementRonde.etatPointeau.color = Fonction.obtenirDesignationPointeau();
                //deroulementRonde.designationPointeau.text = Fonction.obtenirDesignationPointeau();
                deroulementRonde.listePointeaux.model = Fonction.obtenirDesignationPointeau();
                selectionRonde.destroy();
            }
        }
        DeroulementRonde{
            id: deroulementRonde
            buttonAnomalie.onClicked: {
                Fonction.changerPage();
            }
            buttonPointeauScanne.onClicked: {
                pointeau.horodater();
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
}
