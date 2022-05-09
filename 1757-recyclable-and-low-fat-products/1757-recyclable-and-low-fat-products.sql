# Write your MySQL query statement below
SELECT
    product_id
FROM
    Products
WHERE
    FIELD(low_fats, "Y")
    AND
    FIELD(recyclable, "Y")