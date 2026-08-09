CREATE TABLE IF NOT EXISTS person_audit (
	created	timestamp with time zone default current_timestamp not null,
	type_event	char(1) default 'I' not null,
	row_id	bigint not null,
	name	varchar, 
	age	int,
	gender	varchar,	
	address	varchar,
	constraint	ch_type_event check ( type_event in ('I','U','D') ) 
);

CREATE OR REPLACE FUNCTION fnc_trg_person_insert_audit() RETURNS TRIGGER as $$
	BEGIN
		INSERT INTO person_audit SELECT current_timestamp, 'I', NEW.*;
		RETURN NEW; -- return value is ignored
	END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER trg_person_insert_audit 
AFTER INSERT ON person
FOR EACH ROW
EXECUTE FUNCTION fnc_trg_person_insert_audit();

INSERT INTO person(id, name, age, gender, address) VALUES (10,'Damir', 22, 'male', 'Irkutsk');

SELECT * FROM person_audit;
