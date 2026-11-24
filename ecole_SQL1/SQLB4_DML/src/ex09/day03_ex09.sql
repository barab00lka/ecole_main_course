INSERT INTO person_visits (id, person_id, pizzeria_id, visit_date)
SELECT
    (
        SELECT
            COALESCE(MAX(id), 0)
        FROM
            person_visits) + ROW_NUMBER() OVER (ORDER BY p.id),
    p.id,
    (
        SELECT
            id
        FROM
            pizzeria
        WHERE
            name = 'Dominos'), DATE '2022-02-24'
FROM
    person p
WHERE
    p.name IN ('Denis', 'Irina')

returning *;
