CREATE OR REPLACE FUNCTION fnc_trg_person_update_audit() RETURNS TRIGGER AS $null$
	BEGIN
		INSERT INTO person_audit SELECT current_timestamp, 'U', OLD.*;
		RETURN OLD; -- return value is ignored (not used)
	END;
$null$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER trg_person_update_audit
AFTER UPDATE ON person
FOR EACH ROW
EXECUTE FUNCTION fnc_trg_person_update_audit();

UPDATE person SET name = 'Bulat' WHERE id = 10; UPDATE person SET name = 'Damir' WHERE id = 10;

Select * from person_audit;
