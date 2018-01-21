-- Ocupacy
select s.IDWarehouse, w.Location, s.Stored, w.Capacity
from (
	select pp.IDWarehouse, sum(pp.Amount) as 'Stored'
	from  Produced as pp
	group by pp.IDWarehouse) as s, Warehouse as w
where s.IDWarehouse = w.IDWarehouse