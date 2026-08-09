with visit_count as (
	select pv.person_id, count(*) AS count_of_visits
from person_visits pv
	group by pv.person_id
	order by 2 desc, 1
)

select * from visit_count;
