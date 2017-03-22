SELECT DISTINCT\n\
	-- \"T1\".\"ID\" AS \"Original\", \"T1\".\"ID\" + 1 AS \"Next\", TYPEOF (\"T1\".\"ID\") AS \"Type\"\n\
	\"T1\".\"ID\" + 1 AS \"ID\"\n\
FROM\n\
		(\n\
			SELECT DISTINCT\n\
				0 AS \"ID\"\n\
			\n\
			UNION\n\
			\n\
			SELECT DISTINCT\n\
				\"T4\".\"Group\" AS \"ID\"\n\
			FROM\n\
				\"Entities\" AS \"T4\"\n\
			WHERE\n\
				\"T4\".\"Group\" IS NOT NULL\n\
				AND\n\
				TYPEOF (\"T4\".\"Group\") = 'integer'\n\
			\n\
			ORDER BY\n\
				\"ID\" ASC\n\
		) AS \"T1\"\n\
	LEFT OUTER JOIN\n\
		(\n\
			SELECT DISTINCT\n\
				0 AS \"ID\"\n\
			\n\
			UNION\n\
			\n\
			SELECT DISTINCT\n\
				\"T4\".\"Group\" AS \"ID\"\n\
			FROM\n\
				\"Entities\" AS \"T4\"\n\
			WHERE\n\
				\"T4\".\"Group\" IS NOT NULL\n\
				AND\n\
				TYPEOF (\"T4\".\"Group\") = 'integer'\n\
			\n\
			ORDER BY\n\
				\"ID\" ASC\n\
		) AS \"T2\"\n\
			ON \"T1\".\"ID\" = \"T2\".\"ID\" - 1\n\
WHERE\n\
	\"T2\".\"ID\" IS NULL\n\
	AND\n\
	\"T1\".\"ID\" + 1 >= 1\n\
ORDER BY \"T1\".\"ID\" ASC\n\
\n\
LIMIT 1\n\
