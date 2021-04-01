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
    var nomRondeCourante = ronde.obtenirNomRondeCourante();
    console.log(nomRondeCourante);
    return nomRondeCourante;
}

function obtenirDesignationPointeau(){
    var idronde = ronde.obtenirIdRondeCourante();
    var designationPointeau = pointeau.obtenirListeDesignationsPointeaux(idronde);
    console.log(Array.from(designationPointeau));
    return Array.from(designationPointeau);
}

function obtenirCouleurPointeau(){
    var couleurPointeau = pointeau.obtenirListeCouleursPointeaux();
    console.log(Array.from(couleurPointeau));
    return Array.from(couleurPointeau);
}
