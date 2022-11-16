DROP table Customers;
DROP table Book;

create table Book
(
   Book_id integer not null PRIMARY key,
   title varchar2(100),
   Author varchar2(100),
   Category varchar2(100),
   PublicationDate varchar2(100),
   Prize int 
);

create table Customers
(
   Customer_id integer not null,
   Name varchar2(100),
   Address varchar2(100),
   Email varchar2(100), 
   PhoneNumber varchar2(100),
   Payment varchar2(100),
   Total varchar2(100),
   PRIMARY key(Customer_id),
   Book_id int,
   FOREIGN KEY(Book_id) REFERENCES  Book (Book_id)
); 

insert into Book (Book_id,title,Author,Category,PublicationDate,Prize) values (1,'Balaka','Rabindranath Tagore','Poetry','1916',169);
insert into Book (Book_id,title,Author,Category,PublicationDate,Prize) values (2, 'Himu','Humayun Ahmed','novel','1990', 135);
insert into Book (Book_id,title,Author,Category,PublicationDate,Prize) values (3, 'The Good Muslim','Tahmima Anam','novel','2011',525);
insert into Book (Book_id,title,Author,Category,PublicationDate,Prize) values (4, 'Hamlet','William Shakespeare','Drama','1603',150);
insert into Book (Book_id,title,Author,Category,PublicationDate,Prize) values (5, 'Banalata Sen','Jibanananda Das','Poetry','1990',113);
insert into Book (Book_id,title,Author,Category,PublicationDate,Prize) values (6, 'Lalsalu','Syed Waliullah','novel','2001',150);
insert into Book (Book_id,title,Author,Category,PublicationDate,Prize) values (7, 'Antony and Cleopatra','William Shakespeare','Drama','1607',171);
insert into Book (Book_id,title,Author,Category,PublicationDate,Prize) values (8, 'Matir Kanna','Jasimuddin','Poetry','2011',120);
insert into Book (Book_id,title,Author,Category,PublicationDate,Prize) values (9, 'Nawab Sirajuddaula','Sikandar Abu Zafar','Drama','1967', 113);
insert into Book (Book_id,title,Author,Category,PublicationDate,Prize) values (10, 'Mohakashe Mohatrash','Muhammed Zafar Iqbal','science fiction','2020',75);
insert into Book (Book_id,title,Author,Category,PublicationDate,Prize) values (11, 'Project Nebula','Muhammed Zafar Iqbal','science fiction','2001',150);
insert into Book (Book_id,title,Author,Category,PublicationDate,Prize) values (12, 'Tara Tinjon','Humayun Ahmed','science fiction','2002',150);
insert into Book (Book_id,title,Author,Category,PublicationDate,Prize) values (13, 'Rani Kanchan Mala and Other Stories','Runa Khan Marre','fairy tale','2000',191);
insert into Book (Book_id,title,Author,Category,PublicationDate,Prize) values (14, 'Cinderella','Brothers Grimm','fairy tale','1968',120);
insert into Book (Book_id,title,Author,Category,PublicationDate,Prize)values (15, 'Beauty and the beast','Robert Sabuda','fairy tale','2010',126);

commit;


