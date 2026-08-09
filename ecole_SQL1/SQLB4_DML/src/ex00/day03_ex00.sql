select
    m.pizza_name,
    m.price,
    pz.name as pizzeria_name,
    pv.visit_date
from
    person p
    join person_visits pv on p.id = pv.person_id
    join pizzeria pz on pz.id = pv.pizzeria_id
    join menu m on pz.id = m.pizzeria_id
where
    p.name = 'Kate'
    and m.price between 800
    and 1000
order by
    1,
    2,
    3