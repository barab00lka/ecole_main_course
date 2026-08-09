select menu.pizza_name, name as pizzeria_name, price
from pizzeria
join menu on pizzeria.id = pizzeria_id
where menu.pizza_name = 'mushroom pizza' or menu.pizza_name = 'pepperoni pizza'
order by 1,2;
