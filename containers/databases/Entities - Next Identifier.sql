-- sed 's/"/\\"/g' 'Entities - Next Identifier.sql' | sed 's/$/\\n\\/' -

SELECT DISTINCT
	-- "T1"."ID" AS "Original", "T1"."ID" + 1 AS "Next", TYPEOF ("T1"."ID") AS "Type"
	"T1"."ID" + 1 AS "ID"
FROM
		(
			SELECT DISTINCT
				0 AS "ID"
			
			UNION
			
			SELECT DISTINCT
				"T4"."Group" AS "ID"
			FROM
				"Entities" AS "T4"
			WHERE
				"T4"."Group" IS NOT NULL
				AND
				TYPEOF ("T4"."Group") = 'integer'
			
			ORDER BY
				"ID" ASC
		) AS "T1"
	LEFT OUTER JOIN
		(
			SELECT DISTINCT
				0 AS "ID"
			
			UNION
			
			SELECT DISTINCT
				"T4"."Group" AS "ID"
			FROM
				"Entities" AS "T4"
			WHERE
				"T4"."Group" IS NOT NULL
				AND
				TYPEOF ("T4"."Group") = 'integer'
			
			ORDER BY
				"ID" ASC
		) AS "T2"
			ON "T1"."ID" = "T2"."ID" - 1
WHERE
	"T2"."ID" IS NULL
	AND
	"T1"."ID" + 1 >= 1
ORDER BY "T1"."ID" ASC

LIMIT 1
