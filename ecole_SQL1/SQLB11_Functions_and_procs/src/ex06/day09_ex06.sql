CREATE OR REPLACE FUNCTION fnc_person_visits_and_eats_on_date(pperson varchar DEFAULT 'Dmitriy', pprice numeric DEFAULT 500, pdate date DEFAULT '2022-01-08')
RETURNS TABLE (pizzeria_name varchar)
AS $$
	BEGIN
		RETURN QUERY
			SELECT
			    pizzeria.name AS pizzeria_name
			FROM
			    pizzeria
			    JOIN person_visits ON pizzeria.id = person_visits.pizzeria_id
			    JOIN person ON person_visits.person_id = person.id
			    JOIN menu ON pizzeria.id = menu.pizzeria_id
			WHERE
			    person.name = pperson
			    AND person_visits.visit_date = pdate
			    AND menu.price < pprice;
	END;
$$ LANGUAGE plpgsql;

select *
from fnc_person_visits_and_eats_on_date(pprice := 800);

select *
from fnc_person_visits_and_eats_on_date(pperson := 'Anna',pprice := 1300,pdate := '2022-01-01');


