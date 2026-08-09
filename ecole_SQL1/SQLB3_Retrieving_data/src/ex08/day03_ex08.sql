select distinct name
from (select name, id from person where address in ('Moscow','Samara') and gender = 'male') msmen
join person_order on person_id = msmen.id 
join menu on menu.id = person_order.menu_id
where menu.pizza_name in ('pepperoni pizza', 'mushroom pizza')
order by 1 desc;
