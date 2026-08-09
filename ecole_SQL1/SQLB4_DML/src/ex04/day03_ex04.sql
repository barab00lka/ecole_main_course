WITH male_pzs AS (
    SELECT
        pz.name AS pizzeria_name
    FROM
        pizzeria pz
        JOIN menu m ON m.pizzeria_id = pz.id
        JOIN person_order po ON po.menu_id = m.id
        JOIN person p ON p.id = po.person_id
    WHERE
        p.gender = 'male'
),
female_pzs AS (
    SELECT
        pz.name AS pizzeria_name
    FROM
        pizzeria pz
        JOIN menu m ON m.pizzeria_id = pz.id
        JOIN person_order po ON po.menu_id = m.id
        JOIN person p ON p.id = po.person_id
    WHERE
        p.gender = 'female'
)
SELECT
    pizzeria_name
FROM (
    SELECT
        *
    FROM
        female_pzs
    EXCEPT
    SELECT
        *
    FROM
        male_pzs)
UNION (
    SELECT
        *
    FROM
        male_pzs
    EXCEPT
    SELECT
        *
    FROM
        female_pzs)
ORDER BY
    1;
