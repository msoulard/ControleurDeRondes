-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost
-- Généré le : mer. 27 mai 2020 à 11:26
-- Version du serveur :  8.0.16
-- Version de PHP : 7.4.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `controleurderonde2020`
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
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `agents`
--

INSERT INTO `agents` (`idAgent`, `idTag`, `nom`, `prenom`, `agentActif`) VALUES
(2, 'Tc41', 'Hureau', 'Mathis', 1),
(3, 'Ubnda', 'Guillaumin', 'Jeremi', 1),
(4, 'Hbcae', 'Mezerette', 'Brice', 1),
(5, 'a0YUB', 'Chevrel', 'Antoine', 1),
(6, 'Ybdal1', 'Blanchet', 'Paul', 1),
(7, '53-bbda', 'Harbach', 'Mathis', 1),
(8, '67bdpa', 'Pinto', 'Romain', 1),
(9, 'MQ_65', 'Pinaud', 'Lucas', 1),
(10, '098ha', 'Simier', 'Philippe', 1),
(11, '68hbuba', 'Cruchet', 'Philippe', 1),
(12, 'ldaAUINM', 'Bernard', 'Didier', 1);

-- --------------------------------------------------------

--
-- Structure de la table `associationagentsrondes`
--

CREATE TABLE `associationagentsrondes` (
  `id` int(11) NOT NULL,
  `idAgent` int(11) NOT NULL,
  `idRonde` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4  ;

--
-- Déchargement des données de la table `associationagentsrondes`
--

INSERT INTO `associationagentsrondes` (`id`, `idAgent`, `idRonde`) VALUES
(4, 5, 2),
(5, 12, 1),
(6, 12, 2),
(7, 12, 3),
(8, 6, 3),
(9, 8, 1),
(10, 8, 3),
(11, 3, 3);

-- --------------------------------------------------------

--
-- Structure de la table `associationpointeauxrondes`
--

CREATE TABLE `associationpointeauxrondes` (
  `id` int(11) NOT NULL,
  `idRonde` int(11) NOT NULL,
  `idPointeau` int(11) NOT NULL,
  `ordrePointeau` int(11) NOT NULL,
  `tempsMin` int(11) DEFAULT NULL,
  `tempsMax` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4  ;

--
-- Déchargement des données de la table `associationpointeauxrondes`
--

INSERT INTO `associationpointeauxrondes` (`id`, `idRonde`, `idPointeau`, `ordrePointeau`, `tempsMin`, `tempsMax`) VALUES
(1, 1, 2, 1, 5, 15),
(2, 1, 5, 2, 5, 15),
(3, 1, 9, 3, 5, 15),
(4, 1, 8, 4, 5, 15),
(5, 1, 6, 5, 0, 0),
(6, 2, 13, 1, 5, 15),
(7, 2, 11, 2, 5, 15),
(8, 2, 6, 3, 5, 15),
(9, 2, 3, 4, 5, 15),
(10, 2, 5, 5, 5, 15),
(11, 2, 2, 6, 5, 15),
(12, 2, 1, 7, 5, 15),
(13, 2, 7, 8, 5, 15),
(14, 2, 4, 9, 5, 15),
(15, 2, 12, 10, 0, 0),
(16, 3, 2, 1, 5, 15),
(17, 3, 6, 2, 5, 15),
(18, 3, 8, 3, 5, 15),
(19, 3, 5, 4, 5, 15),
(20, 3, 4, 5, 0, 0);

-- --------------------------------------------------------

--
-- Structure de la table `batiment`
--

CREATE TABLE `batiment` (
  `batiment` varchar(2) CHARACTER SET utf8mb4   NOT NULL,
  `idBatiment` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4  ;

--
-- Déchargement des données de la table `batiment`
--

INSERT INTO `batiment` (`batiment`, `idBatiment`) VALUES
('A', '1'),
('B', '2'),
('C', '3'),
('D', '4'),
('E', '5'),
('F', '6'),
('G', '7');

-- --------------------------------------------------------

--
-- Structure de la table `emplacement`
--

CREATE TABLE `emplacement` (
  `localisation` varchar(20) NOT NULL,
  `etage` int(11) DEFAULT NULL,
  `batiment` varchar(45) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `emplacement`
--

INSERT INTO `emplacement` (`localisation`, `etage`, `batiment`) VALUES
('cantine', 1, 'B'),
('eefefefe', 0, 'A'),
('toilettes', 2, 'A'),
('zefaefa', 3, 'C');

-- --------------------------------------------------------

--
-- Structure de la table `etage`
--

CREATE TABLE `etage` (
  `etage` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4  ;

--
-- Déchargement des données de la table `etage`
--

INSERT INTO `etage` (`etage`) VALUES
(1),
(2),
(3),
(0),
(5),
(6),
(7),
(8),
(9),
(4);

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
  `numeroRonde` int(11) NOT NULL,
  `anomalie` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `historiquepointeau`
--

INSERT INTO `historiquepointeau` (`id`, `idAgent`, `idRonde`, `idPointeau`, `date`, `ordrePointeau`, `numeroRonde`, `anomalie`) VALUES
(1, 1, 1, 1, '2017-05-01 00:00:00', 2, 0, 0);

-- --------------------------------------------------------

--
-- Structure de la table `historiqueronde`
--

CREATE TABLE `historiqueronde` (
  `id` int(11) NOT NULL,
  `idAgent` int(11) NOT NULL,
  `idRonde` int(11) NOT NULL,
  `idPointeau` int(11) NOT NULL,
  `date` datetime NOT NULL,
  `numeroRonde` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `pointeaux`
--

CREATE TABLE `pointeaux` (
  `idPointeau` int(11) NOT NULL,
  `idTag` char(8) DEFAULT NULL,
  `localisation` varchar(20) DEFAULT NULL,
  `alias` int(11) NOT NULL,
  `pointeauActif` tinyint(4) NOT NULL,
  `etage` varchar(45) DEFAULT NULL,
  `idBatiment` varchar(45) CHARACTER SET utf8mb4   NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `pointeaux`
--

INSERT INTO `pointeaux` (`idPointeau`, `idTag`, `localisation`, `alias`, `pointeauActif`, `etage`, `idBatiment`) VALUES
(1, 'id101', 'Accueil', 1001, 1, '1', '1'),
(2, 'id101', 'batimentA', 1002, 1, '0', '1'),
(3, 'id101', 'batimentE', 1003, 1, '0', '1'),
(4, 'id101', 'Gymnase', 1004, 1, '0', '1'),
(5, 'id101', 'salleDeMuscu', 1005, 1, '1', '2'),
(6, 'id101', 'Self', 1006, 1, '0', '2'),
(7, 'id101', 'batimentD', 1007, 1, '0', '2'),
(8, 'id101', 'dortoir1', 1008, 1, '1', '2'),
(9, 'id101', 'dortoir2', 1009, 1, '2', '3'),
(10, 'id101', 'CDI', 1010, 1, '0', '3'),
(11, 'id101', 'salleDesProfs', 1011, 1, '0', '4'),
(12, 'id101', 'Cafeteria', 1012, 1, '1', '4'),
(13, 'id101', 'vieScolaire', 1013, 1, '0', '4');

-- --------------------------------------------------------

--
-- Structure de la table `responsable`
--

CREATE TABLE `responsable` (
  `idresponsables` int(11) NOT NULL,
  `login` varchar(45) NOT NULL,
  `mdp` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `responsable`
--

INSERT INTO `responsable` (`idresponsables`, `login`, `mdp`) VALUES
(1, 'toto', 'toto');

-- --------------------------------------------------------

--
-- Structure de la table `rondes`
--

CREATE TABLE `rondes` (
  `idRonde` int(11) NOT NULL,
  `nomrondes` varchar(30) NOT NULL,
  `rondeActive` int(4) NOT NULL DEFAULT '1'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `rondes`
--

INSERT INTO `rondes` (`idRonde`, `nomrondes`, `rondeActive`) VALUES
(1, 'rondeGenerale', 1),
(2, 'rondeLycée', 1),
(3, 'rondeTouchard', 1);

-- --------------------------------------------------------

--
-- Structure de la table `smartphones`
--

CREATE TABLE `smartphones` (
  `idsmartphones` int(11) NOT NULL,
  `nomSmartphone` varchar(45) DEFAULT NULL,
  `idADB` varchar(45) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `smartphones`
--

INSERT INTO `smartphones` (`idsmartphones`, `nomSmartphone`, `idADB`) VALUES
(1, 'test', 'ZY322DHJWR'),
(4, 'Telephone1', '4TE7N16B17000721');

-- --------------------------------------------------------

--
-- Structure de la table `tags`
--

CREATE TABLE `tags` (
  `idTag` char(8) CHARACTER SET utf8mb4   NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4  ;

--
-- Déchargement des données de la table `tags`
--

INSERT INTO `tags` (`idTag`) VALUES
('85f6s98a'),
('85f6s98b'),
('85f6s91n'),
('Tc41'),
('Ubnda'),
('Hbcae'),
('a0YUB'),
('Ybdal1'),
('53-bbda'),
('67bdpa'),
('MQ_65'),
('098ha'),
('68hbuba'),
('ldaAUINM');

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
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `associationpointeauxrondes`
--
ALTER TABLE `associationpointeauxrondes`
  ADD PRIMARY KEY (`id`),
  ADD KEY `idRonde` (`idRonde`),
  ADD KEY `idPointeau` (`idPointeau`);

--
-- Index pour la table `batiment`
--
ALTER TABLE `batiment`
  ADD PRIMARY KEY (`idBatiment`);

--
-- Index pour la table `emplacement`
--
ALTER TABLE `emplacement`
  ADD PRIMARY KEY (`localisation`),
  ADD UNIQUE KEY `localisation` (`localisation`);

--
-- Index pour la table `historiquepointeau`
--
ALTER TABLE `historiquepointeau`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fk_historiquePointeau_pointeaux1_idx` (`idPointeau`),
  ADD KEY `fk_historiquePointeau_rondes1_idx` (`idRonde`),
  ADD KEY `fk_historiquePointeau_agents1_idx` (`idAgent`);

--
-- Index pour la table `historiqueronde`
--
ALTER TABLE `historiqueronde`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `pointeaux`
--
ALTER TABLE `pointeaux`
  ADD PRIMARY KEY (`idPointeau`),
  ADD KEY `idBatiment` (`idBatiment`);

--
-- Index pour la table `responsable`
--
ALTER TABLE `responsable`
  ADD PRIMARY KEY (`idresponsables`);

--
-- Index pour la table `rondes`
--
ALTER TABLE `rondes`
  ADD PRIMARY KEY (`idRonde`);

--
-- Index pour la table `smartphones`
--
ALTER TABLE `smartphones`
  ADD PRIMARY KEY (`idsmartphones`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `agents`
--
ALTER TABLE `agents`
  MODIFY `idAgent` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;

--
-- AUTO_INCREMENT pour la table `associationagentsrondes`
--
ALTER TABLE `associationagentsrondes`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT pour la table `associationpointeauxrondes`
--
ALTER TABLE `associationpointeauxrondes`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=21;

--
-- AUTO_INCREMENT pour la table `rondes`
--
ALTER TABLE `rondes`
  MODIFY `idRonde` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pour la table `smartphones`
--
ALTER TABLE `smartphones`
  MODIFY `idsmartphones` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `associationpointeauxrondes`
--
ALTER TABLE `associationpointeauxrondes`
  ADD CONSTRAINT `associationpointeauxrondes_ibfk_1` FOREIGN KEY (`idRonde`) REFERENCES `rondes` (`idRonde`),
  ADD CONSTRAINT `associationpointeauxrondes_ibfk_2` FOREIGN KEY (`idPointeau`) REFERENCES `pointeaux` (`idPointeau`);

--
-- Contraintes pour la table `pointeaux`
--
ALTER TABLE `pointeaux`
  ADD CONSTRAINT `pointeaux_ibfk_1` FOREIGN KEY (`idBatiment`) REFERENCES `batiment` (`idBatiment`) ON DELETE RESTRICT ON UPDATE RESTRICT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
