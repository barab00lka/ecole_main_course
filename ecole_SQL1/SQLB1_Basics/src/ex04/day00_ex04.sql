select
	format('%s (age:%s,gender:''%s'',address:''%s'')', name, age, gender, address) as person_information
from person
order by person_information asc;
