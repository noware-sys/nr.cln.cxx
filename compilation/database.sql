-- Adminer 4.2.1 SQLite 3 dump

DROP TABLE IF EXISTS "Entities";
CREATE TABLE "Entities"
(
	"Group" none NOT NULL DEFAULT '',
	"Name" none NOT NULL,
	"Reference" none NULL DEFAULT NULL,
	"Content" none NULL DEFAULT NULL
);

CREATE UNIQUE INDEX "Uniqueness" ON "Entities" ("Group", "Name");


-- 
