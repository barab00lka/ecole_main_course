select p.name, m.pizza_name, m.price, (m.price  - (m.price * pd.discount * 0.01))::int as discount_price, pz.name as pizzeria_name
from person_order po
join menu m on m.id = po.menu_id
join pizzeria pz on pz.id = m.pizzeria_id
join person_discounts pd on pd.person_id = po.person_id AND pd.pizzeria_id = m.pizzeria_id
join person p on p.id = po.person_id
order by 1,2;
