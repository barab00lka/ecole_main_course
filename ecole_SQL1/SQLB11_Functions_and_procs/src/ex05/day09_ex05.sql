DROP FUNCTION IF EXISTS fnc_persons_female, fnc_persons_male CASCADE;

CREATE OR REPLACE FUNCTION fnc_persons(pgender varchar DEFAULT 'female') RETURNS TABLE (id bigint, name varchar, age int, gender varchar, address varchar) AS $$
	SELECT * FROM person where gender = pgender;
$$ LANGUAGE SQL;

select *
from fnc_persons(pgender := 'male');

select *
from fnc_persons();
