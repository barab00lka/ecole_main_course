select t1.name as person_name1, t2.name as person_name2, t1.address as common_address
from (select name, address from person) as t1
join (select name, address from person) as t2 on t1.address = t2.address
where t1.name < t2.name
order by 1,2
