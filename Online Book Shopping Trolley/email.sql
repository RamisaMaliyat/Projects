SET SERVEROUTPUT ON;

DECLARE
   b_isvalid   BOOLEAN;
BEGIN
   b_isvalid :=
      REGEXP_LIKE ('&Email',
                   '^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,4}$');

   IF b_isvalid
   THEN
      DBMS_OUTPUT.put_line ('It is a valid email address.');
   ELSE
      DBMS_OUTPUT.put_line ('It is Not a valid email address.');
   END IF;
END;
/