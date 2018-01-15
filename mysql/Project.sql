-- --------------------------------------------------------------------------------------
-- Script de criação da base de dados para a aula 2 (versão de 24-09-2006 16:34)
-- --------------------------------------------------------------------------------------
--
-- Como correr este exemplo nos labs da RNL --
--
-- *** em WINDOWS ***
--
-- 1. fazer download deste script e guardar no Desktop
-- 2. abrir uma linha de comando (cmd) e ir para "cd Desktop"
-- 3. arrancar o mysql com "mysql -u root -p"
-- 4. fornecer a password "root" (igual a username)
-- 5. já dentro do MySQL, escrever "source employee.sql" (o mysql cria então a base de dados)
-- 6. fazer queries, não esquecendo o ponto-e-vírgula final (p.ex. "select * from works;")
-- 7. também é possível usar o MySQL Query Browser (host="localhost", user="root", pass="root")
--
-- *** em LINUX ***
--
-- 1. fazer download deste script e guardar no Desktop
-- 2. abrir uma linha de comando (terminal) e ir para "cd Desktop"
-- 3. arrancar o mysql com "mysql -u root -p"
-- 4. fornecer a password "mysqladmin"
-- 5. já dentro do MySQL, escrever "source employee.sql" (o mysql cria então a base de dados)
-- 6. fazer queries, não esquecendo o ponto-e-vírgula final (p.ex. "select * from works;")
-- 7. também é possível usar o MySQL Query Browser (host="localhost", user="root", pass="mysqladmin")
--
-- --------------------------------------------------------------------------------------

DROP DATABASE IF EXISTS
ist170940;
CREATE SCHEMA IF NOT EXISTS
ist170940;
USE ist170940;

SET FOREIGN_KEY_CHECKS=0 ;

/* Create Tables */

CREATE TABLE `Warehouse`
(
	`ID_Warehouse` VARCHAR(50) NOT NULL,
	`Warehouse_Name` VARCHAR(50) 	,
	CONSTRAINT `PK_Warehouse` PRIMARY KEY (`ID_Warehouse`)
)

;

CREATE TABLE `Plant`
(
	`ID_Plant` VARCHAR(50) NOT NULL,
	`Plant_name` VARCHAR(50) 	,
	CONSTRAINT `PK_Plant` PRIMARY KEY (`ID_Plant`)
)

;

CREATE TABLE `order`
(
	`ID_Plant` VARCHAR(50) NOT NULL,
	`ID_Farm` VARCHAR(50) NOT NULL,
	`ID_Warehouse` VARCHAR(50) NOT NULL,
	`ID_Costumer` VARCHAR(50) 	,
	`ID_Order` VARCHAR(50) 	,
	CONSTRAINT `PK_order` PRIMARY KEY (`ID_Plant`,`ID_Farm`,`ID_Warehouse`)
)

;

CREATE TABLE `needs`
(
	`ID_Farm` VARCHAR(50) NOT NULL,
	`ID_Plant` VARCHAR(50) NOT NULL,
	`ID_Warehouse` VARCHAR(50) NOT NULL,
	CONSTRAINT `FK_needs_Farm` FOREIGN KEY (`ID_Farm`) REFERENCES `Farm` (`ID_Farm`) ON DELETE Restrict ON UPDATE Restrict,
	CONSTRAINT `FK_needs_Plant` FOREIGN KEY (`ID_Plant`) REFERENCES `Plant` (`ID_Plant`) ON DELETE Restrict ON UPDATE Restrict
)

;

CREATE TABLE `Farm`
(
	`ID_Farm` VARCHAR(50) NOT NULL,
	`Farm_Name` VARCHAR(50) 	,
	CONSTRAINT `PK_Farm` PRIMARY KEY (`ID_Farm`)
)

;

CREATE TABLE `Costumer`
(
	`ID_Costumer` VARCHAR(50) NOT NULL,
	`Costumer_Name` VARCHAR(50) 	,
	CONSTRAINT `PK_Costumer` PRIMARY KEY (`ID_Costumer`)
)

;

SET FOREIGN_KEY_CHECKS=1 ;

-- Populate Tables
load data local infile 'C:\\Users\\David\\Dropbox\\Projecto POBD\\\\Farm.csv'
into table Plant 
fields terminated by ';'
lines terminated by '\r\n';

load data local infile 'C:\\Users\\Manuel\\CSV\\Costumer.csv' 
into table Costumer
fields terminated by ';'
lines terminated by '\r\n';

load data local infile 'C:\\Users\\Manuel\\CSV\\Farm.csv' 
into table Farm 
fields terminated by ';'
lines terminated by '\r\n';

load data local infile 'C:\\Users\\Manuel\\CSV\\Warehouse.csv' 
into table Warehouse 
fields terminated by ';'
lines terminated by '\r\n';

load data local infile 'C:\\Users\\Manuel\\CSV\\Order.csv' 
into table `order`
fields terminated by ';'
lines terminated by '\r\n';

load data local infile 'C:\\Users\\Manuel\\CSV\\needs.csv' 
into table needs
fields terminated by ';'
lines terminated by '\r\n';
