select order_date as action_date, person_id
from person_order
intersect
select visit_date as action_date, person_id
from person_visits
order by 1, person_id desc;
