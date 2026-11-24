SELECT
    p.address,
    pz.name,
    count(po.id) AS count_of_orders
FROM
    person_order po
    RIGHT JOIN menu m ON m.id = po.menu_id
    RIGHT JOIN pizzeria pz ON pz.id = m.pizzeria_id
        AND po.order_date IS NOT NULL
    JOIN person p ON po.person_id = p.id
GROUP BY
    p.address,
    pz.name,
    m.pizzeria_id
ORDER BY
    1,
    2;

