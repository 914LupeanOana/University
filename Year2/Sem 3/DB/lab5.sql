if exists (select * from dbo.sysobjects where id = object_id(N'[FK_TestRunTables_Tables]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
	ALTER TABLE [TestRunTables] DROP CONSTRAINT FK_TestRunTables_Tables
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[FK_TestTables_Tables]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
	ALTER TABLE [TestTables] DROP CONSTRAINT FK_TestTables_Tables
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[FK_TestRunTables_TestRuns]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
	ALTER TABLE [TestRunTables] DROP CONSTRAINT FK_TestRunTables_TestRuns
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[FK_TestRunViews_TestRuns]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
	ALTER TABLE [TestRunViews] DROP CONSTRAINT FK_TestRunViews_TestRuns
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[FK_TestTables_Tests]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
	ALTER TABLE [TestTables] DROP CONSTRAINT FK_TestTables_Tests
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[FK_TestViews_Tests]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
	ALTER TABLE [TestViews] DROP CONSTRAINT FK_TestViews_Tests
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[FK_TestRunViews_Views]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
	ALTER TABLE [TestRunViews] DROP CONSTRAINT FK_TestRunViews_Views
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[FK_TestViews_Views]') and OBJECTPROPERTY(id, N'IsForeignKey') = 1)
	ALTER TABLE [TestViews] DROP CONSTRAINT FK_TestViews_Views
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[Tables]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
	drop table [Tables]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[TestRunTables]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
	drop table [TestRunTables]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[TestRunViews]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
	drop table [TestRunViews]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[TestRuns]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
	drop table [TestRuns]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[TestTables]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
	drop table [TestTables]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[TestViews]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
	drop table [TestViews]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[Tests]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
	drop table [Tests]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[Views]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
	drop table [Views]
GO


CREATE TABLE [Tables] (
	[TableID] [int] IDENTITY (1, 1) NOT NULL ,
	[Name] [nvarchar] (50) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [TestRunTables] (
	[TestRunID] [int] NOT NULL ,
	[TableID] [int] NOT NULL ,
	[StartAt] [datetime] NOT NULL ,
	[EndAt] [datetime] NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [TestRunViews] (
	[TestRunID] [int] NOT NULL ,
	[ViewID] [int] NOT NULL ,
	[StartAt] [datetime] NOT NULL ,
	[EndAt] [datetime] NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [TestRuns] (
	[TestRunID] [int] IDENTITY (1, 1) NOT NULL,
	[Description] [nvarchar] (2000) COLLATE SQL_Latin1_General_CP1_CI_AS NULL,
	[StartAt] [datetime] NULL,
	[EndAt] [datetime] NULL 
) ON [PRIMARY]
GO

CREATE TABLE [TestTables] (
	[TestID] [int] NOT NULL,
	[TableID] [int] NOT NULL,
	[NoOfRows] [int] NOT NULL,
	[Position] [int] NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [TestViews] (
	[TestID] [int] NOT NULL ,
	[ViewID] [int] NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [Tests] (
	[TestID] [int] IDENTITY (1, 1) NOT NULL ,
	[Name] [nvarchar] (50) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [Views] (
	[ViewID] [int] IDENTITY (1, 1) NOT NULL ,
	[Name] [nvarchar] (50) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL 
) ON [PRIMARY]
GO


ALTER TABLE [Tables] WITH NOCHECK ADD 
	CONSTRAINT [PK_Tables] PRIMARY KEY  CLUSTERED (
		[TableID]
	) ON [PRIMARY] 
GO

ALTER TABLE [TestRunTables] WITH NOCHECK ADD 
	CONSTRAINT [PK_TestRunTables] PRIMARY KEY  CLUSTERED (
		[TestRunID],
		[TableID]
	) ON [PRIMARY]
GO

ALTER TABLE [TestRunViews] WITH NOCHECK ADD 
	CONSTRAINT [PK_TestRunViews] PRIMARY KEY  CLUSTERED (
		[TestRunID],
		[ViewID]
	) ON [PRIMARY] 
GO

ALTER TABLE [TestRuns] WITH NOCHECK ADD 
	CONSTRAINT [PK_TestRuns] PRIMARY KEY  CLUSTERED (
		[TestRunID]
	) ON [PRIMARY] 
GO

ALTER TABLE [TestTables] WITH NOCHECK ADD 
	CONSTRAINT [PK_TestTables] PRIMARY KEY  CLUSTERED (
		[TestID],
		[TableID]
	) ON [PRIMARY] 
GO

ALTER TABLE [TestViews] WITH NOCHECK ADD 
	CONSTRAINT [PK_TestViews] PRIMARY KEY  CLUSTERED (
		[TestID],
		[ViewID]
	) ON [PRIMARY] 
GO

ALTER TABLE [Tests] WITH NOCHECK ADD 
	CONSTRAINT [PK_Tests] PRIMARY KEY  CLUSTERED (
		[TestID]
	) ON [PRIMARY]
GO

ALTER TABLE [Views] WITH NOCHECK ADD 
	CONSTRAINT [PK_Views] PRIMARY KEY  CLUSTERED  (
		[ViewID]
	) ON [PRIMARY] 
GO

ALTER TABLE [TestRunTables] ADD 
	CONSTRAINT [FK_TestRunTables_Tables] FOREIGN KEY (
		[TableID]
	) REFERENCES [Tables] (
		[TableID]
	) ON DELETE CASCADE  ON UPDATE CASCADE,
	CONSTRAINT [FK_TestRunTables_TestRuns] FOREIGN KEY (
		[TestRunID]
	) REFERENCES [TestRuns] (
		[TestRunID]
	) ON DELETE CASCADE  ON UPDATE CASCADE 
GO

ALTER TABLE [TestRunViews] ADD 
	CONSTRAINT [FK_TestRunViews_TestRuns] FOREIGN KEY (
		[TestRunID]
	) REFERENCES [TestRuns] (
		[TestRunID]
	) ON DELETE CASCADE  ON UPDATE CASCADE,
	CONSTRAINT [FK_TestRunViews_Views] FOREIGN KEY (
		[ViewID]
	) REFERENCES [Views] (
		[ViewID]
	) ON DELETE CASCADE  ON UPDATE CASCADE
GO

ALTER TABLE [TestTables] ADD 
	CONSTRAINT [FK_TestTables_Tables] FOREIGN KEY (
		[TableID]
	) REFERENCES [Tables] (
		[TableID]
	) ON DELETE CASCADE  ON UPDATE CASCADE ,
	CONSTRAINT [FK_TestTables_Tests] FOREIGN KEY (
		[TestID]
	) REFERENCES [Tests] (
		[TestID]
	) ON DELETE CASCADE  ON UPDATE CASCADE 
GO

ALTER TABLE [TestViews] ADD 
	CONSTRAINT [FK_TestViews_Tests] FOREIGN KEY (
		[TestID]
	) REFERENCES [Tests] (
		[TestID]
	),
	CONSTRAINT [FK_TestViews_Views] FOREIGN KEY (
		[ViewID]
	) REFERENCES [Views] (
		[ViewID]
	)
GO

-- --------------------------------------------------------------------------------- --
GO

CREATE TABLE tbl1 (
	id INT PRIMARY KEY,
	info VARCHAR(100)
);

CREATE TABLE tbl2 (
	id INT PRIMARY KEY,
	id_tbl1 INT FOREIGN KEY REFERENCES tbl1(id),
	info VARCHAR(100)
);

CREATE TABLE tbl3 (
	id1 INT,
	id2 INT,
	CONSTRAINT PK_tbl3 PRIMARY KEY (id1, id2)
);

GO

CREATE VIEW v1 AS
SELECT * FROM tbl1;
GO

CREATE VIEW v2 AS
SELECT tbl2.id, tbl1.info FROM tbl1, tbl2
WHERE tbl1.id = tbl2.id_tbl1;
GO

CREATE VIEW v3 AS
SELECT COUNT(tbl2.id) AS nr_of_tbls, tbl2.id_tbl1
FROM tbl2
GROUP BY tbl2.id_tbl1;
GO

-- ------------------------------------------------------------------------------------

CREATE PROCEDURE insert_in_tbl  @table_name  VARCHAR(50), @nr_rows INT AS
	DECLARE @index int;
	SET @index = 0;

	WHILE @index < @nr_rows BEGIN
		IF @table_name = 'tbl1' BEGIN
			INSERT INTO tbl1 VALUES(@index, 'info1');
		END
		ELSE IF @table_name  = 'tbl2' BEGIN
			INSERT INTO tbl2 VALUES(@index, @index, 'info2');
		END
		ELSE IF @table_name  = 'tbl3' BEGIN
			INSERT INTO tbl3 VALUES(@index, @index + 1);
		END
		SET @index = @index + 1
	END

GO

CREATE PROCEDURE delete_from_tbl @table_name VARCHAR(50) AS
	EXEC('DELETE FROM ' + @table_name + ';');
GO

CREATE PROCEDURE view_test @name VARCHAR(50) AS
	EXEC('SELECT * FROM ' + @name + ';');
GO

CREATE PROCEDURE run @test_id INTEGER AS
	DECLARE @start_time DATETIME;
	DECLARE @end_time DATETIME;

	DECLARE @current_table_name VARCHAR(50);
	DECLARE @current_no_rows INT;
	DECLARE @current_table_id INT;

	DECLARE @test_name VARCHAR(50);
	SET @test_name = (
		SELECT Name
		FROM Tests
		WHERE TestID = @test_id
	);

	SET @start_time = GETDATE();

	IF ( SELECT 1 FROM TestRuns WHERE TestRunID = @test_id)> 0 BEGIN
		UPDATE TestRuns
		SET StartAt = @start_time, EndAt = @end_time WHERE TestRunID = @test_id;
	END
	ELSE BEGIN		
		INSERT INTO TestRuns VALUES(@test_name, @start_time, @end_time);
	END

	-- run tests for delete procedure:
	DECLARE @Cursor CURSOR;
	SET @Cursor = CURSOR FOR
		SELECT [Tables].Name, [TestTables].NoOfRows, [Tables].TableID FROM [TestTables]
		INNER JOIN [Tables] ON [Tables].TableID = [TestTables].TableID
		WHERE TestID = @test_id ORDER BY Position;
	OPEN @Cursor;

	FETCH NEXT FROM @Cursor
	INTO @current_table_name, @current_no_rows, @current_table_id;
	WHILE @@FETCH_STATUS = 0 BEGIN
		EXEC delete_from_tbl @table_name = @current_table_name;
		FETCH NEXT FROM @Cursor INTO @current_table_name, @current_no_rows, @current_table_id;
    END

	CLOSE @Cursor;
    DEALLOCATE @Cursor;


	-- run tests for insert procedure:
	DECLARE @Cursor2 CURSOR;
	SET @Cursor2 = CURSOR FOR
		SELECT [Tables].Name, [TestTables].NoOfRows, [Tables].TableID FROM [TestTables]
		INNER JOIN [Tables] ON [Tables].TableID = [TestTables].TableID
		WHERE TestID = @test_id ORDER BY Position DESC;
	
	OPEN @Cursor2;
	FETCH NEXT FROM @Cursor2
	INTO @current_table_name, @current_no_rows, @current_table_id;
	WHILE @@FETCH_STATUS = 0 BEGIN
		
		SET @start_time = GETDATE();
		EXEC insert_in_tbl @table_name = @current_table_name, @nr_rows = @current_no_rows;
		SET @end_time = GETDATE();

		IF ( SELECT 1 FROM [TestRunTables] WHERE TestRunID = @test_id AND TableID = @current_table_id )> 0 BEGIN
			UPDATE [TestRunTables]
			SET StartAt = @start_time, EndAt = @end_time WHERE TestRunID = @test_id AND TableID = @current_table_id;
		END
		ELSE BEGIN
			INSERT INTO [TestRunTables] VALUES(@test_id, @current_table_id, @start_time, @end_time);
		END

		PRINT @test_id;
		PRINT @current_table_id;
		FETCH NEXT FROM @Cursor2
		INTO @current_table_name, @current_no_rows, @current_table_id;
    END
	CLOSE @Cursor2 ;
    DEALLOCATE @Cursor2;
	

	-- run tests for view procedure:
	DECLARE @Cursor3 CURSOR;
	SET @Cursor3 = CURSOR FOR
		SELECT [Views].Name, [Views].ViewID
		FROM [TestViews]
		INNER JOIN [Views] ON [Views].ViewID = [TestViews].ViewID
		WHERE TestID = @test_id;

	OPEN @Cursor3;
	FETCH NEXT FROM @Cursor3
	INTO @current_table_name, @current_table_id;
	WHILE @@FETCH_STATUS = 0 BEGIN
		
		SET @start_time = GETDATE();
		EXEC view_test @name = @current_table_name;
		SET @end_time = GETDATE();

		IF ( SELECT 1 FROM [TestRunViews] WHERE TestRunID = @test_id AND ViewID = @current_table_id )> 0 BEGIN
			UPDATE [TestRunViews]
			SET StartAt = @start_time, EndAt = @end_time WHERE TestRunID = @test_id AND ViewID = @current_table_id;
		END
		ELSE BEGIN
			INSERT INTO [TestRunViews] VALUES(@test_id, @current_table_id, @start_time, @end_time);
		END

		FETCH NEXT FROM @Cursor3
		INTO @current_table_name, @current_table_id;
    END;
	CLOSE @Cursor3;
    DEALLOCATE @Cursor3;
	
	SET @end_time = GETDATE();
	UPDATE TestRuns
	SET EndAt = @end_time
	WHERE TestRunID = @test_id;

GO


INSERT INTO [Tables] Values ('tbl1');
INSERT INTO [Tables] Values ('tbl2');
INSERT INTO [Tables] Values ('tbl3');

INSERT INTO [Tests] Values('tbl1');
INSERT INTO [Tests] Values('tbl2');
INSERT INTO [Tests] Values('tbl3');

INSERT INTO [Views] VALUES('v1');
INSERT INTO [Views] VALUES('v2');
INSERT INTO [Views] VALUES('v3');


INSERT INTO [TestViews] VALUES(1, 1);
INSERT INTO [TestViews] VALUES(2, 2);
INSERT INTO [TestViews] VALUES(3, 3);

INSERT INTO [TestTables] Values(1, 1, 100, 1);
INSERT INTO [TestTables] Values(2, 2, 30, 2);
INSERT INTO [TestTables] Values(3, 3, 25, 3);

EXEC run @test_id = 1;
EXEC run @test_id = 2;
EXEC run @test_id = 3;

SELECT * FROM Tests;
SELECT * FROM TestRuns;
SELECT * FROM TestTables;
SELECT * FROM TestRunTables;
SELECT * FROM TestRunViews;

SELECT * FROM tbl1;
SELECT * FROM tbl2;
SELECT * FROM tbl3;


DELETE FROM tbl2;
DELETE FROM tbl3;
DELETE FROM tbl1;

Delete from TestViews;
Delete from TestTables;

-----------------------------------------------------------------------------

CREATE TABLE Ta(
	aid INT PRIMARY KEY, 
	a2 INT UNIQUE,
	a3 INT,
	a4 INT
);

CREATE TABLE Tb(
	bid INT PRIMARY KEY, 
	b2 INT
);

CREATE TABLE Tc(
	cid INT PRIMARY KEY, 
	aid INT FOREIGN KEY REFERENCES Ta(aid),
	bid INT FOREIGN KEY REFERENCES Tb(bid)
);

--  ///////////////    a    ////////////////

DECLARE @i INT
SET @i = 0
WHILE (@i < 5000)
BEGIN
	IF (@i % 2 =0)
		INSERT INTO Ta(aid, a2, a3, a4) VALUES (@i, @i+1, @i+2, @i+2);
	ELSE 
		INSERT INTO Ta(aid, a2, a3, a4) VALUES (@i, @i+1, @i+1, @i+4);
	SET @i = @i +1
END

DELETE FROM Ta;
Select * from Ta;

-- clustered index scan:
SELECT * FROM Ta WHERE a3=432;

-- clustered index seek:
SELECT * FROM Ta WHERE aid=240;

-- non-clustered index scan:
CREATE NONCLUSTERED INDEX IX_a4 ON Ta(a4);
SELECT a4 FROM Ta;

-- non-clustered index seek AND key lookup:
SELECT * FROM Ta WHERE a2=356;

-- ///////////   b   //////////////

DECLARE @i INT
SET @i = 0
WHILE (@i < 2000)
BEGIN
	IF (@i % 2 =0)
		INSERT INTO Tb(bid, b2) VALUES (@i, @i+1);
	ELSE 
		INSERT INTO Tb(bid, b2) VALUES (@i, @i+2);
	SET @i = @i +1
END

DELETE FROM Tb;
SELECT * FROM Tb;

DROP INDEX Tb.IX_b2;
SELECT b2 FROM Tb WHERE b2=123;

CREATE NONCLUSTERED INDEX IX_b2 ON Tb(b2);
SELECT b2 FROM Tb WHERE b2=123;


-- ///////////   c   //////////////
DECLARE @i INT
SET @i = 0
WHILE (@i < 5000)
BEGIN
	INSERT INTO Tc(cid, bid, aid) VALUES (@i, @i, @i);
	SET @i = @i +1
END

DELETE FROM Tc;
SELECT * FROM Tc;

GO
DROP VIEW IF EXISTS my_view;
GO
CREATE VIEW my_view AS
	SELECT Ta.aid, Tc.cid FROM
	Ta JOIN Tc ON Tc.aid = Ta.aid
	WHERE Ta.a2 > 300
GO

DROP INDEX IF EXISTS IX_Tc_aid ON Tc;
CREATE NONCLUSTERED INDEX IX_Tc_aid ON Tc(aid);

SELECT * FROM my_view;

GO