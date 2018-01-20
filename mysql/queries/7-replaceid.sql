select Plant
from(

select p.Name as 'Plant', f.Name as 'Farm', w.Location as 'Warehouse',
pp.Amount as 'Amount', pp.UnitPrice as 'Unit Price', pp.Date as 'Entry Date'
from Plant as p, Farm as f, Warehouse as w, Produced as pp
where p.IDPlant = pp.IDPlant 
and f.IDFarm = pp.IDFarm
and w.IDWarehouse = pp.IDWarehouse
and pp.Amount > 30) as t