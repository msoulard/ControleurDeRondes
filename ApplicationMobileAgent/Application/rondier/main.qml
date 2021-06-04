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
                anomalie.nomRonde.text = qsTr(Fonction.obtenirRondeChoisie(index));
                rondier.mettreAJourListePointeaux();
                deroulementRonde.listePointeaux.model = pointeauxModel;
                deroulementRonde.designationPointeau.text = qsTr("Désignation : " + Fonction.obtenirDesignationPointeau());
                deroulementRonde.batimentPointeau.text = qsTr("Bâtiment : " + Fonction.obtenirBatimentPointeau());
                deroulementRonde.etagePointeau.text = qsTr("Etage : " + Fonction.obtenirEtagePointeau());
                deroulementRonde.tempsMiniPointeau.text = qsTr("Temps mini : " + Fonction.obtenirTempsMiniPointeau());
                deroulementRonde.tempsMaxiPointeau.text = qsTr("Temps maxi : " + Fonction.obtenirTempsMaxiPointeau());
                Fonction.changerPage();
            }
        }

        DeroulementRonde{
            id:deroulementRonde
            buttonPointeauScanne.onClicked: {
                designationPointeau.text = qsTr("Désignation : " + Fonction.obtenirDesignationPointeau());
                batimentPointeau.text = qsTr("Bâtiment : " + Fonction.obtenirBatimentPointeau());
                etagePointeau.text = qsTr("Etage : " + Fonction.obtenirEtagePointeau());
                tempsMiniPointeau.text = qsTr("Temps mini : " + Fonction.obtenirTempsMiniPointeau());
                tempsMaxiPointeau.text = qsTr("Temps maxi : " + Fonction.obtenirTempsMaxiPointeau());
            }
            buttonAnomalie.onClicked: {
                Fonction.verifAppuieBouton = 0;
                anomalie.emplacementPointeau.text = qsTr("Emplacement : " + Fonction.obtenirEmplacementPointeauAnomalie());
                anomalie.designationPointeau.text = qsTr("Pointeau : " + Fonction.obtenirDesignationPointeauAnomalie());
                Fonction.changerPage();
            }
            buttonIgnorerLePointeau.onClicked: {
                Fonction.verifAppuieBouton = 1;
                anomalie.emplacementPointeau.text = qsTr("Emplacement : " + Fonction.obtenirEmplacementPointeauAnomalie());
                anomalie.designationPointeau.text = qsTr("Pointeau : " + Fonction.obtenirDesignationPointeauAnomalie());
                anomalie.textAreaDescriptionAnomalie.text = qsTr("Pointeau ignoré");
                Fonction.changerPage();
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
                onAccepted: {
                    Fonction.verifAppuieBouton = -1;
                    var item = deroulementRonde.listePointeaux.itemAtIndex(deroulementRonde.listePointeaux.currentIndex-1);
                    //l'état devient vert
                    item.m_couleur = "#00FF00";
                    leRondier.currentIndex = leRondier.currentIndex-1;
                }
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
                            onClicked: {
                                dialogVerifAnnulation.accepted();
                            }
                        }
                        Button{
                            id: a_annuler
                            text: "Annuler"
                            onClicked: dialogVerifAnnulation.rejected()
                        }
                    }
                }
            }

            buttonValiderAnomalie.onClicked: {
                onClicked: dialogVerifValidation.open()
            }

            Dialog{
                id: dialogVerifValidation
                title: "Validation de l'anomalie"
                onAccepted: {
                    Fonction.declarerAnomalie();
                    leRondier.currentIndex = leRondier.currentIndex-1;
                }
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
    }
}
