-- SELECT
--     user_id,
--     MAX(CASE WHEN rn = 1 THEN plan_name END) AS current_plan,
--     MAX(CASE WHEN rn = 1 THEN monthly_amount END) AS current_monthly_amount,
--     MAX(monthly_amount) AS max_historical_amount,
--     DATEDIFF(MAX(event_date), MIN(event_date)) AS days_as_subscriber
-- FROM (
--     SELECT
--         se.*,
--         ROW_NUMBER() OVER (
--             PARTITION BY user_id
--             ORDER BY event_date DESC
--         ) AS rn
--     FROM subscription_events se
-- ) x
-- GROUP BY user_id
-- HAVING
--     COUNT(CASE WHEN event_type = 'downgrade' THEN 1 END) > 0
--     AND COUNT(CASE WHEN rn = 1 AND event_type != 'cancel' THEN 1 END) > 0
--     AND MAX(CASE WHEN rn = 1 THEN monthly_amount END) < 0.5 * MAX(monthly_amount)
--     AND DATEDIFF(MAX(event_date), MIN(event_date)) >= 60
-- ORDER BY days_as_subscriber DESC, user_id ASC;

-- ### SAI Solution
-- LeetCode 3216

with CTE as
(
	select
		*,
        min(event_date) over(partition by user_id) first_date,
		max(event_date) over(partition by user_id) last_date,
        max(monthly_amount) over(partition by user_id) max_revenue,
        last_value(event_type) over(partition by user_id order by event_date rows between
			current row and unbounded following) last_event
	from subscription_events
)

select
	user_id,
    plan_name current_plan,
    monthly_amount current_monthly_amount,
    max_revenue max_historical_amount,
    datediff(last_date,first_date) days_as_subscriber
from cte
where last_date = event_date and 
last_event != "cancel" and 
monthly_amount/max_revenue*100 <= 50
and datediff(last_date,first_date) >= 60 
and user_id in(select user_id from subscription_events where event_type = "downgrade")
order by days_as_subscriber desc, user_id