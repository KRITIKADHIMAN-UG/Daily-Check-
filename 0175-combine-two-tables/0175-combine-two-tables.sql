# Write your MySQL query statement 
SELECT P.FirstName, P.lastName, A.city, A.state
FROM Person P
LEFT JOIN Address A USING (PersonId)