select * from (select name from person order by 1) as object_name
union all 
select * from (select pizza_name from menu order by 1)