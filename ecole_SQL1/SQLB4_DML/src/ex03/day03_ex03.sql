select m_pizzeria_name as pizzeria_name 
from 
		(select pz.name as m_pizzeria_name, p.gender, COUNT(*) as m_visited
		from person_visits pv
		join pizzeria pz on pv.pizzeria_id = pz.id
		join person p on p.id = pv.person_id
		where p.gender = 'male'
		group by m_pizzeria_name, gender
		order by 1 ) 
	left join 
		(select pz.name as f_pizzeria_name, p.gender, COUNT(*) as f_visited
		from person_visits pv
		join pizzeria pz on pv.pizzeria_id = pz.id
		join person p on p.id = pv.person_id
		where p.gender = 'female'
		group by f_pizzeria_name, gender
		order by 1)
on f_pizzeria_name = m_pizzeria_name
where m_visited != f_visited
order by 1;
