with pzs as (
	select m.pizza_name, pz.name, m.price
	from menu m 
	join pizzeria pz on pz.id = m.pizzeria_id
)

select pzs.pizza_name, pzs.name as pizzeria_name_1, pzs2.name as pizzeria_name_2, pzs.price
from pzs 
inner join pzs pzs2 on pzs.price = pzs2.price and pzs.pizza_name = pzs2.pizza_name
where pzs.name < pzs2.name
order by 1;
