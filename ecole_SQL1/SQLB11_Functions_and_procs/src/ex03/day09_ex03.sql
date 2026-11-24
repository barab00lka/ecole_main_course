DROP FUNCTION IF EXISTS fnc_trg_person_insert_audit, fnc_trg_person_update_audit, fnc_trg_person_delete_audit CASCADE;

CREATE OR REPLACE FUNCTION fnc_trg_person_audit() RETURNS TRIGGER AS $$
    BEGIN
        IF (TG_OP = 'DELETE') THEN
            INSERT INTO person_audit SELECT current_timestamp,'D', OLD.*;
        	RETURN OLD; -- result is ignored since this is an AFTER trigger
        ELSIF (TG_OP = 'UPDATE') THEN
            INSERT INTO person_audit SELECT current_timestamp,'U', OLD.*;
        	RETURN NEW; -- result is ignored since this is an AFTER trigger
        ELSIF (TG_OP = 'INSERT') THEN
            INSERT INTO person_audit SELECT current_timestamp,'I', NEW.*;
        	RETURN NEW; -- result is ignored since this is an AFTER trigger
        END IF;
    END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER trg_person_audit 
AFTER INSERT OR UPDATE OR DELETE ON person
	FOR EACH ROW EXECUTE FUNCTION fnc_trg_person_audit();

TRUNCATE person_audit;

--------------------------

INSERT INTO person(id, name, age, gender, address) VALUES (10,'Damir', 22, 'male', 'Irkutsk'); UPDATE person SET name = 'Bulat' WHERE id = 10; UPDATE person SET name = 'Damir' WHERE id = 10; DELETE FROM person WHERE id = 10;

SELECT * FROM person_audit;
