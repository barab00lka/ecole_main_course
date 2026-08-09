WITH visits_data AS (
    SELECT
        p.name,
	  	count(pv.id) as count_of_visits
    FROM
        person_visits pv
    JOIN person p ON p.id = pv.person_id
    GROUP BY
        p.name
	HAVING count(pv.id) > 3
)
select * from visits_data;
