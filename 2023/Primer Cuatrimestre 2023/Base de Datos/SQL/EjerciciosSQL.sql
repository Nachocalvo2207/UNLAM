--Ejercicio1:

CREATE DATABASE Ejercicio1

CREATE TABLE Almacen
(
Nro			int PRIMARY KEY,
Responsable	varchar (45),
)

CREATE TABLE Articulo
(
CodArt		int PRIMARY KEY,
descripcion	varchar(60),
precio		decimal (12,2),
)


create table Material
(
CodMat int primary key, 
Descripcion varchar(50)
)

create table Proveedor
(
CodProv int primary key,
Nombre varchar(50), 
Domicilio varchar(50), Ciudad varchar(50)
)

create table Tiene
(
Nro int, CodArt int
)

create table Compuesto_Por
(
CodArt int, CodMat int
)

create table Provisto_Por
(
CodMat int, CodProv int
)

insert into Almacen values
(1, 'Juan Perez'),
(2, 'Jose Basualdo'),
(3, 'Rogelio Rodriguez')
insert into Articulo values
(1, 'Sandwich JyQ', 5),
(2, 'Pancho', 6),
(3, 'Hamburguesa', 10),
(4, 'Hamburguesa completa', 15)
insert into Material values
(1, 'Pan'),
(2, 'Jamon'),
(3, 'Queso'),
(4, 'Salchicha'),
(5, 'Pan Pancho'),
(6, 'Paty'),
(7, 'Lechuga'),
(8, 'Tomate')
insert into Proveedor values
(1, 'Panadería Carlitos', 'Carlos Calvo 1212', 'CABA'),
(2, 'Fiambres Perez', 'San Martin 121', 'Pergamino'),
(3, 'Almacen San Pedrito', 'San Pedrito 1244', 'CABA'),
(4, 'Carnicería Boedo', 'Av. Boedo 3232', 'CABA'),
(5, 'Verdulería Platense', '5 3232', 'La Plata')
insert into Tiene values
--Juan Perez
(1, 1),
--Jose Basualdo
(2, 1),
(2, 2),
(2, 3),
(2, 4),

--Rogelio Rodriguez
(3, 3),
(3, 4)
insert into Compuesto_Por values
--Sandwich JyQ
(1, 1), (1, 2), (1, 3),
--Pancho
(2, 4), (2, 5),
--Hamburguesa
(3, 1), (3, 6),
--Hamburguesa completa
(4, 1), (4, 6), (4, 7), (4, 8)
insert into Provisto_Por values
--Pan
(1, 1), (1, 3),
--Jamon
(2, 2), (2, 3), (2, 4),
--Queso
(3, 2), (3, 3),
--Salchicha
(4, 3), (4, 4),
--Pan Pancho
(5, 1), (5, 3),
--Paty
(6, 3), (6, 4),
--Lechuga
(7, 3), (7, 5),
--Tomate
(8, 3), (8, 5)



--1:
SELECT *
FROM Proveedor p
WHERE p.Ciudad = 'La Plata'
--2:
SELECT CodArt
FROM Articulo
WHERE Precio<10

--3:

SELECT Responsable
FROM Almacen

--4
SELECT *
FROM Proveedor

SELECT *
FROM Material

SELECT *
FROM Provisto_Por


--4
SELECT CodMat
FROM Provisto_por
WHERE CodProv = 3
FROM Provisto_por
WHERE CodProv = 5)

SELECT CodMat
FROM Provisto_por
WHERE CodProv = 3

EXCEPT

SELECT CodMat
FROM Provisto_por
WHERE CodProv = 5




--7:

SELECT *
FROM Tiene
WHERE CodArt = '1'
AND Nro
IN (SELECT Nro
	FROM Tiene
	WHERE CodArt = '2')


--Hecho por el profe

SELECT Nro
FROM Tiene t, Articulo a
WHERE t.CodArt = a.CodArt
AND a.descripcion = 'Pancho'
INTERSECT 
SELECT Nro
FROM Tiene t, Articulo a
WHERE t.CodArt = a.CodArt
AND a.descripcion = 'Hamburguesa completa'


--8:
SELECT *
FROM Articulo

SELECT *
FROM Compuesto_Por

SELECT A.CodArt
FROM Articulo A 
JOIN Compuesto_por C 
ON A.CodArt = C.CodArt
WHERE A.Precio>=10 
AND C.CodMat = 1

--9:
SELECT M.CodMat, Descripcion, Ciudad
FROM Provisto_Por PP 
JOIN Proveedor PR ON PR.CodProv = PP.CodProv 
JOIN Material M ON PP.CodMat = M.CodMat
WHERE Ciudad = 'CABA'

--10:

SELECT *
FROM Almacen

SELECT *
FROM Articulo

SELECT *
FROM Tiene

SELECT *
FROM Tiene T
JOIN Almacen Al ON T.Nro = Al.Nro
JOIN Articulo Ar ON T.CodArt = Ar.CodArt
WHERE Al.Nro = 1

--12: Usar a Juan Perez

SELECT *
FROM Proveedor

SELECT *
FROM Almacen A
JOIN Proveedor Pr ON A.Nro = Pr.

SELECT Id
FROM Tiene Ti, Provisto_Por PR, Almacen Al, Proveedor Prov




