-- Select the plant ID's from Include and cross with the ID in Plant. Do not repeat
select p.Name as 'Name'
from Plant as p, Include as i
where i.ID_Plant = p.ID_Plant
group by Name;