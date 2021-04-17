SELECT constructor, country
FROM Constructors
WHERE races_entered>=100;


SELECT constructor, engine, races_entered
FROM Constructors
WHERE height!=95 AND width<180
ORDER BY engine, races_entered ASC;


SELECT DISTINCT constructor
FROM Constructors
WHERE engine = 'Ferrari';


SELECT name AS newBoys
FROM Drivers
WHERE year(birthday) > 1980;


SELECT driver, race
FROM Results
WHERE race_rank = 'first place';


SELECT name, date
FROM Races
WHERE area = 'Europe'
ORDER BY name ASC;


SELECT *
FROM Drivers
WHERE name LIKE "h%";


SELECT constructor
FROM Constructors
WHERE constructor LIKE "%\ %";

