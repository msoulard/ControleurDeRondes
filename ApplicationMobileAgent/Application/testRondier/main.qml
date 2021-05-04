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

        Identification {
            id: identification
        }
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
                deroulementRonde.listePointeaux.model = pointeau.obtenirListeDesignationsPointeaux(ronde.obtenirIdRondeCourante());
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
                onClicked: dialogVerifAnnulation.open()
            }

            Dialog{
                id: dialogVerifAnnulation
                title: "Annulation de l'anomalie"
                onAccepted: leRondier.currentIndex = leRondier.currentIndex-1;
                onRejected: {
                    this.close()
                }

                contentItem: Rectangle{
                    Column{
                        anchors.fill: parent
                        Text{
                            text: "Voulez-vous annuler l'anomalie ?"
                        }
                        Button{
                            id: a_valider
                            text: "Valider"
                            onClicked: dialogVerifAnnulation.accepted()
                        }
                        Button{
                            id: a_annuler
                            text: "Annuler"
                            onClicked: dialogVerifAnnulation.rejected()
                        }
                    }
                }
            }

            buttonPhoto.onClicked: {
                Fonction.changerPage();
            }
            buttonValiderAnomalie.onClicked: {
                onClicked: dialogVerifValidation.open()
            }

            Dialog{
                id: dialogVerifValidation
                title: "Validation de l'anomalie"
                onAccepted: leRondier.currentIndex = leRondier.currentIndex-1;
                onRejected: {
                    this.close()
                }

                contentItem: Rectangle{
                    Column{
                        anchors.fill: parent
                        Text{
                            text: "Voulez-vous valider l'anomalie ?"
                        }
                        Button{
                            id: v_valider
                            text: "Valider"
                            onClicked: dialogVerifValidation.accepted()
                        }
                        Button{
                            id: v_annuler
                            text: "Annuler"
                            onClicked: dialogVerifValidation.rejected()
                        }
                    }
                }
            }
        }

        Photo{
            id: photo
        }
    }
}
