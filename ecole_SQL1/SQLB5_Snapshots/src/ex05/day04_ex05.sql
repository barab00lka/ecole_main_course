CREATE OR REPLACE VIEW v_price_with_discount AS
WITH name_pizza_price AS (
    SELECT
        p.name,
        menu.pizza_name,
        menu.price::int
    FROM
        person_order po
        JOIN person p ON po.person_id = p.id
        JOIN menu ON menu.id = po.menu_id
),
discounts AS (
    SELECT
        name,
        pizza_name,
        (price - price * 0.1)::int AS discount_price
    FROM
        name_pizza_price
)
SELECT
    *
FROM
    name_pizza_price n
    NATURAL JOIN discounts
ORDER BY
    name,
    pizza_name;

SELECT
    *
FROM
    v_price_with_discount;
