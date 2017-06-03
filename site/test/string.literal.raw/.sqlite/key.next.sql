CREATE VIEW if not exists
	"entity.key.next.seq"
AS
SELECT DISTINCT
	"id"
from
	"entity.group.usage.seq"

	"Group",
	(
		SELECT DISTINCT
			"T1"."ID" + 1 AS "ID"
		FROM
		(
			SELECT
				0 AS "ID"
		
			UNION ALL
		
			SELECT DISTINCT
				"T4"."Name" AS "ID"
			FROM
				"Entities" AS "T4"
			WHERE
				"T4"."Name" IS NOT NULL
				AND
				TYPEOF ("T4"."Name") = 'integer'
				AND
				"T4"."Group" = "Outer"."Group"
			ORDER BY
				"ID" ASC
		)
		AS "T1"
		LEFT OUTER JOIN
		(
			SELECT
				0 AS "ID"
		
			UNION ALL
		
			SELECT DISTINCT
				"T4"."Name" AS "ID"
			FROM
				"Entities" AS "T4"
			WHERE
				"T4"."Name" IS NOT NULL
				AND
				TYPEOF ("T4"."Name") = 'integer'
				AND
				"T4"."Group" = "Outer"."Group"
				ORDER BY
				"ID" ASC
		)
		AS "T2"
		ON
			"T1"."ID" = "T2"."ID" - 1
		WHERE
			"T2"."ID" IS NULL
			AND
			"T1"."ID" + 1 >= 0
		ORDER BY
			"T1"."ID" ASC
		LIMIT 1
	) AS "Name"
FROM
	"Entities" AS "Outer";
