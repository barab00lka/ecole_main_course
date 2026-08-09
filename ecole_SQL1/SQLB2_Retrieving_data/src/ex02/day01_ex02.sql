select pizza_name from menu 
intersect 
select pizza_name from menu order by 1 desc;

select pizza_name from menu 
union 
select pizza_name from menu order by 1 desc;
