			-- session 1											-- session 2
BEGIN; SET TRANSACTION ISOLATION LEVEL REPEATABLE READ;

															BEGIN; SET TRANSACTION ISOLATION LEVEL REPEATABLE READ;

SELECT sum(rating) FROM pizzeria;

															INSERT into pizzeria values (11,'Kazan Pizza 2', 4);
															COMMIT;

SELECT sum(rating) FROM pizzeria;
COMMIT;
SELECT sum(rating) FROM pizzeria;

															SELECT sum(rating) FROM pizzeria;
