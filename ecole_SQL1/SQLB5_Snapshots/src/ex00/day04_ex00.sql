CREATE OR REPLACE VIEW v_persons_female as
	select * from person 
	where gender = 'female';

CREATE OR REPLACE VIEW v_persons_male as
	select * from person 
	where gender = 'male';
