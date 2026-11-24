			-- session 1											-- session 2
BEGIN; 

															BEGIN; 

UPDATE pizzeria SET rating = 5 WHERE id = 1;
															UPDATE pizzeria SET rating = 3 WHERE id = 2;
UPDATE pizzeria SET rating = 2 WHERE id = 2;
															UPDATE pizzeria SET rating = 4 WHERE id = 1;
COMMIT;
															COMMIT;
