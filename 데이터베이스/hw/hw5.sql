SELECT country
FROM Constructors
WHERE races_entered >= ALL ( SELECT races_entered
							FROM Constructors);
							
							
SELECT DISTINCT constructor
FROM Drivers
WHERE name IN (SELECT DISTINCT driver
					FROM Results
					WHERE race_rank = 'first place');
					
					
SELECT name
FROM Drivers
WHERE EXISTS (SELECT Drivers.name
				FROM Drivers JOIN Constructors
				USING (constructor)
				WHERE Constructors.engine = 'Mercedes');
				
				
SELECT DISTINCT race
FROM Results
WHERE driver = ANY (SELECT name
					FROM Drivers
					WHERE constructor = 'Ferrari');
					
					
SELECT name
FROM Drivers JOIN Constructors
USING (constructor)
WHERE constructor = SOME (SELECT T.constructor
							FROM Constructors T, Constructors S
							WHERE T.height = S.height AND T.width > S.width);