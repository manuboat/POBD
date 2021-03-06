/* ---------------------------------------------------- */
/*  Generated by Enterprise Architect Version 12.0 		*/
/*  Created On : 20-jan-2018 11:46:28 				*/
/*  DBMS       : MySql 						*/
/* ---------------------------------------------------- */

DROP DATABASE IF EXISTS
ist170940;
CREATE SCHEMA IF NOT EXISTS
ist170940;
USE ist170940;



SET FOREIGN_KEY_CHECKS=0 ;

/* Create Tables */

CREATE TABLE `Warehouse`
(
	`IDWarehouse` INT NOT NULL ,
	`Location` VARCHAR(50) 	,
	`Capacity` INT NOT NULL	,
	CONSTRAINT `PK_Table1` PRIMARY KEY (`IDWarehouse`)
)

;

CREATE TABLE `TOrder`
(
	`IDOrder` INT NOT NULL auto_increment,
	`Date` DATE 	,
	`Status` VARCHAR(50) 	,
	`Cost` INT 	,
	`ETA` INT 	,
	CONSTRAINT `Order` PRIMARY KEY (`IDOrder`)
)

;

CREATE TABLE `Produced`
(
	`IDPlant` INT NOT NULL,
	`IDFarm` INT NOT NULL,
	`IDWarehouse` INT NOT NULL,
	`Amount` INT 	,
	`UnitPrice` INT 	,
	`Date` DATE 	,
	CONSTRAINT `PK_Produced` PRIMARY KEY (`IDPlant`,`IDFarm`,`IDWarehouse`)
)

;

CREATE TABLE `Plant`
(
	`IDPlant` INT NOT NULL auto_increment,
	`Name` VARCHAR(50) 	,
	`Variety` VARCHAR(50) 	,
	`Type` VARCHAR(50) 	,
	`MST` INT 	,
	`Family` VARCHAR(50) 	,
	CONSTRAINT `PK_Plant` PRIMARY KEY (`IDPlant`)
)

;

CREATE TABLE `Makes`
(
	`IDCostumer` INT NOT NULL auto_increment,
	`IDOrder` INT NOT NULL,
	CONSTRAINT `PK_Makes` PRIMARY KEY (`IDCostumer`,`IDOrder`)
)

;

CREATE TABLE `Include`
(
	`IDOrder` INT NOT NULL,
	`IDPlant` INT NOT NULL,
	`IDFarm` INT NOT NULL,
	`IDWarehouse` INT NOT NULL,
	`Amount` INT 	,
	CONSTRAINT `PK_Include` PRIMARY KEY (`IDOrder`,`IDPlant`,`IDFarm`,`IDWarehouse`)
)

;

CREATE TABLE `Farm`
(
	`IDFarm` INT NOT NULL auto_increment,
	`Name` VARCHAR(50) 	,
	`Address` VARCHAR(50) 	,
	`Owner` VARCHAR(50) 	,
	CONSTRAINT `PK_Table1` PRIMARY KEY (`IDFarm`)
)

;

CREATE TABLE `Costumer`
(
	`IDCostumer` INT NOT NULL auto_increment,
	`Name` VARCHAR(50) 	,
	`Mail` VARCHAR(50) 	,
	`Phone` VARCHAR(50) 	,
	`Address` VARCHAR(50) 	,
	CONSTRAINT `Costumer` PRIMARY KEY (`IDCostumer`)
)

;

/* Create Foreign Key Constraints */

ALTER TABLE `Produced` 
 ADD CONSTRAINT `FK_Produced_Farm`
	FOREIGN KEY (`IDFarm`) REFERENCES `Farm` (`IDFarm`) ON DELETE Restrict ON UPDATE Restrict
;

ALTER TABLE `Produced` 
 ADD CONSTRAINT `FK_Produced_Plant`
	FOREIGN KEY (`IDPlant`) REFERENCES `Plant` (`IDPlant`) ON DELETE Restrict ON UPDATE Restrict
;

ALTER TABLE `Produced` 
 ADD CONSTRAINT `FK_Produced_Warehouse`
	FOREIGN KEY (`IDWarehouse`) REFERENCES `Warehouse` (`IDWarehouse`) ON DELETE Restrict ON UPDATE Restrict
;

ALTER TABLE `Makes` 
 ADD CONSTRAINT `FK_Makes_Costumer`
	FOREIGN KEY (`IDCostumer`) REFERENCES `Costumer` (`IDCostumer`) ON DELETE Restrict ON UPDATE Restrict
;

ALTER TABLE `Makes` 
 ADD CONSTRAINT `FK_Makes_TOrder`
	FOREIGN KEY (`IDOrder`) REFERENCES `TOrder` (`IDOrder`) ON DELETE Restrict ON UPDATE Restrict
;

ALTER TABLE `Include` 
 ADD CONSTRAINT `FK_Include_Produced`
	FOREIGN KEY (`IDPlant`,`IDFarm`,`IDWarehouse`) REFERENCES `Produced` (`IDPlant`,`IDFarm`,`IDWarehouse`) ON DELETE Restrict ON UPDATE Restrict
;

ALTER TABLE `Include` 
 ADD CONSTRAINT `FK_Include_TOrder`
	FOREIGN KEY (`IDOrder`) REFERENCES `TOrder` (`IDOrder`) ON DELETE Restrict ON UPDATE Restrict
;

SET FOREIGN_KEY_CHECKS=1 ;


load data local infile 'C:\\Users\\David\\Documents\\GitHub\\POBD\\mysql\\CSV\\Warehouse.csv'
into table Warehouse  
fields terminated by ','
lines terminated by '\r\n'
IGNORE 1 ROWs;

load data local infile 'C:\\Users\\David\\Documents\\GitHub\\POBD\\mysql\\CSV\\Costumer.csv'
into table Costumer
fields terminated by ','
lines terminated by '\r\n'
IGNORE 1 ROWs;


load data local infile 'C:\\Users\\David\\Documents\\GitHub\\POBD\\mysql\\CSV\\Plant.csv'
into table Plant
fields terminated by ','
lines terminated by '\r\n'
IGNORE 1 ROWs;

load data local infile 'C:\\Users\\David\\Documents\\GitHub\\POBD\\mysql\\CSV\\Order.csv'
into table TOrder
fields terminated by ','
lines terminated by '\r\n'
IGNORE 1 ROWs;


load data local infile 'C:\\Users\\David\\Documents\\GitHub\\POBD\\mysql\\CSV\\Farm.csv'
into table Farm
fields terminated by ','
lines terminated by '\r\n'
IGNORE 1 ROWs;


load data local infile 'C:\\Users\\David\\Documents\\GitHub\\POBD\\mysql\\CSV\\r_makes.csv'
into table Makes 
fields terminated by ','
lines terminated by '\r\n'
IGNORE 1 ROWs;


load data local infile 'C:\\Users\\David\\Documents\\GitHub\\POBD\\mysql\\CSV\\r_Produced.csv'
into table Produced
fields terminated by ','
lines terminated by '\r\n'
IGNORE 1 ROWs;

load data local infile 'C:\\Users\\David\\Documents\\GitHub\\POBD\\mysql\\CSV\\r_include.csv'
into table Include
fields terminated by ','
lines terminated by '\r\n'
IGNORE 1 ROWs;

select * from Warehouse;