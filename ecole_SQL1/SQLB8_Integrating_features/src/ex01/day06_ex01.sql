-- CREATE OR REPLACE VIEW calculated_discount AS
WITH orders_data AS (
    SELECT
        po.person_id,
        m.pizzeria_id,
      count(po.id) AS order_count
    FROM
        person_order po
        JOIN menu m ON m.id = po.menu_id
    GROUP BY
        po.person_id,
        m.pizzeria_id
    ORDER BY
        1,
        2
),

calculated_discount as (
	SELECT
		ROW_NUMBER() OVER () AS id,
	    person_id,
	    pizzeria_id,
	    CASE order_count
	    WHEN 1 THEN
	        10.5
	    WHEN 2 THEN
	        22
	    ELSE
	        30
	    END AS discount
	FROM
		orders_data
)

INSERT INTO person_discounts SELECT * from calculated_discount
returning *;
