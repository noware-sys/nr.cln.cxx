CREATE VIEW "Entities: Sequence: Groups: Available" AS
WITH RECURSIVE
	"Sequence"
	(
		"ID"
	)
	AS
	(
		SELECT
			COALESCE
			(
				(
					SELECT
						MIN ("ID") - 1
				),
				1
			)
		FROM
			"Entities: Sequence: Groups: Used"
		
		UNION ALL
		
		SELECT
			"ID" + 1
		FROM
			"Sequence"
		WHERE
			"ID" <=
			(
				SELECT
					MAX ("ID")
				FROM
					"Entities: Sequence: Groups: Used"
			)
	)
SELECT
	*
FROM
	"Sequence"
WHERE
	"ID" NOT IN
	(
		SELECT
			"ID"
		FROM
			"Entities: Sequence: Groups: Used"
	);
