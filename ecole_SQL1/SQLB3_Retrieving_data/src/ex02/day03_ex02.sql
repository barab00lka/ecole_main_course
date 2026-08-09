select coalesce(person.name, '-') as person_name, 
visit_date,
coalesce(pizzeria.name, '-') as pizzeria_name
from person
left join (
	select person_id, visit_date, pizzeria_id
	from person_visits
	where visit_date between '2022-01-01' and '2022-01-03'
) on person_id = person.id
full join pizzeria on pizzeria.id = pizzeria_id
order by 1,2,3;
