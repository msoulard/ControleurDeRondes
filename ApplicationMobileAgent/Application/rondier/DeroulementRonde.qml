import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import QtQml.Models 2.15
import QtQml 2.2
import QtQuick.Dialogs 1.2

import "main.js" as Fonction

Page {
    property alias buttonAnomalie: buttonAnomalie
    property alias buttonPointeauScanne: buttonPointeauScanne
    property alias buttonInterrompreLaRonde: buttonInterrompreLaRonde
    property alias buttonIgnorerLePointeau: buttonIgnorerLePointeau
    property alias nomRonde : nomRonde
    property alias listePointeaux : listePointeaux
    property alias emplacementPointeau : emplacementPointeau
    property alias tempsMiniPointeau: tempsMiniPointeau
    property alias tempsMaxiPointeau: tempsMaxiPointeau
    property alias batimentPointeau: batimentPointeau
    property alias etagePointeau: etagePointeau
    property alias textFieldTag: textFieldTag

    title: "Déroulement de la ronde"
    id: deroulementRonde
    padding: 10

    GridLayout {
        id: gridLayout
        width: parent.width
        height: parent.height
        visible: true
        columns: 2
        rows : 15

        Text {
            id: titre
            width: parent.width
            color: "#9c0101"
            text: qsTr("DEROULEMENT DE LA RONDE")
            verticalAlignment: Text.AlignVCenter
            font.italic: true
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 25
            Layout.columnSpan: 2
        }

        Text {
            id: message
            y: titre.height+10
            width: parent.width
            text: qsTr("Veuillez valider les pointeaux indiqués.")
            wrapMode: Text.WordWrap
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.bold: true
            font.pixelSize: 20
            Layout.columnSpan: 2
        }

        Text {
            id: nomRonde
            y: message.y+message.height+10
            font.underline: true
            font.pixelSize: 15
            Layout.columnSpan: 2
            text: Fonction.obtenirNomRondeCourante();
        }
        Rectangle {
            width:217
            height: 192
            border.width: 2
            radius: 5
            x:29
            y:110
            Layout.rowSpan: 10

            Component {
                id: representation // Manière dont s'affiche les données
                Row {
                    height: 30
                    spacing: 10
                    //Déclaration de variables QML qui font le lien avec celles en C++
                    required property string m_couleur
                    required property string m_designation
                    Text { text: " " } // pour ne pas coller la représentation graphique
                    Column {
                        Rectangle       // premier rectangle
                        {
                            x:5
                            width: 5
                            height: 8
                            color: "black"
                        }
                        Rectangle       // rond
                        {
                            id: etatPointeau
                            height: 15;
                            width: 14;
                            radius: 20
                            color: m_couleur
                        }
                        Rectangle   // deuxième rectangle
                        {
                            x:5
                            width: 5
                            height: 8
                            color: "black"
                        }
                    }
                    Text    //  texte correspondant
                    {
                        id: designationPointeau
                        y:8
                        text: m_designation
                        MouseArea{
                            anchors.fill: parent
                            onClicked: listePointeaux.currentIndex = index
                        }
                    }
                }
            }
            ListView {
                id: listePointeaux
                anchors.rightMargin: 13
                anchors.leftMargin: 14
                anchors.topMargin: 36
                anchors.bottomMargin: 40
                anchors.fill: parent
                model: pointeauxModel
                delegate: representation
            }
        }

        Text {
            id: emplacementPointeau
            x: 274
            y: 135
            width: 172
            height: 14
            font.pixelSize: 12
            Layout.column: 1
            Layout.row: 3
        }

        Text {
            id: batimentPointeau
            x: 274
            y: 155
            width: 172
            height: 14
            font.pixelSize: 12
            Layout.column: 1
            Layout.row: 4
        }

        Text {
            id: etagePointeau
            x: 274
            y: 175
            width: 172
            height: 14
            font.pixelSize: 12
            Layout.column: 1
            Layout.row: 5
        }

        Text {
            id: tempsMiniPointeau
            x: 274
            y: 195
            width: 172
            height: 14
            font.pixelSize: 12
            Layout.column: 1
            Layout.row: 6
        }

        Text {
            id: tempsMaxiPointeau
            x: 274
            y: 215
            width: 172
            height: 14
            font.pixelSize: 12
            Layout.column: 1
            Layout.row: 7
        }

        Button {
            id: buttonPointeauScanne
            x: 274
            y: 294
            Layout.column: 1
            Layout.row: 9
            text: qsTr("Pointeau scanné")
            onClicked: {
                //récupérer l'index courrant de l'item
                var item = listePointeaux.itemAtIndex(listePointeaux.currentIndex);
                //récupérer le nombre d'item dans la liste
                var nb = listePointeaux.count;
                console.log("nombre d'item dans la liste : " + nb);
                //récupérer l'index courant du pointeau
                var indexCourant = listePointeaux.currentIndex;
                //vérifier le tag donné
                var verif = Fonction.verifierTagPointeau();
                //si le resultat est correct
                if(verif === "correct"){
                    //vérifier si c'est le dernier pointeau de la liste
                    if(indexCourant === (nb-1)){
                        //il met le pointeau courant en vert
                        item.m_couleur = "#00FF00";
                        //il incrémente l'index courant
                        listePointeaux.incrementCurrentIndex();
                    }
                    else{
                        bdd.mettreAJourTableAEteEffectueePar();
                        //il met le pointeau courant en vert
                        item.m_couleur = "#00FF00";
                        //il incrémente l'index courant
                        listePointeaux.incrementCurrentIndex();
                        //il récupère l'index courrant
                        item = listePointeaux.itemAtIndex(listePointeaux.currentIndex);
                        //l'état du pointeau courrant devient bleu
                        item.m_couleur = "#0000FF";
                    }
                }
                else{
                    //le pointeau courant reste bleu
                    item.m_couleur = "#0000FF";
                    //le mauvais pointeau scanné devient orange
                    var fauxPointeau = listePointeaux.itemAtIndex(verif);
                    fauxPointeau.m_couleur = "#FFA500";
                }
            }
        }

        TextField {
            id: textFieldTag
            x: 274
            y: 248
            Layout.column: 1
            Layout.row: 8
            placeholderText: qsTr("Numéro de badge")
        }

        Button {
            id: buttonAnomalie
            x: 346
            y: 353
            Layout.column: 0
            Layout.row: 13
            text: qsTr("Anomalie")
            onClicked: {
                var item = listePointeaux.itemAtIndex(listePointeaux.currentIndex-1);
                //l'état devient rouge
                item.m_couleur = "#FF0000";
            }
        }

        Button {
            id: buttonIgnorerLePointeau
            x: 150
            y: 353
            Layout.column: 1
            Layout.row: 13
            text: qsTr("Ignorer le pointeau")
            onClicked: {
                var item = listePointeaux.itemAtIndex(listePointeaux.currentIndex);
                //l'état devient rouge
                item.m_couleur = "#FF0000";
                //il incrémente l'index courant
                listePointeaux.incrementCurrentIndex();
                //il récupère l'index courant
                item = listePointeaux.itemAtIndex(listePointeaux.currentIndex);
                //l'état du pointeau courant devient bleu
                item.m_couleur = "#0000FF";
            }
        }


        Button {
            id: buttonInterrompreLaRonde
            x: 21
            y: 353
            width: 146
            height: 40
            Layout.column: 0
            Layout.row: 14
            text: qsTr("Interrompre la ronde")
            onClicked: dialogVerif.open()
        }

        Dialog {
            id: dialogVerif
            title: "Interruption de la ronde"
            onAccepted: Qt.quit();
            onRejected: {
                this.close()
            }

            contentItem: Rectangle{
                Column{
                    anchors.fill: parent
                    Text{
                        text: "Voulez-vous interrompre la ronde ?"
                    }
                    Button{
                        id: valider
                        text: "Valider"
                        onClicked: dialogVerif.accepted()
                    }
                    Button{
                        id: annuler
                        text: "Annuler"
                        onClicked: dialogVerif.rejected()
                    }
                }
            }
        }
    }
}
