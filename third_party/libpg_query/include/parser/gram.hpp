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
    LM = 499,                      /* LM  */
    LOAD = 500,                    /* LOAD  */
    LOCAL = 501,                   /* LOCAL  */
    LOCATION = 502,                /* LOCATION  */
    LOCK_P = 503,                  /* LOCK_P  */
    LOCKED = 504,                  /* LOCKED  */
    LOGGED = 505,                  /* LOGGED  */
    MACRO = 506,                   /* MACRO  */
    MAP = 507,                     /* MAP  */
    MAPPING = 508,                 /* MAPPING  */
    MATCH = 509,                   /* MATCH  */
    MATERIALIZED = 510,            /* MATERIALIZED  */
    MAXVALUE = 511,                /* MAXVALUE  */
    METHOD = 512,                  /* METHOD  */
    MICROSECOND_P = 513,           /* MICROSECOND_P  */
    MICROSECONDS_P = 514,          /* MICROSECONDS_P  */
    MILLENNIA_P = 515,             /* MILLENNIA_P  */
    MILLENNIUM_P = 516,            /* MILLENNIUM_P  */
    MILLISECOND_P = 517,           /* MILLISECOND_P  */
    MILLISECONDS_P = 518,          /* MILLISECONDS_P  */
    MINUTE_P = 519,                /* MINUTE_P  */
    MINUTES_P = 520,               /* MINUTES_P  */
    MINVALUE = 521,                /* MINVALUE  */
    MODE = 522,                    /* MODE  */
    MODEL = 523,                   /* MODEL  */
    MONTH_P = 524,                 /* MONTH_P  */
    MONTHS_P = 525,                /* MONTHS_P  */
    MOVE = 526,                    /* MOVE  */
    NAME_P = 527,                  /* NAME_P  */
    NAMES = 528,                   /* NAMES  */
    NATIONAL = 529,                /* NATIONAL  */
    NATURAL = 530,                 /* NATURAL  */
    NCHAR = 531,                   /* NCHAR  */
    NEW = 532,                     /* NEW  */
    NEXT = 533,                    /* NEXT  */
    NO = 534,                      /* NO  */
    NODES = 535,                   /* NODES  */
    NONE = 536,                    /* NONE  */
    NOT = 537,                     /* NOT  */
    NOTHING = 538,                 /* NOTHING  */
    NOTIFY = 539,                  /* NOTIFY  */
    NOTNULL = 540,                 /* NOTNULL  */
    NOWAIT = 541,                  /* NOWAIT  */
    NULL_P = 542,                  /* NULL_P  */
    NULLIF = 543,                  /* NULLIF  */
    NULLS_P = 544,                 /* NULLS_P  */
    NUMERIC = 545,                 /* NUMERIC  */
    OBJECT_P = 546,                /* OBJECT_P  */
    OF = 547,                      /* OF  */
    OFF = 548,                     /* OFF  */
    OFFSET = 549,                  /* OFFSET  */
    OIDS = 550,                    /* OIDS  */
    OLD = 551,                     /* OLD  */
    ON = 552,                      /* ON  */
    ONLY = 553,                    /* ONLY  */
    OPERATOR = 554,                /* OPERATOR  */
    OPTION = 555,                  /* OPTION  */
    OPTIONS = 556,                 /* OPTIONS  */
    OR = 557,                      /* OR  */
    ORDER = 558,                   /* ORDER  */
    ORDINALITY = 559,              /* ORDINALITY  */
    OTHERS = 560,                  /* OTHERS  */
    OUT_P = 561,                   /* OUT_P  */
    OUTER_P = 562,                 /* OUTER_P  */
    OUTPUT = 563,                  /* OUTPUT  */
    OVER = 564,                    /* OVER  */
    OVERLAPS = 565,                /* OVERLAPS  */
    OVERLAY = 566,                 /* OVERLAY  */
    OVERRIDING = 567,              /* OVERRIDING  */
    OWNED = 568,                   /* OWNED  */
    OWNER = 569,                   /* OWNER  */
    PARALLEL = 570,                /* PARALLEL  */
    PARSER = 571,                  /* PARSER  */
    PARTIAL = 572,                 /* PARTIAL  */
    PARTITION = 573,               /* PARTITION  */
    PASSING = 574,                 /* PASSING  */
    PASSWORD = 575,                /* PASSWORD  */
    PATH = 576,                    /* PATH  */
    PERCENT = 577,                 /* PERCENT  */
    PERSISTENT = 578,              /* PERSISTENT  */
    PIVOT = 579,                   /* PIVOT  */
    PIVOT_LONGER = 580,            /* PIVOT_LONGER  */
    PIVOT_WIDER = 581,             /* PIVOT_WIDER  */
    PLACING = 582,                 /* PLACING  */
    PLANS = 583,                   /* PLANS  */
    POLICY = 584,                  /* POLICY  */
    POSITION = 585,                /* POSITION  */
    POSITIONAL = 586,              /* POSITIONAL  */
    PRAGMA_P = 587,                /* PRAGMA_P  */
    PRECEDING = 588,               /* PRECEDING  */
    PRECISION = 589,               /* PRECISION  */
    PREDICT = 590,                 /* PREDICT  */
    PREPARE = 591,                 /* PREPARE  */
    PREPARED = 592,                /* PREPARED  */
    PRESERVE = 593,                /* PRESERVE  */
    PRIMARY = 594,                 /* PRIMARY  */
    PRIOR = 595,                   /* PRIOR  */
    PRIVILEGES = 596,              /* PRIVILEGES  */
    PROCEDURAL = 597,              /* PROCEDURAL  */
    PROCEDURE = 598,               /* PROCEDURE  */
    PROGRAM = 599,                 /* PROGRAM  */
    PROMPT = 600,                  /* PROMPT  */
    PUBLICATION = 601,             /* PUBLICATION  */
    QUALIFY = 602,                 /* QUALIFY  */
    QUARTER_P = 603,               /* QUARTER_P  */
    QUARTERS_P = 604,              /* QUARTERS_P  */
    QUOTE = 605,                   /* QUOTE  */
    RANGE = 606,                   /* RANGE  */
    READ_P = 607,                  /* READ_P  */
    REAL = 608,                    /* REAL  */
    REASSIGN = 609,                /* REASSIGN  */
    RECHECK = 610,                 /* RECHECK  */
    RECURSIVE = 611,               /* RECURSIVE  */
    REF = 612,                     /* REF  */
    REFERENCES = 613,              /* REFERENCES  */
    REFERENCING = 614,             /* REFERENCING  */
    REFRESH = 615,                 /* REFRESH  */
    REINDEX = 616,                 /* REINDEX  */
    RELATIVE_P = 617,              /* RELATIVE_P  */
    RELEASE = 618,                 /* RELEASE  */
    RENAME = 619,                  /* RENAME  */
    REPEATABLE = 620,              /* REPEATABLE  */
    REPLACE = 621,                 /* REPLACE  */
    REPLICA = 622,                 /* REPLICA  */
    RESET = 623,                   /* RESET  */
    RESPECT_P = 624,               /* RESPECT_P  */
    RESTART = 625,                 /* RESTART  */
    RESTRICT = 626,                /* RESTRICT  */
    RETURNING = 627,               /* RETURNING  */
    RETURNS = 628,                 /* RETURNS  */
    REVOKE = 629,                  /* REVOKE  */
    RIGHT = 630,                   /* RIGHT  */
    ROLE = 631,                    /* ROLE  */
    ROLLBACK = 632,                /* ROLLBACK  */
    ROLLUP = 633,                  /* ROLLUP  */
    ROW = 634,                     /* ROW  */
    ROWS = 635,                    /* ROWS  */
    RULE = 636,                    /* RULE  */
    SAMPLE = 637,                  /* SAMPLE  */
    SAVEPOINT = 638,               /* SAVEPOINT  */
    SCHEMA = 639,                  /* SCHEMA  */
    SCHEMAS = 640,                 /* SCHEMAS  */
    SCOPE = 641,                   /* SCOPE  */
    SCROLL = 642,                  /* SCROLL  */
    SEARCH = 643,                  /* SEARCH  */
    SECOND_P = 644,                /* SECOND_P  */
    SECONDS_P = 645,               /* SECONDS_P  */
    SECRET = 646,                  /* SECRET  */
    SECURITY = 647,                /* SECURITY  */
    SELECT = 648,                  /* SELECT  */
    SEMI = 649,                    /* SEMI  */
    SEQUENCE = 650,                /* SEQUENCE  */
    SEQUENCES = 651,               /* SEQUENCES  */
    SERIALIZABLE = 652,            /* SERIALIZABLE  */
    SERVER = 653,                  /* SERVER  */
    SESSION = 654,                 /* SESSION  */
    SET = 655,                     /* SET  */
    SETOF = 656,                   /* SETOF  */
    SETS = 657,                    /* SETS  */
    SHARE = 658,                   /* SHARE  */
    SHOW = 659,                    /* SHOW  */
    SIMILAR = 660,                 /* SIMILAR  */
    SIMPLE = 661,                  /* SIMPLE  */
    SKIP = 662,                    /* SKIP  */
    SMALLINT = 663,                /* SMALLINT  */
    SNAPSHOT = 664,                /* SNAPSHOT  */
    SOME = 665,                    /* SOME  */
    SQL_P = 666,                   /* SQL_P  */
    STABLE = 667,                  /* STABLE  */
    STANDALONE_P = 668,            /* STANDALONE_P  */
    START = 669,                   /* START  */
    STATEMENT = 670,               /* STATEMENT  */
    STATISTICS = 671,              /* STATISTICS  */
    STDIN = 672,                   /* STDIN  */
    STDOUT = 673,                  /* STDOUT  */
    STORAGE = 674,                 /* STORAGE  */
    STORED = 675,                  /* STORED  */
    STRICT_P = 676,                /* STRICT_P  */
    STRIP_P = 677,                 /* STRIP_P  */
    STRUCT = 678,                  /* STRUCT  */
    SUBSCRIPTION = 679,            /* SUBSCRIPTION  */
    SUBSTRING = 680,               /* SUBSTRING  */
    SUMMARIZE = 681,               /* SUMMARIZE  */
    SYMMETRIC = 682,               /* SYMMETRIC  */
    SYSID = 683,                   /* SYSID  */
    SYSTEM_P = 684,                /* SYSTEM_P  */
    TABLE = 685,                   /* TABLE  */
    TABLES = 686,                  /* TABLES  */
    TABLESAMPLE = 687,             /* TABLESAMPLE  */
    TABLESPACE = 688,              /* TABLESPACE  */
    TABULAR = 689,                 /* TABULAR  */
    TAKES = 690,                   /* TAKES  */
    TEMP = 691,                    /* TEMP  */
    TEMPLATE = 692,                /* TEMPLATE  */
    TEMPORARY = 693,               /* TEMPORARY  */
    TEXT_P = 694,                  /* TEXT_P  */
    THEN = 695,                    /* THEN  */
    TIES = 696,                    /* TIES  */
    TIME = 697,                    /* TIME  */
    TIMESTAMP = 698,               /* TIMESTAMP  */
    TO = 699,                      /* TO  */
    TRAILING = 700,                /* TRAILING  */
    TRANSACTION = 701,             /* TRANSACTION  */
    TRANSFORM = 702,               /* TRANSFORM  */
    TREAT = 703,                   /* TREAT  */
    TRIGGER = 704,                 /* TRIGGER  */
    TRIM = 705,                    /* TRIM  */
    TRUE_P = 706,                  /* TRUE_P  */
    TRUNCATE = 707,                /* TRUNCATE  */
    TRUSTED = 708,                 /* TRUSTED  */
    TRY_CAST = 709,                /* TRY_CAST  */
    TYPE_P = 710,                  /* TYPE_P  */
    TYPES_P = 711,                 /* TYPES_P  */
    UNBOUNDED = 712,               /* UNBOUNDED  */
    UNCOMMITTED = 713,             /* UNCOMMITTED  */
    UNENCRYPTED = 714,             /* UNENCRYPTED  */
    UNION = 715,                   /* UNION  */
    UNIQUE = 716,                  /* UNIQUE  */
    UNKNOWN = 717,                 /* UNKNOWN  */
    UNLISTEN = 718,                /* UNLISTEN  */
    UNLOGGED = 719,                /* UNLOGGED  */
    UNPIVOT = 720,                 /* UNPIVOT  */
    UNTIL = 721,                   /* UNTIL  */
    UPDATE = 722,                  /* UPDATE  */
    USE_P = 723,                   /* USE_P  */
    USER = 724,                    /* USER  */
    USING = 725,                   /* USING  */
    VACUUM = 726,                  /* VACUUM  */
    VALID = 727,                   /* VALID  */
    VALIDATE = 728,                /* VALIDATE  */
    VALIDATOR = 729,               /* VALIDATOR  */
    VALUE_P = 730,                 /* VALUE_P  */
    VALUES = 731,                  /* VALUES  */
    VARCHAR = 732,                 /* VARCHAR  */
    VARIABLE_P = 733,              /* VARIABLE_P  */
    VARIADIC = 734,                /* VARIADIC  */
    VARYING = 735,                 /* VARYING  */
    VERBOSE = 736,                 /* VERBOSE  */
    VERSION_P = 737,               /* VERSION_P  */
    VIEW = 738,                    /* VIEW  */
    VIEWS = 739,                   /* VIEWS  */
    VIRTUAL = 740,                 /* VIRTUAL  */
    VOLATILE = 741,                /* VOLATILE  */
    WEEK_P = 742,                  /* WEEK_P  */
    WEEKS_P = 743,                 /* WEEKS_P  */
    WHEN = 744,                    /* WHEN  */
    WHERE = 745,                   /* WHERE  */
    WHITESPACE_P = 746,            /* WHITESPACE_P  */
    WINDOW = 747,                  /* WINDOW  */
    WITH = 748,                    /* WITH  */
    WITHIN = 749,                  /* WITHIN  */
    WITHOUT = 750,                 /* WITHOUT  */
    WORK = 751,                    /* WORK  */
    WRAPPER = 752,                 /* WRAPPER  */
    WRITE_P = 753,                 /* WRITE_P  */
    XML_P = 754,                   /* XML_P  */
    XMLATTRIBUTES = 755,           /* XMLATTRIBUTES  */
    XMLCONCAT = 756,               /* XMLCONCAT  */
    XMLELEMENT = 757,              /* XMLELEMENT  */
    XMLEXISTS = 758,               /* XMLEXISTS  */
    XMLFOREST = 759,               /* XMLFOREST  */
    XMLNAMESPACES = 760,           /* XMLNAMESPACES  */
    XMLPARSE = 761,                /* XMLPARSE  */
    XMLPI = 762,                   /* XMLPI  */
    XMLROOT = 763,                 /* XMLROOT  */
    XMLSERIALIZE = 764,            /* XMLSERIALIZE  */
    XMLTABLE = 765,                /* XMLTABLE  */
    YEAR_P = 766,                  /* YEAR_P  */
    YEARS_P = 767,                 /* YEARS_P  */
    YES_P = 768,                   /* YES_P  */
    ZONE = 769,                    /* ZONE  */
    NOT_LA = 770,                  /* NOT_LA  */
    NULLS_LA = 771,                /* NULLS_LA  */
    WITH_LA = 772,                 /* WITH_LA  */
    POSTFIXOP = 773,               /* POSTFIXOP  */
    UMINUS = 774                   /* UMINUS  */
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

#line 634 "third_party/libpg_query/grammar/grammar_out.hpp"

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
