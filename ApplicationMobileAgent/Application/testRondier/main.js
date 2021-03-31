function changerPage() {
    console.log("boutton appuyer");
    leRondier.currentIndex = leRondier.currentIndex+1;
}

function obtenirNomRondes(){
    var nomRonde = ronde.obtenirListeRondes("1B4DBE53");
    console.log(nomRonde);
    console.log(Array.from(nomRonde));
    return Array.from(nomRonde);
}
