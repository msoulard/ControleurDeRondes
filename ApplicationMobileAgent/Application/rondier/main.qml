import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

import "main.js" as Fonction

ApplicationWindow{
    visible: true
    width: 640
    height: 480
    title: qsTr("Rondier")

    SwipeView{
        id: leRondier
        anchors.fill: parent

        Identification{
            id: identification
            buttonValiderBadge.onClicked: {
                console.log("largeur : " + parent.width + "\nhauteur : " + parent.height);
                var numBadge = textFieldBadge.text;
                selectionRonde.message.text = qsTr("Bonjour " +Fonction.obtenirNomAgent(numBadge)+", veuillez choisir votre ronde");
                selectionRonde.comboBoxListeRondes.model = Fonction.obtenirListeNomsRonde();
                Fonction.changerPage();
            }
        }

        SelectionRonde{
            id: selectionRonde
            buttonValider.onClicked: {
                var index = comboBoxListeRondes.currentIndex;
                deroulementRonde.nomRonde.text = qsTr(Fonction.obtenirRondeChoisie(index));
                Fonction.changerPage();
            }
        }

        DeroulementRonde{
            id:deroulementRonde
        }
    }
}
