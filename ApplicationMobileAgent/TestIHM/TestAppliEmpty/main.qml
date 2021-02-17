import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import QtQml.Models 2.15

Window {
    //@disable-check M16
    visible: true
    //@disable-check M16
    width: 640
    //@disable-check M16
    height: 480
    //@disable-check M16
    title: qsTr("Test")

    //    RoundButton {
    //        id: roundButton
    //        x: 345
    //        y: 79
    //        background: Rectangle{
    //            radius : roundButton.radius
    //            color : "green"
    //        }
    //    }

    //    BusyIndicator {
    //        id: busyIndicator
    //        x: 290
    //        y: 148
    //    }
    //    Text {
    //        id: element1
    //        x: 37
    //        y: 209
    //        width: 126
    //        height: 15
    //        text: qsTr("Plateau sportif")
    //        font.pixelSize: 12
    //    }

    //    Text {
    //        id: element2
    //        x: 338
    //        y: 52
    //        width: 126
    //        height: 15
    //        text: qsTr("Accueil")
    //        font.pixelSize: 12
    //    }

    //    Text {
    //        id: element3
    //        x: 190
    //        y: 234
    //        width: 126
    //        height: 15
    //        text: qsTr("Cour d'honneur")
    //        font.pixelSize: 12
    //    }

    //    Text {
    //        id: element4
    //        x: 24
    //        y: 179
    //        width: 126
    //        height: 15
    //        text: qsTr("Self")
    //        font.pixelSize: 12
    //    }

//    ListModel {
//        id: pointeaux
//        ListElement {
//            //@disable-check M16
//            name: "Accueil"
//        }
//        ListElement {
//            //@disable-check M16
//            name: "Cours d'honneur"
//        }
//    }



    //    RoundButton{
    //        id: rouge
    //        background: Rectangle{
    //            radius: rouge.radius
    //            color: "red"
    //        }
    //    }

    //    Image {
    //        id: rondBleu
    //        source: "qrc:/img/rondBleu.png"
    //    }

//    ListView{
//        x: 105
//        width : 180
//        height: 200
//        model : pointeaux
//        delegate: Text {
//            text: name
//        }
//    }
//    ObjectModel{
//        id: images
//        Rectangle{ height : 20; width : 20; color : pointCouleur.changerCouleur(3) ; radius : 50}
//        Rectangle{ height : 20; width : 20; color : pointCouleur.changerCouleur(2) ; radius : 50}
//        Rectangle{ height : 20; width : 20; color : pointCouleur.changerCouleur(0) ; radius : 50}
//        Rectangle{ height : 20; width : 20; color : pointCouleur.changerCouleur(4) ; radius : 50}
//        Rectangle{ height : 20; width : 20; color : pointCouleur.changerCouleur(1) ; radius : 50}
//    }
//    ListView{
//        id: points
//        anchors.fill: parent
//        ScrollBar.vertical: ScrollBar{active:true}

//        model : images

//    }
    Rectangle
    {
        width: 200; height: 90
        border.width: 2
        radius: 5
        x:50
        y:200

//        ListModel
//        {
//            id: modelPointeaux // Données -> liste de pointeaux

//            ListElement {
//                lieu: pointeauxModel.name
//                etat : pointeauxModel.etat
//            }
//            ListElement {
//                lieu: pointeauxModel.name
//                etat: pointeauxModel.etat
//            }
//            ListElement {
//                lieu: pointeauxModel.name
//                etat: pointeauxModel.etat
//            }

//            ListElement {
//                lieu: pointeauxModel.name
//                etat : pointeauxModel.etat
//            }
//            ListElement {
//                lieu: pointeauxModel.name
//                etat: pointeauxModel.etat
//            }
//            ListElement {
//                lieu: pointeauxModel.name
//                etat: pointeauxModel.etat
//            }
//        }

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
