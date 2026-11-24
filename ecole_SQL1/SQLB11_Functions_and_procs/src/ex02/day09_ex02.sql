CREATE OR REPLACE FUNCTION fnc_trg_person_delete_audit() RETURNS TRIGGER as $$
	BEGIN
		INSERT INTO person_audit SELECT current_timestamp, 'D', OLD.*;
		RETURN OLD; -- return value is ignored (not used by postgres)
	END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER trg_person_delete_audit
AFTER DELETE ON person
FOR EACH ROW
	EXECUTE FUNCTION fnc_trg_person_delete_audit();

DELETE FROM person WHERE id = 10;

SELECT * FROM person_audit;