SELECT DISTINCT Prov.Nombre, Al.Responsable
FROM Proveedor Prov
JOIN Provisto_Por PR ON Prov.CodProv = PR.CodProv
JOIN Compuesto_Por CP ON PR.CodMat = CP.CodMat
JOIN Tiene T ON CP.CodArt = T.CodArt
JOIN Almacen Al ON T.Nro = Al.Nro
WHERE Al.Responsable = 'Juan Perez'


select distinct p.Nombre
from Proveedor p
join Provisto_Por pp on pp.CodProv = p.CodProv
join Compuesto_Por cp on cp.CodMat = pp.CodMat
join Tiene t on t.CodArt = cp.CodArt
join Almacen a on t.Nro = a.Nro
where Responsable = 'Juan Perez'





SELECT DISTINCT P.Nombre 
FROM Proveedor P 
INNER JOIN Provisto_por PX ON P.CodProv=PX.CodProv
WHERE PX.CodMat 
IN (SELECT C.CodMat FROM Compuesto_por C 
INNER JOIN Tiene T ON C.CodArt=T.CodArt
WHERE T.Nro IN (SELECT A.Nro FROM Almacen A WHERE Responsable='Juan Perez'));

--Hecho por el profe:

SELECT A.Nro, A.Responsable, CP.CodMat, p.CodProv, p.Nombre Nombre_prov
FROM	Almacen a, Tiene t, Compuesto_Por CP, Provisto_Por PP, Proveedor P
WHERE	a.Responsable = 'Jose Basualdo'
AND		A.Nro = T.Nro
AND		T.CodArt = CP.CodArt
AND		CP.CodMat = PP.CodMat
AND		PP.CodProv = P.CodProv

SELECT * FROM Proveedor WHERE CodProv IN(
SELECT	p.CodProv
FROM	Almacen a, Tiene t, Compuesto_Por CP, Provisto_Por PP, Proveedor P
WHERE	a.Responsable = 'Jose Basualdo'
AND		a.Nro = T.Nro
AND		T.CodArt = CP.CodArt
AND		CP.CodMat = PP.CodMat
AND		PP.CodProv = P.CodProv
)

--15 Hecho por el profe

SELECT *
FROM Material

SELECT *
FROM Compuesto_Por

SELECT *
FROM	Compuesto_Por CP
WHERE	CodMat = 6

--Almacenes que contienen a TODOS los articulos compuestos por el material 6

--Almacenes tales que
--NO existe un articulo compuesto por el material 6
--que NO tengan

SELECT * 
FROM	Almacen a
WHERE	NOT EXISTS (	SELECT *
						FROM	Compuesto_Por CP
						WHERE	CodMat = 6
						AND NOT EXISTS(	SELECT *
										FROM	Tiene T
										WHERE	T.CodArt = CP.CodArt
										AND		T.Nro = a.Nro))


--16 Hecho por el profe

SELECT *
FROM	Proveedor P, Provisto_Por ProvP
WHERE	Ciudad = 'CABA'
AND		NOT EXISTS (SELECT *
					FROM	Provisto_Por ProvP2, Proveedor P2
					WHERE	ProvP2.CodMat = ProvP.CodMat
					AND		ProvP2.CodProv <> ProvP.CodProv --<> Significa distinto
					AND		ProvP2.CodProv = P2.CodProv
					AND		P2.Ciudad = 'CABA')

SELECT			*FROM			Provisto_Por PP, Proveedor Prov WHERE			Prov.Ciudad = 'CABA'AND NOT EXISTS	(SELECT	*				FROM	Provisto_Por PP2, Proveedor Prov2				WHERE	PP2.CodMat = PP.CodMat				AND		Prov.CodProv <> Prov2.CodProv				AND		PP2.CodProv	= Prov2.CodProv				AND		Prov2.Ciudad = 'CABA')


--17 Hecho por el profe

SELECT MAX(Precio) Precio_Maximo
FROM	Articulo A

--Esta muestra todo usando una subconsulta
SELECT *
FROM	Articulo
WHERE	precio = (	SELECT MAX (precio)
					FROM Articulo)

--18 Hecho por el profe

SELECT t.Nro, AVG(precio)
FROM	Tiene t, Articulo a
WHERE	T.CodArt = a.CodArt
GROUP BY T.Nro

--22

SELECT		CodArt, count (*) Cant_Materiales
FROM		Compuesto_Por
GROUP BY	CodArt	
HAVING  count (*) = 2

--Listar los almacenes que almacenan la mayor cant de articulos

SELECT *
FROM	Tiene

CREATE VIEW	Cant_Articulos AS
SELECT		Nro, count (*) Cant_Articulos
FROM		Tiene
GROUP BY	Nro

SELECT *
FROM	Cant_Articulos
WHERE	Cant_art 


--Hechos por mi:
--14.	Hallar los códigos y nombres de los proveedores que proveen al menos un
--		material que se usa en algún artículo cuyo precio es mayor a $100.SELECT DISTINCT	Prov.CodProv, Prov.Nombre, A.descripcion, A.precioFROM			Provisto_Por PP, Cant_Articulos CA, Proveedor Prov, Compuesto_Por CP, Tiene T, Articulo AWHERE			PP.CodProv = Prov.CodProvAND				PP.CodMat = CP.CodMatAND				T.CodArt = CP.CodArtAND				T.CodArt = A.CodArtSELECT *FROM Articulo--16	Listar los proveedores de Capital Federal que sean únicos proveedores de algún
--		material.SELECT	*FROM	Proveedor