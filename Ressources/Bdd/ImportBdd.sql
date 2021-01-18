-- MySQL dump 10.13  Distrib 5.7.12, for Win64 (x86_64)
--
-- Host: localhost    Database: controleurderonde
-- ------------------------------------------------------
-- Server version	5.7.17-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `agents`
--

DROP TABLE IF EXISTS `agents`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `agents` (
  `idAgent` int(11) NOT NULL AUTO_INCREMENT,
  `idTag` char(8) DEFAULT NULL,
  `nom` varchar(45) NOT NULL,
  `prenom` varchar(45) NOT NULL,
  `agentActif` tinyint(4) NOT NULL DEFAULT '1',
  PRIMARY KEY (`idAgent`),
  KEY `fk_Agents_Tags1_idx` (`idTag`),
  CONSTRAINT `fk_Agents_Tags1` FOREIGN KEY (`idTag`) REFERENCES `tags` (`idTag`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `agents`
--

LOCK TABLES `agents` WRITE;
/*!40000 ALTER TABLE `agents` DISABLE KEYS */;
INSERT INTO `agents` VALUES (1,'45v2ty1c','Bidochon','Robert',1),(5,'85f6s98a','Lemée','Gabriel',1),(6,'gfy45e5d','Bidochon','Marta',1),(7,'f55d8888','Herbron','Tanguy',1),(8,'455qsd88','Dupe','Gwendal',1),(11,'d4s5d8e4','Guedon','Guillaume',1),(12,'s6d5e8c2','Senechal','Florian',1);
/*!40000 ALTER TABLE `agents` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `associationagentsrondes`
--

DROP TABLE IF EXISTS `associationagentsrondes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `associationagentsrondes` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idAgent` int(11) NOT NULL,
  `idRonde` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_AssociationAgentsRondes_Rondes1_idx` (`idRonde`),
  KEY `fk_AssociationAgentsRondes_Agents1_idx` (`idAgent`),
  CONSTRAINT `fk_AssociationAgentsRondes_Agents1` FOREIGN KEY (`idAgent`) REFERENCES `agents` (`idAgent`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fk_AssociationAgentsRondes_Rondes1` FOREIGN KEY (`idRonde`) REFERENCES `rondes` (`idRonde`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `associationagentsrondes`
--

LOCK TABLES `associationagentsrondes` WRITE;
/*!40000 ALTER TABLE `associationagentsrondes` DISABLE KEYS */;
/*!40000 ALTER TABLE `associationagentsrondes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `associationpointeauxrondes`
--

DROP TABLE IF EXISTS `associationpointeauxrondes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `associationpointeauxrondes` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idRonde` int(11) NOT NULL,
  `idPointeau` int(11) NOT NULL,
  `ordrePointeau` int(11) NOT NULL,
  `tempsProchainMin` int(11) DEFAULT '5',
  `tempsProchainMax` int(11) DEFAULT '15',
  PRIMARY KEY (`id`),
  KEY `fk_AssociationPointeauxRondes_Pointeaux_idx` (`idPointeau`),
  KEY `fk_AssociationPointeauxRondes_Rondes1_idx` (`idRonde`),
  CONSTRAINT `fk_AssociationPointeauxRondes_Pointeaux` FOREIGN KEY (`idPointeau`) REFERENCES `pointeaux` (`idPointeau`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fk_AssociationPointeauxRondes_Rondes1` FOREIGN KEY (`idRonde`) REFERENCES `rondes` (`idRonde`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `associationpointeauxrondes`
--

LOCK TABLES `associationpointeauxrondes` WRITE;
/*!40000 ALTER TABLE `associationpointeauxrondes` DISABLE KEYS */;
INSERT INTO `associationpointeauxrondes` VALUES (1,1,1,1,5,15),(2,1,4,2,5,15),(3,1,5,3,7,15),(4,1,8,4,5,15),(5,1,6,5,5,15),(6,1,3,6,5,15);
/*!40000 ALTER TABLE `associationpointeauxrondes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `historiquepointeau`
--

DROP TABLE IF EXISTS `historiquepointeau`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `historiquepointeau` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idAgent` int(11) NOT NULL,
  `idRonde` int(11) NOT NULL,
  `idPointeau` int(11) NOT NULL,
  `date` datetime NOT NULL,
  `ordrePointeau` int(11) NOT NULL,
  `numeroRonde` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_HistoriquePointeau_Rondes1_idx` (`idRonde`),
  KEY `fk_HistoriquePointeau_Pointeaux1_idx` (`idPointeau`),
  KEY `fk_HistoriquePointeau_Agents1_idx` (`idAgent`),
  CONSTRAINT `fk_HistoriquePointeau_Agents1` FOREIGN KEY (`idAgent`) REFERENCES `agents` (`idAgent`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fk_HistoriquePointeau_Pointeaux1` FOREIGN KEY (`idPointeau`) REFERENCES `pointeaux` (`idPointeau`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fk_HistoriquePointeau_Rondes1` FOREIGN KEY (`idRonde`) REFERENCES `rondes` (`idRonde`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=309 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `historiquepointeau`
--

LOCK TABLES `historiquepointeau` WRITE;
/*!40000 ALTER TABLE `historiquepointeau` DISABLE KEYS */;
INSERT INTO `historiquepointeau` VALUES (1,1,1,1,'2017-05-01 00:00:00',2,0),(2,1,1,1,'2017-05-01 00:00:00',2,0),(3,1,1,1,'2017-05-01 00:00:00',2,0),(4,1,1,2,'2017-05-02 00:00:00',-1,0),(5,1,1,1,'2017-05-02 00:00:00',2,0),(6,1,1,1,'2017-05-02 00:00:00',2,0),(7,1,1,3,'2017-05-02 00:00:00',1,0),(8,1,1,3,'2017-05-02 00:00:00',1,0),(9,1,1,1,'2017-05-02 00:00:00',2,0),(10,1,1,1,'2017-05-01 00:00:00',2,0),(11,1,1,1,'2017-05-01 00:00:00',2,0),(12,1,1,1,'2017-05-01 00:00:00',2,0),(13,1,1,2,'2017-05-02 00:00:00',-1,0),(14,1,1,1,'2017-05-02 00:00:00',2,0),(15,1,1,1,'2017-05-02 00:00:00',2,0),(16,1,1,3,'2017-05-02 00:00:00',1,0),(17,1,1,3,'2017-05-02 00:00:00',1,0),(18,1,1,1,'2017-05-02 00:00:00',2,0),(19,1,1,1,'2017-05-04 00:00:00',2,0),(20,1,1,1,'2017-05-04 00:00:00',2,0),(21,1,1,3,'2017-05-04 00:00:00',1,0),(22,1,1,3,'2017-05-04 00:00:00',1,0),(23,1,1,1,'2017-05-01 00:00:00',2,0),(24,1,1,1,'2017-05-01 00:00:00',2,0),(25,1,1,1,'2017-05-01 00:00:00',2,0),(26,1,1,2,'2017-05-02 00:00:00',-1,0),(27,1,1,1,'2017-05-02 00:00:00',2,0),(28,1,1,1,'2017-05-02 00:00:00',2,0),(29,1,1,3,'2017-05-02 00:00:00',1,0),(30,1,1,3,'2017-05-02 00:00:00',1,0),(31,1,1,1,'2017-05-02 00:00:00',2,0),(32,1,1,1,'2017-05-04 00:00:00',2,0),(33,1,1,1,'2017-05-04 00:00:00',2,0),(34,1,1,3,'2017-05-04 00:00:00',1,0),(35,1,1,3,'2017-05-04 00:00:00',1,0),(36,1,1,1,'2017-05-01 00:00:00',2,0),(37,1,1,1,'2017-05-01 00:00:00',2,0),(38,1,1,1,'2017-05-01 00:00:00',2,0),(39,1,1,2,'2017-05-02 00:00:00',-1,0),(40,1,1,1,'2017-05-02 00:00:00',2,0),(41,1,1,1,'2017-05-02 00:00:00',2,0),(42,1,1,3,'2017-05-02 00:00:00',1,0),(43,1,1,3,'2017-05-02 00:00:00',1,0),(44,1,1,1,'2017-05-02 00:00:00',2,0),(45,1,1,1,'2017-05-04 00:00:00',2,0),(46,1,1,1,'2017-05-04 00:00:00',2,0),(47,1,1,3,'2017-05-04 00:00:00',1,0),(48,1,1,3,'2017-05-04 00:00:00',1,0),(49,1,1,1,'2017-05-01 00:00:00',2,0),(50,1,1,1,'2017-05-01 00:00:00',2,0),(51,1,1,1,'2017-05-01 00:00:00',2,0),(52,1,1,2,'2017-05-02 00:00:00',-1,0),(53,1,1,1,'2017-05-02 00:00:00',2,0),(54,1,1,1,'2017-05-02 00:00:00',2,0),(55,1,1,3,'2017-05-02 00:00:00',1,0),(56,1,1,3,'2017-05-02 00:00:00',1,0),(57,1,1,1,'2017-05-02 00:00:00',2,0),(58,1,1,1,'2017-05-04 00:00:00',2,0),(59,1,1,1,'2017-05-04 00:00:00',2,0),(60,1,1,3,'2017-05-04 00:00:00',1,0),(61,1,1,3,'2017-05-04 00:00:00',1,0),(62,1,1,1,'2017-05-01 00:00:00',2,0),(63,1,1,1,'2017-05-01 00:00:00',2,0),(64,1,1,1,'2017-05-01 00:00:00',2,0),(65,1,1,2,'2017-05-02 00:00:00',-1,0),(66,1,1,1,'2017-05-02 00:00:00',2,0),(67,1,1,1,'2017-05-02 00:00:00',2,0),(68,1,1,3,'2017-05-02 00:00:00',1,0),(69,1,1,3,'2017-05-02 00:00:00',1,0),(70,1,1,1,'2017-05-02 00:00:00',2,0),(71,1,1,1,'2017-05-04 00:00:00',2,0),(72,1,1,1,'2017-05-04 00:00:00',2,0),(73,1,1,3,'2017-05-04 00:00:00',1,0),(74,1,1,3,'2017-05-04 00:00:00',1,0),(75,1,1,1,'2017-05-01 00:00:00',2,0),(76,1,1,1,'2017-05-01 00:00:00',2,0),(77,1,1,1,'2017-05-01 00:00:00',2,0),(78,1,1,2,'2017-05-02 00:00:00',-1,0),(79,1,1,1,'2017-05-02 00:00:00',2,0),(80,1,1,1,'2017-05-02 00:00:00',2,0),(81,1,1,3,'2017-05-02 00:00:00',1,0),(82,1,1,3,'2017-05-02 00:00:00',1,0),(83,1,1,1,'2017-05-02 00:00:00',2,0),(84,1,1,1,'2017-05-04 00:00:00',2,0),(85,1,1,1,'2017-05-04 00:00:00',2,0),(86,1,1,3,'2017-05-04 00:00:00',1,0),(87,1,1,3,'2017-05-04 00:00:00',1,0),(88,1,1,1,'2017-05-01 00:00:00',2,0),(89,1,1,1,'2017-05-01 00:00:00',2,0),(90,1,1,1,'2017-05-01 00:00:00',2,0),(91,1,1,2,'2017-05-02 00:00:00',-1,0),(92,1,1,1,'2017-05-02 00:00:00',2,0),(93,1,1,1,'2017-05-02 00:00:00',2,0),(94,1,1,3,'2017-05-02 00:00:00',1,0),(95,1,1,3,'2017-05-02 00:00:00',1,0),(96,1,1,1,'2017-05-02 00:00:00',2,0),(97,1,1,1,'2017-05-04 00:00:00',2,0),(98,1,1,1,'2017-05-04 00:00:00',2,0),(99,1,1,3,'2017-05-04 00:00:00',1,0),(100,1,1,3,'2017-05-04 00:00:00',1,0),(101,1,1,1,'2017-05-01 00:00:00',2,0),(102,1,1,1,'2017-05-01 00:00:00',2,0),(103,1,1,1,'2017-05-01 00:00:00',2,0),(104,1,1,2,'2017-05-02 00:00:00',-1,0),(105,1,1,1,'2017-05-02 00:00:00',2,0),(106,1,1,1,'2017-05-02 00:00:00',2,0),(107,1,1,3,'2017-05-02 00:00:00',1,0),(108,1,1,3,'2017-05-02 00:00:00',1,0),(109,1,1,1,'2017-05-02 00:00:00',2,0),(110,1,1,1,'2017-05-04 00:00:00',2,0),(111,1,1,1,'2017-05-04 00:00:00',2,0),(112,1,1,3,'2017-05-04 00:00:00',1,0),(113,1,1,3,'2017-05-04 00:00:00',1,0),(114,1,1,1,'2017-05-01 00:00:00',2,0),(115,1,1,1,'2017-05-01 00:00:00',2,0),(116,1,1,1,'2017-05-01 00:00:00',2,0),(117,1,1,2,'2017-05-02 00:00:00',-1,0),(118,1,1,1,'2017-05-02 00:00:00',2,0),(119,1,1,1,'2017-05-02 00:00:00',2,0),(120,1,1,3,'2017-05-02 00:00:00',1,0),(121,1,1,3,'2017-05-02 00:00:00',1,0),(122,1,1,1,'2017-05-02 00:00:00',2,0),(123,1,1,1,'2017-05-04 00:00:00',2,0),(124,1,1,1,'2017-05-04 00:00:00',2,0),(125,1,1,3,'2017-05-04 00:00:00',1,0),(126,1,1,3,'2017-05-04 00:00:00',1,0),(127,1,1,1,'2017-05-01 00:00:00',2,0),(128,1,1,1,'2017-05-01 00:00:00',2,0),(129,1,1,1,'2017-05-01 00:00:00',2,0),(130,1,1,2,'2017-05-02 00:00:00',-1,0),(131,1,1,1,'2017-05-02 00:00:00',2,0),(132,1,1,1,'2017-05-02 00:00:00',2,0),(133,1,1,3,'2017-05-02 00:00:00',1,0),(134,1,1,3,'2017-05-02 00:00:00',1,0),(135,1,1,1,'2017-05-02 00:00:00',2,0),(136,1,1,1,'2017-05-04 00:00:00',2,0),(137,1,1,1,'2017-05-04 00:00:00',2,0),(138,1,1,3,'2017-05-04 00:00:00',1,0),(139,1,1,3,'2017-05-04 00:00:00',1,0),(140,1,1,1,'2017-05-01 00:00:00',2,0),(141,1,1,1,'2017-05-01 00:00:00',2,0),(142,1,1,1,'2017-05-01 00:00:00',2,0),(143,1,1,2,'2017-05-02 00:00:00',-1,0),(144,1,1,1,'2017-05-02 00:00:00',2,0),(145,1,1,1,'2017-05-02 00:00:00',2,0),(146,1,1,3,'2017-05-02 00:00:00',1,0),(147,1,1,3,'2017-05-02 00:00:00',1,0),(148,1,1,1,'2017-05-02 00:00:00',2,0),(149,1,1,1,'2017-05-04 00:00:00',2,0),(150,1,1,1,'2017-05-04 00:00:00',2,0),(151,1,1,3,'2017-05-04 00:00:00',1,0),(152,1,1,3,'2017-05-04 00:00:00',1,0),(153,1,1,1,'2017-05-01 00:00:00',2,0),(154,1,1,1,'2017-05-01 00:00:00',2,0),(155,1,1,1,'2017-05-01 00:00:00',2,0),(156,1,1,2,'2017-05-02 00:00:00',-1,0),(157,1,1,1,'2017-05-02 00:00:00',2,0),(158,1,1,1,'2017-05-02 00:00:00',2,0),(159,1,1,3,'2017-05-02 00:00:00',1,0),(160,1,1,3,'2017-05-02 00:00:00',1,0),(161,1,1,1,'2017-05-02 00:00:00',2,0),(162,1,1,1,'2017-05-04 00:00:00',2,0),(163,1,1,1,'2017-05-04 00:00:00',2,0),(164,1,1,3,'2017-05-04 00:00:00',1,0),(165,1,1,3,'2017-05-04 00:00:00',1,0),(166,1,1,1,'2017-05-01 00:00:00',2,0),(167,1,1,1,'2017-05-01 00:00:00',2,0),(168,1,1,1,'2017-05-01 00:00:00',2,0),(169,1,1,2,'2017-05-02 00:00:00',-1,0),(170,1,1,1,'2017-05-02 00:00:00',2,0),(171,1,1,1,'2017-05-02 00:00:00',2,0),(172,1,1,3,'2017-05-02 00:00:00',1,0),(173,1,1,3,'2017-05-02 00:00:00',1,0),(174,1,1,1,'2017-05-02 00:00:00',2,0),(175,1,1,1,'2017-05-04 00:00:00',2,0),(176,1,1,1,'2017-05-04 00:00:00',2,0),(177,1,1,3,'2017-05-04 00:00:00',1,0),(178,1,1,3,'2017-05-04 00:00:00',1,0),(179,1,1,1,'2017-05-01 00:00:00',2,0),(180,1,1,1,'2017-05-01 00:00:00',2,0),(181,1,1,1,'2017-05-01 00:00:00',2,0),(182,1,1,2,'2017-05-02 00:00:00',-1,0),(183,1,1,1,'2017-05-02 00:00:00',2,0),(184,1,1,1,'2017-05-02 00:00:00',2,0),(185,1,1,3,'2017-05-02 00:00:00',1,0),(186,1,1,3,'2017-05-02 00:00:00',1,0),(187,1,1,1,'2017-05-02 00:00:00',2,0),(188,1,1,1,'2017-05-04 00:00:00',2,0),(189,1,1,1,'2017-05-04 00:00:00',2,0),(190,1,1,3,'2017-05-04 00:00:00',1,0),(191,1,1,3,'2017-05-04 00:00:00',1,0),(192,1,1,1,'2017-05-01 00:00:00',2,0),(193,1,1,1,'2017-05-01 00:00:00',2,0),(194,1,1,1,'2017-05-01 00:00:00',2,0),(195,1,1,2,'2017-05-02 00:00:00',-1,0),(196,1,1,1,'2017-05-02 00:00:00',2,0),(197,1,1,1,'2017-05-02 00:00:00',2,0),(198,1,1,3,'2017-05-02 00:00:00',1,0),(199,1,1,3,'2017-05-02 00:00:00',1,0),(200,1,1,1,'2017-05-02 00:00:00',2,0),(201,1,1,1,'2017-05-04 00:00:00',2,0),(202,1,1,1,'2017-05-04 00:00:00',2,0),(203,1,1,3,'2017-05-04 00:00:00',1,0),(204,1,1,3,'2017-05-04 00:00:00',1,0),(205,1,1,1,'2017-05-01 14:18:18',2,0),(206,1,1,1,'2017-05-01 18:06:18',2,0),(207,1,1,1,'2017-05-01 18:06:33',2,0),(208,1,1,2,'2017-05-02 11:40:42',-1,0),(209,1,1,1,'2017-05-02 11:41:56',2,0),(210,1,1,1,'2017-05-02 11:45:04',2,0),(211,1,1,3,'2017-05-02 11:45:29',1,0),(212,1,1,3,'2017-05-02 11:46:31',1,0),(213,1,1,1,'2017-05-02 11:50:07',2,0),(214,1,1,1,'2017-05-04 09:36:33',2,0),(215,1,1,1,'2017-05-04 09:36:48',2,0),(216,1,1,3,'2017-05-04 09:37:19',1,0),(217,1,1,3,'2017-05-04 09:37:34',1,0),(218,1,1,1,'2017-05-01 14:18:18',2,0),(219,1,1,1,'2017-05-01 18:06:18',2,0),(220,1,1,1,'2017-05-01 18:06:33',2,0),(221,1,1,2,'2017-05-02 11:40:42',-1,0),(222,1,1,1,'2017-05-02 11:41:56',2,0),(223,1,1,1,'2017-05-02 11:45:04',2,0),(224,1,1,3,'2017-05-02 11:45:29',1,0),(225,1,1,3,'2017-05-02 11:46:31',1,0),(226,1,1,1,'2017-05-02 11:50:07',2,0),(227,1,1,1,'2017-05-04 09:36:33',2,0),(228,1,1,1,'2017-05-04 09:36:48',2,0),(229,1,1,3,'2017-05-04 09:37:19',1,0),(230,1,1,3,'2017-05-04 09:37:34',1,0),(231,1,1,1,'2017-05-01 14:18:18',2,0),(232,1,1,1,'2017-05-01 18:06:18',2,0),(233,1,1,1,'2017-05-01 18:06:33',2,0),(234,1,1,2,'2017-05-02 11:40:42',-1,0),(235,1,1,1,'2017-05-02 11:41:56',2,0),(236,1,1,1,'2017-05-02 11:45:04',2,0),(237,1,1,3,'2017-05-02 11:45:29',1,0),(238,1,1,3,'2017-05-02 11:46:31',1,0),(239,1,1,1,'2017-05-02 11:50:07',2,0),(240,1,1,1,'2017-05-04 09:36:33',2,0),(241,1,1,1,'2017-05-04 09:36:48',2,0),(242,1,1,3,'2017-05-04 09:37:19',1,0),(243,1,1,3,'2017-05-04 09:37:34',1,0),(244,1,1,1,'2017-05-01 14:18:18',2,0),(245,1,1,1,'2017-05-01 18:06:18',2,0),(246,1,1,1,'2017-05-01 18:06:33',2,0),(247,1,1,2,'2017-05-02 11:40:42',-1,0),(248,1,1,1,'2017-05-02 11:41:56',2,0),(249,1,1,1,'2017-05-02 11:45:04',2,0),(250,1,1,3,'2017-05-02 11:45:29',1,0),(251,1,1,3,'2017-05-02 11:46:31',1,0),(252,1,1,1,'2017-05-02 11:50:07',2,0),(253,1,1,1,'2017-05-04 09:36:33',2,0),(254,1,1,1,'2017-05-04 09:36:48',2,0),(255,1,1,3,'2017-05-04 09:37:19',1,0),(256,1,1,3,'2017-05-04 09:37:34',1,0),(257,1,1,1,'2017-05-01 14:18:18',2,0),(258,1,1,1,'2017-05-01 18:06:18',2,0),(259,1,1,1,'2017-05-01 18:06:33',2,0),(260,1,1,2,'2017-05-02 11:40:42',-1,0),(261,1,1,1,'2017-05-02 11:41:56',2,0),(262,1,1,1,'2017-05-02 11:45:04',2,0),(263,1,1,3,'2017-05-02 11:45:29',1,0),(264,1,1,3,'2017-05-02 11:46:31',1,0),(265,1,1,1,'2017-05-02 11:50:07',2,0),(266,1,1,1,'2017-05-04 09:36:33',2,0),(267,1,1,1,'2017-05-04 09:36:48',2,0),(268,1,1,3,'2017-05-04 09:37:19',1,0),(269,1,1,3,'2017-05-04 09:37:34',1,0),(270,1,1,1,'2017-05-01 14:18:18',2,0),(271,1,1,1,'2017-05-01 18:06:18',2,0),(272,1,1,1,'2017-05-01 18:06:33',2,0),(273,1,1,2,'2017-05-02 11:40:42',-1,0),(274,1,1,1,'2017-05-02 11:41:56',2,0),(275,1,1,1,'2017-05-02 11:45:04',2,0),(276,1,1,3,'2017-05-02 11:45:29',1,0),(277,1,1,3,'2017-05-02 11:46:31',1,0),(278,1,1,1,'2017-05-02 11:50:07',2,0),(279,1,1,1,'2017-05-04 09:36:33',2,0),(280,1,1,1,'2017-05-04 09:36:48',2,0),(281,1,1,3,'2017-05-04 09:37:19',1,0),(282,1,1,3,'2017-05-04 09:37:34',1,0),(283,1,1,1,'2017-05-01 14:18:18',2,0),(284,1,1,1,'2017-05-01 18:06:18',2,0),(285,1,1,1,'2017-05-01 18:06:33',2,0),(286,1,1,2,'2017-05-02 11:40:42',-1,0),(287,1,1,1,'2017-05-02 11:41:56',2,0),(288,1,1,1,'2017-05-02 11:45:04',2,0),(289,1,1,3,'2017-05-02 11:45:29',1,0),(290,1,1,3,'2017-05-02 11:46:31',1,0),(291,1,1,1,'2017-05-02 11:50:07',2,0),(292,1,1,1,'2017-05-04 09:36:33',2,0),(293,1,1,1,'2017-05-04 09:36:48',2,0),(294,1,1,3,'2017-05-04 09:37:19',1,0),(295,1,1,3,'2017-05-04 09:37:34',1,0),(296,1,1,1,'2017-05-01 14:18:18',2,0),(297,1,1,1,'2017-05-01 18:06:18',2,0),(298,1,1,1,'2017-05-01 18:06:33',2,0),(299,1,1,2,'2017-05-02 11:40:42',-1,0),(300,1,1,1,'2017-05-02 11:41:56',2,0),(301,1,1,1,'2017-05-02 11:45:04',2,0),(302,1,1,3,'2017-05-02 11:45:29',1,0),(303,1,1,3,'2017-05-02 11:46:31',1,0),(304,1,1,1,'2017-05-02 11:50:07',2,0),(305,1,1,1,'2017-05-04 09:36:33',2,0),(306,1,1,1,'2017-05-04 09:36:48',2,0),(307,1,1,3,'2017-05-04 09:37:19',1,0),(308,1,1,3,'2017-05-04 09:37:34',1,0);
/*!40000 ALTER TABLE `historiquepointeau` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `mainscourantes`
--

DROP TABLE IF EXISTS `mainscourantes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mainscourantes` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `texte` varchar(250) NOT NULL,
  `idHistoriquePointeau` int(11) NOT NULL,
  `date` datetime NOT NULL,
  `type` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=166 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `mainscourantes`
--

LOCK TABLES `mainscourantes` WRITE;
/*!40000 ALTER TABLE `mainscourantes` DISABLE KEYS */;
INSERT INTO `mainscourantes` VALUES (1,'Bâtiment extérieur|Entrepot|1.5.2017|18.6.30.jpg',3,'2017-05-01 00:00:00',1),(2,'Test synchro ',4,'2017-05-01 00:00:00',0),(3,'Fgfd',6,'2017-05-02 00:00:00',0),(4,'Bâtiment extérieur|Entrepot|2.5.2017|11.45.1.jpg',6,'2017-05-02 00:00:00',1),(5,'Bâtiment extérieur|Entrepot|1.5.2017|18.6.30.jpg',12,'2017-05-01 00:00:00',1),(6,'Test synchro ',13,'2017-05-01 00:00:00',0),(7,'Fgfd',15,'2017-05-02 00:00:00',0),(8,'Bâtiment extérieur|Entrepot|2.5.2017|11.45.1.jpg',15,'2017-05-02 00:00:00',1),(9,'Fgfd',21,'2017-05-04 00:00:00',0),(10,'Test',22,'2017-05-04 00:00:00',0),(11,'Bâtiment extérieur|Ordinateur|4.5.2017|9.37.32.jpg',22,'2017-05-04 00:00:00',1),(12,'Bâtiment extérieur|Entrepot|1.5.2017|18.6.30.jpg',25,'2017-05-01 00:00:00',1),(13,'Test synchro ',26,'2017-05-01 00:00:00',0),(14,'Fgfd',28,'2017-05-02 00:00:00',0),(15,'Bâtiment extérieur|Entrepot|2.5.2017|11.45.1.jpg',28,'2017-05-02 00:00:00',1),(16,'Fgfd',34,'2017-05-04 00:00:00',0),(17,'Test',35,'2017-05-04 00:00:00',0),(18,'Bâtiment extérieur|Ordinateur|4.5.2017|9.37.32.jpg',35,'2017-05-04 00:00:00',1),(19,'Bâtiment extérieur|Entrepot|1.5.2017|18.6.30.jpg',38,'2017-05-01 00:00:00',1),(20,'Test synchro ',39,'2017-05-01 00:00:00',0),(21,'Fgfd',41,'2017-05-02 00:00:00',0),(22,'Bâtiment extérieur|Entrepot|2.5.2017|11.45.1.jpg',41,'2017-05-02 00:00:00',1),(23,'Fgfd',47,'2017-05-04 00:00:00',0),(24,'Test',48,'2017-05-04 00:00:00',0),(25,'Bâtiment extérieur|Ordinateur|4.5.2017|9.37.32.jpg',48,'2017-05-04 00:00:00',1),(26,'Bâtiment extérieur|Entrepot|1.5.2017|18.6.30.jpg',51,'2017-05-01 00:00:00',1),(27,'Test synchro ',52,'2017-05-01 00:00:00',0),(28,'Fgfd',54,'2017-05-02 00:00:00',0),(29,'Bâtiment extérieur|Entrepot|2.5.2017|11.45.1.jpg',54,'2017-05-02 00:00:00',1),(30,'Fgfd',60,'2017-05-04 00:00:00',0),(31,'Test',61,'2017-05-04 00:00:00',0),(32,'Bâtiment extérieur|Ordinateur|4.5.2017|9.37.32.jpg',61,'2017-05-04 00:00:00',1),(33,'Bâtiment extérieur|Entrepot|1.5.2017|18.6.30.jpg',64,'2017-05-01 00:00:00',1),(34,'Test synchro ',65,'2017-05-01 00:00:00',0),(35,'Fgfd',67,'2017-05-02 00:00:00',0),(36,'Bâtiment extérieur|Entrepot|2.5.2017|11.45.1.jpg',67,'2017-05-02 00:00:00',1),(37,'Fgfd',73,'2017-05-04 00:00:00',0),(38,'Test',74,'2017-05-04 00:00:00',0),(39,'Bâtiment extérieur|Ordinateur|4.5.2017|9.37.32.jpg',74,'2017-05-04 00:00:00',1),(40,'Bâtiment extérieur|Entrepot|1.5.2017|18.6.30.jpg',77,'2017-05-01 00:00:00',1),(41,'Test synchro ',78,'2017-05-01 00:00:00',0),(42,'Fgfd',80,'2017-05-02 00:00:00',0),(43,'Bâtiment extérieur|Entrepot|2.5.2017|11.45.1.jpg',80,'2017-05-02 00:00:00',1),(44,'Fgfd',86,'2017-05-04 00:00:00',0),(45,'Test',87,'2017-05-04 00:00:00',0),(46,'Bâtiment extérieur|Ordinateur|4.5.2017|9.37.32.jpg',87,'2017-05-04 00:00:00',1),(47,'Bâtiment extérieur|Entrepot|1.5.2017|18.6.30.jpg',90,'2017-05-01 00:00:00',1),(48,'Test synchro ',91,'2017-05-01 00:00:00',0),(49,'Fgfd',93,'2017-05-02 00:00:00',0),(50,'Bâtiment extérieur|Entrepot|2.5.2017|11.45.1.jpg',93,'2017-05-02 00:00:00',1),(51,'Fgfd',99,'2017-05-04 00:00:00',0),(52,'Test',100,'2017-05-04 00:00:00',0),(53,'Bâtiment extérieur|Ordinateur|4.5.2017|9.37.32.jpg',100,'2017-05-04 00:00:00',1),(54,'Bâtiment extérieur|Entrepot|1.5.2017|18.6.30.jpg',103,'2017-05-01 00:00:00',1),(55,'Test synchro ',104,'2017-05-01 00:00:00',0),(56,'Fgfd',106,'2017-05-02 00:00:00',0),(57,'Bâtiment extérieur|Entrepot|2.5.2017|11.45.1.jpg',106,'2017-05-02 00:00:00',1),(58,'Fgfd',112,'2017-05-04 00:00:00',0),(59,'Test',113,'2017-05-04 00:00:00',0),(60,'Bâtiment extérieur|Ordinateur|4.5.2017|9.37.32.jpg',113,'2017-05-04 00:00:00',1),(61,'Bâtiment extérieur|Entrepot|1.5.2017|18.6.30.jpg',116,'2017-05-01 00:00:00',1),(62,'Test synchro ',117,'2017-05-01 00:00:00',0),(63,'Fgfd',119,'2017-05-02 00:00:00',0),(64,'Bâtiment extérieur|Entrepot|2.5.2017|11.45.1.jpg',119,'2017-05-02 00:00:00',1),(65,'Fgfd',125,'2017-05-04 00:00:00',0),(66,'Test',126,'2017-05-04 00:00:00',0),(67,'Bâtiment extérieur|Ordinateur|4.5.2017|9.37.32.jpg',126,'2017-05-04 00:00:00',1),(68,'Bâtiment extérieur|Entrepot|1.5.2017|18.6.30.jpg',129,'2017-05-01 00:00:00',1),(69,'Test synchro ',130,'2017-05-01 00:00:00',0),(70,'Fgfd',132,'2017-05-02 00:00:00',0),(71,'Bâtiment extérieur|Entrepot|2.5.2017|11.45.1.jpg',132,'2017-05-02 00:00:00',1),(72,'Fgfd',138,'2017-05-04 00:00:00',0),(73,'Test',139,'2017-05-04 00:00:00',0),(74,'Bâtiment extérieur|Ordinateur|4.5.2017|9.37.32.jpg',139,'2017-05-04 00:00:00',1),(75,'Bâtiment extérieur|Entrepot|1.5.2017|18.6.30.jpg',142,'2017-05-01 00:00:00',1),(76,'Test synchro ',143,'2017-05-01 00:00:00',0),(77,'Fgfd',145,'2017-05-02 00:00:00',0),(78,'Bâtiment extérieur|Entrepot|2.5.2017|11.45.1.jpg',145,'2017-05-02 00:00:00',1),(79,'Fgfd',151,'2017-05-04 00:00:00',0),(80,'Test',152,'2017-05-04 00:00:00',0),(81,'Bâtiment extérieur|Ordinateur|4.5.2017|9.37.32.jpg',152,'2017-05-04 00:00:00',1),(82,'Bâtiment extérieur|Entrepot|1.5.2017|18.6.30.jpg',155,'2017-05-01 00:00:00',1),(83,'Test synchro ',156,'2017-05-01 00:00:00',0),(84,'Fgfd',158,'2017-05-02 00:00:00',0),(85,'Bâtiment extérieur|Entrepot|2.5.2017|11.45.1.jpg',158,'2017-05-02 00:00:00',1),(86,'Fgfd',164,'2017-05-04 00:00:00',0),(87,'Test',165,'2017-05-04 00:00:00',0),(88,'Bâtiment extérieur|Ordinateur|4.5.2017|9.37.32.jpg',165,'2017-05-04 00:00:00',1),(89,'Bâtiment extérieur|Entrepot|1.5.2017|18.6.30.jpg',168,'2017-05-01 00:00:00',1),(90,'Test synchro ',169,'2017-05-01 00:00:00',0),(91,'Fgfd',171,'2017-05-02 00:00:00',0),(92,'Bâtiment extérieur|Entrepot|2.5.2017|11.45.1.jpg',171,'2017-05-02 00:00:00',1),(93,'Fgfd',177,'2017-05-04 00:00:00',0),(94,'Test',178,'2017-05-04 00:00:00',0),(95,'Bâtiment extérieur|Ordinateur|4.5.2017|9.37.32.jpg',178,'2017-05-04 00:00:00',1),(96,'Bâtiment extérieur|Entrepot|1.5.2017|18.6.30.jpg',181,'2017-05-01 00:00:00',1),(97,'Test synchro ',182,'2017-05-01 00:00:00',0),(98,'Fgfd',184,'2017-05-02 00:00:00',0),(99,'Bâtiment extérieur|Entrepot|2.5.2017|11.45.1.jpg',184,'2017-05-02 00:00:00',1),(100,'Fgfd',190,'2017-05-04 00:00:00',0),(101,'Test',191,'2017-05-04 00:00:00',0),(102,'Bâtiment extérieur|Ordinateur|4.5.2017|9.37.32.jpg',191,'2017-05-04 00:00:00',1),(103,'Bâtiment extérieur|Entrepot|1.5.2017|18.6.30.jpg',194,'2017-05-01 00:00:00',1),(104,'Test synchro ',195,'2017-05-01 00:00:00',0),(105,'Fgfd',197,'2017-05-02 00:00:00',0),(106,'Bâtiment extérieur|Entrepot|2.5.2017|11.45.1.jpg',197,'2017-05-02 00:00:00',1),(107,'Fgfd',203,'2017-05-04 00:00:00',0),(108,'Test',204,'2017-05-04 00:00:00',0),(109,'Bâtiment extérieur|Ordinateur|4.5.2017|9.37.32.jpg',204,'2017-05-04 00:00:00',1),(110,'Bâtiment extérieur|Entrepot|1.5.2017|18.6.30.jpg',207,'2017-05-01 18:06:32',1),(111,'Test synchro ',208,'2017-05-01 18:06:42',0),(112,'Fgfd',210,'2017-05-02 11:44:21',0),(113,'Bâtiment extérieur|Entrepot|2.5.2017|11.45.1.jpg',210,'2017-05-02 11:45:03',1),(114,'Fgfd',216,'2017-05-04 09:36:53',0),(115,'Test',217,'2017-05-04 09:37:25',0),(116,'Bâtiment extérieur|Ordinateur|4.5.2017|9.37.32.jpg',217,'2017-05-04 09:37:33',1),(117,'Bâtiment extérieur|Entrepot|1.5.2017|18.6.30.jpg',220,'2017-05-01 18:06:32',1),(118,'Test synchro ',221,'2017-05-01 18:06:42',0),(119,'Fgfd',223,'2017-05-02 11:44:21',0),(120,'Bâtiment extérieur|Entrepot|2.5.2017|11.45.1.jpg',223,'2017-05-02 11:45:03',1),(121,'Fgfd',229,'2017-05-04 09:36:53',0),(122,'Test',230,'2017-05-04 09:37:25',0),(123,'Bâtiment extérieur|Ordinateur|4.5.2017|9.37.32.jpg',230,'2017-05-04 09:37:33',1),(124,'Bâtiment extérieur|Entrepot|1.5.2017|18.6.30.jpg',233,'2017-05-01 18:06:32',1),(125,'Test synchro ',234,'2017-05-01 18:06:42',0),(126,'Fgfd',236,'2017-05-02 11:44:21',0),(127,'Bâtiment extérieur|Entrepot|2.5.2017|11.45.1.jpg',236,'2017-05-02 11:45:03',1),(128,'Fgfd',242,'2017-05-04 09:36:53',0),(129,'Test',243,'2017-05-04 09:37:25',0),(130,'Bâtiment extérieur|Ordinateur|4.5.2017|9.37.32.jpg',243,'2017-05-04 09:37:33',1),(131,'Bâtiment extérieur|Entrepot|1.5.2017|18.6.30.jpg',246,'2017-05-01 18:06:32',1),(132,'Test synchro ',247,'2017-05-01 18:06:42',0),(133,'Fgfd',249,'2017-05-02 11:44:21',0),(134,'Bâtiment extérieur|Entrepot|2.5.2017|11.45.1.jpg',249,'2017-05-02 11:45:03',1),(135,'Fgfd',255,'2017-05-04 09:36:53',0),(136,'Test',256,'2017-05-04 09:37:25',0),(137,'Bâtiment extérieur|Ordinateur|4.5.2017|9.37.32.jpg',256,'2017-05-04 09:37:33',1),(138,'Bâtiment extérieur|Entrepot|1.5.2017|18.6.30.jpg',259,'2017-05-01 18:06:32',1),(139,'Test synchro ',260,'2017-05-01 18:06:42',0),(140,'Fgfd',262,'2017-05-02 11:44:21',0),(141,'Bâtiment extérieur|Entrepot|2.5.2017|11.45.1.jpg',262,'2017-05-02 11:45:03',1),(142,'Fgfd',268,'2017-05-04 09:36:53',0),(143,'Test',269,'2017-05-04 09:37:25',0),(144,'Bâtiment extérieur|Ordinateur|4.5.2017|9.37.32.jpg',269,'2017-05-04 09:37:33',1),(145,'Bâtiment extérieur|Entrepot|1.5.2017|18.6.30.jpg',272,'2017-05-01 18:06:32',1),(146,'Test synchro ',273,'2017-05-01 18:06:42',0),(147,'Fgfd',275,'2017-05-02 11:44:21',0),(148,'Bâtiment extérieur|Entrepot|2.5.2017|11.45.1.jpg',275,'2017-05-02 11:45:03',1),(149,'Fgfd',281,'2017-05-04 09:36:53',0),(150,'Test',282,'2017-05-04 09:37:25',0),(151,'Bâtiment extérieur|Ordinateur|4.5.2017|9.37.32.jpg',282,'2017-05-04 09:37:33',1),(152,'Bâtiment extérieur|Entrepot|1.5.2017|18.6.30.jpg',285,'2017-05-01 18:06:32',1),(153,'Test synchro ',286,'2017-05-01 18:06:42',0),(154,'Fgfd',288,'2017-05-02 11:44:21',0),(155,'Bâtiment extérieur|Entrepot|2.5.2017|11.45.1.jpg',288,'2017-05-02 11:45:03',1),(156,'Fgfd',294,'2017-05-04 09:36:53',0),(157,'Test',295,'2017-05-04 09:37:25',0),(158,'Bâtiment extérieur|Ordinateur|4.5.2017|9.37.32.jpg',295,'2017-05-04 09:37:33',1),(159,'Bâtiment extérieur|Entrepot|1.5.2017|18.6.30.jpg',298,'2017-05-01 18:06:32',1),(160,'Test synchro ',299,'2017-05-01 18:06:42',0),(161,'Fgfd',301,'2017-05-02 11:44:21',0),(162,'Bâtiment extérieur|Entrepot|2.5.2017|11.45.1.jpg',301,'2017-05-02 11:45:03',1),(163,'Fgfd',307,'2017-05-04 09:36:53',0),(164,'Test',308,'2017-05-04 09:37:25',0),(165,'Bâtiment extérieur|Ordinateur|4.5.2017|9.37.32.jpg',308,'2017-05-04 09:37:33',1);
/*!40000 ALTER TABLE `mainscourantes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pointeaux`
--

DROP TABLE IF EXISTS `pointeaux`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `pointeaux` (
  `idPointeau` int(11) NOT NULL AUTO_INCREMENT,
  `idTag` char(8) NOT NULL,
  `lieu` varchar(20) DEFAULT NULL,
  `numero` int(11) NOT NULL,
  `pointeauActif` tinyint(4) NOT NULL DEFAULT '1',
  PRIMARY KEY (`idPointeau`),
  KEY `fk_Pointeaux_Tags1_idx` (`idTag`),
  CONSTRAINT `fk_Pointeaux_Tags1` FOREIGN KEY (`idTag`) REFERENCES `tags` (`idTag`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pointeaux`
--

LOCK TABLES `pointeaux` WRITE;
/*!40000 ALTER TABLE `pointeaux` DISABLE KEYS */;
INSERT INTO `pointeaux` VALUES (1,'2d15s46z','Entrée principale',12,1),(2,'4d2d1e5d','',8,1),(3,'99ds45d2','Sortie Sud',9,1),(4,'4s2x15fd','Bureau A',1,1),(5,'7a5s4d5e','Bureau B',2,1),(6,'d4f5c1v2','Hall Nord',3,1),(7,'x1d25f4r','Escalier accueil',4,1),(8,'d1c25f44','Escalier parking',5,1),(9,'1c2f54g7','Hall Est',6,1);
/*!40000 ALTER TABLE `pointeaux` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `responsable`
--

DROP TABLE IF EXISTS `responsable`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `responsable` (
  `idResponsable` int(11) NOT NULL AUTO_INCREMENT,
  `login` varchar(45) NOT NULL,
  `mdp` varchar(45) NOT NULL,
  PRIMARY KEY (`idResponsable`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `responsable`
--

LOCK TABLES `responsable` WRITE;
/*!40000 ALTER TABLE `responsable` DISABLE KEYS */;
INSERT INTO `responsable` VALUES (1,'admin','admin');
/*!40000 ALTER TABLE `responsable` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `rondes`
--

DROP TABLE IF EXISTS `rondes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `rondes` (
  `idRonde` int(11) NOT NULL AUTO_INCREMENT,
  `nom` varchar(30) NOT NULL,
  `rondeActive` tinyint(4) NOT NULL DEFAULT '1',
  PRIMARY KEY (`idRonde`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `rondes`
--

LOCK TABLES `rondes` WRITE;
/*!40000 ALTER TABLE `rondes` DISABLE KEYS */;
INSERT INTO `rondes` VALUES (1,'Bâtiment A',1);
/*!40000 ALTER TABLE `rondes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tags`
--

DROP TABLE IF EXISTS `tags`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tags` (
  `idTag` char(8) NOT NULL,
  PRIMARY KEY (`idTag`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tags`
--

LOCK TABLES `tags` WRITE;
/*!40000 ALTER TABLE `tags` DISABLE KEYS */;
INSERT INTO `tags` VALUES ('1c2f54g7'),('2d15s46z'),('455qsd88'),('45v2ty1c'),('4d2d1e5d'),('4s2x15fd'),('7a5s4d5e'),('85f6s98a'),('99ds45d2'),('d1c25f44'),('d4f5c1v2'),('d4s5d8e4'),('f55d8888'),('gfy45e5d'),('s6d5e8c2'),('x1d25f4r');
/*!40000 ALTER TABLE `tags` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2017-05-04 15:00:38
