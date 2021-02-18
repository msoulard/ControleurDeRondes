import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import QtQml.Models 2.15

ApplicationWindow {

    //@disable-check M16
    visible: true
    //@disable-check M16
    width: 640
    //@disable-check M16
    height: 480
    //@disable-check M16
    title: qsTr("Test")

    SwipeView{
        anchors.fill: parent
        id: leRondier
        required property int pageCourrante
        currentIndex: pageCourrante
        Identification{
            id: identification
            boutonSelectionRonde.onClicked: {
                pageCourrante = currentIndex + 1;

            }

        }

        SelectionRonde{
            id: selectionRonde
        }
    }


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

}
