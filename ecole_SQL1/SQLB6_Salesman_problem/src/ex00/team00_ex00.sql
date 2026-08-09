DROP TABLE IF EXISTS roads CASCADE;

CREATE TABLE IF NOT EXISTS roads (
    point1 varchar,
    point2 varchar,
    cost INTEGER
);

INSERT INTO roads (point1, point2, cost)
VALUES
    ('a', 'b', 10),
    ('b', 'a', 10),
    ('a', 'c', 15),
    ('c', 'a', 15),
    ('a', 'd', 20),
    ('d', 'a', 20),
    ('b', 'd', 25),
    ('d', 'b', 25),
    ('d', 'c', 30),
    ('c', 'd', 30),
    ('b', 'c', 35),
    ('c', 'b', 35);

CREATE MATERIALIZED VIEW valid_paths as 
	WITH RECURSIVE all_paths AS (
        SELECT
            point1,
            point2,
            COST,
            (point1 || ',' || point2) AS path,
            1 AS deep
        FROM
            roads r
        WHERE
            point1 = 'a'
        UNION
        SELECT
            r.point1,
            r.point2,
            p.cost + r.cost AS
            COST,
            (p.path || ',' || r.point2) AS path,
            p.deep + 1 AS deep
        FROM
            all_paths p
            JOIN roads r ON p.point2 = r.point1
        WHERE
            r.point2 != p.point1
            AND deep < 4
)

        SELECT
            cost AS total_cost,
            path AS tour
        FROM
            all_paths
        WHERE
            point2 = 'a' AND
			deep = 4;

WITH costs as (
	select total_cost from valid_paths
)

select total_cost, '{' || tour || '}' as tour from valid_paths 
where total_cost = (SELECT MIN(total_cost) as min_cost from costs)
ORDER BY 1,2;
