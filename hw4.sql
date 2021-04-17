
SELECT Drivers.name, Drivers.birthday, Drivers.country
FROM Drivers, Constructors
WHERE Drivers.constructor = Constructors.constructor
AND Constructors.country = 'Italian';


SELECT Drivers.name, Drivers.country
FROM Drivers, Constructors
WHERE Drivers.constructor = Constructors.constructor
AND Constructors.country = Drivers.country;


SELECT DISTINCT Results.driver, Constructors.engine, Constructors.races_entered
FROM Results JOIN Drivers JOIN Constructors
WHERE Results.driver = Drivers.name
AND Drivers.constructor = Constructors.constructor
AND Results.race = 'Monaco Grand Prix';


WITH R AS
(SELECT Constructors.constructor, COUNT(name) AS NumOfDrivers
FROM Drivers INNER JOIN Constructors
ON Drivers.constructor = Constructors.constructor
GROUP BY Constructors.constructor)
SELECT constructor
FROM R
WHERE NumOfDrivers=1;


SELECT DISTINCT Drivers.name
FROM Drivers INNER JOIN Results
ON Drivers.name = Results.driver
WHERE Drivers.constructor = 'BMW Sauber'
OR Results.race = 'Spanish Grand Prix';


SELECT Drivers.name, Constructors.races_entered
FROM Drivers INNER JOIN Constructors
ON Drivers.constructor = Constructors.constructor
ORDER BY Constructors.races_entered, Drivers.name DESC;


WITH R AS (
SELECT country, COUNT(engine) AS isBoth
FROM Constructors
WHERE engine = 'Cosworth' OR engine = 'Mercedes'
GROUP BY country
)
SELECT country
FROM R
WHERE isBoth = 2;


WITH R AS (
SELECT DISTINCT Drivers.name
FROM Drivers INNER JOIN Results
ON Drivers.name = Results.driver
WHERE Results.race_rank = 'second place' OR Results.race_rank = 'third place'
)
SELECT DISTINCT *
FROM R
WHERE name IN (
SELECT Drivers.name
FROM Drivers INNER JOIN Results
ON Drivers.name = Results.driver
WHERE Results.race_rank = 'first place');


SELECT Results.driver ,Results.race, DATE_FORMAT(Races.date, '%m-%y') AS begindate
FROM Races INNER JOIN Results
ON Races.name = Results.race
WHERE year(Races.date) = 2008 OR year(Races.date) = 2009;












