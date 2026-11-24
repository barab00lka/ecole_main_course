CREATE OR REPLACE VIEW v_symmetric_union AS
WITH R AS (
    SELECT *
    FROM person_visits
    WHERE visit_date = '2022-01-02'
),
S AS (
    SELECT *
    FROM person_visits
    WHERE visit_date = '2022-01-06'
)
SELECT
    COALESCE(R.person_id, S.person_id) AS person_id
FROM
    R
    FULL JOIN S ON R.person_id = S.person_id
WHERE
    R.person_id IS NULL OR S.person_id IS NULL
ORDER BY 1;
