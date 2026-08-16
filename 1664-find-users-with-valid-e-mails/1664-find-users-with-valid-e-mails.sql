# Write your MySQL query statement below
-- SELECT *
-- FROM Users u
-- WHERE REGEXP_LIKE(u.mail, "^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\\.com$", 'c');


SELECT *
FROM Users u
WHERE
u.mail REGEXP "^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\.com$"
AND
u.mail LIKE BINARY "%@leetcode.com";