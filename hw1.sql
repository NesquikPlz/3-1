CREATE DATABASE F_1;
SHOW DATABASES;
USE F_1;

CREATE TABLE Constructors (
	constructor VARCHAR(30),
	country VARCHAR(20),
	engine VARCHAR(15),
	races_entered INT(4),
	height INT(3),
	width INT(3),
PRIMARY KEY(constructor)
);

DESC Constructors;

CREATE TABLE Drivers (
	name VARCHAR(20),
	birthday DATE,
	country VARCHAR(20),
	constructor VARCHAR(30),
PRIMARY KEY(name, constructor),
FOREIGN KEY(constructor) REFERENCES Constructors(constructor)
);

DESC Drivers;

CREATE TABLE Races (
	name VARCHAR(30),
	date DATE,
	area VARCHAR(20),
PRIMARY KEY(name, date)
);

DESC Races;

CREATE TABLE Results (
	race VARCHAR(30),
	driver VARCHAR(20),
	race_rank ENUM("first place", "second place", "third place"),
PRIMARY KEY(race, driver),
FOREIGN KEY(race) REFERENCES Races(name),
FOREIGN KEY(driver) REFERENCES Drivers(name)
);

DESC Results;