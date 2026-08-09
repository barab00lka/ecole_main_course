WITH pz_ordered AS (
    SELECT
        pz.name AS pizzeria_name
    FROM
        pizzeria pz
        JOIN menu m ON m.pizzeria_id = pz.id
        JOIN person_order po ON po.menu_id = m.id
        JOIN person p ON p.id = po.person_id
    WHERE
        p.name = 'Andrey'
    GROUP BY
        1
),
pz_visited AS (
    SELECT
        pz.name AS pizzeria_name
    FROM
        pizzeria pz
        JOIN person_visits pv ON pv.pizzeria_id = pz.id
        JOIN person p ON p.id = pv.person_id
    WHERE
        p.name = 'Andrey'
    GROUP BY
        1
)
SELECT
    *
FROM (
    SELECT
        *
    FROM
        pz_visited)
EXCEPT (
    SELECT
        *
    FROM
        pz_ordered)
