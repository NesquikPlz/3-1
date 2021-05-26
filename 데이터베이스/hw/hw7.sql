
SELECT *
FROM Drivers;

INSERT INTO Drivers
VALUES
('Russell', '1998-02-15', 'British', 'BMW Sauber'),
('Villeneuve', '1971-04-09', 'Canadian', 'BMW Sauber');

SELECT *
FROM Drivers;


SELECT *
FROM Constructors JOIN Drivers
USING(Constructor);

INSERT INTO Constructors
VALUES
('Sauber', 'Swiss', 'Mercedes', 0, 93, 180);
INSERT INTO Drivers
VALUES
('Frentzen', '1967-05-18', 'German', 'Sauber');

SELECT *
FROM Constructors JOIN Drivers
USING(Constructor);



SELECT *
FROM Results JOIN Drivers
ON Results.driver = Drivers.name;

CREATE TABLE R (
	driver VARCHAR(30)
);

INSERT INTO R
SELECT DISTINCT driver
FROM Races JOIN Results
ON Races.name = Results.race
WHERE Races.area = 'Asia'
AND Results.race_rank = 'third place';
SELECT * FROM R;

DELETE FROM Results
WHERE driver IN (SELECT * FROM R);

DELETE FROM Drivers
WHERE name IN (SELECT * FROM R);

SELECT *
FROM Results JOIN Drivers
ON Results.driver = Drivers.name;
					
				
					
SELECT *
FROM Constructors;

UPDATE Constructors					
SET height = height/2.5,
width = width/2.5;

SELECT *
FROM Constructors;					



CREATE TABLE S (
	driver VARCHAR(30)
);

INSERT INTO S
SELECT DISTINCT Drivers.name
FROM Results JOIN Drivers JOIN Constructors
ON Results.driver = drivers.name
AND Drivers.constructor = Constructors.constructor
WHERE Constructors.engine = 'Honda';

SELECT *
FROM Results;

ALTER TABLE Results 
MODIFY COLUMN race_rank ENUM("first place", "second place", "third place", "drop out");

UPDATE Results
SET race_rank = 'drop out'
WHERE driver IN (SELECT * FROM S);

SELECT *
FROM Results;



CREATE TABLE T (
	constructor VARCHAR(30)
);

INSERT INTO T
SELECT DISTINCT Constructors.constructor
FROM Drivers JOIN Constructors
ON Drivers.constructor = Constructors.constructor
GROUP BY Constructors.constructor
HAVING COUNT(Drivers.name)>=2;

SELECT * FROM T;


SELECT * FROM Results;
SELECT * FROM Drivers;

DELETE FROM Results
WHERE driver IN ( SELECT name
FROM Drivers 
WHERE constructor IN (SELECT * FROM T));
					
DELETE FROM Drivers
WHERE constructor IN (SELECT * FROM T);

SELECT * FROM Results;
SELECT * FROM Drivers;








					
			
					
					
					
					
					
					
					
					
					
					