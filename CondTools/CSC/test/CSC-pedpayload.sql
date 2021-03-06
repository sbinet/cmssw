-- Create payload object tables generated from CSCPedestals-mapping-custom.xml
CREATE TABLE CMS_COND_CSC."CSCPEDESTALS" ( "IOV_VALUE_ID" NUMBER(10), CONSTRAINT "CSCPEDESTALS_PK" PRIMARY KEY ( "IOV_VALUE_ID" ) );
CREATE TABLE CMS_COND_CSC."CSCPEDESTALS_MAP" ( "MAP_ID" NUMBER(10) NOT NULL, "IOV_VALUE_ID" NUMBER(10) NOT NULL, "CSC_INT_ID" NUMBER(10) NOT NULL, CONSTRAINT "CSCPEDESTALS_MAP_PK" PRIMARY KEY ( "IOV_VALUE_ID","MAP_ID" ), CONSTRAINT "CSCPEDESTALS_MAP_ID_FK" FOREIGN KEY ( "IOV_VALUE_ID" ) REFERENCES CMS_COND_CSC."CSCPEDESTALS" ( "IOV_VALUE_ID" ) );
CREATE TABLE CMS_COND_CSC."CSCPEDESTALS_DATA" ( "VEC_INDEX" NUMBER(10) NOT NULL, "MAP_ID" NUMBER(10) NOT NULL, "IOV_VALUE_ID" NUMBER(10) NOT NULL, "PEDESTALS_PED" BINARY_FLOAT NOT NULL, "PEDESTALS_RMS" BINARY_FLOAT NOT NULL, CONSTRAINT "CSCPEDESTALS_DATA_PK" PRIMARY KEY ( "IOV_VALUE_ID","MAP_ID","VEC_INDEX" ), CONSTRAINT "CSCPEDESTALS_DATA_ID_FK" FOREIGN KEY ( "IOV_VALUE_ID","MAP_ID" ) REFERENCES CMS_COND_CSC."CSCPEDESTALS_MAP" ( "IOV_VALUE_ID","MAP_ID" ) );

-- Add TIME column for IOV
ALTER TABLE CMS_COND_CSC."CSCPEDESTALS" ADD "TIME" NUMBER(10);

