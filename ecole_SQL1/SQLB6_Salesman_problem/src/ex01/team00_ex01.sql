WITH costs as (
	select total_cost from valid_paths
)

select total_cost, '{' || tour || '}' as tour from valid_paths 
where total_cost = (SELECT MIN(total_cost) as min_cost from costs)
union
select total_cost, '{' || tour || '}' as tour from valid_paths 
where total_cost = (SELECT MAX(total_cost) as max_cost from costs)
ORDER BY 1,2;
