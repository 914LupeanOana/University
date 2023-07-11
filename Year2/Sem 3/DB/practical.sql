--1ac
--2c
--3a




CREATE TABLE MedicalCenters(
    idCenter INT PRIMARY KEY,
    nameCenter varchar(100),
    unique(nameCenter),
    addressCenter varchar(100)
)

CREATE TABLE Doctors(
    idDoctor INT PRIMARY KEY,
    nameDoctor varchar(100),
    idCenter INT REFERENCES MedicalCenters(idCenter),
    dateofbirth varchar(100)
)

CREATE TABLE BloodTypes(
    idType INT PRIMARY KEY,
    nametype varchar(100)
)

CREATE TABLE Donor(
    idDonor INT PRIMARY KEY,
    datebirthDonor varchar(100),
    idType INT REFERENCES BloodTypes(idType)
)

ALTER TABLE [Donor] ADD nameDonor varchar(100)


CREATE TABLE Donations(
    idDonation INT PRIMARY KEY,
    dateofdonation varchar(100),
    idDonor INT REFERENCES Donor(idDonor),
    idCenter INT REFERENCES MedicalCenters(idCenter),
    idDoctor INT REFERENCES Doctors(idDoctor),
    statusdonation varchar(100)
)

SELECT * FROM MedicalCenters
SELECT * FROM Doctors
SELECT * FROM BloodTypes
select * from Donor

---- 2
go
CREATE OR ALTER PROC addDonation(@idDonation INT, @dateofdonation varchar(100), @idDonor int, @nameCenter varchar(100), @nameDoctor varchar(100), @status varchar(100)) AS
BEGIN
    --declare @idDonor INT = (select idDonor from Donor where nameDonor = @nameDonor)
    declare @idCenter INT = (select idCenter from MedicalCenters where nameCenter = @nameCenter)
    declare @idDoctor INT = (select idDoctor from Doctors where nameDoctor = @nameDoctor)
    

    if @idDoctor is not null and @idCenter is not null and @idDonor is not null 
        insert into Donations(idDonation, dateofdonation, idDonor, idCenter, idDoctor, statusdonation) values (@idDonation, @dateofdonation , @idDonor, @idCenter, @idDoctor, @status)
    else 
        raiserror('No associate donation found', 12, 1)

END

insert into Doctors(idDoctor,nameDoctor, idCenter, dateofbirth) values (1, 'Mihai', 1, '22.02.1999')
insert into MedicalCenters(idCenter, nameCenter, addressCenter) values (1, 'abc', 'bnj')
insert into Donor(idDonor, datebirthDonor, idType) values (2, '26.04.1987', 1 )
insert into BloodTypes(idType, nametype) values(1, 'AB4')

exec addDonation @idDonation=1, @dateofdonation='11.09.2022', @idDonor=2, @nameCenter='abc', @nameDoctor = 'Mihai', @status = 'succesfull'

select * from Donations

--3

go
create view viewCenters as 
select M.nameCenter
from MedicalCenters M
where idCenter in (select idCenter from Donations where statusdonation like 's%'
 )
go

select * from viewCenters

-- 4
go
create function functionf (@R INT) 
returns Table as return
	select idDonor
	from Donor
	where idDonor in (
		select D.idDonor
		from Donations D
		group by D.idDonation
		having count(*) > @R
		)

go