select
	(select name from person where person.id = person_order.person_id) as name,
    CASE 
        WHEN (SELECT name 
              FROM person 
              WHERE person.id = person_order.person_id) = 'Denis'
        THEN TRUE
        ELSE FALSE
    END AS check_name
from person_order 
where person_order.order_date = '2022-01-07' 
and (person_order.menu_id = 13 or person_order.menu_id = 14 or person_order.menu_id = 18);
