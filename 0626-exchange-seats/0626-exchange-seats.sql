# Write your MySQL query statement below
select
    case
        when id%2!=0 and id!= (select max(id) from Seat) then id+1
        when id%2=0 then id-1
        else id
    END as id


    , student
from Seat

order by id ASC;