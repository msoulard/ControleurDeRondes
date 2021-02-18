import QtQuick 2.0
import QtQuick.Controls 2.15

ListModel {
    ListElement {
        name: "Accueil"
        image: rondBleu
    }
    ListElement {
        name: "Cours d'honneur"
        image : rondBleu
    }
    Image {
        id: rondBleu
        source: "qrc:/img/rondBleu.png"
    }
}


