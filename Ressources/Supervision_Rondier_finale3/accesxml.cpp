/**
  * \file accesxml.cpp
  * \brief Définition des méthodes de la classe AccesXML
  * \version 1.0
  * \author Gabriel Lemée
  * \date 2 avril 2017
  *
  * Classe de gestion des acces au fichier de configuration XML.
  */

#include "accesxml.h"

AccesXML::AccesXML()
{
    configurationBDD = NULL;
}
/**
 * @brief AccesXML::LireConfiguration
 * @param fichierConfig
 */
void AccesXML::LireConfiguration(QString fichierConfig)
{
    QFile fichier(fichierConfig);
    if(!fichier.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Impossible de lire le fichier : " << fichier.errorString();
    }
    else
    {
        QXmlStreamReader lecteurXML(&fichier);

        if (lecteurXML.readNextStartElement()) {
            if (lecteurXML.name() == "configuration")
            {
                ///Création de la configuration
                configurationBDD = new typeConfigurationBDD;
                while(lecteurXML.readNextStartElement())
                {
                    if (lecteurXML.name() == "ipServeurBDD")
                    {
                        configurationBDD->ipServeurBDD = lecteurXML.readElementText();
                    }
                    if (lecteurXML.name() == "portServeurBDD")
                    {
                        configurationBDD->portServeurBDD = lecteurXML.readElementText().toInt();
                    }
                    if (lecteurXML.name() == "nomBDD")
                    {
                        configurationBDD->nomBDD = lecteurXML.readElementText();
                    }
                    if (lecteurXML.name() == "utilisateurBDD")
                    {
                        configurationBDD->utilisateurBDD = lecteurXML.readElementText();
                    }
                    if (lecteurXML.name() == "motDePasseBDD")
                    {
                        configurationBDD->motDePasseBDD = lecteurXML.readElementText();
                    }
                    if (lecteurXML.name() == "cheminImageClient")
                    {
                        cheminImageClient = lecteurXML.readElementText();
                    }
                    if (lecteurXML.name() == "cheminDossierImages")
                    {
                        cheminDossierImages = lecteurXML.readElementText();
                    }
                    if (lecteurXML.name() == "telephoneDefaut")
                    {
                        telephoneDefaut = lecteurXML.readElementText();
                    }
                }
            }
            else
            {
                lecteurXML.raiseError(QObject::tr("Fichier incorrect."));
            }
        }
        ///Fermeture du fichier
        fichier.close();
    }
}
/**
 * @brief AccesXML::EcrireConfiguration
 * @param fichierConfig
 */
void AccesXML::EcrireConfiguration(QString fichierConfig)
{
    QFile fichier(fichierConfig);
    if (configurationBDD != NULL)
    {
        bool ouvert = fichier.open(QIODevice::WriteOnly | QIODevice::Text);
        if (!ouvert)
        {
            qDebug() << "Impossible d'ouvrir le fichier";
        }
        else
        {
            qDebug() << "Fichier ouvert";

            QXmlStreamWriter ecrireXML(&fichier);

            ecrireXML.setAutoFormatting(true);
            ecrireXML.writeStartDocument();
            ecrireXML.writeStartElement("configuration");
            ecrireXML.writeTextElement("ipServeurBDD",configurationBDD->ipServeurBDD);
            ecrireXML.writeTextElement("portServeurBDD",QString::number(configurationBDD->portServeurBDD));
            ecrireXML.writeTextElement("nomBDD",configurationBDD->nomBDD);
            ecrireXML.writeTextElement("utilisateurBDD",configurationBDD->utilisateurBDD);
            ecrireXML.writeTextElement("motDePasseBDD",configurationBDD->motDePasseBDD);
            ecrireXML.writeTextElement("cheminImageClient",cheminImageClient);
            ecrireXML.writeTextElement("cheminDossierImages",cheminDossierImages);
            ecrireXML.writeTextElement("telephoneDefaut",telephoneDefaut);
            ///Fin de configuration
            ecrireXML.writeEndElement();
            ecrireXML.writeEndDocument();
            fichier.close();
        }
    }
}
/**
 * @brief AccesXML::ObtenirConfigurationBDD
 * @return
 */
typeConfigurationBDD *AccesXML::ObtenirConfigurationBDD() const
{
    return configurationBDD;
}
/**
 * @brief AccesXML::DefinirConfigurationBDD
 * @param config
 */
void AccesXML::DefinirConfigurationBDD(typeConfigurationBDD *config)
{
    configurationBDD = config;
}
/**
 * @brief AccesXML::ObtenirCheminDossierImages
 * @return
 */
QString AccesXML::ObtenirCheminDossierImages() const
{
    return cheminDossierImages;
}
/**
 * @brief AccesXML::DefinirCheminDossierImages
 * @param value
 */
void AccesXML::DefinirCheminDossierImages(const QString &value)
{
    cheminDossierImages = value;
}
/**
 * @brief AccesXML::ObtenirCheminImageClient
 * @return
 */
QString AccesXML::ObtenirCheminImageClient() const
{
    return cheminImageClient;
}
/**
 * @brief AccesXML::DefinirCheminImageClient
 * @param value
 */
void AccesXML::DefinirCheminImageClient(const QString &value)
{
    cheminImageClient = value;
}
/**
 * @brief AccesXML::ObtenirTelephoneDefaut
 * @return
 */
QString AccesXML::ObtenirTelephoneDefaut() const
{
    return telephoneDefaut;
}
/**
 * @brief AccesXML::DefinirTelephoneDefaut
 * @param value
 */
void AccesXML::DefinirTelephoneDefaut(const QString &value)
{
    telephoneDefaut = value;
}
