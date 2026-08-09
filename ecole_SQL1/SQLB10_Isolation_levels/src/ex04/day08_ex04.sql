                -- session 1													-- session 2
BEGIN; SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
															BEGIN; SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
															UPDATE pizzeria SET rating = 3.0 WHERE name = 'Pizza Hut';
															COMMIT;
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
COMMIT;
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
															SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
															
																
