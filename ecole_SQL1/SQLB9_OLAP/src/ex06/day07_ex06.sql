WITH pz_order_count AS (
    SELECT
        pz.name,
        count(po.id) AS count_of_orders,
        coalesce(round(avg(m.price), 2), 0)::int AS average_price,
        coalesce(max(m.price), 0) AS max_price,
        coalesce(min(m.price), 0) AS min_price
    FROM
        person_order po
        RIGHT JOIN menu m ON m.id = po.menu_id
        RIGHT JOIN pizzeria pz ON pz.id = m.pizzeria_id
            AND po.order_date IS NOT NULL
    GROUP BY
        pz.name,
        m.pizzeria_id
)
SELECT
    *
FROM
    pz_order_count
ORDER BY
    name
