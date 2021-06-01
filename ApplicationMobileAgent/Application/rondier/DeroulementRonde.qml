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
    property alias designationPointeau : designationPointeau
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
            Layout.columnSpan: 2
            color: "#9c0101"
            text: qsTr("DEROULEMENT DE LA RONDE")
            verticalAlignment: Text.AlignVCenter
            font.italic: true
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 25
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
        }
        Rectangle {
            width:parent.width/3
            height: parent.height/2
            border.width: 2
            radius: 5
            y: nomRonde.y+nomRonde.height+10
            Layout.rowSpan: 10

            Component {
                id: representation // Manière dont s'affiche les données
                Row {
                    height: 30
                    spacing: 10
                    //Déclaration de variables QML qui font le lien avec celles en C++
                    required property string m_couleur
                    required property string m_emplacement
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
                        text: m_emplacement
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
                delegate: representation
            }
        }

        GroupBox {
            id: groupBoxPointeau
            width: parent.width/2
            height: designationPointeau.height+batimentPointeau.height+etagePointeau.height+tempsMiniPointeau.height+tempsMaxiPointeau.height
            Layout.column: 1
            Layout.row: 2
            Layout.rowSpan: 5
            title: qsTr("Pointeau suivant :")

            ColumnLayout{
                anchors.fill: parent
                Text {
                    id: designationPointeau
                    width: parent.width
                    font.pixelSize: 12
                }

                Text {
                    id: batimentPointeau
                    y: designationPointeau.y+designationPointeau.height+5
                    width: parent.width
                    font.pixelSize: 12
                }

                Text {
                    id: etagePointeau
                    y: batimentPointeau.y+batimentPointeau.height+5
                    width: parent.width
                    font.pixelSize: 12
                }

                Text {
                    id: tempsMiniPointeau
                    y: etagePointeau.y+etagePointeau.height+5
                    width: parent.width
                    font.pixelSize: 12
                }

                Text {
                    id: tempsMaxiPointeau
                    y: tempsMiniPointeau.y+tempsMiniPointeau.height+5
                    width: parent.width
                    font.pixelSize: 12
                }
            }
        }

        Button {
            id: buttonPointeauScanne
            Layout.column: 1
            Layout.row: 9
            text: qsTr("Pointeau scanné")
            onClicked: {
                //récupérer l'index courant de l'item
                var item = listePointeaux.itemAtIndex(listePointeaux.currentIndex);
                //récupérer le nombre d'item dans la liste
                var nb = listePointeaux.count;
                //console.log("nombre d'item dans la liste : " + nb);
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
            Layout.column: 1
            Layout.row: 8
            placeholderText: qsTr("Numéro de badge")
        }

        Button {
            id: buttonAnomalie
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

        Connections {
            target: lecteurNFC
            onTagDetecte: {
                console.log("Tag : " + tagNFC)
                textFieldTag.text = tagNFC;
                var tag = tagNFC;
                //récupérer l'index courant de l'item
                var item = listePointeaux.itemAtIndex(listePointeaux.currentIndex);
                //récupérer le nombre d'item dans la liste
                var nb = listePointeaux.count;
                //récupérer l'index courant du pointeau
                var indexCourant = listePointeaux.currentIndex;
                //vérifier le tag donné
                var verif = Fonction.verifierTagPointeauNFC(tag);
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

        Button {
            id: buttonInterrompreLaRonde
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
