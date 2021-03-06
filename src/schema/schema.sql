CREATE TABLE REF_TASK_TYPE
  (
    ID             INTEGER NOT NULL ,
    NAME           VARCHAR2 (4000) NOT NULL ,
    DESCR          VARCHAR2 (4000) NOT NULL ,
    ISRT_TMSTMP    TIMESTAMP NOT NULL ,
    LST_UPD_TMSTMP TIMESTAMP NOT NULL,
    PRIMARY KEY ( ID )
  ) ;
CREATE TABLE TASK
  (
    ID             VARCHAR2 (4000) NOT NULL ,
    BOX            VARCHAR2 (4000) NOT NULL ,
    TYPE           INTEGER NOT NULL ,
    ISRT_TMSTMP    TIMESTAMP NOT NULL ,
    LST_UPD_TMSTMP TIMESTAMP NOT NULL,
    PRIMARY KEY ( ID ),
    /* NOTE! FOREIGN KEY ( BOX ) REFERENCES BOX ( ID ), */
    FOREIGN KEY ( TYPE ) REFERENCES REF_TASK_TYPE ( ID )
  ) ;
