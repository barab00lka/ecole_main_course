with new_order_from_everyone AS (
    SELECT generate_series(
        (SELECT COALESCE(MAX(id),0) FROM person_order) + 1,
        (SELECT COALESCE(MAX(id),0) FROM person_order) + (SELECT COUNT(*) FROM person),
        1
    )
)

INSERT INTO person_order (id, person_id, menu_id, order_date)

SELECT o.generate_series as id, p.id AS person_id,
(select id as menu_id from menu where pizza_name = 'greek pizza') as menu_id, DATE '2022-02-25' AS visit_date
FROM new_order_from_everyone o
JOIN person p
  ON o.generate_series = p.id + (SELECT COALESCE(MAX(id),0) FROM person_order)

returning *;
