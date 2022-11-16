SET SERVEROUTPUT ON;
SET Verify off;

whenever sqlerror exit;

SELECT * FROM book_view1 @site1;
SELECT * FROM book_view2 @site1;
SELECT * FROM book_view3 @site1;
SELECT * FROM book_view4 @site1;
SELECT * FROM book_view5 @site1;

ACCEPT X NUMBER PROMPT "CHOOSE option: 1 for Yes:  ";

 
CREATE OR REPLACE PACKAGE mypack AS

	FUNCTION F1(A1 IN NUMBER)
	RETURN NUMBER;
	
	PROCEDURE P1(B1 IN NUMBER);
END mypack;
/


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
	  
	  validemail EXCEPTION;
	  validphone EXCEPTION;
	  
	  b_isvalid   BOOLEAN;
	  b_isvalid1   BOOLEAN;
	  
	  A Customers.Name%TYPE:='&Name';
	  B Customers.Address%TYPE:='&Address';
	  C Customers.Email%TYPE:='&Email';
	  D Customers.PhoneNumber%TYPE:='&PhoneNumber';
	  E Customers.Payment%TYPE:='&Payment';
	  F Customers.Total%TYPE:='&Total';
	  
	 
	    
	  
	BEGIN
      
	  
      
       FOR R IN (SELECT Book_id ,title,Author,Category,PublicationDate,Prize FROM Book @site1 WHERE Book_id  = B1 )
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
		 DBMS_OUTPUT.PUT_LINE('Total_Prize:' ||' '||F*T);
		
		 
        END LOOP;

		

	   insert into Customers (Name,Address,Payment,Total,Book_id)
       values(A,B,E,F,B1);
       commit;

       b_isvalid :=
       REGEXP_LIKE (C,
                    '^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,4}$');
				   
       IF b_isvalid
        THEN
		 insert into Customers (Email)values(C);
       ELSE
         RAISE validemail;
       END IF;

       b_isvalid1 :=
       REGEXP_LIKE (D,
                   '^0\d{9}|\d{10}$');


      IF b_isvalid1
       THEN
        insert into Customers (PhoneNumber)values(D);
       ELSE
        RAISE  validphone;
      END IF;

   
		select count(*) into flag from Book where Book_id = B1;
		
		

 
 
		EXCEPTION
          WHEN NO_DATA_FOUND THEN
          
		  DBMS_OUTPUT.PUT_LINE('Book is not available');
		  
		  WHEN validemail THEN
          
		  DBMS_OUTPUT.PUT_LINE('It is Not a valid Email.');
		  
		  
		  WHEN  validphone THEN
          
		  DBMS_OUTPUT.PUT_LINE('It is Not a valid Phone Number.');


		 
	END P1;
	
	
	
	
	FUNCTION F1(A1 IN NUMBER)
	RETURN NUMBER
	IS 
	
	A  int:='&Book_id';
	B int:=0;
	
	
	BEGIN
	     
		 
         
         IF A1=1 THEN 
		    mypack.P1(A);
			
		    RETURN 1;
		   ELSE
		    DBMS_OUTPUT.PUT_LINE('Invalid Option');
		   RETURN 0;
	     END IF;
		  
		
	END F1;
	
	
	
END mypack;
/

DECLARE
	D number;
	B  int:=&X;
    	
BEGIN 
        		
		D := mypack.F1(B);
	
END;
/

