-- Da o storage time apartir do plant ID
-- 1: Data a que a plant foi armazenada
-- 2: Storage time from Plant
-- 3: Subtract 1 with currdate and see if it is larger

select (pp.MST - datediff(current_date(), p.Date))
from Produced as p, Plant as pp
where p.ID_Plant=1
and p.ID_Plant=pp.ID_Plant