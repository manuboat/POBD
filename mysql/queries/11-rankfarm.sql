select f.IDFarm, f.Name as 'Name', sum(p.Amount) as 'Supplied', f.Owner ,f.Address, p.Date 
from Produced as p , Farm as f
where f.IDFarm = p.IDFarm
group by f.IDFarm
order by Supplied desc;


