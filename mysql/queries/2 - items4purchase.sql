-- Select the plant ID's from Include and cross with the ID in Plant. Do not repeat

select * from
(
	select p.Name as 'Name'
	from Plant as p, Produced as i
	where i.IDPlant = p.IDPlant) as t
group by Name
    