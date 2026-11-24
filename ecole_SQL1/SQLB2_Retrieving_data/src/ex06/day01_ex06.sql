select action_date,name as person_name
from (
	select order_date as action_date, person_id
	from person_order
	
	intersect
	
	select visit_date as action_date, person_id
	from person_visits
) 
join person on person_id = person.id
order by action_date asc, person_name desc;
	
