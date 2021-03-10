CREATE DATABASE IF NOT EXISTS `Rondier`;
USE `Rondier`;

CREATE TABLE `AGENTS` (
  `idagent` INTEGER,
  `nom` TEXT,
  `prenom` TEXT,
  `numbadge` TEXT,
  PRIMARY KEY (`idagent`)
);

CREATE TABLE `ANOMALIES` (
  `idanomalie` INTEGER,
  `description` TEXT,
  `photos` TEXT,
  PRIMARY KEY (`idanomalie`)
) ;

CREATE TABLE `LIEUX` (
  `idlieux` INTEGER,
  `batiment` TEXT,
  `etage` TEXT,
  `emplacement` TEXT,
  `idpointeau` INTEGER,
  PRIMARY KEY (`idlieux`)
);

CREATE TABLE `PEUTFAIRE` (
  `idagent` INTEGER,
  `idronde` INTEGER,
  PRIMARY KEY (`idagent`, `idronde`)
);

CREATE TABLE `AETEEFFECTUEEPAR` (
  `idronde` INTEGER,
  `idagent` INTEGER,
  `date` TEXT,
  `heure` TEXT,
  PRIMARY KEY (`idronde`, `idagent`)
) ;

CREATE TABLE `AETESCANNE` (
  `idpointeau` INTEGER,
  `idagent` INTEGER,
  `idronde` INTEGER,
  `idanomalie` INTEGER,
  `ordre` INTEGER,
  `temps` TEXT,
  PRIMARY KEY (`idpointeau`, `idagent`, `idronde`, `idanomalie`)
);

CREATE TABLE `RONDES` (
  `idronde` INTEGER,
  `nom` TEXT,
  PRIMARY KEY (`idronde`)
) ;

CREATE TABLE `COMPORTE` (
  `idronde` INTEGER,
  `idpointeau` INTEGER,
  `ordre` INTEGER,
  `tempsmini` TEXT,
  `tempsmaxi` TEXT,
  PRIMARY KEY (`idronde`, `idpointeau`)
) ;

CREATE TABLE `POINTEAUX` (
  `idpointeau` INTEGER,
  `designation` TEXT,
  `tag_mifare` TEXT,
  PRIMARY KEY (`idpointeau`)
) ;

ALTER TABLE `LIEUX` ADD FOREIGN KEY (`idpointeau`) REFERENCES `POINTEAUX` (`idpointeau`);
ALTER TABLE `PEUTFAIRE` ADD FOREIGN KEY (`idronde`) REFERENCES `RONDES` (`idronde`);
ALTER TABLE `PEUTFAIRE` ADD FOREIGN KEY (`idagent`) REFERENCES `AGENTS` (`idagent`);
ALTER TABLE `AETEEFFECTUEEPAR` ADD FOREIGN KEY (`idagent`) REFERENCES `AGENTS` (`idagent`);
ALTER TABLE `AETEEFFECTUEEPAR` ADD FOREIGN KEY (`idronde`) REFERENCES `RONDES` (`idronde`);
ALTER TABLE `AETESCANNE` ADD FOREIGN KEY (`idanomalie`) REFERENCES `ANOMALIES` (`idanomalie`);
ALTER TABLE `AETESCANNE` ADD FOREIGN KEY (`idronde`) REFERENCES `RONDES` (`idronde`);
ALTER TABLE `AETESCANNE` ADD FOREIGN KEY (`idagent`) REFERENCES `AGENTS` (`idagent`);
ALTER TABLE `AETESCANNE` ADD FOREIGN KEY (`idpointeau`) REFERENCES `POINTEAUX` (`idpointeau`);
ALTER TABLE `COMPORTE` ADD FOREIGN KEY (`idpointeau`) REFERENCES `POINTEAUX` (`idpointeau`);
ALTER TABLE `COMPORTE` ADD FOREIGN KEY (`idronde`) REFERENCES `RONDES` (`idronde`);
