select p.IDPlant as 'id', p.Name, p.Variety, p.Type, p.MST, p.Family
from Plant as p, Produced as pp
where p.Name = 'Tomato'
and p.IDPlant = pp.IDPlant
