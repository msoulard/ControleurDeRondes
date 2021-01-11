-- phpMyAdmin SQL Dump
-- version 4.6.6deb4
-- https://www.phpmyadmin.net/
--
-- Client :  localhost:3306
-- Généré le :  Jeu 19 Avril 2018 à 14:13
-- Version du serveur :  10.1.26-MariaDB-0+deb9u1
-- Version de PHP :  7.0.27-0+deb9u1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `rondes`
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
  `agentActif` tinyint(4) NOT NULL DEFAULT '1'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `agents`
--

INSERT INTO `agents` (`idAgent`, `idTag`, `nom`, `prenom`, `agentActif`) VALUES
(401, 'pJNy648h', 'Bourge', 'Baptiste', 1),
(402, 'bSvg32V3', 'Fouyet', 'Théo', 1),
(403, '26YX3vdv', 'Housseau', 'Killian', 1),
(404, 'm2fv3LM2', 'Cruchet', 'Philippe', 1),
(405, 'Kh65N3xc', 'Simier', 'Philippe', 1);

-- --------------------------------------------------------

--
-- Structure de la table `associationagentsrondes`
--

CREATE TABLE `associationagentsrondes` (
  `id` int(11) NOT NULL,
  `idAgent` int(11) NOT NULL,
  `idRonde` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `associationagentsrondes`
--

INSERT INTO `associationagentsrondes` (`id`, `idAgent`, `idRonde`) VALUES
(1, 401, 304),
(2, 404, 302),
(3, 402, 305),
(4, 403, 303),
(5, 405, 301);

-- --------------------------------------------------------

--
-- Structure de la table `associationpointeauxrondes`
--

CREATE TABLE `associationpointeauxrondes` (
  `id` int(11) NOT NULL,
  `idRonde` int(11) NOT NULL,
  `idPointeau` int(11) NOT NULL,
  `ordrePointeau` int(11) NOT NULL,
  `tempsProchainMin` int(11) DEFAULT '5',
  `tempsProchainMax` int(11) DEFAULT '15'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `associationpointeauxrondes`
--

INSERT INTO `associationpointeauxrondes` (`id`, `idRonde`, `idPointeau`, `ordrePointeau`, `tempsProchainMin`, `tempsProchainMax`) VALUES
(17, 304, 231, 1, 5, 15),
(18, 304, 232, 2, 5, 15),
(19, 304, 233, 3, 5, 15),
(20, 304, 234, 4, 5, 15),
(21, 304, 235, 5, 5, 15),
(22, 304, 236, 6, 5, 15),
(23, 304, 237, 7, 5, 15),
(24, 304, 238, 8, 5, 15),
(25, 304, 239, 9, 5, 15),
(26, 304, 240, 10, 0, 0),
(27, 301, 201, 1, 5, 15),
(28, 301, 202, 2, 5, 15),
(29, 301, 203, 3, 5, 15),
(30, 301, 204, 4, 5, 15),
(31, 301, 205, 5, 5, 15),
(32, 301, 206, 6, 5, 15),
(33, 301, 207, 7, 5, 15),
(34, 301, 208, 8, 5, 15),
(35, 301, 209, 9, 5, 15),
(36, 301, 210, 10, 0, 0),
(37, 302, 211, 1, 5, 15),
(38, 302, 212, 2, 5, 15),
(39, 302, 213, 3, 5, 15),
(40, 302, 214, 4, 5, 15),
(41, 302, 215, 5, 5, 15),
(42, 302, 216, 6, 5, 15),
(43, 302, 217, 7, 5, 15),
(44, 302, 218, 8, 5, 15),
(45, 302, 219, 9, 5, 15),
(46, 302, 220, 10, 0, 0),
(47, 305, 241, 1, 5, 15),
(48, 305, 242, 2, 5, 15),
(49, 305, 243, 3, 5, 15),
(50, 305, 244, 4, 5, 15),
(51, 305, 245, 5, 5, 15),
(52, 305, 246, 6, 5, 15),
(53, 305, 247, 7, 5, 15),
(54, 305, 248, 8, 5, 15),
(55, 305, 249, 9, 5, 15),
(56, 305, 240, 10, 0, 0),
(57, 303, 221, 1, 5, 15),
(58, 303, 222, 2, 5, 15),
(59, 303, 223, 3, 5, 15),
(60, 303, 224, 4, 5, 15),
(61, 303, 225, 5, 5, 15),
(62, 303, 226, 6, 5, 15),
(63, 303, 227, 7, 5, 15),
(64, 303, 228, 8, 5, 15),
(65, 303, 229, 9, 5, 15),
(66, 303, 230, 10, 0, 0);

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
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `mainscourantes`
--

CREATE TABLE `mainscourantes` (
  `id` int(11) NOT NULL,
  `texte` varchar(250) NOT NULL,
  `idHistoriquePointeau` int(11) NOT NULL,
  `date` datetime NOT NULL,
  `type` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `pointeaux`
--

CREATE TABLE `pointeaux` (
  `idPointeau` int(11) NOT NULL,
  `idTag` char(8) NOT NULL,
  `lieu` varchar(20) DEFAULT NULL,
  `numero` int(11) NOT NULL,
  `pointeauActif` tinyint(4) NOT NULL DEFAULT '1'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `pointeaux`
--

INSERT INTO `pointeaux` (`idPointeau`, `idTag`, `lieu`, `numero`, `pointeauActif`) VALUES
(201, '778AcdDs', 'Accueil', 1, 1),
(202, '8bwAf4E2', 'BatPrehistoire', 2, 1),
(203, 'd59xQs3U', 'BatMedieval', 3, 1),
(204, 'Jag49S5v', 'BatRomain', 4, 1),
(205, 'm5F6Liz2', 'toilettes1', 5, 1),
(206, '5S8yfPr9', 'BatRenaissance', 6, 1),
(207, '6w79YjAi', 'BatPremGM', 7, 1),
(208, 'CC5c23uz', 'BatDeuxGM', 8, 1),
(209, 'FNx3gu69', 'toilettes2', 9, 1),
(210, 'xR9uB2h5', 'Sortie', 10, 1),
(211, 'xR9uB2h5', 'Portail', 1, 1),
(212, 'fq39XeB2', 'Douves', 2, 1),
(213, 'v5Y4zZ8a', 'Cour', 3, 1),
(214, 'C9Frp26j', 'Tour', 4, 1),
(215, '9v7Aa5Mv', 'Muraille', 5, 1),
(216, 'QU8d47jy', 'SalleDeBanquet', 6, 1),
(217, 'm68Esk2M', 'SalleDesGardes', 7, 1),
(218, '7fBe4g6C', 'SalleDesArmes', 8, 1),
(219, '254YpayY', 'BoutiqueDeSouvenirs', 9, 1),
(220, 'R6s9vbY4', 'PontLevis', 10, 1),
(221, '3bD25rFi', 'Parking', 1, 1),
(222, '6Yg6xKs2', 'Cuisine', 2, 1),
(223, '3c25cKmM', 'Stockage', 3, 1),
(224, '4tTRe37c', 'Frigo', 4, 1),
(225, 'cvs59LP3', 'Caisse', 5, 1),
(226, 'YMv8b6f6', 'toilettes', 6, 1),
(227, 'a7S2Fr2k', 'salleDeRestauration', 7, 1),
(228, 'k7d5sU7V', 'jeuxEnfants', 8, 1),
(229, 'x5n72mGU', 'Distributeur', 9, 1),
(230, '9ShMr34w', 'Entrée', 10, 1),
(231, 'x5n72mGU', 'parkingEmployes', 1, 1),
(232, '9ShMr34w', 'parkingVisiteurs', 2, 1),
(233, 'Np8kv92X', 'portailTournant', 3, 1),
(234, 'qs9WMa48', 'Bureaux', 4, 1),
(235, '9n7x6BzS', 'salleDesMachines', 5, 1),
(236, '7M9Ugz6k', 'chaineDeProd1', 6, 1),
(237, 'KhM5b3g7', 'chaineDeProd2', 7, 1),
(238, 'RryEv676', 'chaineDeProd3', 8, 1),
(239, '9q55TpeU', 'bureauxProd', 9, 1),
(240, 'A6x6e2xG', 'toilettes', 10, 1),
(241, 'vG932Skh', 'Portillon', 1, 1),
(242, 'a5Wc43Tk', 'Bureaux', 2, 1),
(243, '72m9MbzZ', 'Cantine', 3, 1),
(244, '4T8a9Vyq', 'batimentMaternelle', 4, 1),
(245, '4tw5sW7N', 'batimentPrimaire', 5, 1),
(246, 'Jt3gM8y7', 'SalleDesInstits', 6, 1),
(247, 'wna44BY4', 'courDeRecreation', 7, 1),
(248, 'T33Xize3', 'Gymnase', 8, 1),
(249, '6kz3k7GG', 'Dortoir', 9, 1),
(250, 'Hiy83f6K', 'toilettes', 10, 1);

-- --------------------------------------------------------

--
-- Structure de la table `responsable`
--

CREATE TABLE `responsable` (
  `idResponsable` int(11) NOT NULL,
  `login` varchar(45) NOT NULL,
  `mdp` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `responsable`
--

INSERT INTO `responsable` (`idResponsable`, `login`, `mdp`) VALUES
(1, 'admin', 'admin');

-- --------------------------------------------------------

--
-- Structure de la table `rondes`
--

CREATE TABLE `rondes` (
  `idRonde` int(11) NOT NULL,
  `nom` varchar(30) NOT NULL,
  `rondeActive` tinyint(4) NOT NULL DEFAULT '1'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `rondes`
--

INSERT INTO `rondes` (`idRonde`, `nom`, `rondeActive`) VALUES
(301, 'Musee', 1),
(302, 'Chateau', 1),
(303, 'Restaurant', 1),
(304, 'Usine', 1),
(305, 'Ecole', 1);

-- --------------------------------------------------------

--
-- Structure de la table `smartphones`
--

CREATE TABLE `smartphones` (
  `id` int(11) NOT NULL,
  `nom` text NOT NULL,
  `idADB` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `smartphones`
--

INSERT INTO `smartphones` (`id`, `nom`, `idADB`) VALUES
(0, 'test', 'ZY322DHJWR');

-- --------------------------------------------------------

--
-- Structure de la table `tags`
--

CREATE TABLE `tags` (
  `idTag` char(8) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `tags`
--

INSERT INTO `tags` (`idTag`) VALUES
('254YpayY'),
('26YX3vdv'),
('3bD25rFi'),
('3c25cKmM'),
('4T8a9Vyq'),
('4tTRe37c'),
('4tw5sW7N'),
('5S8yfPr9'),
('6kz3k7GG'),
('6w79YjAi'),
('6Yg6xKs2'),
('72m9MbzZ'),
('778AcdDs'),
('7fBe4g6C'),
('7M9Ugz6k'),
('8bwAf4E2'),
('9n7x6BzS'),
('9q55TpeU'),
('9ShMr34w'),
('9v7Aa5Mv'),
('a5Wc43Tk'),
('A6x6e2xG'),
('a7S2Fr2k'),
('bSvg32V3'),
('C9Frp26j'),
('CC5c23uz'),
('cvs59LP3'),
('cY8D9g4k'),
('d59xQs3U'),
('FNx3gu69'),
('fq39XeB2'),
('Hiy83f6K'),
('Jag49S5v'),
('Jt3gM8y7'),
('k7d5sU7V'),
('Kh65N3xc'),
('KhM5b3g7'),
('m2fv3LM2'),
('m5F6Liz2'),
('m68Esk2M'),
('Np8kv92X'),
('pJNy648h'),
('qrnSF253'),
('qs9WMa48'),
('QU8d47jy'),
('R6s9vbY4'),
('RryEv676'),
('Sd3n5m5M'),
('T33Xize3'),
('v5Y4zZ8a'),
('vG932Skh'),
('wna44BY4'),
('x5n72mGU'),
('xR9uB2h5'),
('YMv8b6f6');

-- --------------------------------------------------------

--
-- Structure de la table `utilisateur`
--

CREATE TABLE `utilisateur` (
  `idutilisateur` int(32) NOT NULL,
  `mdp` varchar(50) NOT NULL,
  `mail` varchar(50) NOT NULL,
  `niveau_droit` int(3) NOT NULL,
  `code_recup` int(5) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `utilisateur`
--

INSERT INTO `utilisateur` (`idutilisateur`, `mdp`, `mail`, `niveau_droit`, `code_recup`) VALUES
(1, 'toto', 'toto', 1, 15647);

--
-- Index pour les tables exportées
--

--
-- Index pour la table `agents`
--
ALTER TABLE `agents`
  ADD PRIMARY KEY (`idAgent`),
  ADD KEY `fk_Agents_Tags1_idx` (`idTag`);

--
-- Index pour la table `associationagentsrondes`
--
ALTER TABLE `associationagentsrondes`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fk_AssociationAgentsRondes_Rondes1_idx` (`idRonde`),
  ADD KEY `fk_AssociationAgentsRondes_Agents1_idx` (`idAgent`);

--
-- Index pour la table `associationpointeauxrondes`
--
ALTER TABLE `associationpointeauxrondes`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fk_AssociationPointeauxRondes_Pointeaux_idx` (`idPointeau`),
  ADD KEY `fk_AssociationPointeauxRondes_Rondes1_idx` (`idRonde`);

--
-- Index pour la table `historiquepointeau`
--
ALTER TABLE `historiquepointeau`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fk_HistoriquePointeau_Rondes1_idx` (`idRonde`),
  ADD KEY `fk_HistoriquePointeau_Pointeaux1_idx` (`idPointeau`),
  ADD KEY `fk_HistoriquePointeau_Agents1_idx` (`idAgent`);

--
-- Index pour la table `mainscourantes`
--
ALTER TABLE `mainscourantes`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `pointeaux`
--
ALTER TABLE `pointeaux`
  ADD PRIMARY KEY (`idPointeau`),
  ADD KEY `fk_Pointeaux_Tags1_idx` (`idTag`);

--
-- Index pour la table `responsable`
--
ALTER TABLE `responsable`
  ADD PRIMARY KEY (`idResponsable`);

--
-- Index pour la table `rondes`
--
ALTER TABLE `rondes`
  ADD PRIMARY KEY (`idRonde`);

--
-- Index pour la table `tags`
--
ALTER TABLE `tags`
  ADD PRIMARY KEY (`idTag`);

--
-- Index pour la table `utilisateur`
--
ALTER TABLE `utilisateur`
  ADD PRIMARY KEY (`idutilisateur`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `agents`
--
ALTER TABLE `agents`
  MODIFY `idAgent` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=406;
--
-- AUTO_INCREMENT pour la table `associationagentsrondes`
--
ALTER TABLE `associationagentsrondes`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;
--
-- AUTO_INCREMENT pour la table `associationpointeauxrondes`
--
ALTER TABLE `associationpointeauxrondes`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=67;
--
-- AUTO_INCREMENT pour la table `historiquepointeau`
--
ALTER TABLE `historiquepointeau`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=309;
--
-- AUTO_INCREMENT pour la table `mainscourantes`
--
ALTER TABLE `mainscourantes`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=166;
--
-- AUTO_INCREMENT pour la table `pointeaux`
--
ALTER TABLE `pointeaux`
  MODIFY `idPointeau` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=251;
--
-- AUTO_INCREMENT pour la table `responsable`
--
ALTER TABLE `responsable`
  MODIFY `idResponsable` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
--
-- AUTO_INCREMENT pour la table `rondes`
--
ALTER TABLE `rondes`
  MODIFY `idRonde` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=306;
--
-- Contraintes pour les tables exportées
--

--
-- Contraintes pour la table `agents`
--
ALTER TABLE `agents`
  ADD CONSTRAINT `fk_Agents_Tags1` FOREIGN KEY (`idTag`) REFERENCES `tags` (`idTag`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Contraintes pour la table `associationagentsrondes`
--
ALTER TABLE `associationagentsrondes`
  ADD CONSTRAINT `fk_AssociationAgentsRondes_Agents1` FOREIGN KEY (`idAgent`) REFERENCES `agents` (`idAgent`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_AssociationAgentsRondes_Rondes1` FOREIGN KEY (`idRonde`) REFERENCES `rondes` (`idRonde`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Contraintes pour la table `associationpointeauxrondes`
--
ALTER TABLE `associationpointeauxrondes`
  ADD CONSTRAINT `fk_AssociationPointeauxRondes_Pointeaux` FOREIGN KEY (`idPointeau`) REFERENCES `pointeaux` (`idPointeau`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_AssociationPointeauxRondes_Rondes1` FOREIGN KEY (`idRonde`) REFERENCES `rondes` (`idRonde`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Contraintes pour la table `historiquepointeau`
--
ALTER TABLE `historiquepointeau`
  ADD CONSTRAINT `fk_HistoriquePointeau_Agents1` FOREIGN KEY (`idAgent`) REFERENCES `agents` (`idAgent`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_HistoriquePointeau_Pointeaux1` FOREIGN KEY (`idPointeau`) REFERENCES `pointeaux` (`idPointeau`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_HistoriquePointeau_Rondes1` FOREIGN KEY (`idRonde`) REFERENCES `rondes` (`idRonde`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Contraintes pour la table `pointeaux`
--
ALTER TABLE `pointeaux`
  ADD CONSTRAINT `fk_Pointeaux_Tags1` FOREIGN KEY (`idTag`) REFERENCES `tags` (`idTag`) ON DELETE NO ACTION ON UPDATE NO ACTION;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
