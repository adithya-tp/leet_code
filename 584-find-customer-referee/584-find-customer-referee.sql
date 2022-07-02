SELECT
    name
FROM
    customer
WHERE
    referee_id IS NULL or referee_id <> 2
;