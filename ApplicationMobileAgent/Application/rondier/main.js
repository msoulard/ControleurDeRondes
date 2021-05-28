function obtenirNomAgent(_numBadge) {
    rondier.mettreAJourAgent(_numBadge);
    var prenomNom = agent.obtenirPrenomNom();
    return prenomNom;
}

function changerPage() {
    console.log("boutton appuyer");
    leRondier.currentIndex = leRondier.currentIndex+1;
}

function obtenirListeNomsRonde(){
    var listeNoms = rondier.obtenirRondes();
    return Array.from(listeNoms);
}

function obtenirRondeChoisie(_index){
    var nomRonde = rondier.obtenirNomRondeCourante(_index);
    return nomRonde;
}
