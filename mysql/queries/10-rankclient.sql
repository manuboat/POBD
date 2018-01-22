-- Ocupacy
select c.IDCostumer, c.Name as 'Name', r.Consumption, c.Phone,c.Mail
from (
select w.IDCostumer, s.IDOrder ,s.Cost as 'Consumption'
from TOrder as s
natural join Makes as w
where s.IDOrder = w.IDOrder
group by w.IDCostumer) as r, Costumer as c
where r.IDCostumer = c.IDCostumer
group by r.Consumption 
ORDER BY r.consumption desc;
