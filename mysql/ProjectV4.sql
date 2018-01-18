/* ---------------------------------------------------- */
/*  Generated by Enterprise Architect Version 12.0 		*/
/*  Created On : 18-jan-2018 00:50:15 				*/
/*  DBMS       : MySql 						*/
/* ---------------------------------------------------- */

SET FOREIGN_KEY_CHECKS=0 ;

/* Create Tables */



CREATE TABLE `T_Order`
(
	`ID_Order` VARCHAR(50) NOT NULL,
	`Date` DATE 	,
	`Status` VARCHAR(50) 	,
	`Cost` INT 	,
	`ETA` INT 	,
	CONSTRAINT `Order` PRIMARY KEY (`ID_Order`)
)

;

;

CREATE TABLE `Makes`
(
	`ID_Costumer` VARCHAR(50) NOT NULL,
	`ID_Order` VARCHAR(50) NOT NULL
)

;



CREATE TABLE `Costumer`
(
	`ID_Costumer` VARCHAR(50) NOT NULL,
	`Name` VARCHAR(50) 	,
	`Mail` VARCHAR(50) 	,
	`Phone` VARCHAR(50) 	,
	`Address` VARCHAR(50) 	,
	CONSTRAINT `Costumer` PRIMARY KEY (`ID_Costumer`)
)

;

/* Create Foreign Key Constraints */



ALTER TABLE `Makes` 
 ADD CONSTRAINT `FK_Makes_Costumer`
	FOREIGN KEY (`ID_Costumer`) REFERENCES `Costumer` (`ID_Costumer`) ON DELETE Restrict ON UPDATE Restrict
;

ALTER TABLE `Makes` 
 ADD CONSTRAINT `FK_Makes_T_Order`
	FOREIGN KEY (`ID_Order`) REFERENCES `T_Order` (`ID_Order`) ON DELETE Restrict ON UPDATE Restrict
;



SET FOREIGN_KEY_CHECKS=1 ;
