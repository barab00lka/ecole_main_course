UPDATE menu 
SET price = (price * 0.9)::int
where pizza_name = 'greek pizza'
returning *;
