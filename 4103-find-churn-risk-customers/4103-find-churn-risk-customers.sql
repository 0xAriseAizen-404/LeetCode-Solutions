SELECT
    user_id,
    MAX(CASE WHEN rn = 1 THEN plan_name END) AS current_plan,
    MAX(CASE WHEN rn = 1 THEN monthly_amount END) AS current_monthly_amount,
    MAX(monthly_amount) AS max_historical_amount,
    DATEDIFF(MAX(event_date), MIN(event_date)) AS days_as_subscriber
FROM (
    SELECT
        se.*,
        ROW_NUMBER() OVER (
            PARTITION BY user_id
            ORDER BY event_date DESC
        ) AS rn
    FROM subscription_events se
) x
GROUP BY user_id
HAVING
    COUNT(CASE WHEN event_type = 'downgrade' THEN 1 END) > 0
    AND COUNT(CASE WHEN rn = 1 AND event_type != 'cancel' THEN 1 END) > 0
    AND MAX(CASE WHEN rn = 1 THEN monthly_amount END) < 0.5 * MAX(monthly_amount)
    AND DATEDIFF(MAX(event_date), MIN(event_date)) >= 60
ORDER BY days_as_subscriber DESC, user_id ASC;