CREATE OR REPLACE TEMP VIEW new_visit AS
WITH v_dmitriy as (
    SELECT
        person_visits.person_id,
        person_visits.visit_date
    FROM
        pizzeria
        JOIN person_visits ON pizzeria.id = person_visits.pizzeria_id
        JOIN person ON person_visits.person_id = person.id
        JOIN menu ON pizzeria.id = menu.pizzeria_id
    WHERE
        person.name = 'Dmitriy'
        AND person_visits.visit_date = '2022-01-08'
        AND menu.price < 800
    LIMIT 1
),
new_cheap_pz AS (
    SELECT
        pz.id
    FROM
        pizzeria pz
        JOIN menu m ON pz.id = m.pizzeria_id
    WHERE
        m.price < 800
    EXCEPT
    SELECT
        id
    FROM
        pizzeria pz
        JOIN mv_dmitriy_visits_and_eats ON pz.name = mv_dmitriy_visits_and_eats.pizzeria_name
    LIMIT 1
)
SELECT
    (
        SELECT
            coalesce(max(id), 0) + 1
        FROM
            person_visits) AS id,
    v_dmitriy.person_id,
    (
        SELECT
            id
        FROM
            new_cheap_pz) AS pizzeria_id,
    v_dmitriy.visit_date
FROM
    v_dmitriy;

INSERT INTO person_visits (id, person_id, pizzeria_id, visit_date)
SELECT
    *
FROM
    new_visit
RETURNING
    *;

REFRESH MATERIALIZED VIEW mv_dmitriy_visits_and_eats;
