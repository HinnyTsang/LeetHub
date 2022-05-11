# Write your MySQL query statement below
# update the table.

UPDATE 
    Salary
SET 
    sex = IF(sex = 'f', 'm', 'f');

# UPDATE 
#     Salary
# SET sex = (
#     CASE WHEN
#         sex='f' 
#     THEN
#         'm'
#     ELSE
#         'f'
#     END
# );
