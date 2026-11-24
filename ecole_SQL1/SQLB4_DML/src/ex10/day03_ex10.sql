 INSERT INTO person_order (id, person_id, menu_id, order_date)
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
             menu
         WHERE
             pizza_name = 'sicilian pizza'), 
		DATE '2022-02-24'
 FROM
     person p
 WHERE
     p.name IN ('Denis', 'Irina')

returning *;
