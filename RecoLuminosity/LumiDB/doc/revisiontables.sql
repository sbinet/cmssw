CREATE TABLE "REVISIONS"
("REVISION_ID" NUMBER(20,0),
"BRANCH_ID" NUMBER(20,0),
"NAME" VARCHAR2(56),
"BRANCH_NAME" VARCHAR2(4000),
"COMMENT" VARCHAR2(1024),
"CTIME" TIMESTAMP (6),
 CONSTRAINT "REVISIONS_PK" PRIMARY KEY ("REVISION_ID")
);
GRANT SELECT ON "REVISIONS" TO PUBLIC;	
GRANT SELECT,INSERT,DELETE,UPDATE ON "REVISIONS" TO CMS_LUMI_WRITER;
create index REVISIONS_BRANCH_NAME_IDX on REVISIONS(BRANCH_NAME);
