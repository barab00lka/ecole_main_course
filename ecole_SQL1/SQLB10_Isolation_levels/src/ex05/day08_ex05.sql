			-- session 1											-- session 2
BEGIN; SET TRANSACTION ISOLATION LEVEL READ COMMITTED;

															BEGIN; SET TRANSACTION ISOLATION LEVEL READ COMMITTED;

SELECT sum(rating) FROM pizzeria;

															INSERT into pizzeria values (10,'Kazan Pizza', 5);
															COMMIT;

SELECT sum(rating) FROM pizzeria;
COMMIT;
SELECT sum(rating) FROM pizzeria;

															SELECT sum(rating) FROM pizzeria;
											
												

