-- Ultima Order, para ele saber qual e o numero da order a seguir
-- SELECT fields FROM table ORDER BY id DESC LIMIT 1

select MAX(ID_Order) from T_Order;