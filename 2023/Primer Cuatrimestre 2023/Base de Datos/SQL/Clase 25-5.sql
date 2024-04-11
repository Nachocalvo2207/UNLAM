CREATE DATABASE clas2_sql

--TABLA Empleado:
CREATE TABLE Empleado
(
Legajo		integer PRIMARY KEY,
Nombre		varchar (30),
Apellido	varchar(30),
Salario		numeric(8,2),
Categoria	char(1),
tel			char(15),
cod_depto	integer FOREIGN KEY REFERENCES Departamento (cod_depto),
)

--TABLA Departamento

CREATE TABLE Departamento
(
cod_depto	integer PRIMARY KEY,
descripcion	varchar(30),
)


--Inserto valores para Departamento
INSERT INTO Departamento VALUES (1, 'Ventas')

INSERT INTO Departamento VALUES (2, 'Compras')

INSERT INTO Departamento VALUES (3, 'Contabilidad')

INSERT INTO Departamento VALUES (4, 'Marketing')

INSERT INTO Departamento VALUES (5, 'Sistemas')

--Inserto valores para Empleados

INSERT INTO Empleado VALUES (100, 'Marcelo', 'Mendes', 120000, 'B', null, 1)

INSERT INTO Empleado VALUES (101, 'Diego', 'Mancieri', 60000, 'A', null, 2)

INSERT INTO Empleado VALUES (102, 'Andrea', 'Alberti', 90000, 'C', null, 3)

INSERT INTO Empleado VALUES (103, 'Janice', 'Orzechoski', 100000, 'C', null, 4)

INSERT INTO Empleado VALUES (104, 'Fabio', 'Vitale', 180000, 'A', null, 5)

INSERT INTO Empleado VALUES (105, 'Rodrigo', 'Berti', 180000, 'A', null, 5)

INSERT INTO Empleado VALUES (106, 'Ignacio', 'Calvo', 200000, 'A', 555-1234, 5)



SELECT *
FROM Empleado

--Variable SUM

SELECT SUM (salario) AS Salarios_Sistemas --Es optativo el AS, no es necesario
FROM Empleado e, Departamento d --A empleado en esta funcion le cambio el nombre por "e" y a departamento por d"
WHERE e.cod_depto = d.cod_depto -- entonces aca va a empleado.cod_depto y lo mismo en departamento
AND d.descripcion = 'Sistemas' 

--VARIABLES MAX () Y MIN ()

SELECT  MIN (salario) AS Salario_Minimo, 
		MAX (Salario) Salario_Maximo --Es optativo el AS, no es necesario
FROM Empleado
WHERE Categoria = 'C'

--Variables COUNT

SELECT COUNT(*) Cant_Deptos
FROM Departamento

SELECT COUNT (tel) Cant_Telefonos 
FROM Empleado
--Cuenta la cantida de NO nulos, no se usa mucho, si queremos contar un NO null podemos hacer lo siguiente:

SELECT COUNT(*) Cant_Telefonos
FROM Empleado
WHERE tel IS NOT NULL --IS NOT NULL chequeamos los NO nulos, y con IS NULL chequeamos los que SI son null


--GROUP BY

SELECT categoria, count (*) Cant_Empleados
FROM Empleado
GROUP BY Categoria

--Es lo mismo

SELECT  count (*) Cant_Empleados -- Solo que no muestra columna 
FROM Empleado
GROUP BY Categoria


--HAVING

SELECT		Categoria , count (*) Cant_Empleados
FROM		empleado
WHERE Salario > 80000 --Tener en cuenta siempre si se puede poner en el WHERE
GROUP BY	Categoria
HAVING count (*) > 1 --El alias de la columna no se puede usar en el HAVING

--ORDER BY

SELECT legajo, nombre, apellido, salario sueldo -- Aca si podemos cambiar el alias en el Order BY
FROM Empleado
ORDER BY Salario, Apellido desc  --Por default esta en ASC

--Ademas puede ordenarlo sin necesidad de que se muestre

SELECT legajo, nombre, apellido -- Aca si podemos cambiar el alias en el Order BY
FROM Empleado
ORDER BY Salario, Apellido desc

SELECT			Categoria , count (*) Cant_Empleados
FROM			empleado
WHERE			Salario > 80000 --Tener en cuenta siempre si se puede poner en el WHERE
GROUP BY		Categoria
HAVING SUM		(salario) > 150000
ORDER BY sum	(salario) --Una vez que usamos GROUP BY el ordenar tiene que estar en el SELECT

SELECT legajo, nombre, apellido -- Aca si podemos cambiar el alias en el Order BY
FROM Empleado
ORDER BY 3 --Esto es lo mismo que haber puesto ORDER BY Apellido, porque el 3 es la columa Apellido

SELECT		legajo, nombre, apellido, 
			salario sueldo_en_pesos,
			round (Salario/185 ,2) sueldo_en_usd --Para redondear decimales
