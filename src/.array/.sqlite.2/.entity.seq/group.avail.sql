CREATE VIEW "Entities: Sequence: Group: Next: Available" AS
-- "Order", "Sequence"
SELECT
	DISTINCT
	"T1"."ID" + 1 AS "ID"
FROM
(
	SELECT
		1 AS "ID"
	
	UNION ALL
	
	SELECT
		"Group"
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
		TYPEOF ("Content") = 'integer'
	
	ORDER BY
		1 ASC
) AS "T1"
LEFT OUTER JOIN
(
	SELECT
		1 AS "ID"
	
	UNION ALL
	
	SELECT
		"Group"
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
		TYPEOF ("Content") = 'integer'
	
	ORDER BY
		1 ASC
) AS "T2"
ON
	"T1"."ID" = "T2"."ID" - 1
WHERE
	"T2"."ID" IS NULL
AND
	"T1"."ID" + 1 >= 1
ORDER BY
	"T1"."ID" ASC
LIMIT 1;
