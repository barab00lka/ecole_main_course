select pizzeria.name as pizzeria_name
from pizzeria 
join person_visits on pizzeria.id = person_visits.pizzeria_id join person on person_visits.person_id = person.id
join menu on pizzeria.id = menu.pizzeria_id
where person.name = 'Dmitriy' and person_visits.visit_date = '2022-01-08' and menu.price < 800;
