SELECT
    name AS Customers
FROM
    customers
WHERE NOT EXISTS
(
    SELECT
        customerId
    FROM
        orders
    WHERE
        customers.id = orders.customerId
);