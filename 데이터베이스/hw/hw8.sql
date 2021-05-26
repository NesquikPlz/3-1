SELECT *
FROM Constructors;

ALTER TABLE Constructors
DROP COLUMN races_entered;

SELECT *
FROM Constructors;


SELECT *
FROM Constructors;

ALTER TABLE Constructors
ADD COLUMN tire VARCHAR(30) DEFAULT 'KoreanCompany';

SELECT *
FROM Constructors;