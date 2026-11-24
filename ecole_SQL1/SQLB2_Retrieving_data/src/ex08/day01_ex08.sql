select order_date, format('%s (age:%s)', name, age) as person_information 
from person
natural join (select person_id as id, order_date from person_order)
order by 1,2 asc
