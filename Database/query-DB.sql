/* Creazione e selezione del DB */
CREATE DATABASE IF NOT EXISTS ESP32_plant1; 
SHOW DATABASES;
USE ESP32_plant1;

/* Visualizzazione di tutte le tabelle e selezione 
				--PS--
La tabella "production" viene creata dal modulo sequelize di NodeJS */
SHOW TABLES;
SELECT * FROM production;

/* Creazione user in sola lettura in questo DB per Grafana */
CREATE USER 'grafana' IDENTIFIED BY 'yourPassword';
GRANT SELECT ON ESP32_plant1.production TO 'grafana';
FLUSH PRIVILEGES;

/* Query di prova per test visualizzazione con Grafana */
SELECT  DATE_FORMAT(createdAt, '%H:%i:%s') AS Date FROM production;

/* Eliminazione tabella e database (COMPORTA LA PERDITA DI TUTTI I DATI CONTENUTI NEL DB) */
TRUNCATE production;
DROP DATABASE ESP32_plant1;