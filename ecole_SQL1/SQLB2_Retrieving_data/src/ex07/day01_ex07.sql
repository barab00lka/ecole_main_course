select order_date, 

	format('%s (age:%s)', name, age) as person_information from person

join person_order on person_id = person.id
order by 1,2 asc
