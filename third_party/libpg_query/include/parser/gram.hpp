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
    LAMBDA_ARROW = 272,            /* LAMBDA_ARROW  */
    DOUBLE_ARROW = 273,            /* DOUBLE_ARROW  */
    LESS_EQUALS = 274,             /* LESS_EQUALS  */
    GREATER_EQUALS = 275,          /* GREATER_EQUALS  */
    NOT_EQUALS = 276,              /* NOT_EQUALS  */
    ABORT_P = 277,                 /* ABORT_P  */
    ABSOLUTE_P = 278,              /* ABSOLUTE_P  */
    ACCESS = 279,                  /* ACCESS  */
    ACTION = 280,                  /* ACTION  */
    ADD_P = 281,                   /* ADD_P  */
    ADMIN = 282,                   /* ADMIN  */
    AFTER = 283,                   /* AFTER  */
    AGGREGATE = 284,               /* AGGREGATE  */
    ALL = 285,                     /* ALL  */
    ALSO = 286,                    /* ALSO  */
    ALTER = 287,                   /* ALTER  */
    ALWAYS = 288,                  /* ALWAYS  */
    ANALYSE = 289,                 /* ANALYSE  */
    ANALYZE = 290,                 /* ANALYZE  */
    AND = 291,                     /* AND  */
    ANTI = 292,                    /* ANTI  */
    ANY = 293,                     /* ANY  */
    ARRAY = 294,                   /* ARRAY  */
    AS = 295,                      /* AS  */
    ASC_P = 296,                   /* ASC_P  */
    ASOF = 297,                    /* ASOF  */
    ASSERTION = 298,               /* ASSERTION  */
    ASSIGNMENT = 299,              /* ASSIGNMENT  */
    ASYMMETRIC = 300,              /* ASYMMETRIC  */
    AT = 301,                      /* AT  */
    ATTACH = 302,                  /* ATTACH  */
    ATTRIBUTE = 303,               /* ATTRIBUTE  */
    AUTHORIZATION = 304,           /* AUTHORIZATION  */
    BACKWARD = 305,                /* BACKWARD  */
    BEFORE = 306,                  /* BEFORE  */
    BEGIN_P = 307,                 /* BEGIN_P  */
    BETWEEN = 308,                 /* BETWEEN  */
    BIGINT = 309,                  /* BIGINT  */
    BINARY = 310,                  /* BINARY  */
    BIT = 311,                     /* BIT  */
    BOOLEAN_P = 312,               /* BOOLEAN_P  */
    BOTH = 313,                    /* BOTH  */
    BY = 314,                      /* BY  */
    CACHE = 315,                   /* CACHE  */
    CALL_P = 316,                  /* CALL_P  */
    CALLED = 317,                  /* CALLED  */
    CASCADE = 318,                 /* CASCADE  */
    CASCADED = 319,                /* CASCADED  */
    CASE = 320,                    /* CASE  */
    CAST = 321,                    /* CAST  */
    CATALOG_P = 322,               /* CATALOG_P  */
    CENTURIES_P = 323,             /* CENTURIES_P  */
    CENTURY_P = 324,               /* CENTURY_P  */
    CHAIN = 325,                   /* CHAIN  */
    CHAR_P = 326,                  /* CHAR_P  */
    CHARACTER = 327,               /* CHARACTER  */
    CHARACTERISTICS = 328,         /* CHARACTERISTICS  */
    CHECK_P = 329,                 /* CHECK_P  */
    CHECKPOINT = 330,              /* CHECKPOINT  */
    CLASS = 331,                   /* CLASS  */
    CLOSE = 332,                   /* CLOSE  */
    CLUSTER = 333,                 /* CLUSTER  */
    COALESCE = 334,                /* COALESCE  */
    COLLATE = 335,                 /* COLLATE  */
    COLLATION = 336,               /* COLLATION  */
    COLUMN = 337,                  /* COLUMN  */
    COLUMNS = 338,                 /* COLUMNS  */
    COMMENT = 339,                 /* COMMENT  */
    COMMENTS = 340,                /* COMMENTS  */
    COMMIT = 341,                  /* COMMIT  */
    COMMITTED = 342,               /* COMMITTED  */
    COMPRESSION = 343,             /* COMPRESSION  */
    CONCURRENTLY = 344,            /* CONCURRENTLY  */
    CONFIGURATION = 345,           /* CONFIGURATION  */
    CONFLICT = 346,                /* CONFLICT  */
    CONNECTION = 347,              /* CONNECTION  */
    CONSTRAINT = 348,              /* CONSTRAINT  */
    CONSTRAINTS = 349,             /* CONSTRAINTS  */
    CONTENT_P = 350,               /* CONTENT_P  */
    CONTINUE_P = 351,              /* CONTINUE_P  */
    CONVERSION_P = 352,            /* CONVERSION_P  */
    COPY = 353,                    /* COPY  */
    COST = 354,                    /* COST  */
    CREATE_P = 355,                /* CREATE_P  */
    CROSS = 356,                   /* CROSS  */
    CSV = 357,                     /* CSV  */
    CUBE = 358,                    /* CUBE  */
    CURRENT_P = 359,               /* CURRENT_P  */
    CURSOR = 360,                  /* CURSOR  */
    CYCLE = 361,                   /* CYCLE  */
    DATA_P = 362,                  /* DATA_P  */
    DATABASE = 363,                /* DATABASE  */
    DAY_P = 364,                   /* DAY_P  */
    DAYS_P = 365,                  /* DAYS_P  */
    DEALLOCATE = 366,              /* DEALLOCATE  */
    DEC = 367,                     /* DEC  */
    DECADE_P = 368,                /* DECADE_P  */
    DECADES_P = 369,               /* DECADES_P  */
    DECIMAL_P = 370,               /* DECIMAL_P  */
    DECLARE = 371,                 /* DECLARE  */
    DEFAULT = 372,                 /* DEFAULT  */
    DEFAULTS = 373,                /* DEFAULTS  */
    DEFERRABLE = 374,              /* DEFERRABLE  */
    DEFERRED = 375,                /* DEFERRED  */
    DEFINER = 376,                 /* DEFINER  */
    DELETE_P = 377,                /* DELETE_P  */
    DELIMITER = 378,               /* DELIMITER  */
    DELIMITERS = 379,              /* DELIMITERS  */
    DEPENDS = 380,                 /* DEPENDS  */
    DESC_P = 381,                  /* DESC_P  */
    DESCRIBE = 382,                /* DESCRIBE  */
    DETACH = 383,                  /* DETACH  */
    DICTIONARY = 384,              /* DICTIONARY  */
    DISABLE_P = 385,               /* DISABLE_P  */
    DISCARD = 386,                 /* DISCARD  */
    DISTINCT = 387,                /* DISTINCT  */
    DO = 388,                      /* DO  */
    DOCUMENT_P = 389,              /* DOCUMENT_P  */
    DOMAIN_P = 390,                /* DOMAIN_P  */
    DOUBLE_P = 391,                /* DOUBLE_P  */
    DROP = 392,                    /* DROP  */
    EACH = 393,                    /* EACH  */
    EDGES = 394,                   /* EDGES  */
    ELSE = 395,                    /* ELSE  */
    ENABLE_P = 396,                /* ENABLE_P  */
    ENCODING = 397,                /* ENCODING  */
    ENCRYPTED = 398,               /* ENCRYPTED  */
    END_P = 399,                   /* END_P  */
    ENUM_P = 400,                  /* ENUM_P  */
    ESCAPE = 401,                  /* ESCAPE  */
    EVENT = 402,                   /* EVENT  */
    EXCEPT = 403,                  /* EXCEPT  */
    EXCLUDE = 404,                 /* EXCLUDE  */
    EXCLUDING = 405,               /* EXCLUDING  */
    EXCLUSIVE = 406,               /* EXCLUSIVE  */
    EXECUTE = 407,                 /* EXECUTE  */
    EXISTS = 408,                  /* EXISTS  */
    EXPLAIN = 409,                 /* EXPLAIN  */
    EXPORT_P = 410,                /* EXPORT_P  */
    EXPORT_STATE = 411,            /* EXPORT_STATE  */
    EXTENSION = 412,               /* EXTENSION  */
    EXTENSIONS = 413,              /* EXTENSIONS  */
    EXTERNAL = 414,                /* EXTERNAL  */
    EXTRACT = 415,                 /* EXTRACT  */
    FALSE_P = 416,                 /* FALSE_P  */
    FAMILY = 417,                  /* FAMILY  */
    FEATURES = 418,                /* FEATURES  */
    FETCH = 419,                   /* FETCH  */
    FILTER = 420,                  /* FILTER  */
    FIRST_P = 421,                 /* FIRST_P  */
    FLOAT_P = 422,                 /* FLOAT_P  */
    FOLLOWING = 423,               /* FOLLOWING  */
    FOR = 424,                     /* FOR  */
    FORCE = 425,                   /* FORCE  */
    FOREIGN = 426,                 /* FOREIGN  */
    FORWARD = 427,                 /* FORWARD  */
    FREEZE = 428,                  /* FREEZE  */
    FROM = 429,                    /* FROM  */
    FULL = 430,                    /* FULL  */
    FUNCTION = 431,                /* FUNCTION  */
    FUNCTIONS = 432,               /* FUNCTIONS  */
    GENERATED = 433,               /* GENERATED  */
    GLOB = 434,                    /* GLOB  */
    GLOBAL = 435,                  /* GLOBAL  */
    GNN = 436,                     /* GNN  */
    GRANT = 437,                   /* GRANT  */
    GRANTED = 438,                 /* GRANTED  */
    GROUP_P = 439,                 /* GROUP_P  */
    GROUPING = 440,                /* GROUPING  */
    GROUPING_ID = 441,             /* GROUPING_ID  */
    GROUPS = 442,                  /* GROUPS  */
    HANDLER = 443,                 /* HANDLER  */
    HAVING = 444,                  /* HAVING  */
    HEADER_P = 445,                /* HEADER_P  */
    HOLD = 446,                    /* HOLD  */
    HOUR_P = 447,                  /* HOUR_P  */
    HOURS_P = 448,                 /* HOURS_P  */
    IDENTITY_P = 449,              /* IDENTITY_P  */
    IF_P = 450,                    /* IF_P  */
    IGNORE_P = 451,                /* IGNORE_P  */
    ILIKE = 452,                   /* ILIKE  */
    IMMEDIATE = 453,               /* IMMEDIATE  */
    IMMUTABLE = 454,               /* IMMUTABLE  */
    IMPLICIT_P = 455,              /* IMPLICIT_P  */
    IMPORT_P = 456,                /* IMPORT_P  */
    IN_P = 457,                    /* IN_P  */
    INCLUDE_P = 458,               /* INCLUDE_P  */
    INCLUDING = 459,               /* INCLUDING  */
    INCREMENT = 460,               /* INCREMENT  */
    INDEX = 461,                   /* INDEX  */
    INDEXES = 462,                 /* INDEXES  */
    INHERIT = 463,                 /* INHERIT  */
    INHERITS = 464,                /* INHERITS  */
    INITIALLY = 465,               /* INITIALLY  */
    INLINE_P = 466,                /* INLINE_P  */
    INNER_P = 467,                 /* INNER_P  */
    INOUT = 468,                   /* INOUT  */
    INPUT_P = 469,                 /* INPUT_P  */
    INSENSITIVE = 470,             /* INSENSITIVE  */
    INSERT = 471,                  /* INSERT  */
    INSTALL = 472,                 /* INSTALL  */
    INSTEAD = 473,                 /* INSTEAD  */
    INT_P = 474,                   /* INT_P  */
    INTEGER = 475,                 /* INTEGER  */
    INTERSECT = 476,               /* INTERSECT  */
    INTERVAL = 477,                /* INTERVAL  */
    INTO = 478,                    /* INTO  */
    INVOKER = 479,                 /* INVOKER  */
    IS = 480,                      /* IS  */
    ISNULL = 481,                  /* ISNULL  */
    ISOLATION = 482,               /* ISOLATION  */
    JOIN = 483,                    /* JOIN  */
    JSON = 484,                    /* JSON  */
    KEY = 485,                     /* KEY  */
    LABEL = 486,                   /* LABEL  */
    LANGUAGE = 487,                /* LANGUAGE  */
    LARGE_P = 488,                 /* LARGE_P  */
    LAST_P = 489,                  /* LAST_P  */
    LATERAL_P = 490,               /* LATERAL_P  */
    LEADING = 491,                 /* LEADING  */
    LEAKPROOF = 492,               /* LEAKPROOF  */
    LEFT = 493,                    /* LEFT  */
    LEVEL = 494,                   /* LEVEL  */
    LIKE = 495,                    /* LIKE  */
    LIMIT = 496,                   /* LIMIT  */
    LISTEN = 497,                  /* LISTEN  */
    LLM = 498,                     /* LLM  */
    LOAD = 499,                    /* LOAD  */
    LOCAL = 500,                   /* LOCAL  */
    LOCATION = 501,                /* LOCATION  */
    LOCK_P = 502,                  /* LOCK_P  */
    LOCKED = 503,                  /* LOCKED  */
    LOGGED = 504,                  /* LOGGED  */
    MACRO = 505,                   /* MACRO  */
    MAP = 506,                     /* MAP  */
    MAPPING = 507,                 /* MAPPING  */
    MATCH = 508,                   /* MATCH  */
    MATERIALIZED = 509,            /* MATERIALIZED  */
    MAXVALUE = 510,                /* MAXVALUE  */
    METHOD = 511,                  /* METHOD  */
    MICROSECOND_P = 512,           /* MICROSECOND_P  */
    MICROSECONDS_P = 513,          /* MICROSECONDS_P  */
    MILLENNIA_P = 514,             /* MILLENNIA_P  */
    MILLENNIUM_P = 515,            /* MILLENNIUM_P  */
    MILLISECOND_P = 516,           /* MILLISECOND_P  */
    MILLISECONDS_P = 517,          /* MILLISECONDS_P  */
    MINUTE_P = 518,                /* MINUTE_P  */
    MINUTES_P = 519,               /* MINUTES_P  */
    MINVALUE = 520,                /* MINVALUE  */
    MODE = 521,                    /* MODE  */
    MODEL = 522,                   /* MODEL  */
    MONTH_P = 523,                 /* MONTH_P  */
    MONTHS_P = 524,                /* MONTHS_P  */
    MOVE = 525,                    /* MOVE  */
    NAME_P = 526,                  /* NAME_P  */
    NAMES = 527,                   /* NAMES  */
    NATIONAL = 528,                /* NATIONAL  */
    NATURAL = 529,                 /* NATURAL  */
    NCHAR = 530,                   /* NCHAR  */
    NEW = 531,                     /* NEW  */
    NEXT = 532,                    /* NEXT  */
    NO = 533,                      /* NO  */
    NODES = 534,                   /* NODES  */
    NONE = 535,                    /* NONE  */
    NOT = 536,                     /* NOT  */
    NOTHING = 537,                 /* NOTHING  */
    NOTIFY = 538,                  /* NOTIFY  */
    NOTNULL = 539,                 /* NOTNULL  */
    NOWAIT = 540,                  /* NOWAIT  */
    NULL_P = 541,                  /* NULL_P  */
    NULLIF = 542,                  /* NULLIF  */
    NULLS_P = 543,                 /* NULLS_P  */
    NUMERIC = 544,                 /* NUMERIC  */
    OBJECT_P = 545,                /* OBJECT_P  */
    OF = 546,                      /* OF  */
    OFF = 547,                     /* OFF  */
    OFFSET = 548,                  /* OFFSET  */
    OIDS = 549,                    /* OIDS  */
    OLD = 550,                     /* OLD  */
    ON = 551,                      /* ON  */
    ONLY = 552,                    /* ONLY  */
    OPERATOR = 553,                /* OPERATOR  */
    OPTION = 554,                  /* OPTION  */
    OPTIONS = 555,                 /* OPTIONS  */
    OR = 556,                      /* OR  */
    ORDER = 557,                   /* ORDER  */
    ORDINALITY = 558,              /* ORDINALITY  */
    OTHERS = 559,                  /* OTHERS  */
    OUT_P = 560,                   /* OUT_P  */
    OUTER_P = 561,                 /* OUTER_P  */
    OUTPUT = 562,                  /* OUTPUT  */
    OVER = 563,                    /* OVER  */
    OVERLAPS = 564,                /* OVERLAPS  */
    OVERLAY = 565,                 /* OVERLAY  */
    OVERRIDING = 566,              /* OVERRIDING  */
    OWNED = 567,                   /* OWNED  */
    OWNER = 568,                   /* OWNER  */
    PARALLEL = 569,                /* PARALLEL  */
    PARSER = 570,                  /* PARSER  */
    PARTIAL = 571,                 /* PARTIAL  */
    PARTITION = 572,               /* PARTITION  */
    PASSING = 573,                 /* PASSING  */
    PASSWORD = 574,                /* PASSWORD  */
    PATH = 575,                    /* PATH  */
    PERCENT = 576,                 /* PERCENT  */
    PERSISTENT = 577,              /* PERSISTENT  */
    PIVOT = 578,                   /* PIVOT  */
    PIVOT_LONGER = 579,            /* PIVOT_LONGER  */
    PIVOT_WIDER = 580,             /* PIVOT_WIDER  */
    PLACING = 581,                 /* PLACING  */
    PLANS = 582,                   /* PLANS  */
    POLICY = 583,                  /* POLICY  */
    POSITION = 584,                /* POSITION  */
    POSITIONAL = 585,              /* POSITIONAL  */
    PRAGMA_P = 586,                /* PRAGMA_P  */
    PRECEDING = 587,               /* PRECEDING  */
    PRECISION = 588,               /* PRECISION  */
    PREDICT = 589,                 /* PREDICT  */
    PREPARE = 590,                 /* PREPARE  */
    PREPARED = 591,                /* PREPARED  */
    PRESERVE = 592,                /* PRESERVE  */
    PRIMARY = 593,                 /* PRIMARY  */
    PRIOR = 594,                   /* PRIOR  */
    PRIVILEGES = 595,              /* PRIVILEGES  */
    PROCEDURAL = 596,              /* PROCEDURAL  */
    PROCEDURE = 597,               /* PROCEDURE  */
    PROGRAM = 598,                 /* PROGRAM  */
    PUBLICATION = 599,             /* PUBLICATION  */
    QUALIFY = 600,                 /* QUALIFY  */
    QUARTER_P = 601,               /* QUARTER_P  */
    QUARTERS_P = 602,              /* QUARTERS_P  */
    QUOTE = 603,                   /* QUOTE  */
    RANGE = 604,                   /* RANGE  */
    READ_P = 605,                  /* READ_P  */
    REAL = 606,                    /* REAL  */
    REASSIGN = 607,                /* REASSIGN  */
    RECHECK = 608,                 /* RECHECK  */
    RECURSIVE = 609,               /* RECURSIVE  */
    REF = 610,                     /* REF  */
    REFERENCES = 611,              /* REFERENCES  */
    REFERENCING = 612,             /* REFERENCING  */
    REFRESH = 613,                 /* REFRESH  */
    REINDEX = 614,                 /* REINDEX  */
    RELATIVE_P = 615,              /* RELATIVE_P  */
    RELEASE = 616,                 /* RELEASE  */
    RENAME = 617,                  /* RENAME  */
    REPEATABLE = 618,              /* REPEATABLE  */
    REPLACE = 619,                 /* REPLACE  */
    REPLICA = 620,                 /* REPLICA  */
    RESET = 621,                   /* RESET  */
    RESPECT_P = 622,               /* RESPECT_P  */
    RESTART = 623,                 /* RESTART  */
    RESTRICT = 624,                /* RESTRICT  */
    RETURNING = 625,               /* RETURNING  */
    RETURNS = 626,                 /* RETURNS  */
    REVOKE = 627,                  /* REVOKE  */
    RIGHT = 628,                   /* RIGHT  */
    ROLE = 629,                    /* ROLE  */
    ROLLBACK = 630,                /* ROLLBACK  */
    ROLLUP = 631,                  /* ROLLUP  */
    ROW = 632,                     /* ROW  */
    ROWS = 633,                    /* ROWS  */
    RULE = 634,                    /* RULE  */
    SAMPLE = 635,                  /* SAMPLE  */
    SAVEPOINT = 636,               /* SAVEPOINT  */
    SCHEMA = 637,                  /* SCHEMA  */
    SCHEMAS = 638,                 /* SCHEMAS  */
    SCOPE = 639,                   /* SCOPE  */
    SCROLL = 640,                  /* SCROLL  */
    SEARCH = 641,                  /* SEARCH  */
    SECOND_P = 642,                /* SECOND_P  */
    SECONDS_P = 643,               /* SECONDS_P  */
    SECRET = 644,                  /* SECRET  */
    SECURITY = 645,                /* SECURITY  */
    SELECT = 646,                  /* SELECT  */
    SEMI = 647,                    /* SEMI  */
    SEQUENCE = 648,                /* SEQUENCE  */
    SEQUENCES = 649,               /* SEQUENCES  */
    SERIALIZABLE = 650,            /* SERIALIZABLE  */
    SERVER = 651,                  /* SERVER  */
    SESSION = 652,                 /* SESSION  */
    SET = 653,                     /* SET  */
    SETOF = 654,                   /* SETOF  */
    SETS = 655,                    /* SETS  */
    SHARE = 656,                   /* SHARE  */
    SHOW = 657,                    /* SHOW  */
    SIMILAR = 658,                 /* SIMILAR  */
    SIMPLE = 659,                  /* SIMPLE  */
    SKIP = 660,                    /* SKIP  */
    SMALLINT = 661,                /* SMALLINT  */
    SNAPSHOT = 662,                /* SNAPSHOT  */
    SOME = 663,                    /* SOME  */
    SQL_P = 664,                   /* SQL_P  */
    STABLE = 665,                  /* STABLE  */
    STANDALONE_P = 666,            /* STANDALONE_P  */
    START = 667,                   /* START  */
    STATEMENT = 668,               /* STATEMENT  */
    STATISTICS = 669,              /* STATISTICS  */
    STDIN = 670,                   /* STDIN  */
    STDOUT = 671,                  /* STDOUT  */
    STORAGE = 672,                 /* STORAGE  */
    STORED = 673,                  /* STORED  */
    STRICT_P = 674,                /* STRICT_P  */
    STRIP_P = 675,                 /* STRIP_P  */
    STRUCT = 676,                  /* STRUCT  */
    SUBSCRIPTION = 677,            /* SUBSCRIPTION  */
    SUBSTRING = 678,               /* SUBSTRING  */
    SUMMARIZE = 679,               /* SUMMARIZE  */
    SYMMETRIC = 680,               /* SYMMETRIC  */
    SYSID = 681,                   /* SYSID  */
    SYSTEM_P = 682,                /* SYSTEM_P  */
    TABLE = 683,                   /* TABLE  */
    TABLES = 684,                  /* TABLES  */
    TABLESAMPLE = 685,             /* TABLESAMPLE  */
    TABLESPACE = 686,              /* TABLESPACE  */
    TABULAR = 687,                 /* TABULAR  */
    TAKES = 688,                   /* TAKES  */
    TEMP = 689,                    /* TEMP  */
    TEMPLATE = 690,                /* TEMPLATE  */
    TEMPORARY = 691,               /* TEMPORARY  */
    TEXT_P = 692,                  /* TEXT_P  */
    THEN = 693,                    /* THEN  */
    TIES = 694,                    /* TIES  */
    TIME = 695,                    /* TIME  */
    TIMESTAMP = 696,               /* TIMESTAMP  */
    TO = 697,                      /* TO  */
    TRAILING = 698,                /* TRAILING  */
    TRANSACTION = 699,             /* TRANSACTION  */
    TRANSFORM = 700,               /* TRANSFORM  */
    TREAT = 701,                   /* TREAT  */
    TRIGGER = 702,                 /* TRIGGER  */
    TRIM = 703,                    /* TRIM  */
    TRUE_P = 704,                  /* TRUE_P  */
    TRUNCATE = 705,                /* TRUNCATE  */
    TRUSTED = 706,                 /* TRUSTED  */
    TRY_CAST = 707,                /* TRY_CAST  */
    TYPE_P = 708,                  /* TYPE_P  */
    TYPES_P = 709,                 /* TYPES_P  */
    UNBOUNDED = 710,               /* UNBOUNDED  */
    UNCOMMITTED = 711,             /* UNCOMMITTED  */
    UNENCRYPTED = 712,             /* UNENCRYPTED  */
    UNION = 713,                   /* UNION  */
    UNIQUE = 714,                  /* UNIQUE  */
    UNKNOWN = 715,                 /* UNKNOWN  */
    UNLISTEN = 716,                /* UNLISTEN  */
    UNLOGGED = 717,                /* UNLOGGED  */
    UNPIVOT = 718,                 /* UNPIVOT  */
    UNTIL = 719,                   /* UNTIL  */
    UPDATE = 720,                  /* UPDATE  */
    USE_P = 721,                   /* USE_P  */
    USER = 722,                    /* USER  */
    USING = 723,                   /* USING  */
    VACUUM = 724,                  /* VACUUM  */
    VALID = 725,                   /* VALID  */
    VALIDATE = 726,                /* VALIDATE  */
    VALIDATOR = 727,               /* VALIDATOR  */
    VALUE_P = 728,                 /* VALUE_P  */
    VALUES = 729,                  /* VALUES  */
    VARCHAR = 730,                 /* VARCHAR  */
    VARIABLE_P = 731,              /* VARIABLE_P  */
    VARIADIC = 732,                /* VARIADIC  */
    VARYING = 733,                 /* VARYING  */
    VERBOSE = 734,                 /* VERBOSE  */
    VERSION_P = 735,               /* VERSION_P  */
    VIEW = 736,                    /* VIEW  */
    VIEWS = 737,                   /* VIEWS  */
    VIRTUAL = 738,                 /* VIRTUAL  */
    VOLATILE = 739,                /* VOLATILE  */
    WEEK_P = 740,                  /* WEEK_P  */
    WEEKS_P = 741,                 /* WEEKS_P  */
    WHEN = 742,                    /* WHEN  */
    WHERE = 743,                   /* WHERE  */
    WHITESPACE_P = 744,            /* WHITESPACE_P  */
    WINDOW = 745,                  /* WINDOW  */
    WITH = 746,                    /* WITH  */
    WITHIN = 747,                  /* WITHIN  */
    WITHOUT = 748,                 /* WITHOUT  */
    WORK = 749,                    /* WORK  */
    WRAPPER = 750,                 /* WRAPPER  */
    WRITE_P = 751,                 /* WRITE_P  */
    XML_P = 752,                   /* XML_P  */
    XMLATTRIBUTES = 753,           /* XMLATTRIBUTES  */
    XMLCONCAT = 754,               /* XMLCONCAT  */
    XMLELEMENT = 755,              /* XMLELEMENT  */
    XMLEXISTS = 756,               /* XMLEXISTS  */
    XMLFOREST = 757,               /* XMLFOREST  */
    XMLNAMESPACES = 758,           /* XMLNAMESPACES  */
    XMLPARSE = 759,                /* XMLPARSE  */
    XMLPI = 760,                   /* XMLPI  */
    XMLROOT = 761,                 /* XMLROOT  */
    XMLSERIALIZE = 762,            /* XMLSERIALIZE  */
    XMLTABLE = 763,                /* XMLTABLE  */
    YEAR_P = 764,                  /* YEAR_P  */
    YEARS_P = 765,                 /* YEARS_P  */
    YES_P = 766,                   /* YES_P  */
    ZONE = 767,                    /* ZONE  */
    NOT_LA = 768,                  /* NOT_LA  */
    NULLS_LA = 769,                /* NULLS_LA  */
    WITH_LA = 770,                 /* WITH_LA  */
    POSTFIXOP = 771,               /* POSTFIXOP  */
    UMINUS = 772                   /* UMINUS  */
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

#line 632 "third_party/libpg_query/grammar/grammar_out.hpp"

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
