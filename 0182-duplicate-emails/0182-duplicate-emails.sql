# Write your MySQL query statement below
SELECT Email as Email
FROM Person
GROUP BY Email
HAVING Count(Email)>1;