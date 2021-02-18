import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import QtQml.Models 2.15

Item {
    Rectangle
    {
        width: 200; height: 90
        border.width: 2
        radius: 5
        x:50
        y:200

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
            anchors.fill: parent
            model: pointeauxModel
            delegate: representation
        }
    }

    Button {
        id: buttonAnomalie
        x: 215
        y: 126
        text: qsTr("Anomalie")
        onClicked: {
            var item = listePointeaux.itemAtIndex(listePointeaux.currentIndex);
            //l'état devient rouge
            //item.etat = Qt.rgba(255, 0, 0);
            item.etat = "#FF0000";
        }
    }
    Button {
        id: buttonScanner
        x: 350
        y: 126
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
}
