SELECT
   v.generated_date as missing_date
FROM
    v_generated_dates v
EXCEPT (
    SELECT
        visit_date
    FROM
        person_visits po
    WHERE
        visit_date >= '2022-01-01'::date
        AND visit_date < '2023-01-01'::date
    GROUP BY
        1)
ORDER BY
    1;
