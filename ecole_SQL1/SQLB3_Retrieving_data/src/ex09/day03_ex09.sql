select name 
from 
	(select name from 
		(select name, id from person where gender = 'female') women
		join person_order on person_id = women.id 
		join menu on menu.id = person_order.menu_id
		where menu.pizza_name = 'pepperoni pizza')
	intersect
	(select name from 
		(select name, id from person where gender = 'female') women
		join person_order on person_id = women.id 
		join menu on menu.id = person_order.menu_id
		where menu.pizza_name = 'cheese pizza')
order by 1 asc;
