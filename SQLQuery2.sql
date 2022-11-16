CREATE TABLE [dbo].[File] (
    [FileId]    INT             IDENTITY (1, 1) NOT NULL,
    [FileName]  NVARCHAR (100)  NULL,
    [Filebytes] VARBINARY (MAX) NULL,
    CONSTRAINT [PK_dbo.File] PRIMARY KEY CLUSTERED ([FileId] ASC)
);