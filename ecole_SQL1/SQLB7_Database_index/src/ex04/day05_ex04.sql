set enable_seqscan =off;
create unique index idx_menu_unique on menu (pizzeria_id, pizza_name);
explain analyze select pizza_name from menu m join pizzeria pz on pz.id = m.pizzeria_id ;
