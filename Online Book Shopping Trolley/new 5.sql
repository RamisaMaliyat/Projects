SET SERVEROUTPUT ON;
SET Verify off;


-------DECLARING A PACKAGE----------
CREATE OR REPLACE PACKAGE mypack AS

	FUNCTION F1(A1 IN NUMBER)
	RETURN NUMBER;
	
	PROCEDURE P1(B1 IN NUMBER);
END mypack;
/


--------IMPLEMENTING THE BODY OF A PACKAGE-------- 
CREATE OR REPLACE PACKAGE BODY mypack AS

	
	
	PROCEDURE P1(B1 IN NUMBER)
	IS
	  X Book.Book_id %TYPE;
	  Y Book.title%TYPE;
	  Z Book.Author%TYPE;
	  P Book.Category%TYPE;
	  Q Book.PublicationDate%TYPE;
	  T Book.Prize%TYPE;
	  flag NUMBER;
	  
	  
	BEGIN
      
	  
      
       FOR R IN (SELECT Book_id ,title,Author,Category,PublicationDate,Prize FROM Book  WHERE Book_id  = B1 )
        LOOP
         X:= R.Book_id;
         Y:= R.title;
		 Z:= R.Author;
	     P:= R.Category;
		 Q:= R.PublicationDate;
		 T:= R.Prize;
		 
		
         DBMS_OUTPUT.PUT_LINE('Book_id:' ||' '|| X);
		 DBMS_OUTPUT.PUT_LINE('Title:' ||' '||Y);
		 DBMS_OUTPUT.PUT_LINE('Author:' ||' '||Z);
		 DBMS_OUTPUT.PUT_LINE('Category:' ||' '||P);
		 DBMS_OUTPUT.PUT_LINE('PublicationDate:' ||' '||Q);
		 DBMS_OUTPUT.PUT_LINE('Prize:' ||' '||T);
		
		 
        END LOOP;
	
		
		select count(*) into flag from Book where Book_id = B1;
		
		
		EXCEPTION
          WHEN NO_DATA_FOUND THEN
          flag:=0;
		  DBMS_OUTPUT.PUT_LINE('Book is not available');
		 
	END P1;
	
	
	FUNCTION F1(A1 IN NUMBER)
	RETURN NUMBER
	IS 
	
	opt EXCEPTION;
	
	
	  X Book.Book_id %TYPE;
	  Y Book.title%TYPE;
	  Z Book.Author%TYPE;
	  P Book.Category%TYPE;
	  Q Book.PublicationDate%TYPE;
	  T Book.Prize%TYPE;
	  flag NUMBER;
	  A  int:='&id';
	
	BEGIN
		
	
		IF A1=1 THEN
		  mypack.P1(A);
		  RETURN 1;
		
	  
	   
	   	ELSE
		
		  RETURN 0;
	   END IF;
	   
	   
		
	
		
		
	
		
		
	END F1;
	
	
	
END mypack;
/


DECLARE
	D number;
	B  int:='&option';



	
BEGIN 
		D := mypack.F1(B);
		DBMS_OUTPUT.PUT_LINE(D);
		
	
  
	
END;
/
