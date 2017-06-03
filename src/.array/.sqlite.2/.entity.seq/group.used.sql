CREATE VIEW "Entities: Sequence: Groups: Used" AS
SELECT
	"Group" AS "ID"
FROM
	"Entities"
WHERE
	TYPEOF ("Group") = 'integer'

UNION ALL

SELECT
	"Content"
FROM
	"Entities"
WHERE
	"Content: Type" = 1
AND
	TYPEOF ("Content") = 'integer';
