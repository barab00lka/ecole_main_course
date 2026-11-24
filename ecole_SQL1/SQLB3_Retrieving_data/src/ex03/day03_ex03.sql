with day_generator as (select generate_series('2022-01-01'::date, '2022-01-10'::date, '1 day')::date as missing_date)

select missing_date 
from day_generator
left join (select visit_date as onetwo_visit_date from person_visits where person_id = 1 or person_id = 2) on day_generator.missing_date = onetwo_visit_date
where onetwo_visit_date is NULL
order by missing_date

