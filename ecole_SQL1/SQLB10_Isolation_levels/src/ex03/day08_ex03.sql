                -- session 1													-- session 2
BEGIN; SET TRANSACTION ISOLATION LEVEL READ COMMITTED;
															BEGIN; SET TRANSACTION ISOLATION LEVEL READ COMMITTED;
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
															UPDATE pizzeria SET rating = 3.6 WHERE name = 'Pizza Hut';
															COMMIT;
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
COMMIT;
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
															SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
															
																
