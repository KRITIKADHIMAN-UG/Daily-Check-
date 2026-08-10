# Write your MySQL query statement below
SELECT E1.name AS Employee
FROM Employee E1 JOIN Employee E2
ON E1.Managerid = E2.id AND E1.Salary > E2.Salary;