select id as menu_id
from menu
where menu.id not in (select po.menu_id from person_order po)
order by 1;
