-- phpMyAdmin SQL Dump
-- version 4.7.4
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost
-- Généré le :  jeu. 20 juin 2019 à 17:22
-- Version du serveur :  5.5.57-MariaDB
-- Version de PHP :  5.5.38

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `controleurDeRonde`
--

-- --------------------------------------------------------

--
-- Structure de la table `agents`
--

CREATE TABLE `agents` (
  `idAgent` int(11) NOT NULL,
  `idTag` char(8) DEFAULT NULL,
  `nom` varchar(45) NOT NULL,
  `prenom` varchar(45) NOT NULL,
  `agentActif` tinyint(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `agents`
--

INSERT INTO `agents` (`idAgent`, `idTag`, `nom`, `prenom`, `agentActif`) VALUES
(1, '45v2ty1c', 'Bidochon', 'Robert', 1),
(2, '85f6s98a', 'Lemée', 'Gabriel', 1),
(3, 'gfy45e5d', 'Bidochon', 'Marta', 1),
(4, 'f55d8888', 'Herbron', 'Tanguy', 1),
(5, '455qsd88', 'Dupe', 'Gwendal', 1),
(6, 'd4s5d8e4', 'Guedon', 'Guillaume', 1),
(7, 's6d5e8c2', 'Senechal', 'Florian', 1);

-- --------------------------------------------------------

--
-- Structure de la table `associationagentsrondes`
--

CREATE TABLE `associationagentsrondes` (
  `id` int(11) NOT NULL,
  `idAgent` int(11) NOT NULL,
  `idRonde` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `associationagentsrondes`
--

INSERT INTO `associationagentsrondes` (`id`, `idAgent`, `idRonde`) VALUES
(1, 1, 11);

-- --------------------------------------------------------

--
-- Structure de la table `associationpointeauxrondes`
--

CREATE TABLE `associationpointeauxrondes` (
  `id` int(11) NOT NULL,
  `idRonde` int(11) NOT NULL,
  `idPointeau` int(11) NOT NULL,
  `ordrePointeau` int(11) NOT NULL,
  `tempsProchainMin` int(11) DEFAULT NULL,
  `tempsProchainMax` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `associationpointeauxrondes`
--

INSERT INTO `associationpointeauxrondes` (`id`, `idRonde`, `idPointeau`, `ordrePointeau`, `tempsProchainMin`, `tempsProchainMax`) VALUES
(1, 11, 1001, 1, 5, 15),
(2, 11, 1002, 2, 5, 15),
(3, 11, 1003, 3, 7, 15),
(4, 11, 1004, 4, 5, 15),
(5, 11, 1005, 5, 5, 15),
(6, 11, 1006, 6, 5, 15);

-- --------------------------------------------------------

--
-- Structure de la table `historiquepointeau`
--

CREATE TABLE `historiquepointeau` (
  `id` int(11) NOT NULL,
  `idAgent` int(11) NOT NULL,
  `idRonde` int(11) NOT NULL,
  `idPointeau` int(11) NOT NULL,
  `date` datetime NOT NULL,
  `ordrePointeau` int(11) NOT NULL,
  `numeroRonde` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `historiquepointeau`
--

INSERT INTO `historiquepointeau` (`id`, `idAgent`, `idRonde`, `idPointeau`, `date`, `ordrePointeau`, `numeroRonde`) VALUES
(1, 1, 11, 1001, '2019-04-01 10:00:00', 1, 1),
(2, 1, 11, 1002, '2019-04-01 10:00:05', 2, 1),
(3, 1, 11, 1003, '2019-04-01 10:00:10', 2, 1),
(4, 1, 11, 1004, '2019-04-01 10:00:15', 2, 1),
(5, 2, 12, 1001, '2019-04-02 20:00:00', 1, 2),
(6, 2, 12, 1002, '2019-04-02 20:00:05', 2, 2),
(7, 2, 12, 1003, '2019-04-02 20:00:10', 2, 2),
(8, 2, 12, 1004, '2019-04-02 20:00:15', 2, 2),
(9, 7, 11, 1003, '2019-05-03 08:00:00', 1, 3),
(10, 7, 11, 1004, '2019-05-03 08:00:05', 2, 3),
(11, 7, 11, 1005, '2019-05-03 08:00:10', 2, 3),
(12, 7, 11, 1006, '2019-05-03 08:00:15', 2, 3),
(13, 4, 12, 1009, '2019-04-05 09:00:00', 1, 4),
(14, 4, 12, 1010, '2019-04-05 09:00:05', 2, 4),
(15, 4, 12, 1011, '2019-04-05 09:00:10', 2, 4),
(16, 4, 12, 1012, '2019-04-05 09:00:20', 2, 4),
(17, 4, 12, 1013, '2019-04-05 09:00:25', 2, 4),
(18, 1, 13, 1001, '2019-04-06 14:00:00', 1, 5),
(19, 1, 13, 1002, '2019-04-06 14:00:05', 2, 5),
(20, 1, 13, 1003, '2019-04-06 14:00:10', 2, 5),
(21, 1, 13, 1004, '2019-04-06 14:00:30', -1, 5),
(22, 5, 12, 1005, '2019-04-06 21:00:00', 1, 6),
(23, 5, 12, 1006, '2019-04-06 21:00:05', 2, 6),
(24, 5, 12, 1007, '2019-04-06 21:00:15', 2, 6),
(25, 5, 12, 1008, '2019-04-06 21:00:20', 2, 6);

-- --------------------------------------------------------

--
-- Structure de la table `Liste_abonnes`
--

CREATE TABLE `Liste_abonnes` (
  `abonnes_id` int(13) NOT NULL,
  `abonnes_nom` varchar(12) NOT NULL,
  `abonnes_prenom` varchar(12) NOT NULL,
  `abonnes_civilite` varchar(8) NOT NULL,
  `abonnes_email` varchar(40) NOT NULL,
  `abonnes_entreprise` varchar(11) NOT NULL,
  `abonnes_fonction` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `Liste_abonnes`
--

INSERT INTO `Liste_abonnes` (`abonnes_id`, `abonnes_nom`, `abonnes_prenom`, `abonnes_civilite`, `abonnes_email`, `abonnes_entreprise`, `abonnes_fonction`) VALUES
(1, 'Paré', 'Thomas', 'Homme', 'tpare@pommier4.depinfo.touchard.edu', 'Auchan', 'Responsable'),
(2, 'Poitou', 'Kilian', 'Homme', 'kpoitou@pommier4.depinfo.touchard.edu', 'Auchan', 'Vigil'),
(3, 'Levillain', 'Dimitri', 'Homme', 'dlevillain@pommier4.depinfo.touchard.edu', 'Auchan', 'Vigil'),
(4, 'Leca', 'Kévin', 'Homme', 'kleca@pommier4.depinfo.touchard.edu', 'Auchan', 'Vigil'),
(5, 'Nevier', 'Ghislain', 'Homme', 'gnevier@pommier4.depinfo.touchard.edu', 'Leclerc', 'Responsable'),
(6, 'Cousin', 'Élise', 'Femme', 'ecousin@pommier4.depinfo.touchard.edu', 'Leclerc', 'Vigil'),
(7, 'Parer', 'Thomas', 'Homme', 'thomas.pare72@gmail.com', 'Leclerc', 'Vigil'),
(12, 'Vieillard', 'Roger', 'Homme', 'Jean-claude.vieillard@saintaubinlasalle.', 'sals', 'enseignant');

-- --------------------------------------------------------

--
-- Structure de la table `mainscourantes`
--

CREATE TABLE `mainscourantes` (
  `id` int(11) NOT NULL,
  `texte` varchar(250) NOT NULL,
  `date` datetime NOT NULL,
  `idHistoriquePointeau` int(11) NOT NULL,
  `idPremierPointeau` int(11) NOT NULL,
  `photos` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `mainscourantes`
--

INSERT INTO `mainscourantes` (`id`, `texte`, `date`, `idHistoriquePointeau`, `idPremierPointeau`, `photos`) VALUES
(1, 'Casser', '2019-03-29 09:35:00', 2, 1, 0),
(2, '/home/USERS/ELEVES/SNIR2017/dlevillain/photosRonde/1_1002_', '2017-05-01 00:00:00', 2, 1, 2),
(3, 'erreur', '2019-04-06 14:00:05', 19, 18, 0),
(4, '/home/USERS/ELEVES/SNIR2017/dlevillain/photosRonde/1_1002_', '2017-05-01 00:00:00', 2, 1, 1),
(6, 'Probleme', '2017-05-01 00:00:00', 1, 1, 0),
(7, '/home/USERS/ELEVES/SNIR2017/dlevillain/photosRonde/5_1002_', '2019-04-06 14:00:05', 19, 18, 1);

-- --------------------------------------------------------

--
-- Structure de la table `pointeaux`
--

CREATE TABLE `pointeaux` (
  `idpointeaux` int(11) NOT NULL,
  `idTag` char(8) DEFAULT NULL,
  `lieu` varchar(20) DEFAULT NULL,
  `numero` int(11) NOT NULL,
  `pointeauActif` tinyint(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `pointeaux`
--

INSERT INTO `pointeaux` (`idpointeaux`, `idTag`, `lieu`, `numero`, `pointeauActif`) VALUES
(1001, 'id101', 'Accueil', 1001, 1),
(1002, 'id101', 'batimentA', 1002, 1),
(1003, 'id101', 'batimentE', 1003, 1),
(1004, 'id101', 'Gymnase', 1004, 1),
(1005, 'id101', 'salleDeMuscu', 1005, 1),
(1006, 'id101', 'Self', 1006, 1),
(1007, 'id101', 'batimentD', 1007, 1),
(1008, 'id101', 'dortoir1', 1008, 1),
(1009, 'id101', 'dortoir2', 1009, 1),
(1010, 'id101', 'CDI', 1010, 1),
(1011, 'id101', 'salleDesProfs', 1011, 1),
(1012, 'id101', 'Cafeteria', 1012, 1),
(1013, 'id101', 'vieScolaire', 1013, 1),
(1014, 'id101', 'batimentC', 1014, 1),
(1015, 'id101', 'batimentB', 1015, 1);

-- --------------------------------------------------------

--
-- Structure de la table `responsable`
--

CREATE TABLE `responsable` (
  `idResponsable` int(11) NOT NULL DEFAULT '0',
  `login` varchar(45) NOT NULL,
  `mdp` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `responsable`
--

INSERT INTO `responsable` (`idResponsable`, `login`, `mdp`) VALUES
(1, 'toto', 'toto');

-- --------------------------------------------------------

--
-- Structure de la table `rondes`
--

CREATE TABLE `rondes` (
  `idrondes` int(11) NOT NULL,
  `nomrondes` varchar(30) NOT NULL,
  `rondeActive` tinyint(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `rondes`
--

INSERT INTO `rondes` (`idrondes`, `nomrondes`, `rondeActive`) VALUES
(11, 'rondeTouchard', 1),
(12, 'rondeGymnase', 1),
(13, 'rondeSelf', 0);

-- --------------------------------------------------------

--
-- Structure de la table `Sauvegarde_pour_mail`
--

CREATE TABLE `Sauvegarde_pour_mail` (
  `Sauvegarde_id` int(5) NOT NULL,
  `Sauvegarde_nomRonde` varchar(20) NOT NULL,
  `Sauvegarde_EmailAbonne` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `Sauvegarde_pour_mail`
--

INSERT INTO `Sauvegarde_pour_mail` (`Sauvegarde_id`, `Sauvegarde_nomRonde`, `Sauvegarde_EmailAbonne`) VALUES
(14, 'rondeSelf', 'kpoitou@pommier4.depinfo.touchard.edu'),
(15, 'rondeGymnase', 'kpoitou@pommier4.depinfo.touchard.edu'),
(16, 'rondeTouchard', 'tpare@pommier4.depinfo.touchard.edu'),
(17, 'rondeTouchard', 'dlevillain@pommier4.depinfo.touchard.edu'),
(18, 'rondeSelf', 'tpare@pommier4.depinfo.touchard.edu'),
(19, 'rondeSelf', 'kpoitou@pommier4.depinfo.touchard.edu'),
(20, 'rondeSelf', 'thomas.pare72@gmail.com'),
(22, 'rondeGymnase', 'tpare@pommier4.depinfo.touchard.edu'),
(23, 'rondeGymnase', 'kleca@pommier4.depinfo.touchard.edu'),
(24, 'rondeGymnase', 'Jean-claude.vieillard@saintaubinlasalle.'),
(25, 'rondeTouchard', 'tpare@pommier4.depinfo.touchard.edu'),
(26, 'rondeTouchard', 'dlevillain@pommier4.depinfo.touchard.edu'),
(27, 'rondeTouchard', 'thomas.pare72@gmail.com'),
(28, 'rondeTouchard', 'Jean-claude.vieillard@saintaubinlasalle.'),
(29, 'rondeSelf', 'tpare@pommier4.depinfo.touchard.edu'),
(30, 'rondeSelf', 'dlevillain@pommier4.depinfo.touchard.edu'),
(31, 'rondeSelf', 'thomas.pare72@gmail.com'),
(32, 'rondeSelf', 'Jean-claude.vieillard@saintaubinlasalle.'),
(33, 'rondeSelf', 'kpoitou@pommier4.depinfo.touchard.edu');

-- --------------------------------------------------------

--
-- Structure de la table `smartphones`
--

CREATE TABLE `smartphones` (
  `idsmartphones` int(11) NOT NULL,
  `nom` varchar(45) DEFAULT NULL,
  `idADB` varchar(45) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `smartphones`
--

INSERT INTO `smartphones` (`idsmartphones`, `nom`, `idADB`) VALUES
(0, 'test', 'ZY322DHJWR');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `agents`
--
ALTER TABLE `agents`
  ADD PRIMARY KEY (`idAgent`);

--
-- Index pour la table `associationagentsrondes`
--
ALTER TABLE `associationagentsrondes`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fk_associationagentsrondes_agents1_idx` (`idAgent`),
  ADD KEY `fk_associationagentsrondes_rondes1_idx` (`idRonde`);

--
-- Index pour la table `associationpointeauxrondes`
--
ALTER TABLE `associationpointeauxrondes`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fk_associationpointeauxrondes_pointeaux1_idx` (`idPointeau`),
  ADD KEY `fk_associationpointeauxrondes_rondes1_idx` (`idRonde`);

--
-- Index pour la table `historiquepointeau`
--
ALTER TABLE `historiquepointeau`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fk_historiquePointeau_pointeaux1_idx` (`idPointeau`),
  ADD KEY `fk_historiquePointeau_rondes1_idx` (`idRonde`),
  ADD KEY `fk_historiquePointeau_agents1_idx` (`idAgent`);

--
-- Index pour la table `Liste_abonnes`
--
ALTER TABLE `Liste_abonnes`
  ADD PRIMARY KEY (`abonnes_id`);

--
-- Index pour la table `mainscourantes`
--
ALTER TABLE `mainscourantes`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fk_mainscourantes_historiquePointeau_idx` (`idHistoriquePointeau`);

--
-- Index pour la table `pointeaux`
--
ALTER TABLE `pointeaux`
  ADD PRIMARY KEY (`idpointeaux`);

--
-- Index pour la table `responsable`
--
ALTER TABLE `responsable`
  ADD PRIMARY KEY (`idResponsable`);

--
-- Index pour la table `rondes`
--
ALTER TABLE `rondes`
  ADD PRIMARY KEY (`idrondes`);

--
-- Index pour la table `Sauvegarde_pour_mail`
--
ALTER TABLE `Sauvegarde_pour_mail`
  ADD PRIMARY KEY (`Sauvegarde_id`);

--
-- Index pour la table `smartphones`
--
ALTER TABLE `smartphones`
  ADD PRIMARY KEY (`idsmartphones`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `associationagentsrondes`
--
ALTER TABLE `associationagentsrondes`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT pour la table `associationpointeauxrondes`
--
ALTER TABLE `associationpointeauxrondes`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT pour la table `Liste_abonnes`
--
ALTER TABLE `Liste_abonnes`
  MODIFY `abonnes_id` int(13) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;

--
-- AUTO_INCREMENT pour la table `mainscourantes`
--
ALTER TABLE `mainscourantes`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT pour la table `Sauvegarde_pour_mail`
--
ALTER TABLE `Sauvegarde_pour_mail`
  MODIFY `Sauvegarde_id` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=34;

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `associationagentsrondes`
--
ALTER TABLE `associationagentsrondes`
  ADD CONSTRAINT `fk_associationagentsrondes_agents1` FOREIGN KEY (`idAgent`) REFERENCES `agents` (`idAgent`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_associationagentsrondes_rondes1` FOREIGN KEY (`idRonde`) REFERENCES `rondes` (`idrondes`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Contraintes pour la table `associationpointeauxrondes`
--
ALTER TABLE `associationpointeauxrondes`
  ADD CONSTRAINT `fk_associationpointeauxrondes_pointeaux1` FOREIGN KEY (`idPointeau`) REFERENCES `pointeaux` (`idpointeaux`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_associationpointeauxrondes_rondes1` FOREIGN KEY (`idRonde`) REFERENCES `rondes` (`idrondes`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Contraintes pour la table `historiquepointeau`
--
ALTER TABLE `historiquepointeau`
  ADD CONSTRAINT `fk_historiquePointeau_agents1` FOREIGN KEY (`idAgent`) REFERENCES `agents` (`idAgent`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_historiquePointeau_pointeaux1` FOREIGN KEY (`idPointeau`) REFERENCES `pointeaux` (`idpointeaux`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_historiquePointeau_rondes1` FOREIGN KEY (`idRonde`) REFERENCES `rondes` (`idrondes`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Contraintes pour la table `mainscourantes`
--
ALTER TABLE `mainscourantes`
  ADD CONSTRAINT `fk_mainscourantes_historiquePointeau` FOREIGN KEY (`idHistoriquePointeau`) REFERENCES `historiquepointeau` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
