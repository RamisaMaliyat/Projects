CREATE TABLE [dbo].[Contacts] (
    [Id]         INT            IDENTITY (1, 1) NOT NULL,
    [FullName]       NVARCHAR (100)     NULL,
    [Email]          NVARCHAR (100)     NULL,
    [Message]        NVARCHAR (1000)    NULL,
   
    [PhoneNumber]    NVARCHAR (15)      NULL,

     CONSTRAINT [PK_dbo.Contacts] PRIMARY KEY CLUSTERED ([Id] ASC)
   
);


