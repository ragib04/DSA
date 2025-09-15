# Write your MySQL query statement below
SELECT P.FIRSTNAME, P.lastName, A.city, A.state from person p left Join Address A on P.personId = A.personId