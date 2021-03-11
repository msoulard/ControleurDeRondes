CREATE DATABASE IF NOT EXISTS `Rondier`;
USE `Rondier`;

CREATE TABLE `peut_faire` (
  `id_agent` INTEGER,
  `id_ronde` INTEGER,
  PRIMARY KEY (`id_agent`, `id_ronde`)
) ;

CREATE TABLE `rondes` (
  `id_ronde` INTEGER,
  `nom` TEXT,
  PRIMARY KEY (`id_ronde`)
);

CREATE TABLE `comporte` (
  `id_ronde` INTEGER,
  `id_pointeau` INTEGER,
  `ordre` INTEGER,
  `tempsmini` TEXT,
  `tempsmaxi` TEXT,
  PRIMARY KEY (`id_ronde`, `id_pointeau`)
);

CREATE TABLE `agents` (
  `id_agent` INTEGER,
  `nom` TEXT,
  `prenom` TEXT,
  `numbadge` TEXT,
  PRIMARY KEY (`id_agent`)
);

CREATE TABLE `a_ete_effectuee_par` (
  `id_ronde` INTEGER,
  `id_agent` INTEGER,
  `date_heure` TEXT,
  PRIMARY KEY (`id_ronde`, `id_agent`)
);

CREATE TABLE `pointeaux` (
  `id_pointeau` INTEGER,
  `designation` TEXT,
  `tag_mifare` TEXT,
  PRIMARY KEY (`id_pointeau`)
);

CREATE TABLE `anomalies` (
  `id_anomalie` INTEGER,
  `description` TEXT,
  `id_photo` INTEGER,
  PRIMARY KEY (`id_anomalie`)
);

CREATE TABLE `a_ete_scanne` (
  `id_pointeau` INTEGER,
  `id_agent` INTEGER,
  `id_ronde` INTEGER,
  `id_anomalie` INTEGER,
  `ordre` INTEGER,
  `temps` TEXT,
  PRIMARY KEY (`id_pointeau`, `id_agent`, `id_ronde`, `id_anomalie`)
);

CREATE TABLE `lieux` (
  `id_lieu` INTEGER,
  `batiment` TEXT,
  `etage` TEXT,
  `emplacement` TEXT,
  `id_pointeau` INTEGER,
  PRIMARY KEY (`id_lieu`)
);

CREATE TABLE `photos` (
  `id_photo` INTEGER,
  `chemin` TEXT,
  PRIMARY KEY (`id_photo`)
);

ALTER TABLE `peut_faire` ADD FOREIGN KEY (`id_ronde`) REFERENCES `rondes` (`id_ronde`);
ALTER TABLE `peut_faire` ADD FOREIGN KEY (`id_agent`) REFERENCES `agents` (`id_agent`);
ALTER TABLE `comporte` ADD FOREIGN KEY (`id_pointeau`) REFERENCES `pointeaux` (`id_pointeau`);
ALTER TABLE `comporte` ADD FOREIGN KEY (`id_ronde`) REFERENCES `rondes` (`id_ronde`);
ALTER TABLE `a_ete_effectuee_par` ADD FOREIGN KEY (`id_agent`) REFERENCES `agents` (`id_agent`);
ALTER TABLE `a_ete_effectuee_par` ADD FOREIGN KEY (`id_ronde`) REFERENCES `rondes` (`id_ronde`);
ALTER TABLE `anomalies` ADD FOREIGN KEY (`id_photo`) REFERENCES `photos` (`id_photo`);
ALTER TABLE `a_ete_scanne` ADD FOREIGN KEY (`id_anomalie`) REFERENCES `anomalies` (`id_anomalie`);
ALTER TABLE `a_ete_scanne` ADD FOREIGN KEY (`id_ronde`) REFERENCES `rondes` (`id_ronde`);
ALTER TABLE `a_ete_scanne` ADD FOREIGN KEY (`id_agent`) REFERENCES `agents` (`id_agent`);
ALTER TABLE `a_ete_scanne` ADD FOREIGN KEY (`id_pointeau`) REFERENCES `pointeaux` (`id_pointeau`);
ALTER TABLE `lieux` ADD FOREIGN KEY (`id_pointeau`) REFERENCES `pointeaux` (`id_pointeau`);
