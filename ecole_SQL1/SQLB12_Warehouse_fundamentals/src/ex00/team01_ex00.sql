CREATE FUNCTION fnc_last_rate_to_usd (pcurrency_id BIGINT) RETURNS NUMERIC AS $$
  SELECT
    rate_to_usd
  FROM
    currency
  WHERE
    id = pcurrency_id
  ORDER BY
    updated DESC
  LIMIT 1;
$$ LANGUAGE SQL;

WITH 
volume_data AS (
    SELECT 
        user_id, 
        type, 
        SUM(money) AS volume, 
        currency_id
    FROM balance
    GROUP BY user_id, type, currency_id
)
SELECT DISTINCT
    COALESCE("user".name, 'not defined') AS name,
    COALESCE("user".lastname, 'not defined') AS lastname,
    volume_data.type,
    volume_data.volume,
    COALESCE(currency.name, 'not defined') AS currency_name,
    COALESCE(fnc_last_rate_to_usd(volume_data.currency_id), 1) AS last_rate_to_usd,
    (volume_data.volume * COALESCE(fnc_last_rate_to_usd(volume_data.currency_id), 1))::float AS total_volume_in_usd
FROM volume_data
LEFT JOIN "user" on volume_data.user_id = "user".id
LEFT JOIN currency 
    ON volume_data.currency_id = currency.id
ORDER BY name DESC, lastname, type ASC;
