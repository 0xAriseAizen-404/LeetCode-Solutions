# Write your MySQL query statement below
SELECT unique_id ,name
FROM Employees
left OUTER JOIN EmployeeUNI
ON EmployeeUNI.id = Employees.id;
