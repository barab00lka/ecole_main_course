CREATE OR REPLACE FUNCTION fnc_fibonacci(pstop int default 10)
RETURNS SETOF int
LANGUAGE SQL
AS $$
	WITH RECURSIVE t(a,b) AS (
		VALUES (0,1)
	UNION ALL
		SELECT greatest(a,b), a+b as a from t
		WHERE b < $1
	)
	select a FROM t;
$$;

SELECT * FROM fnc_fibonacci(22);
