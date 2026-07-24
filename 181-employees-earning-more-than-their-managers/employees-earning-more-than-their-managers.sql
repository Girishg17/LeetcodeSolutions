# Write your MySQL query statement below
SELECT name as Employee from Employee  e where e.salary > (select salary  from Employee  d where e.managerId = d.id);