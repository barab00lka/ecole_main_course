with pz_visit_count as (
	select pv.pizzeria_id, coalesce(count(visit_date),0) as count, 'visit' as action_type
	from person_visits pv
	group by pv.pizzeria_id
	order by count desc
	limit 3
),
pz_order_count as (
	select m.pizzeria_id, coalesce(count(order_date),0) as count, 'order' as action_type
	from person_order po
	full join menu m on m.id = po.menu_id
	group by m.pizzeria_id
	order by count desc
	limit 3
),

popular_pzs as (
	select pz.name, count, action_type
	from pizzeria pz
	 join (
		select * 
		from pz_visit_count
		union all
		select *
		from pz_order_count
	) on pz.id = pizzeria_id
)

select * from popular_pzs
order by action_type, count desc;
