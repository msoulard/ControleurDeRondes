function changerPage() {
    //console.log("boutton appuyer");
    leRondier.currentIndex = leRondier.currentIndex+1;
}

function obtenirNomRondes(){
    var nomRonde = bdd.obtenirListeNomsRondes();
    //console.log(Array.from(nomRonde));
    return Array.from(nomRonde);
}

function obtenirNomRondeCourante(){
    var listeNomsRondes = obtenirNomRondes();
    var nomRondeCourante = listeNomsRondes[1];
    //console.log(nomRondeCourante);
    return nomRondeCourante;
}

function obtenirDesignationPointeau(){
    var listeDesignationPointeaux = bdd.obtenirListeDesignationsPointeaux();
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

function obtenirEmplacementPointeau(){
    var listeEmplacement = bdd.obtenirListeEmplacementPointeaux();
    var pointeauCourant = deroulementRonde.listePointeaux.currentIndex;
    var emplacementPointeau = listeEmplacement[pointeauCourant];
    //console.log(emplacementPointeau);
    return emplacementPointeau;
}

function obtenirTempsMiniPointeau(){
    var listeTempsMini = bdd.obtenirListeTempsMiniPointeaux();
    var pointeauCourant = deroulementRonde.listePointeaux.currentIndex;
    var tempsMini = listeTempsMini[pointeauCourant];
    //console.log(tempsMini);
    return tempsMini;
}

function obtenirTempsMaxiPointeau(){
    var listeTempsMaxi = bdd.obtenirListeTempsMaxiPointeaux();
    var pointeauCourant = deroulementRonde.listePointeaux.currentIndex;
    var tempsMaxi = listeTempsMaxi[pointeauCourant];
    //console.log(tempsMaxi);
    return tempsMaxi;
}

function obtenirBatimentPointeau(){
    var listeBatiments = bdd.obtenirListeBatimentPointeaux();
    var pointeauCourant = deroulementRonde.listePointeaux.currentIndex;
    var batiment = listeBatiments[pointeauCourant];
    //console.log(batiment);
    return batiment;
}

function obtenirEtagePointeau(){
    var listeEtage = bdd.obtenirListeEtagePointeaux();
    var pointeauCourant = deroulementRonde.listePointeaux.currentIndex;
    var etage = listeEtage[pointeauCourant];
   //console.log(etage);
    return etage;
}

function verifierTagPointeau(){
    var pointeauCourant= deroulementRonde.listePointeaux.currentIndex;
    var listeTag = bdd.obtenirListeTagPointeaux();
    var tagPointeau = listeTag[pointeauCourant];
    var tagCourant = deroulementRonde.textFieldTag.text;
    var resultat;
    console.log("tag courant : " + tagCourant);
    console.log("tag du pointeau : " + tagPointeau);
    if(tagCourant === tagPointeau){
        //le tag est correct
        resultat = "correct";
        console.log("pointeau scanné ok");
    }
    else{
        console.log("mauvais pointeau scanné");
        for(var i = 0 ; i < listeTag.length ; i++){
            if(i !== pointeauCourant){
                if(tagCourant === listeTag[i]){
                    resultat = i;
                    console.log("index mauvais pointeau scanné : " + resultat);
                }
            }
        }
    }
    return resultat;
}
