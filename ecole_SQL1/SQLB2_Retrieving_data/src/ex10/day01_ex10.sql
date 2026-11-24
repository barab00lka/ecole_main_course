select person.name as person_name, pizza_name, pizzeria.name as pizzeria_name
from person 
join person_order on person_id = person.id
join menu on menu.id = person_order.menu_id
join pizzeria on pizzeria.id = menu.pizzeria_id
order by person_name asc, pizza_name asc, pizzeria_name asc;
