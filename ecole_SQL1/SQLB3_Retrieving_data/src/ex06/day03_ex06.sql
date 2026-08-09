select menu.pizza_name, pizzeria.name as pizzeria_name
from menu
join person_order on menu.id = person_order.menu_id 
join pizzeria on pizzeria.id = menu.pizzeria_id
join person on person.id = person_order.person_id
where person.name in ('Denis', 'Anna')
order by 1,2
