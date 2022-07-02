SELECT
    name
FROM
    customer
WHERE
    referee_id is NULL or referee_id != 2
;