# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below

DELETE
    T1
FROM
    Person T1, Person T2
WHERE
    T1.email = T2.email
    AND
    T1.id > T2.id
    