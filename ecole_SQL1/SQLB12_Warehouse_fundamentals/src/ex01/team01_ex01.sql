insert into currency values (100, 'EUR', 0.85, '2022-01-01 13:29');
insert into currency values (100, 'EUR', 0.79, '2022-01-08 13:29');

CREATE FUNCTION fnc_currency_prev_rate_to_usd(pcurrency_id BIGINT, pupdated TIMESTAMP) 
    RETURNS NUMERIC
AS $$ 
    SELECT rate_to_usd
    FROM currency
    WHERE id = pcurrency_id AND updated <= pupdated
    ORDER BY updated DESC
    LIMIT 1
$$ LANGUAGE SQL;

CREATE FUNCTION fnc_currency_next_rate_to_usd(pcurrency_id BIGINT, pupdated TIMESTAMP) 
RETURNS NUMERIC
AS $$
    SELECT rate_to_usd
    FROM currency
    WHERE id = pcurrency_id AND updated > pupdated
    ORDER BY updated ASC
    LIMIT 1
$$ LANGUAGE SQL;

SELECT
    COALESCE("user".name, 'not defined') AS name,
    COALESCE("user".lastname, 'not defined') AS lastname,
    currency.name AS currency_name,
    CAST(balance.money * COALESCE(
        fnc_currency_prev_rate_to_usd(currency.id, balance.updated), 
        fnc_currency_next_rate_to_usd(currency.id, balance.updated)
    ) AS REAL) AS currency_in_usd
FROM balance
LEFT JOIN "user" 
    ON balance.user_id = "user".id
INNER JOIN (SELECT DISTINCT id, name FROM currency) as currency
    ON balance.currency_id = currency.id
ORDER BY name DESC, lastname, currency_name ASC;
