CREATE DATABASE IF NOT EXISTS `StationAccueil` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `StationAccueil`;

CREATE TABLE `peut_faire` (
  `id_agent` INTEGER,
  `id_ronde` INTEGER,
  PRIMARY KEY (`id_agent`, `id_ronde`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `rondes` (
  `id_ronde` INTEGER,
  `nom` VARCHAR(30),
  `statut` VARCHAR(42),
  PRIMARY KEY (`id_ronde`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `comporte` (
  `id_ronde` INTEGER,
  `id_pointeau` INTEGER,
  `ordre` INTEGER,
  `tempsmini` VARCHAR(42),
  `tempsmaxi` VARCHAR(42),
  PRIMARY KEY (`id_ronde`, `id_pointeau`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `responsables` (
  `id_responsable` INTEGER,
  `nom` VARCHAR(30),
  `prenom` VARCHAR(30),
  `numbadge` VARCHAR(10),
  `login` VARCHAR(60),
  `mdp` VARCHAR(30),
  `statut` VARCHAR(42),
  PRIMARY KEY (`id_responsable`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `agents` (
  `id_agent` INTEGER,
  `nom` VARCHAR(30),
  `prenom` VARCHAR(30),
  `numbadge` VARCHAR(10),
  `statut` VARCHAR(42),
  PRIMARY KEY (`id_agent`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `a_ete_effectuee_par` (
  `id_ronde` INTEGER,
  `id_agent` INTEGER,
  `date` VARCHAR(42),
  `heure` VARCHAR(42),
  PRIMARY KEY (`id_ronde`, `id_agent`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `pointeaux` (
  `id_pointeau` INTEGER,
  `designation` VARCHAR(30),
  `statut` VARCHAR(42),
  `tag_mifare` VARCHAR(10),
  PRIMARY KEY (`id_pointeau`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `anomalies` (
  `id_anomalie` INTEGER,
  `description` VARCHAR(150),
  `id_photo` INTEGER,
  PRIMARY KEY (`id_anomalie`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `a_ete_scanne` (
  `id_pointeau` INTEGER,
  `id_agent` INTEGER,
  `id_ronde` INTEGER,
  `id_anomalie` INTEGER,
  `ordre` INTEGER,
  `temps` VARCHAR(42),
  PRIMARY KEY (`id_pointeau`, `id_agent`, `id_ronde`, `id_anomalie`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `lieux` (
  `id_lieu` INTEGER,
  `batiment` VARCHAR(30),
  `etage` VARCHAR(30),
  `emplacement` VARCHAR(30),
  `id_pointeau` INTEGER,
  PRIMARY KEY (`id_lieu`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `photos` (
  `id_photo` INTEGER,
  `chemin` VARCHAR(300),
  PRIMARY KEY (`id_photo`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

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
