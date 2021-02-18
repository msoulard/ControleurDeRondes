import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import QtQml.Models 2.15

Page {
    property alias buttonAnomalie: buttonAnomalie
    property alias buttonPointeauScanne: buttonPointeauScanne
    property alias buttonInterrompreLaRonde: buttonInterrompreLaRonde
    property alias buttonIgnorerLePointeau: buttonIgnorerLePointeau
    width: 600

    title: "Déroulement de la ronde"

    GridLayout {
        id: gridLayout
        x: 0
        y: 0
        width: 560


        columns: 2

        Text {
            id: titre
            x: 21
            y: -60
            width: 600
            height: 46
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
            x: 14
            y: -45
            width: 592
            height: 45
            text: qsTr("Veuillez valider les pointeaux indiqués.")
            wrapMode: Text.WordWrap
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.wordSpacing: 0
            renderType: Text.QtRendering
            font.bold: true
            font.pixelSize: 20
            Layout.columnSpan: 2
        }

        Text {
            id: nomRonde
            x: 84
            y: -39
            width: 400
            height: 15
            text: qsTr("Nom de la ronde")
            font.underline: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 15
            Layout.columnSpan: 2
        }
        Rectangle
        {
            width:217; height: 192
            border.width: 2
            radius: 5
            x:-235
            y:125
            Layout.rowSpan: 3

            Component
            {
                id: representation // Manière dont s'affiche les données


                Row
                {
                    height: 30
                    spacing: 10
                    required property string etat
                    required property string lieu
                    Text { text: " " } // pour ne pas coller la représentation graphique
                    Column
                    {
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

                            color: etat
                            radius: 20
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
                        y:8
                        text: lieu
                    }
                }
            }

            ListView
            {
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

        Button {
            id: buttonAnomalie
            x: 626
            y: 332
            text: qsTr("Anomalie")
            onClicked: {
                var item = listePointeaux.itemAtIndex(listePointeaux.currentIndex);
                //l'état devient rouge
                //item.etat = Qt.rgba(255, 0, 0);
                item.etat = "#FF0000";
            }
        }
        Button {
            id: buttonPointeauScanne
            x: 398
            y: 417
            text: qsTr("Pointeau scanné")
            onClicked: {
                //récupérer l'index courrant de l'item
                var item = listePointeaux.itemAtIndex(listePointeaux.currentIndex);
                //si la couleur est bleu
                if(item.etat === "#0000FF"){
                    //il met en vert
                    item.etat = "#00FF00";
                }
                //il incrémente l'index courant
                listePointeaux.incrementCurrentIndex();
                //il récupère l'index courrant
                item = listePointeaux.itemAtIndex(listePointeaux.currentIndex);
                //l'état du pointeau courrant devient bleu
                item.etat = "#0000FF";

            }
        }

        Button {
            id: buttonInterrompreLaRonde
            x: 42
            y: 410
            width: 146
            height: 40
            text: qsTr("Interrompre la ronde")
        }

        Button {
            id: buttonIgnorerLePointeau
            x: 575
            y: 417
            text: qsTr("Ignorer le pointeau")
        }

        Text {
            id: descriptionPointeau
            x: 626
            y: 68
            width: 172
            height: 126
            text: qsTr("Description :")
            font.pixelSize: 12
        }


    }
}
