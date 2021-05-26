SELECT DISTINCT COUNT(constructor)
FROM constructors
WHERE engine = 'Ferrari';


SELECT AVG(races_entered)
FROM Constructors
WHERE country = 'British';


SELECT MIN(birthday)
FROM Drivers JOIN Constructors
USING (constructor)
GROUP BY constructor;


SELECT constructor, AVG(height)
FROM Constructors JOIN Drivers
USING (constructor)
WHERE Drivers.country='German'
GROUP BY constructor;


SELECT constructor, COUNT(race_rank)
FROM Results JOIN Drivers
ON Results.driver = Drivers.name
WHERE race_rank = 'first place'
GROUP BY constructor;


WITH R AS (SELECT *
		FROM Drivers JOIN Results
		ON Drivers.name = Results.driver)
SELECT COUNT(DISTINCT constructor) 
FROM R
WHERE constructor IN (SELECT DISTINCT constructor
						FROM R
						WHERE race_rank = 'first place')
AND constructor IN (SELECT DISTINCT constructor
						FROM R
						GROUP BY constructor
						HAVING COUNT(driver)>=2);
						
		
SELECT Constructors.country, constructor, TIMESTAMPDIFF(YEAR, AVG(birthday), NOW()) AS avgAge
FROM Constructors JOIN Drivers
USING (constructor)
GROUP BY Constructors.country, constructor;


SELECT race, constructor
FROM Drivers JOIN Results
ON Drivers.name = Results.driver
GROUP BY race, constructor
HAVING COUNT(constructor)>=2
ORDER BY race;










		
