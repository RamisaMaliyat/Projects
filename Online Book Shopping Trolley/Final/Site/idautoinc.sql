DROP SEQUENCE SEQ_T1_ID1;
DROP TRIGGER TRG_T1_ID1;

CREATE SEQUENCE SEQ_T1_ID1;

CREATE OR REPLACE TRIGGER TRG_T1_ID1
BEFORE INSERT ON Customers
FOR EACH ROW
BEGIN
    SELECT SEQ_T1_ID1.NEXTVAL
    INTO :NEW.Customer_id
    FROM DUAL;
END;
/
