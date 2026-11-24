CREATE SEQUENCE IF NOT EXISTS seq_person_discounts 
START WITH 1
owned by person_discounts.id;

select setval(
	'seq_person_discounts',
 	COALESCE((SELECT MAX(id) FROM person_discounts), 0) + 1,
	false
);

ALTER TABLE person_discounts
	alter column id set default nextval('seq_person_discounts');
