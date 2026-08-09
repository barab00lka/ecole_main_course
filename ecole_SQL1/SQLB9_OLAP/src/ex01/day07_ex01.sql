with visit_count as (
	select pv.person_id, count(*) AS count_of_visits
	from person_visits pv
	inner join person p on p.id = pv.person_id
	group by pv.person_id
) 

select  p.name, v.count_of_visits 
from visit_count v
inner join person p on p.id = v.person_id
order by 2 desc, 1
limit 4 ;
