-- Ultima Order, para ele saber qual e o numero da order a seguir
-- SELECT fields FROM table ORDER BY id DESC LIMIT 1

select MAX(IDOrder) from TOrder;