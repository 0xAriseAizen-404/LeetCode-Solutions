-- My Version
SELECT 
    contest_id, 
    ROUND(COUNT(*) * 100 / (SELECT COUNT(*) FROM users), 2) AS percentage
FROM register
GROUP BY contest_id
ORDER BY percentage DESC, contest_id ASC;

-- ChatGPT Version
-- SELECT 
--     r.contest_id, 
--     ROUND(COUNT(DISTINCT r.user_id) * 100.0 / (SELECT COUNT(*) FROM users), 2) AS percentage
-- FROM register AS r
-- GROUP BY r.contest_id
-- ORDER BY percentage DESC, r.contest_id ASC;
