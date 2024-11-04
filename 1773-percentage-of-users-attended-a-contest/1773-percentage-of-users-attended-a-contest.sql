# Write your MySQL query statement below
SELECT
    r.contest_id,
    ROUND(COUNT(*) * 100.0 / (SELECT COUNT(*) FROM users), 2) AS percentage
FROM
    users u
INNER JOIN
    register r ON u.user_id = r.user_id
GROUP BY
    r.contest_id
ORDER BY
    percentage DESC,
    r.contest_id ASC;