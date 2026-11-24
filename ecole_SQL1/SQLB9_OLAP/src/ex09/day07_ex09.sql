SELECT
    address,
	TRIM(TRAILING '.' FROM
			     TRIM(TRAILING '0' FROM round(formula,2)::text)
			)::numeric as formula,
	TRIM(TRAILING '.' FROM
			     TRIM(TRAILING '0' FROM ROUND(average, 2)::text)
		)::numeric as average,

    (formula > average) AS comparison
FROM (
    SELECT
        a.address,
        MAX(a.age)::numeric - MIN(a.age)::numeric / MAX(a.age)::numeric AS formula,
		AVG(age)::numeric AS average
    FROM (select p.address, p.age from person p) a
    GROUP BY a.address
	order by 1
);
