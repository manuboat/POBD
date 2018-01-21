-- Select the plant ID's from Include and cross with the ID in Plant. Do not repeat

select * from
(
	select p.Type as 'Manel'
	from Plant as p, Produced as i
	where i.IDPlant = p.IDPlant) as t
group by Manel
    