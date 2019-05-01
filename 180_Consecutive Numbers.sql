select distinct l1.num as ConsecutiveNums
from logs l1 join logs l2 on l1.ID+1 = l2.ID 
join logs l3 on l2.ID+1 = l3.ID
where l1.num = l2.num and l1.num = l3.num