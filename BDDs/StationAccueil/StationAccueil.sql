-- phpMyAdmin SQL Dump
-- version 4.6.6deb4
-- https://www.phpmyadmin.net/
--
-- Client :  localhost:3306
-- Généré le :  Ven 02 Avril 2021 à 15:07
-- Version du serveur :  10.1.41-MariaDB-0+deb9u1
-- Version de PHP :  7.0.33-0+deb9u6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `StationAccueil`
--

-- --------------------------------------------------------

--
-- Structure de la table `aEteEffectueePar`
--

CREATE TABLE `aEteEffectueePar` (
  `id_historiqueRonde` int(11) NOT NULL,
  `id_ronde` int(11) DEFAULT NULL,
  `id_agent` int(11) DEFAULT NULL,
  `date_heure` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `aEteScannePar`
--

CREATE TABLE `aEteScannePar` (
  `id` int(11) NOT NULL,
  `id_pointeau` int(11) DEFAULT NULL,
  `id_anomalie` int(11) DEFAULT NULL,
  `ordre` int(11) DEFAULT NULL,
  `date_heure` datetime DEFAULT NULL,
  `id_historiqueRonde` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `agents`
--

CREATE TABLE `agents` (
  `id_agent` int(11) NOT NULL,
  `nom` varchar(30) DEFAULT NULL,
  `prenom` varchar(30) DEFAULT NULL,
  `numbadge` varchar(10) DEFAULT NULL,
  `statut` tinyint(1) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `anomalies`
--

CREATE TABLE `anomalies` (
  `id_anomalie` int(11) NOT NULL,
  `description` varchar(150) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `comporte`
--

CREATE TABLE `comporte` (
  `id` int(11) NOT NULL,
  `id_ronde` int(11) NOT NULL,
  `id_pointeau` int(11) NOT NULL,
  `ordre` int(11) DEFAULT NULL,
  `tempsmini` time(4) DEFAULT NULL,
  `tempsmaxi` time(4) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `lieux`
--

CREATE TABLE `lieux` (
  `id_lieu` int(11) NOT NULL,
  `batiment` varchar(30) DEFAULT NULL,
  `etage` varchar(30) DEFAULT NULL,
  `emplacement` varchar(30) DEFAULT NULL,
  `id_pointeau` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `peutFaire`
--

CREATE TABLE `peutFaire` (
  `id` int(11) NOT NULL,
  `id_agent` int(11) NOT NULL,
  `id_ronde` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `photos`
--

CREATE TABLE `photos` (
  `id_photo` int(11) NOT NULL,
  `chemin` varchar(300) DEFAULT NULL,
  `id_anomalie` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `pointeaux`
--

CREATE TABLE `pointeaux` (
  `id_pointeau` int(11) NOT NULL,
  `designation` varchar(30) DEFAULT NULL,
  `statut` tinyint(1) DEFAULT NULL,
  `tag_mifare` varchar(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `responsables`
--

CREATE TABLE `responsables` (
  `id_responsable` int(11) NOT NULL,
  `nom` varchar(30) DEFAULT NULL,
  `prenom` varchar(30) DEFAULT NULL,
  `numbadge` varchar(10) DEFAULT NULL,
  `login` varchar(60) DEFAULT NULL,
  `mdp` varchar(128) DEFAULT NULL,
  `statut` tinyint(1) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `rondes`
--

CREATE TABLE `rondes` (
  `id_ronde` int(11) NOT NULL,
  `nom` varchar(30) DEFAULT NULL,
  `statut` tinyint(1) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Index pour les tables exportées
--

--
-- Index pour la table `aEteEffectueePar`
--
ALTER TABLE `aEteEffectueePar`
  ADD PRIMARY KEY (`id_historiqueRonde`),
  ADD KEY `id_ronde` (`id_ronde`),
  ADD KEY `id_agent` (`id_agent`);

--
-- Index pour la table `aEteScannePar`
--
ALTER TABLE `aEteScannePar`
  ADD PRIMARY KEY (`id`),
  ADD KEY `id_pointeau` (`id_pointeau`),
  ADD KEY `id_anomalie` (`id_anomalie`),
  ADD KEY `aEteScannePar_ibfk_5` (`id_historiqueRonde`);

--
-- Index pour la table `agents`
--
ALTER TABLE `agents`
  ADD PRIMARY KEY (`id_agent`);

--
-- Index pour la table `anomalies`
--
ALTER TABLE `anomalies`
  ADD PRIMARY KEY (`id_anomalie`);

--
-- Index pour la table `comporte`
--
ALTER TABLE `comporte`
  ADD PRIMARY KEY (`id`),
  ADD KEY `id_pointeau` (`id_pointeau`),
  ADD KEY `id_ronde` (`id_ronde`);

--
-- Index pour la table `lieux`
--
ALTER TABLE `lieux`
  ADD PRIMARY KEY (`id_lieu`),
  ADD KEY `id_pointeau` (`id_pointeau`);

--
-- Index pour la table `peutFaire`
--
ALTER TABLE `peutFaire`
  ADD PRIMARY KEY (`id`),
  ADD KEY `id_ronde` (`id_ronde`),
  ADD KEY `id_agent` (`id_agent`);

--
-- Index pour la table `photos`
--
ALTER TABLE `photos`
  ADD PRIMARY KEY (`id_photo`),
  ADD KEY `fk_photos_anomalies1_idx` (`id_anomalie`);

--
-- Index pour la table `pointeaux`
--
ALTER TABLE `pointeaux`
  ADD PRIMARY KEY (`id_pointeau`);

--
-- Index pour la table `responsables`
--
ALTER TABLE `responsables`
  ADD PRIMARY KEY (`id_responsable`);

--
-- Index pour la table `rondes`
--
ALTER TABLE `rondes`
  ADD PRIMARY KEY (`id_ronde`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `aEteEffectueePar`
--
ALTER TABLE `aEteEffectueePar`
  MODIFY `id_historiqueRonde` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `aEteScannePar`
--
ALTER TABLE `aEteScannePar`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `agents`
--
ALTER TABLE `agents`
  MODIFY `id_agent` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `anomalies`
--
ALTER TABLE `anomalies`
  MODIFY `id_anomalie` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `comporte`
--
ALTER TABLE `comporte`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `lieux`
--
ALTER TABLE `lieux`
  MODIFY `id_lieu` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `peutFaire`
--
ALTER TABLE `peutFaire`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `photos`
--
ALTER TABLE `photos`
  MODIFY `id_photo` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `pointeaux`
--
ALTER TABLE `pointeaux`
  MODIFY `id_pointeau` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;
--
-- AUTO_INCREMENT pour la table `responsables`
--
ALTER TABLE `responsables`
  MODIFY `id_responsable` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `rondes`
--
ALTER TABLE `rondes`
  MODIFY `id_ronde` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;
--
-- Contraintes pour les tables exportées
--

--
-- Contraintes pour la table `aEteEffectueePar`
--
ALTER TABLE `aEteEffectueePar`
  ADD CONSTRAINT `aEteEffectueePar_ibfk_1` FOREIGN KEY (`id_ronde`) REFERENCES `rondes` (`id_ronde`),
  ADD CONSTRAINT `aEteEffectueePar_ibfk_2` FOREIGN KEY (`id_agent`) REFERENCES `agents` (`id_agent`);

--
-- Contraintes pour la table `aEteScannePar`
--
ALTER TABLE `aEteScannePar`
  ADD CONSTRAINT `aEteScannePar_ibfk_3` FOREIGN KEY (`id_pointeau`) REFERENCES `pointeaux` (`id_pointeau`),
  ADD CONSTRAINT `aEteScannePar_ibfk_4` FOREIGN KEY (`id_anomalie`) REFERENCES `anomalies` (`id_anomalie`),
  ADD CONSTRAINT `aEteScannePar_ibfk_5` FOREIGN KEY (`id_historiqueRonde`) REFERENCES `aEteEffectueePar` (`id_historiqueRonde`);

--
-- Contraintes pour la table `comporte`
--
ALTER TABLE `comporte`
  ADD CONSTRAINT `comporte_ibfk_1` FOREIGN KEY (`id_pointeau`) REFERENCES `pointeaux` (`id_pointeau`),
  ADD CONSTRAINT `comporte_ibfk_2` FOREIGN KEY (`id_ronde`) REFERENCES `rondes` (`id_ronde`);

--
-- Contraintes pour la table `lieux`
--
ALTER TABLE `lieux`
  ADD CONSTRAINT `lieux_ibfk_1` FOREIGN KEY (`id_pointeau`) REFERENCES `pointeaux` (`id_pointeau`);

--
-- Contraintes pour la table `peutFaire`
--
ALTER TABLE `peutFaire`
  ADD CONSTRAINT `peutFaire_ibfk_1` FOREIGN KEY (`id_ronde`) REFERENCES `rondes` (`id_ronde`),
  ADD CONSTRAINT `peutFaire_ibfk_2` FOREIGN KEY (`id_agent`) REFERENCES `agents` (`id_agent`);

--
-- Contraintes pour la table `photos`
--
ALTER TABLE `photos`
  ADD CONSTRAINT `fk_photos_anomalies1` FOREIGN KEY (`id_anomalie`) REFERENCES `anomalies` (`id_anomalie`) ON DELETE NO ACTION ON UPDATE NO ACTION;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
