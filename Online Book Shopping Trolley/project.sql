SET SERVEROUTPUT ON;
SET VERIFY OFF;
		
CREATE OR REPLACE PACKAGE mypack AS
	
	PROCEDURE P1(B1 IN NUMBER);
END mypack;
/



CREATE OR REPLACE PACKAGE BODY mypack AS
	
	
	PROCEDURE P1(B1 IN NUMBER)
	IS
	X Customer.Customer_id%TYPE;
	Y Customer.PhoneNumber%TYPE;
	invalidPhone EXCEPTION;
	
	BEGIN
		
	    FOR R IN (SELECT Customer_id,PhoneNumber FROM Customer)
        LOOP
         X:= R.Customer_id;
         Y:= R.PhoneNumber;
		 DBMS_OUTPUT.PUT_LINE(X);
		 DBMS_OUTPUT.PUT_LINE(Y);
		
        END LOOP;
		
		IF B1 not like '%[0-9]%' THEN
		RAISE invalidPhone;
		END IF;
		
		EXCEPTION
         WHEN invalidPhone THEN
         DBMS_OUTPUT.PUT_LINE('Phone number is not valid');
		
	END P1;
		
END mypack;
/



DECLARE
	D number;
	S int := &x; 
BEGIN
    mypack.P1(S);
	

END;
/