/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_BASE_YY_THIRD_PARTY_LIBPG_QUERY_GRAMMAR_GRAMMAR_OUT_HPP_INCLUDED
# define YY_BASE_YY_THIRD_PARTY_LIBPG_QUERY_GRAMMAR_GRAMMAR_OUT_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int base_yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENT = 258,                   /* IDENT  */
    FCONST = 259,                  /* FCONST  */
    SCONST = 260,                  /* SCONST  */
    BCONST = 261,                  /* BCONST  */
    XCONST = 262,                  /* XCONST  */
    Op = 263,                      /* Op  */
    ICONST = 264,                  /* ICONST  */
    PARAM = 265,                   /* PARAM  */
    TYPECAST = 266,                /* TYPECAST  */
    DOT_DOT = 267,                 /* DOT_DOT  */
    COLON_EQUALS = 268,            /* COLON_EQUALS  */
    EQUALS_GREATER = 269,          /* EQUALS_GREATER  */
    INTEGER_DIVISION = 270,        /* INTEGER_DIVISION  */
    POWER_OF = 271,                /* POWER_OF  */
    SINGLE_ARROW = 272,            /* SINGLE_ARROW  */
    DOUBLE_ARROW = 273,            /* DOUBLE_ARROW  */
    SINGLE_COLON = 274,            /* SINGLE_COLON  */
    LESS_EQUALS = 275,             /* LESS_EQUALS  */
    GREATER_EQUALS = 276,          /* GREATER_EQUALS  */
    NOT_EQUALS = 277,              /* NOT_EQUALS  */
    ABORT_P = 278,                 /* ABORT_P  */
    ABSOLUTE_P = 279,              /* ABSOLUTE_P  */
    ACCESS = 280,                  /* ACCESS  */
    ACTION = 281,                  /* ACTION  */
    ADD_P = 282,                   /* ADD_P  */
    ADMIN = 283,                   /* ADMIN  */
    AFTER = 284,                   /* AFTER  */
    AGGREGATE = 285,               /* AGGREGATE  */
    ALL = 286,                     /* ALL  */
    ALSO = 287,                    /* ALSO  */
    ALTER = 288,                   /* ALTER  */
    ALWAYS = 289,                  /* ALWAYS  */
    ANALYSE = 290,                 /* ANALYSE  */
    ANALYZE = 291,                 /* ANALYZE  */
    AND = 292,                     /* AND  */
    ANTI = 293,                    /* ANTI  */
    ANY = 294,                     /* ANY  */
    API = 295,                     /* API  */
    ARRAY = 296,                   /* ARRAY  */
    AS = 297,                      /* AS  */
    ASC_P = 298,                   /* ASC_P  */
    ASOF = 299,                    /* ASOF  */
    ASSERTION = 300,               /* ASSERTION  */
    ASSIGNMENT = 301,              /* ASSIGNMENT  */
    ASYMMETRIC = 302,              /* ASYMMETRIC  */
    AT = 303,                      /* AT  */
    ATTACH = 304,                  /* ATTACH  */
    ATTRIBUTE = 305,               /* ATTRIBUTE  */
    AUTHORIZATION = 306,           /* AUTHORIZATION  */
    BACKWARD = 307,                /* BACKWARD  */
    BEFORE = 308,                  /* BEFORE  */
    BEGIN_P = 309,                 /* BEGIN_P  */
    BETWEEN = 310,                 /* BETWEEN  */
    BIGINT = 311,                  /* BIGINT  */
    BINARY = 312,                  /* BINARY  */
    BIT = 313,                     /* BIT  */
    BOOLEAN_P = 314,               /* BOOLEAN_P  */
    BOTH = 315,                    /* BOTH  */
    BY = 316,                      /* BY  */
    CACHE = 317,                   /* CACHE  */
    CALL_P = 318,                  /* CALL_P  */
    CALLED = 319,                  /* CALLED  */
    CASCADE = 320,                 /* CASCADE  */
    CASCADED = 321,                /* CASCADED  */
    CASE = 322,                    /* CASE  */
    CAST = 323,                    /* CAST  */
    CATALOG_P = 324,               /* CATALOG_P  */
    CENTURIES_P = 325,             /* CENTURIES_P  */
    CENTURY_P = 326,               /* CENTURY_P  */
    CHAIN = 327,                   /* CHAIN  */
    CHAR_P = 328,                  /* CHAR_P  */
    CHARACTER = 329,               /* CHARACTER  */
    CHARACTERISTICS = 330,         /* CHARACTERISTICS  */
    CHECK_P = 331,                 /* CHECK_P  */
    CHECKPOINT = 332,              /* CHECKPOINT  */
    CLASS = 333,                   /* CLASS  */
    CLOSE = 334,                   /* CLOSE  */
    CLUSTER = 335,                 /* CLUSTER  */
    COALESCE = 336,                /* COALESCE  */
    COLLATE = 337,                 /* COLLATE  */
    COLLATION = 338,               /* COLLATION  */
    COLUMN = 339,                  /* COLUMN  */
    COLUMNS = 340,                 /* COLUMNS  */
    COMMENT = 341,                 /* COMMENT  */
    COMMENTS = 342,                /* COMMENTS  */
    COMMIT = 343,                  /* COMMIT  */
    COMMITTED = 344,               /* COMMITTED  */
    COMPRESSION = 345,             /* COMPRESSION  */
    CONCURRENTLY = 346,            /* CONCURRENTLY  */
    CONFIGURATION = 347,           /* CONFIGURATION  */
    CONFLICT = 348,                /* CONFLICT  */
    CONNECTION = 349,              /* CONNECTION  */
    CONSTRAINT = 350,              /* CONSTRAINT  */
    CONSTRAINTS = 351,             /* CONSTRAINTS  */
    CONTENT_P = 352,               /* CONTENT_P  */
    CONTINUE_P = 353,              /* CONTINUE_P  */
    CONVERSION_P = 354,            /* CONVERSION_P  */
    COPY = 355,                    /* COPY  */
    COST = 356,                    /* COST  */
    CREATE_P = 357,                /* CREATE_P  */
    CROSS = 358,                   /* CROSS  */
    CSV = 359,                     /* CSV  */
    CUBE = 360,                    /* CUBE  */
    CURRENT_P = 361,               /* CURRENT_P  */
    CURSOR = 362,                  /* CURSOR  */
    CYCLE = 363,                   /* CYCLE  */
    DATA_P = 364,                  /* DATA_P  */
    DATABASE = 365,                /* DATABASE  */
    DAY_P = 366,                   /* DAY_P  */
    DAYS_P = 367,                  /* DAYS_P  */
    DEALLOCATE = 368,              /* DEALLOCATE  */
    DEC = 369,                     /* DEC  */
    DECADE_P = 370,                /* DECADE_P  */
    DECADES_P = 371,               /* DECADES_P  */
    DECIMAL_P = 372,               /* DECIMAL_P  */
    DECLARE = 373,                 /* DECLARE  */
    DEFAULT = 374,                 /* DEFAULT  */
    DEFAULTS = 375,                /* DEFAULTS  */
    DEFERRABLE = 376,              /* DEFERRABLE  */
    DEFERRED = 377,                /* DEFERRED  */
    DEFINER = 378,                 /* DEFINER  */
    DELETE_P = 379,                /* DELETE_P  */
    DELIMITER = 380,               /* DELIMITER  */
    DELIMITERS = 381,              /* DELIMITERS  */
    DEPENDS = 382,                 /* DEPENDS  */
    DESC_P = 383,                  /* DESC_P  */
    DESCRIBE = 384,                /* DESCRIBE  */
    DETACH = 385,                  /* DETACH  */
    DICTIONARY = 386,              /* DICTIONARY  */
    DISABLE_P = 387,               /* DISABLE_P  */
    DISCARD = 388,                 /* DISCARD  */
    DISTINCT = 389,                /* DISTINCT  */
    DO = 390,                      /* DO  */
    DOCUMENT_P = 391,              /* DOCUMENT_P  */
    DOMAIN_P = 392,                /* DOMAIN_P  */
    DOUBLE_P = 393,                /* DOUBLE_P  */
    DROP = 394,                    /* DROP  */
    EACH = 395,                    /* EACH  */
    EDGES = 396,                   /* EDGES  */
    ELSE = 397,                    /* ELSE  */
    ENABLE_P = 398,                /* ENABLE_P  */
    ENCODING = 399,                /* ENCODING  */
    ENCRYPTED = 400,               /* ENCRYPTED  */
    END_P = 401,                   /* END_P  */
    ENUM_P = 402,                  /* ENUM_P  */
    ESCAPE = 403,                  /* ESCAPE  */
    EVENT = 404,                   /* EVENT  */
    EXCEPT = 405,                  /* EXCEPT  */
    EXCLUDE = 406,                 /* EXCLUDE  */
    EXCLUDING = 407,               /* EXCLUDING  */
    EXCLUSIVE = 408,               /* EXCLUSIVE  */
    EXECUTE = 409,                 /* EXECUTE  */
    EXISTS = 410,                  /* EXISTS  */
    EXPLAIN = 411,                 /* EXPLAIN  */
    EXPORT_P = 412,                /* EXPORT_P  */
    EXPORT_STATE = 413,            /* EXPORT_STATE  */
    EXTENSION = 414,               /* EXTENSION  */
    EXTENSIONS = 415,              /* EXTENSIONS  */
    EXTERNAL = 416,                /* EXTERNAL  */
    EXTRACT = 417,                 /* EXTRACT  */
    FALSE_P = 418,                 /* FALSE_P  */
    FAMILY = 419,                  /* FAMILY  */
    FEATURES = 420,                /* FEATURES  */
    FETCH = 421,                   /* FETCH  */
    FILTER = 422,                  /* FILTER  */
    FIRST_P = 423,                 /* FIRST_P  */
    FLOAT_P = 424,                 /* FLOAT_P  */
    FOLLOWING = 425,               /* FOLLOWING  */
    FOR = 426,                     /* FOR  */
    FORCE = 427,                   /* FORCE  */
    FOREIGN = 428,                 /* FOREIGN  */
    FORWARD = 429,                 /* FORWARD  */
    FREEZE = 430,                  /* FREEZE  */
    FROM = 431,                    /* FROM  */
    FULL = 432,                    /* FULL  */
    FUNCTION = 433,                /* FUNCTION  */
    FUNCTIONS = 434,               /* FUNCTIONS  */
    GENERATED = 435,               /* GENERATED  */
    GLOB = 436,                    /* GLOB  */
    GLOBAL = 437,                  /* GLOBAL  */
    GNN = 438,                     /* GNN  */
    GRANT = 439,                   /* GRANT  */
    GRANTED = 440,                 /* GRANTED  */
    GROUP_P = 441,                 /* GROUP_P  */
    GROUPING = 442,                /* GROUPING  */
    GROUPING_ID = 443,             /* GROUPING_ID  */
    GROUPS = 444,                  /* GROUPS  */
    HANDLER = 445,                 /* HANDLER  */
    HAVING = 446,                  /* HAVING  */
    HEADER_P = 447,                /* HEADER_P  */
    HOLD = 448,                    /* HOLD  */
    HOUR_P = 449,                  /* HOUR_P  */
    HOURS_P = 450,                 /* HOURS_P  */
    IDENTITY_P = 451,              /* IDENTITY_P  */
    IF_P = 452,                    /* IF_P  */
    IGNORE_P = 453,                /* IGNORE_P  */
    ILIKE = 454,                   /* ILIKE  */
    IMMEDIATE = 455,               /* IMMEDIATE  */
    IMMUTABLE = 456,               /* IMMUTABLE  */
    IMPLICIT_P = 457,              /* IMPLICIT_P  */
    IMPORT_P = 458,                /* IMPORT_P  */
    IN_P = 459,                    /* IN_P  */
    INCLUDE_P = 460,               /* INCLUDE_P  */
    INCLUDING = 461,               /* INCLUDING  */
    INCREMENT = 462,               /* INCREMENT  */
    INDEX = 463,                   /* INDEX  */
    INDEXES = 464,                 /* INDEXES  */
    INHERIT = 465,                 /* INHERIT  */
    INHERITS = 466,                /* INHERITS  */
    INITIALLY = 467,               /* INITIALLY  */
    INLINE_P = 468,                /* INLINE_P  */
    INNER_P = 469,                 /* INNER_P  */
    INOUT = 470,                   /* INOUT  */
    INPUT_P = 471,                 /* INPUT_P  */
    INSENSITIVE = 472,             /* INSENSITIVE  */
    INSERT = 473,                  /* INSERT  */
    INSTALL = 474,                 /* INSTALL  */
    INSTEAD = 475,                 /* INSTEAD  */
    INT_P = 476,                   /* INT_P  */
    INTEGER = 477,                 /* INTEGER  */
    INTERSECT = 478,               /* INTERSECT  */
    INTERVAL = 479,                /* INTERVAL  */
    INTO = 480,                    /* INTO  */
    INVOKER = 481,                 /* INVOKER  */
    IS = 482,                      /* IS  */
    ISNULL = 483,                  /* ISNULL  */
    ISOLATION = 484,               /* ISOLATION  */
    JOIN = 485,                    /* JOIN  */
    JSON = 486,                    /* JSON  */
    KEY = 487,                     /* KEY  */
    LABEL = 488,                   /* LABEL  */
    LAMBDA = 489,                  /* LAMBDA  */
    LANGUAGE = 490,                /* LANGUAGE  */
    LARGE_P = 491,                 /* LARGE_P  */
    LAST_P = 492,                  /* LAST_P  */
    LATERAL_P = 493,               /* LATERAL_P  */
    LEADING = 494,                 /* LEADING  */
    LEAKPROOF = 495,               /* LEAKPROOF  */
    LEFT = 496,                    /* LEFT  */
    LEVEL = 497,                   /* LEVEL  */
    LIKE = 498,                    /* LIKE  */
    LIMIT = 499,                   /* LIMIT  */
    LISTEN = 500,                  /* LISTEN  */
    LLM = 501,                     /* LLM  */
    LM = 502,                      /* LM  */
    LOAD = 503,                    /* LOAD  */
    LOCAL = 504,                   /* LOCAL  */
    LOCATION = 505,                /* LOCATION  */
    LOCK_P = 506,                  /* LOCK_P  */
    LOCKED = 507,                  /* LOCKED  */
    LOGGED = 508,                  /* LOGGED  */
    MACRO = 509,                   /* MACRO  */
    MAP = 510,                     /* MAP  */
    MAPPING = 511,                 /* MAPPING  */
    MATCH = 512,                   /* MATCH  */
    MATERIALIZED = 513,            /* MATERIALIZED  */
    MAXVALUE = 514,                /* MAXVALUE  */
    METHOD = 515,                  /* METHOD  */
    MICROSECOND_P = 516,           /* MICROSECOND_P  */
    MICROSECONDS_P = 517,          /* MICROSECONDS_P  */
    MILLENNIA_P = 518,             /* MILLENNIA_P  */
    MILLENNIUM_P = 519,            /* MILLENNIUM_P  */
    MILLISECOND_P = 520,           /* MILLISECOND_P  */
    MILLISECONDS_P = 521,          /* MILLISECONDS_P  */
    MINUTE_P = 522,                /* MINUTE_P  */
    MINUTES_P = 523,               /* MINUTES_P  */
    MINVALUE = 524,                /* MINVALUE  */
    MODE = 525,                    /* MODE  */
    MODEL = 526,                   /* MODEL  */
    MONTH_P = 527,                 /* MONTH_P  */
    MONTHS_P = 528,                /* MONTHS_P  */
    MOVE = 529,                    /* MOVE  */
    NAME_P = 530,                  /* NAME_P  */
    NAMES = 531,                   /* NAMES  */
    NATIONAL = 532,                /* NATIONAL  */
    NATURAL = 533,                 /* NATURAL  */
    NCHAR = 534,                   /* NCHAR  */
    NEW = 535,                     /* NEW  */
    NEXT = 536,                    /* NEXT  */
    NO = 537,                      /* NO  */
    NODES = 538,                   /* NODES  */
    NONE = 539,                    /* NONE  */
    NOT = 540,                     /* NOT  */
    NOTHING = 541,                 /* NOTHING  */
    NOTIFY = 542,                  /* NOTIFY  */
    NOTNULL = 543,                 /* NOTNULL  */
    NOWAIT = 544,                  /* NOWAIT  */
    NULL_P = 545,                  /* NULL_P  */
    NULLIF = 546,                  /* NULLIF  */
    NULLS_P = 547,                 /* NULLS_P  */
    NUMERIC = 548,                 /* NUMERIC  */
    OBJECT_P = 549,                /* OBJECT_P  */
    OF = 550,                      /* OF  */
    OFF = 551,                     /* OFF  */
    OFFSET = 552,                  /* OFFSET  */
    OIDS = 553,                    /* OIDS  */
    OLD = 554,                     /* OLD  */
    ON = 555,                      /* ON  */
    ONLY = 556,                    /* ONLY  */
    OPERATOR = 557,                /* OPERATOR  */
    OPTION = 558,                  /* OPTION  */
    OPTIONS = 559,                 /* OPTIONS  */
    OR = 560,                      /* OR  */
    ORDER = 561,                   /* ORDER  */
    ORDINALITY = 562,              /* ORDINALITY  */
    OTHERS = 563,                  /* OTHERS  */
    OUT_P = 564,                   /* OUT_P  */
    OUTER_P = 565,                 /* OUTER_P  */
    OUTPUT = 566,                  /* OUTPUT  */
    OVER = 567,                    /* OVER  */
    OVERLAPS = 568,                /* OVERLAPS  */
    OVERLAY = 569,                 /* OVERLAY  */
    OVERRIDING = 570,              /* OVERRIDING  */
    OWNED = 571,                   /* OWNED  */
    OWNER = 572,                   /* OWNER  */
    PARALLEL = 573,                /* PARALLEL  */
    PARSER = 574,                  /* PARSER  */
    PARTIAL = 575,                 /* PARTIAL  */
    PARTITION = 576,               /* PARTITION  */
    PARTITIONED = 577,             /* PARTITIONED  */
    PASSING = 578,                 /* PASSING  */
    PASSWORD = 579,                /* PASSWORD  */
    PATH = 580,                    /* PATH  */
    PERCENT = 581,                 /* PERCENT  */
    PERSISTENT = 582,              /* PERSISTENT  */
    PIVOT = 583,                   /* PIVOT  */
    PIVOT_LONGER = 584,            /* PIVOT_LONGER  */
    PIVOT_WIDER = 585,             /* PIVOT_WIDER  */
    PLACING = 586,                 /* PLACING  */
    PLANS = 587,                   /* PLANS  */
    POLICY = 588,                  /* POLICY  */
    POSITION = 589,                /* POSITION  */
    POSITIONAL = 590,              /* POSITIONAL  */
    PRAGMA_P = 591,                /* PRAGMA_P  */
    PRECEDING = 592,               /* PRECEDING  */
    PRECISION = 593,               /* PRECISION  */
    PREDICT = 594,                 /* PREDICT  */
    PREPARE = 595,                 /* PREPARE  */
    PREPARED = 596,                /* PREPARED  */
    PRESERVE = 597,                /* PRESERVE  */
    PRIMARY = 598,                 /* PRIMARY  */
    PRIOR = 599,                   /* PRIOR  */
    PRIVILEGES = 600,              /* PRIVILEGES  */
    PROCEDURAL = 601,              /* PROCEDURAL  */
    PROCEDURE = 602,               /* PROCEDURE  */
    PROGRAM = 603,                 /* PROGRAM  */
    PROMPT = 604,                  /* PROMPT  */
    PUBLICATION = 605,             /* PUBLICATION  */
    QUALIFY = 606,                 /* QUALIFY  */
    QUARTER_P = 607,               /* QUARTER_P  */
    QUARTERS_P = 608,              /* QUARTERS_P  */
    QUOTE = 609,                   /* QUOTE  */
    RANGE = 610,                   /* RANGE  */
    READ_P = 611,                  /* READ_P  */
    REAL = 612,                    /* REAL  */
    REASSIGN = 613,                /* REASSIGN  */
    RECHECK = 614,                 /* RECHECK  */
    RECURSIVE = 615,               /* RECURSIVE  */
    REF = 616,                     /* REF  */
    REFERENCES = 617,              /* REFERENCES  */
    REFERENCING = 618,             /* REFERENCING  */
    REFRESH = 619,                 /* REFRESH  */
    REINDEX = 620,                 /* REINDEX  */
    RELATIVE_P = 621,              /* RELATIVE_P  */
    RELEASE = 622,                 /* RELEASE  */
    RENAME = 623,                  /* RENAME  */
    REPEATABLE = 624,              /* REPEATABLE  */
    REPLACE = 625,                 /* REPLACE  */
    REPLICA = 626,                 /* REPLICA  */
    RESET = 627,                   /* RESET  */
    RESPECT_P = 628,               /* RESPECT_P  */
    RESTART = 629,                 /* RESTART  */
    RESTRICT = 630,                /* RESTRICT  */
    RETURNING = 631,               /* RETURNING  */
    RETURNS = 632,                 /* RETURNS  */
    REVOKE = 633,                  /* REVOKE  */
    RIGHT = 634,                   /* RIGHT  */
    ROLE = 635,                    /* ROLE  */
    ROLLBACK = 636,                /* ROLLBACK  */
    ROLLUP = 637,                  /* ROLLUP  */
    ROW = 638,                     /* ROW  */
    ROWS = 639,                    /* ROWS  */
    RULE = 640,                    /* RULE  */
    SAMPLE = 641,                  /* SAMPLE  */
    SAVEPOINT = 642,               /* SAVEPOINT  */
    SCHEMA = 643,                  /* SCHEMA  */
    SCHEMAS = 644,                 /* SCHEMAS  */
    SCOPE = 645,                   /* SCOPE  */
    SCROLL = 646,                  /* SCROLL  */
    SEARCH = 647,                  /* SEARCH  */
    SECOND_P = 648,                /* SECOND_P  */
    SECONDS_P = 649,               /* SECONDS_P  */
    SECRET = 650,                  /* SECRET  */
    SECURITY = 651,                /* SECURITY  */
    SELECT = 652,                  /* SELECT  */
    SEMI = 653,                    /* SEMI  */
    SEQUENCE = 654,                /* SEQUENCE  */
    SEQUENCES = 655,               /* SEQUENCES  */
    SERIALIZABLE = 656,            /* SERIALIZABLE  */
    SERVER = 657,                  /* SERVER  */
    SESSION = 658,                 /* SESSION  */
    SET = 659,                     /* SET  */
    SETOF = 660,                   /* SETOF  */
    SETS = 661,                    /* SETS  */
    SHARE = 662,                   /* SHARE  */
    SHOW = 663,                    /* SHOW  */
    SIMILAR = 664,                 /* SIMILAR  */
    SIMPLE = 665,                  /* SIMPLE  */
    SKIP = 666,                    /* SKIP  */
    SMALLINT = 667,                /* SMALLINT  */
    SNAPSHOT = 668,                /* SNAPSHOT  */
    SOME = 669,                    /* SOME  */
    SORTED = 670,                  /* SORTED  */
    SQL_P = 671,                   /* SQL_P  */
    STABLE = 672,                  /* STABLE  */
    STANDALONE_P = 673,            /* STANDALONE_P  */
    START = 674,                   /* START  */
    STATEMENT = 675,               /* STATEMENT  */
    STATISTICS = 676,              /* STATISTICS  */
    STDIN = 677,                   /* STDIN  */
    STDOUT = 678,                  /* STDOUT  */
    STORAGE = 679,                 /* STORAGE  */
    STORED = 680,                  /* STORED  */
    STRICT_P = 681,                /* STRICT_P  */
    STRIP_P = 682,                 /* STRIP_P  */
    STRUCT = 683,                  /* STRUCT  */
    SUBSCRIPTION = 684,            /* SUBSCRIPTION  */
    SUBSTRING = 685,               /* SUBSTRING  */
    SUMMARIZE = 686,               /* SUMMARIZE  */
    SYMMETRIC = 687,               /* SYMMETRIC  */
    SYSID = 688,                   /* SYSID  */
    SYSTEM_P = 689,                /* SYSTEM_P  */
    TABLE = 690,                   /* TABLE  */
    TABLES = 691,                  /* TABLES  */
    TABLESAMPLE = 692,             /* TABLESAMPLE  */
    TABLESPACE = 693,              /* TABLESPACE  */
    TABULAR = 694,                 /* TABULAR  */
    TAKES = 695,                   /* TAKES  */
    TEMP = 696,                    /* TEMP  */
    TEMPLATE = 697,                /* TEMPLATE  */
    TEMPORARY = 698,               /* TEMPORARY  */
    TEXT_P = 699,                  /* TEXT_P  */
    THEN = 700,                    /* THEN  */
    TIES = 701,                    /* TIES  */
    TIME = 702,                    /* TIME  */
    TIMESTAMP = 703,               /* TIMESTAMP  */
    TO = 704,                      /* TO  */
    TRAILING = 705,                /* TRAILING  */
    TRANSACTION = 706,             /* TRANSACTION  */
    TRANSFORM = 707,               /* TRANSFORM  */
    TREAT = 708,                   /* TREAT  */
    TRIGGER = 709,                 /* TRIGGER  */
    TRIM = 710,                    /* TRIM  */
    TRUE_P = 711,                  /* TRUE_P  */
    TRUNCATE = 712,                /* TRUNCATE  */
    TRUSTED = 713,                 /* TRUSTED  */
    TRY_CAST = 714,                /* TRY_CAST  */
    TYPE_P = 715,                  /* TYPE_P  */
    TYPES_P = 716,                 /* TYPES_P  */
    UNBOUNDED = 717,               /* UNBOUNDED  */
    UNCOMMITTED = 718,             /* UNCOMMITTED  */
    UNENCRYPTED = 719,             /* UNENCRYPTED  */
    UNION = 720,                   /* UNION  */
    UNIQUE = 721,                  /* UNIQUE  */
    UNKNOWN = 722,                 /* UNKNOWN  */
    UNLISTEN = 723,                /* UNLISTEN  */
    UNLOGGED = 724,                /* UNLOGGED  */
    UNPACK = 725,                  /* UNPACK  */
    UNPIVOT = 726,                 /* UNPIVOT  */
    UNTIL = 727,                   /* UNTIL  */
    UPDATE = 728,                  /* UPDATE  */
    USE_P = 729,                   /* USE_P  */
    USER = 730,                    /* USER  */
    USING = 731,                   /* USING  */
    VACUUM = 732,                  /* VACUUM  */
    VALID = 733,                   /* VALID  */
    VALIDATE = 734,                /* VALIDATE  */
    VALIDATOR = 735,               /* VALIDATOR  */
    VALUE_P = 736,                 /* VALUE_P  */
    VALUES = 737,                  /* VALUES  */
    VARCHAR = 738,                 /* VARCHAR  */
    VARIABLE_P = 739,              /* VARIABLE_P  */
    VARIADIC = 740,                /* VARIADIC  */
    VARYING = 741,                 /* VARYING  */
    VERBOSE = 742,                 /* VERBOSE  */
    VERSION_P = 743,               /* VERSION_P  */
    VIEW = 744,                    /* VIEW  */
    VIEWS = 745,                   /* VIEWS  */
    VIRTUAL = 746,                 /* VIRTUAL  */
    VOLATILE = 747,                /* VOLATILE  */
    WEEK_P = 748,                  /* WEEK_P  */
    WEEKS_P = 749,                 /* WEEKS_P  */
    WHEN = 750,                    /* WHEN  */
    WHERE = 751,                   /* WHERE  */
    WHITESPACE_P = 752,            /* WHITESPACE_P  */
    WINDOW = 753,                  /* WINDOW  */
    WITH = 754,                    /* WITH  */
    WITHIN = 755,                  /* WITHIN  */
    WITHOUT = 756,                 /* WITHOUT  */
    WORK = 757,                    /* WORK  */
    WRAPPER = 758,                 /* WRAPPER  */
    WRITE_P = 759,                 /* WRITE_P  */
    XML_P = 760,                   /* XML_P  */
    XMLATTRIBUTES = 761,           /* XMLATTRIBUTES  */
    XMLCONCAT = 762,               /* XMLCONCAT  */
    XMLELEMENT = 763,              /* XMLELEMENT  */
    XMLEXISTS = 764,               /* XMLEXISTS  */
    XMLFOREST = 765,               /* XMLFOREST  */
    XMLNAMESPACES = 766,           /* XMLNAMESPACES  */
    XMLPARSE = 767,                /* XMLPARSE  */
    XMLPI = 768,                   /* XMLPI  */
    XMLROOT = 769,                 /* XMLROOT  */
    XMLSERIALIZE = 770,            /* XMLSERIALIZE  */
    XMLTABLE = 771,                /* XMLTABLE  */
    YEAR_P = 772,                  /* YEAR_P  */
    YEARS_P = 773,                 /* YEARS_P  */
    YES_P = 774,                   /* YES_P  */
    ZONE = 775,                    /* ZONE  */
    NOT_LA = 776,                  /* NOT_LA  */
    NULLS_LA = 777,                /* NULLS_LA  */
    WITH_LA = 778,                 /* WITH_LA  */
    POSTFIXOP = 779,               /* POSTFIXOP  */
    UMINUS = 780                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "third_party/libpg_query/grammar/grammar.y"

	core_YYSTYPE		core_yystype;
	/* these fields must match core_YYSTYPE: */
	int					ival;
	char				*str;
	const char			*keyword;
	const char          *conststr;

	char				chr;
	bool				boolean;
	PGJoinType			jtype;
	PGDropBehavior		dbehavior;
	PGOnCommitAction		oncommit;
	PGOnCreateConflict		oncreateconflict;
	PGList				*list;
	PGNode				*node;
	PGValue				*value;
	PGObjectType			objtype;
	PGTypeName			*typnam;
	PGObjectWithArgs		*objwithargs;
	PGDefElem				*defelt;
	PGSortBy				*sortby;
	PGWindowDef			*windef;
	PGJoinExpr			*jexpr;
	PGIndexElem			*ielem;
	PGAlias				*alias;
	PGRangeVar			*range;
	PGIntoClause			*into;
	PGCTEMaterialize			ctematerialize;
	PGWithClause			*with;
	PGInferClause			*infer;
	PGOnConflictClause	*onconflict;
	PGOnConflictActionAlias onconflictshorthand;
	PGAIndices			*aind;
	PGResTarget			*target;
	PGInsertStmt			*istmt;
	PGVariableSetStmt		*vsetstmt;
	PGOverridingKind       override;
	PGSortByDir            sortorder;
	PGSortByNulls          nullorder;
	PGIgnoreNulls          ignorenulls;
	PGConstrType           constr;
	PGLockClauseStrength lockstrength;
	PGLockWaitPolicy lockwaitpolicy;
	PGSubLinkType subquerytype;
	PGViewCheckOption viewcheckoption;
	PGInsertColumnOrder bynameorposition;
	PGLoadInstallType loadinstalltype;
	PGTransactionStmtType transactiontype;

#line 640 "third_party/libpg_query/grammar/grammar_out.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif




int base_yyparse (core_yyscan_t yyscanner);


#endif /* !YY_BASE_YY_THIRD_PARTY_LIBPG_QUERY_GRAMMAR_GRAMMAR_OUT_HPP_INCLUDED  */
