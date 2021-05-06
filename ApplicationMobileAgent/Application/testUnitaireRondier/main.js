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
    obtenirNomRondes();
    ronde.mettreAJourIndexCourant(1);
    var nomRondeCourante = ronde.obtenirNomRondeCourante();
    console.log(nomRondeCourante);
    return nomRondeCourante;
}

function obtenirDesignationPointeau(){
    //var pointeauCourant = deroulementRonde.listePointeaux.currentIndex;
    var designationPointeau = pointeau.getDesignation();
    console.log(designationPointeau);
    return designationPointeau;
}
