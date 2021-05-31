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

function obtenirDesignationPointeau(){
    var listeDesignations = rondier.obtenirListeDesignations();
    var pointeauCourant = deroulementRonde.listePointeaux.currentIndex;
    return listeDesignations[pointeauCourant];
}

function obtenirBatimentPointeau(){
    var listeBatiments = rondier.obtenirListeBatiments();
    var pointeauCourant = deroulementRonde.listePointeaux.currentIndex;
    return listeBatiments[pointeauCourant];
}

function obtenirEtagePointeau(){
    var listeEtages = rondier.obtenirListeEtages();
    var pointeauCourant = deroulementRonde.listePointeaux.currentIndex;
    return listeEtages[pointeauCourant];
}

function obtenirTempsMiniPointeau(){
    var listeTempsMini = rondier.obtenirListeTempsMini();
    var pointeauCourant = deroulementRonde.listePointeaux.currentIndex;
    return listeTempsMini[pointeauCourant];
}

function obtenirTempsMaxiPointeau(){
    var listeTempsMaxi = rondier.obtenirListeTempsMaxi();
    var pointeauCourant = deroulementRonde.listePointeaux.currentIndex;
    return listeTempsMaxi[pointeauCourant];
}

function verifierTagPointeau(){
    var pointeauCourant= deroulementRonde.listePointeaux.currentIndex;
    var listeTag = rondier.obtenirListeTags();
    var tagPointeau = listeTag[pointeauCourant];
    var tagCourant = deroulementRonde.textFieldTag.text;
    var resultat;
    console.log("tag courant : " + tagCourant);
    console.log("tag du pointeau : " + tagPointeau);

    if(pointeauCourant === 0){
        rondier.mettreAJourTableAEteEffectueeParBDD(pointeauCourant);
    }

    if(tagCourant === tagPointeau){
        //le tag est correct
        resultat = "correct";
        console.log("pointeau scanné ok");
        rondier.mettreAJourTableAEteScanneParSansAnomalieBDD(pointeauCourant);
    }
    else{
        console.log("mauvais pointeau scanné");
        for(var i = 0 ; i < listeTag.length ; i++){
            if(i !== pointeauCourant){
                if(tagCourant === listeTag[i]){
                    resultat = i;
                    console.log("index mauvais pointeau scanné : " + resultat);
                    rondier.mettreAJourTableAEteScanneParAvecAnomalieBDD(1);
                }
            }
        }
    }

    return resultat;
}

function obtenirDesignationPointeauAnomalie(){
    var listeDesignationPointeaux = rondier.obtenirListeDesignations();
    var pointeauCourant = deroulementRonde.listePointeaux.currentIndex;
    //console.log(pointeauCourant);
    var designationPointeau;
    if(pointeauCourant === 0){
        designationPointeau = listeDesignationPointeaux[pointeauCourant];
    }
    else{
        designationPointeau = listeDesignationPointeaux[pointeauCourant-1];
    }

    //console.log(designationPointeau);
    return designationPointeau;
}

function obtenirEmplacementPointeauAnomalie(){
    var listeEmplacementsPointeaux = rondier.obtenirListeEmplacements();
    var pointeauCourant = deroulementRonde.listePointeaux.currentIndex;
    //console.log(pointeauCourant);
    var emplacementPointeau;
    if(pointeauCourant === 0){
        emplacementPointeau = listeEmplacementsPointeaux[pointeauCourant];
    }
    else{
        emplacementPointeau = listeEmplacementsPointeaux[pointeauCourant-1];
    }
    return emplacementPointeau;
}
