function changerPage() {
    console.log("boutton appuyer");
    leRondier.currentIndex = leRondier.currentIndex+1;
}

function obtenirNomRondes(){
    var nomRonde = ronde.obtenirListeRondes("1B4DBE53");
    console.log(Array.from(nomRonde));
    return Array.from(nomRonde);
}

function obtenirNomRondeCourante(){
    obtenirNomRondes();
    var nomRondeCourante = ronde.obtenirNomRondeCourante();
    console.log(nomRondeCourante);
    return nomRondeCourante;
}

function obtenirDesignationPointeau(){
    var pointeauCourant = deroulementRonde.listePointeaux.currentIndex;
    var designationPointeau = pointeau.
    console.log(designationPointeau);
    return designationPointeau;
}
