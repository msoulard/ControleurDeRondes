function changerPage() {
    console.log("boutton appuyer");
    leRondier.currentIndex = leRondier.currentIndex+1;
}

function obtenirNomRondes(){
    var nomRonde = bdd.obtenirListeNomsRondes("1B4DBE53");
    console.log(Array.from(nomRonde));
    return Array.from(nomRonde);
}

function obtenirNomRondeCourante(){
    var listeNomsRondes = obtenirNomRondes();
    var nomRondeCourante = listeNomsRondes[1];
    console.log(nomRondeCourante);
    return nomRondeCourante;
}

function obtenirDesignationPointeau(){
    var listeDesignationPointeaux = bdd.obtenirListeDesignationsPointeaux();
    var pointeauCourant = deroulementRonde.listePointeaux.currentIndex;
    console.log(pointeauCourant);
    var designationPointeau = listeDesignationPointeaux[pointeauCourant-1];
    console.log(designationPointeau);
    return designationPointeau;
}

function obtenirEmplacementPointeau(){
    var listeEmplacement = bdd.obtenirListeEmplacementPointeaux();
    var pointeauCourant = deroulementRonde.listePointeaux.currentIndex;
    var emplacementPointeau = listeEmplacement[pointeauCourant-1];
    console.log(emplacementPointeau);
    return emplacementPointeau;
}
