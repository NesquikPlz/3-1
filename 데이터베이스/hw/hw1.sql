CREATE DATABASE DB2021Team05;
SHOW DATABASES;
USE DB2021Team05;

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
