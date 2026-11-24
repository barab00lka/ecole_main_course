CREATE OR REPLACE FUNCTION fnc_persons_female() RETURNS TABLE (id bigint, name varchar, age int, gender varchar, address varchar) AS $$
BEGIN
	RETURN QUERY
	SELECT * 
	FROM v_persons_female;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION fnc_persons_male() RETURNS TABLE (id bigint, name varchar, age int, gender varchar, address varchar) AS $$
BEGIN
	RETURN QUERY
	SELECT * 
	FROM v_persons_male;
END;
$$ LANGUAGE plpgsql;


select * from fnc_persons_female();
select * from fnc_persons_male();
