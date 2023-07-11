-- ------------------------------------------- TEMA 3 ------------------------------------------------- -- 

-- ------------------- a -------------------- -- 
-- modify the type of a column
DELIMITER //
CREATE PROCEDURE `doA`()
BEGIN
	ALTER TABLE City
	MODIFY COLUMN city_name VARCHAR(100);
END //
DELIMITER ;

-- revert
DELIMITER //
CREATE PROCEDURE `undoA`()
BEGIN
	ALTER TABLE City
	MODIFY COLUMN city_name VARCHAR(50);
END //
DELIMITER ;

-- ------------------ b ------------------ --

-- add a column
DELIMITER //
CREATE PROCEDURE `doB`()
BEGIN
	ALTER TABLE City
	ADD NumberOfVisitors INT;
END //
DELIMITER ;

-- remove
DELIMITER //
CREATE PROCEDURE `undoB`()
BEGIN
	ALTER TABLE City
	DROP COLUMN NumberOfVisitors;
END //
DELIMITER ;


-- ------------------ c ------------------ --

-- add a deafult constraint
DELIMITER //
CREATE PROCEDURE `doC`()
BEGIN
	ALTER TABLE City
	ALTER city_name SET DEFAULT 'not null';
END //
DELIMITER ;

-- remove
DELIMITER //
CREATE PROCEDURE `undoC`()
BEGIN
	ALTER TABLE City
	ALTER city_name DROP DEFAULT;
END //
DELIMITER ;

-- ------------------ d ------------------ --

-- remove primary key
DELIMITER //
CREATE PROCEDURE `doD`()
BEGIN
	 ALTER TABLE Landmark
	 DROP PRIMARY KEY;
END //
DELIMITER ;

-- add primary key
DELIMITER //
CREATE PROCEDURE `undoD`()
BEGIN
	 ALTER TABLE Landmark
	ADD PRIMARY KEY (landmark_id);
END //
DELIMITER ;

CALL undoB();

-- ------------------ e ------------------ --

-- add a candidate key
DELIMITER //
CREATE PROCEDURE `doE`()
BEGIN
	 ALTER TABLE City
	 ADD CONSTRAINT CK_City_1 UNIQUE(city_id, city_name, city_population);
END //
DELIMITER ;

-- remove
DELIMITER //
CREATE PROCEDURE `undoE`()
BEGIN
	 ALTER TABLE City
	 DROP CONSTRAINT CK_City_1;
END //
DELIMITER ;

-- ------------------ f ------------------ --

-- add foreign key
DELIMITER //
CREATE PROCEDURE `doF`()
BEGIN
	 ALTER TABLE Schedule
     ADD Cont_ID INT;
	 ALTER TABLE Schedule
	 ADD CONSTRAINT FK_ContinentID FOREIGN KEY (Cont_ID) REFERENCES Continent(continent_id);
END //
DELIMITER ;


     
-- remove
DELIMITER //
CREATE PROCEDURE `undoF`()
BEGIN
	 ALTER TABLE Schedule
	 DROP CONSTRAINT FK_ContinentID;
	 ALTER TABLE Schedule
	 DROP COLUMN Cont_ID;
END //
DELIMITER ;

-- ------------------ g ------------------ --

-- create table
DELIMITER //
CREATE PROCEDURE `doG`()
BEGIN
	 CREATE TABLE AnimalsOnBeach(
		animal_id INT PRIMARY KEY,
        beach_id INT,
        FOREIGN KEY (beach_id) REFERENCES Beach(beach_id) ON DELETE CASCADE
        );
END //
DELIMITER ;

-- drop table
DELIMITER //
CREATE PROCEDURE `undoG`()
BEGIN
	 DROP TABLE AnimalsOnBeach;
	
END //
DELIMITER ;

CREATE TABLE V(
	current_version INT PRIMARY KEY
    );
    
INSERT INTO V(current_version) VALUES(1);


DELIMITER //
CREATE PROCEDURE `ChangeVersions`(V INT)
BEGIN
IF V != (SELECT current_version FROM V) AND V = 1 THEN
	
		CALL undoA;
		CALL undoB;
		CALL undoC;
		CALL undoD;
		CALL undoE;
		CALL undoF;
		CALL undoG;
		DELETE FROM V WHERE current_version = 2;
		INSERT INTO V(current_version) VALUES (1);
	 
	ELSE IF V != (SELECT current_version FROM V) AND V = 2 THEN
		CALL doA;
		CALL doB;
		CALL doC;
		CALL doD;
		CALL doE;
		CALL doF;
		CALL doG;
		DELETE FROM V WHERE current_version = 1;
		INSERT INTO V(current_version) VALUES (2);
    END IF;    
    END IF;
END //
DELIMITER ;

CALL ChangeVersions(2);