FROM		Empleado
ORDER BY 5 --Ordena por Sueldo en Dls ya que es la 5ta columna

-----------------------------------------

--Tabla ALUMNO
CREATE TABLE ALUMNO
(
Legajo		integer PRIMARY KEY,
NOMBRE		varchar(60),
APELLIDO	varchar(60),
EMAIL		varchar(60),
TELEFONO	char (15)
)

--Tabla MATERIA
CREATE TABLE MATERIA
(
COD_MATERIA    integer PRIMARY KEY,
NOMBRE_MATERIA varchar(45),
ANIO           integer,
)

--Tabla CURSA
CREATE TABLE CURSA
(
LEGAJO     integer FOREIGN KEY REFERENCES ALUMNO (Legajo),
COD_MATERIA    integer FOREIGN KEY REFERENCES MATERIA(COD_MATERIA)
PRIMARY KEY (LEGAJO, COD_MATERIA) -- ES LA UNICA FORMA DE PONER DOS PK
)

INSERT INTO MATERIA VALUES (100,'Analisis Matematico 1',1)
INSERT INTO MATERIA VALUES (101,'Algebra 1',1)

INSERT INTO MATERIA VALUES (201,'Fisica 1',2)
INSERT INTO MATERIA VALUES (202,'Algebra 2',2)

INSERT INTO MATERIA VALUES (301,'Base de Datos',3)
INSERT INTO MATERIA VALUES (302,'Probabilidad y estadistica',3)

select *
from MATERIA

INSERT INTO ALUMNO VALUES (10, 'Maria', 'Suarez', null, null)
INSERT INTO ALUMNO VALUES (11, 'Pablo', 'Perez', null, null)
INSERT INTO ALUMNO VALUES (12, 'Laura', 'Almagro', null, null)
INSERT INTO ALUMNO VALUES (13, 'Jorge', 'Gonzalez', null, null)

SELECT *
FROM ALUMNO

INSERT INTO CURSA VALUES (11,100)
INSERT INTO CURSA VALUES (11,101)

INSERT INTO CURSA VALUES (12,101)
INSERT INTO CURSA VALUES (12,201)
INSERT INTO CURSA VALUES (12,301)

INSERT INTO CURSA VALUES (13,202)
INSERT INTO CURSA VALUES (13,301)
INSERT INTO CURSA VALUES (13,302)



--COCIENTES
--Listar los alumnos que estan cursando todas las materas de 3er anio

--ALUMNOS tales que
--NO existe una Materia de 3er año
--Que NO cursen

SELECT *
FROM	ALUMNO a
WHERE NOT EXISTS(	SELECT *
					FROM MATERIA m
					WHERE ANIO = 3
					AND	NOT EXISTS(	SELECT *
									FROM CURSA c
									WHERE	c.LEGAJO = a.Legajo
									and		c.COD_MATERIA = m.COD_MATERIA))

--No es un legajo esto:

SELECT *
FROM	ALUMNO a
WHERE NOT EXISTS(	SELECT *
					FROM CURSA c
					WHERE C.LEGAJO = a.Legajo)

-- Otra forma de hacer lo siguiente:
SELECT *
FROM  ALUMNO a
WHERE Legajo NOT IN ( SELECT Legajo
					  FROM CURSA c)


SELECT Legajo
FROM ALUMNO
EXCEPT
SELECT legajo
FROM CURSA

--Ejemplos de cocientes:
--Listar los clientes que compraron en todas las Sucursales de Avellaneda.
--COCIENTE
--LISTAR LOS CLIENTES TALES QUE
--NO EXISTE una sucursal de Avellaneda en la que
--NO hayan comprado CS

--Listar los empleados que estan asignados a todos los proyectos de categoria A
--Listar los Empleados tales que
--No existe un proyecto de categoria A
--En el que NO este asignado


--Ejemplo de Parcial:  (1:34:00)

-- Listar los usuarios que han realizado pedidos en TODOS los comercios de categoria "Sushi" del partido de Moron entre el 
-- 01/01/2020 y el 01/07/2021

--Comercios de Sushi de Moron

CREATE VIEW SushiMoron AS
(
SELECT	Id
FROM	Comercio co, Categoria ca, Partido pa
WHERE	co.idCategoria = ca.Id
AND		 co.idPartido = pa.Id
AND		ca.desc = 'Sushi'
AND		pa.nombre = 'Moron'
)

--Listar los Usuarios tales que
--NO EXISTE un comercio de Sushi de Moron
--En el que NO haya hecho un pedido entre el 01/01/2020 y el 01/07/2021

SELECT *
FROM	Usuario u
WHERE NOT EXISTS (	SELECT *
					FROM SushiMoron s
					WHERE NOT EXISTS(	SELECT *
										FROM	pedido p
										WHERE	p.idUsuario = u.id
										AND		p.idComercio = s.id
										AND		p.fecha >= '01/01/2020'
										and		p.fecha <= '01/07/2021'))



