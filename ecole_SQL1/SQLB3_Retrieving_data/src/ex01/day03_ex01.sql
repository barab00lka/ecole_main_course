select missing_date 
from (select generate_series('2022-01-01'::date, '2022-01-10'::date, '1 day')::date as missing_date) as gs_table
left join (select visit_date as onetwo_visit_date from person_visits where person_id = 1 or person_id = 2) on gs_table.missing_date = onetwo_visit_date
where onetwo_visit_date is NULL
order by missing_date

