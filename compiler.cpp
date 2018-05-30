/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANT = 259,
     STRING_LITERAL = 260,
     SIZEOF = 261,
     PTR_OP = 262,
     INC_OP = 263,
     DEC_OP = 264,
     LEFT_OP = 265,
     RIGHT_OP = 266,
     LE_OP = 267,
     GE_OP = 268,
     EQ_OP = 269,
     NE_OP = 270,
     AND_OP = 271,
     OR_OP = 272,
     MUL_ASSIGN = 273,
     DIV_ASSIGN = 274,
     MOD_ASSIGN = 275,
     ADD_ASSIGN = 276,
     SUB_ASSIGN = 277,
     LEFT_ASSIGN = 278,
     RIGHT_ASSIGN = 279,
     AND_ASSIGN = 280,
     XOR_ASSIGN = 281,
     OR_ASSIGN = 282,
     TYPE_NAME = 283,
     TYPEDEF = 284,
     EXTERN = 285,
     STATIC = 286,
     AUTO = 287,
     REGISTER = 288,
     INLINE = 289,
     RESTRICT = 290,
     CHAR = 291,
     SHORT = 292,
     INT = 293,
     LONG = 294,
     SIGNED = 295,
     UNSIGNED = 296,
     FLOAT = 297,
     DOUBLE = 298,
     CONST = 299,
     VOLATILE = 300,
     VOID = 301,
     BOOL = 302,
     COMPLEX = 303,
     IMAGINARY = 304,
     STRUCT = 305,
     UNION = 306,
     ENUM = 307,
     ELLIPSIS = 308,
     CASE = 309,
     DEFAULT = 310,
     IF = 311,
     ELSE = 312,
     SWITCH = 313,
     WHILE = 314,
     DO = 315,
     FOR = 316,
     GOTO = 317,
     CONTINUE = 318,
     BREAK = 319,
     RETURN = 320
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define STRING_LITERAL 260
#define SIZEOF 261
#define PTR_OP 262
#define INC_OP 263
#define DEC_OP 264
#define LEFT_OP 265
#define RIGHT_OP 266
#define LE_OP 267
#define GE_OP 268
#define EQ_OP 269
#define NE_OP 270
#define AND_OP 271
#define OR_OP 272
#define MUL_ASSIGN 273
#define DIV_ASSIGN 274
#define MOD_ASSIGN 275
#define ADD_ASSIGN 276
#define SUB_ASSIGN 277
#define LEFT_ASSIGN 278
#define RIGHT_ASSIGN 279
#define AND_ASSIGN 280
#define XOR_ASSIGN 281
#define OR_ASSIGN 282
#define TYPE_NAME 283
#define TYPEDEF 284
#define EXTERN 285
#define STATIC 286
#define AUTO 287
#define REGISTER 288
#define INLINE 289
#define RESTRICT 290
#define CHAR 291
#define SHORT 292
#define INT 293
#define LONG 294
#define SIGNED 295
#define UNSIGNED 296
#define FLOAT 297
#define DOUBLE 298
#define CONST 299
#define VOLATILE 300
#define VOID 301
#define BOOL 302
#define COMPLEX 303
#define IMAGINARY 304
#define STRUCT 305
#define UNION 306
#define ENUM 307
#define ELLIPSIS 308
#define CASE 309
#define DEFAULT 310
#define IF 311
#define ELSE 312
#define SWITCH 313
#define WHILE 314
#define DO 315
#define FOR 316
#define GOTO 317
#define CONTINUE 318
#define BREAK 319
#define RETURN 320




/* Copy the first part of user declarations.  */
#line 1 "compiler.y"

#include"node.h"
#include"element.h"
#include<stdio.h>
#include<iostream>
extern char yytext[];
extern int column;
extern FILE *yyin;
void yyerror(char const *s);
int yylex();
node* root = NULL;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 13 "compiler.y"
{
	class node* Node;
	class element* Element;
}
/* Line 193 of yacc.c.  */
#line 244 "compiler.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 257 "compiler.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  56
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1413

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  239
/* YYNRULES -- Number of states.  */
#define YYNSTATES  401

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   320

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,     2,     2,    65,    54,     2,
      79,    80,    55,    56,    86,    57,    83,    60,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    88,    89,
      61,    66,    62,    87,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    81,     2,    82,    63,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    84,    64,    85,    58,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    15,    20,    24,
      29,    33,    37,    40,    43,    50,    58,    60,    64,    66,
      69,    72,    75,    78,    83,    85,    87,    89,    91,    93,
      95,    97,   102,   104,   108,   112,   116,   118,   122,   126,
     128,   132,   136,   138,   142,   146,   150,   154,   156,   160,
     164,   166,   170,   172,   176,   178,   182,   184,   188,   190,
     194,   196,   202,   204,   208,   210,   212,   214,   216,   218,
     220,   222,   224,   226,   228,   230,   232,   236,   238,   241,
     245,   247,   250,   252,   255,   257,   260,   262,   265,   267,
     271,   273,   277,   279,   281,   283,   285,   287,   289,   291,
     293,   295,   297,   299,   301,   303,   305,   307,   309,   311,
     313,   315,   317,   323,   328,   331,   333,   335,   337,   340,
     344,   347,   349,   352,   354,   356,   360,   362,   365,   369,
     374,   380,   386,   393,   396,   398,   402,   404,   408,   410,
     412,   414,   416,   419,   421,   423,   427,   433,   438,   443,
     450,   457,   463,   468,   472,   477,   482,   486,   488,   491,
     494,   498,   500,   503,   505,   509,   511,   515,   518,   521,
     523,   525,   529,   531,   534,   536,   538,   541,   545,   548,
     552,   556,   561,   565,   570,   573,   577,   581,   586,   588,
     592,   597,   599,   602,   606,   611,   614,   616,   619,   623,
     626,   628,   630,   632,   634,   636,   638,   642,   647,   651,
     654,   658,   660,   663,   665,   667,   669,   672,   678,   686,
     692,   698,   706,   713,   721,   728,   736,   740,   743,   746,
     749,   753,   755,   757,   760,   762,   764,   769,   773,   775
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     155,     0,    -1,     3,    -1,     4,    -1,     5,    -1,    79,
     110,    80,    -1,    91,    -1,    92,    81,   110,    82,    -1,
      92,    79,    80,    -1,    92,    79,    93,    80,    -1,    92,
      83,     3,    -1,    92,     7,     3,    -1,    92,     8,    -1,
      92,     9,    -1,    79,   138,    80,    84,   142,    85,    -1,
      79,   138,    80,    84,   142,    86,    85,    -1,   108,    -1,
      93,    86,   108,    -1,    92,    -1,     8,    94,    -1,     9,
      94,    -1,    95,    96,    -1,     6,    94,    -1,     6,    79,
     138,    80,    -1,    54,    -1,    55,    -1,    56,    -1,    57,
      -1,    58,    -1,    59,    -1,    94,    -1,    79,   138,    80,
      96,    -1,    96,    -1,    97,    55,    96,    -1,    97,    60,
      96,    -1,    97,    65,    96,    -1,    97,    -1,    98,    56,
      97,    -1,    98,    57,    97,    -1,    98,    -1,    99,    10,
      98,    -1,    99,    11,    98,    -1,    99,    -1,   100,    61,
      99,    -1,   100,    62,    99,    -1,   100,    12,    99,    -1,
     100,    13,    99,    -1,   100,    -1,   101,    14,   100,    -1,
     101,    15,   100,    -1,   101,    -1,   102,    54,   101,    -1,
     102,    -1,   103,    63,   102,    -1,   103,    -1,   104,    64,
     103,    -1,   104,    -1,   105,    16,   104,    -1,   105,    -1,
     106,    17,   105,    -1,   106,    -1,   106,    87,   110,    88,
     107,    -1,   107,    -1,    94,   109,   108,    -1,    66,    -1,
      18,    -1,    19,    -1,    20,    -1,    21,    -1,    22,    -1,
      23,    -1,    24,    -1,    25,    -1,    26,    -1,    27,    -1,
     108,    -1,   110,    86,   108,    -1,   107,    -1,   113,    89,
      -1,   113,   114,    89,    -1,   116,    -1,   116,   113,    -1,
     117,    -1,   117,   113,    -1,   128,    -1,   128,   113,    -1,
     129,    -1,   129,   113,    -1,   115,    -1,   114,    86,   115,
      -1,   130,    -1,   130,    66,   141,    -1,    29,    -1,    30,
      -1,    31,    -1,    32,    -1,    33,    -1,    46,    -1,    36,
      -1,    37,    -1,    38,    -1,    39,    -1,    42,    -1,    43,
      -1,    40,    -1,    41,    -1,    47,    -1,    48,    -1,    49,
      -1,   118,    -1,   125,    -1,    28,    -1,   119,     3,    84,
     120,    85,    -1,   119,    84,   120,    85,    -1,   119,     3,
      -1,    50,    -1,    51,    -1,   121,    -1,   120,   121,    -1,
     122,   123,    89,    -1,   117,   122,    -1,   117,    -1,   128,
     122,    -1,   128,    -1,   124,    -1,   123,    86,   124,    -1,
     130,    -1,    88,   111,    -1,   130,    88,   111,    -1,    52,
      84,   126,    85,    -1,    52,     3,    84,   126,    85,    -1,
      52,    84,   126,    86,    85,    -1,    52,     3,    84,   126,
      86,    85,    -1,    52,     3,    -1,   127,    -1,   126,    86,
     127,    -1,     3,    -1,     3,    66,   111,    -1,    44,    -1,
      35,    -1,    45,    -1,    34,    -1,   132,   131,    -1,   131,
      -1,     3,    -1,    79,   130,    80,    -1,   131,    81,   133,
     108,    82,    -1,   131,    81,   133,    82,    -1,   131,    81,
     108,    82,    -1,   131,    81,    31,   133,   108,    82,    -1,
     131,    81,   133,    31,   108,    82,    -1,   131,    81,   133,
      55,    82,    -1,   131,    81,    55,    82,    -1,   131,    81,
      82,    -1,   131,    79,   134,    80,    -1,   131,    79,   137,
      80,    -1,   131,    79,    80,    -1,    55,    -1,    55,   133,
      -1,    55,   132,    -1,    55,   133,   132,    -1,   128,    -1,
     133,   128,    -1,   135,    -1,   135,    86,    53,    -1,   136,
      -1,   135,    86,   136,    -1,   113,   130,    -1,   113,   139,
      -1,   113,    -1,     3,    -1,   137,    86,     3,    -1,   122,
      -1,   122,   139,    -1,   132,    -1,   140,    -1,   132,   140,
      -1,    79,   139,    80,    -1,    81,    82,    -1,    81,   108,
      82,    -1,   140,    81,    82,    -1,   140,    81,   108,    82,
      -1,    81,    55,    82,    -1,   140,    81,    55,    82,    -1,
      79,    80,    -1,    79,   134,    80,    -1,   140,    79,    80,
      -1,   140,    79,   134,    80,    -1,   108,    -1,    84,   142,
      85,    -1,    84,   142,    86,    85,    -1,   141,    -1,   143,
     141,    -1,   142,    86,   141,    -1,   142,    86,   143,   141,
      -1,   144,    66,    -1,   145,    -1,   144,   145,    -1,    81,
     111,    82,    -1,    83,     3,    -1,   147,    -1,   148,    -1,
     151,    -1,   152,    -1,   153,    -1,   154,    -1,     3,    88,
     146,    -1,    67,   111,    88,   146,    -1,    68,    88,   146,
      -1,    84,    85,    -1,    84,   149,    85,    -1,   150,    -1,
     149,   150,    -1,   112,    -1,   146,    -1,    89,    -1,   110,
      89,    -1,    69,    79,   110,    80,   146,    -1,    69,    79,
     110,    80,   146,    70,   146,    -1,    71,    79,   110,    80,
     146,    -1,    72,    79,   110,    80,   146,    -1,    73,   146,
      72,    79,   110,    80,    89,    -1,    74,    79,   151,   151,
      80,   146,    -1,    74,    79,   151,   151,   110,    80,   146,
      -1,    74,    79,   112,   151,    80,   146,    -1,    74,    79,
     112,   151,   110,    80,   146,    -1,    75,     3,    89,    -1,
      76,    89,    -1,    77,    89,    -1,    78,    89,    -1,    78,
     110,    89,    -1,   156,    -1,   157,    -1,   156,   157,    -1,
     158,    -1,   112,    -1,   113,   130,   159,   148,    -1,   113,
     130,   148,    -1,   112,    -1,   159,   112,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    45,    45,    46,    47,    48,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    65,    66,    70,    71,
      72,    73,    74,    75,    79,    80,    81,    82,    83,    84,
      88,    89,    93,    94,    95,    96,   100,   101,   102,   106,
     107,   108,   112,   113,   114,   115,   116,   120,   121,   122,
     126,   127,   131,   132,   136,   137,   141,   142,   146,   147,
     151,   152,   156,   157,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   175,   176,   180,   184,   185,
     189,   190,   191,   192,   193,   194,   195,   196,   200,   201,
     205,   206,   210,   211,   212,   213,   214,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   236,   237,   238,   242,   243,   247,   248,   252,
     256,   257,   258,   259,   263,   264,   268,   269,   270,   274,
     275,   276,   277,   278,   282,   283,   287,   288,   292,   293,
     294,   298,   302,   303,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   324,   325,   326,
     327,   331,   332,   337,   338,   342,   343,   347,   348,   349,
     353,   354,   358,   359,   363,   364,   365,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   383,   384,
     385,   389,   390,   391,   392,   396,   400,   401,   405,   406,
     410,   411,   412,   413,   414,   415,   419,   420,   421,   425,
     426,   430,   431,   435,   436,   440,   441,   445,   446,   447,
     451,   452,   453,   454,   455,   456,   460,   461,   462,   463,
     464,   468,   471,   472,   476,   477,   481,   482,   486,   487
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "INLINE",
  "RESTRICT", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID", "BOOL", "COMPLEX",
  "IMAGINARY", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "'&'", "'*'", "'+'",
  "'-'", "'~'", "'!'", "'/'", "'<'", "'>'", "'^'", "'|'", "'%'", "'='",
  "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "'('", "')'", "'['", "']'", "'.'", "'{'",
  "'}'", "','", "'?'", "':'", "';'", "$accept", "primary_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "function_specifier", "declarator",
  "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "designation", "designator_list", "designator", "statement",
  "labeled_statement", "compound_statement", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "start", "translation_unit",
  "external_declaration", "function_definition", "declaration_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    38,    42,    43,    45,   126,    33,
      47,    60,    62,    94,   124,    37,    61,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,    40,
      41,    91,    93,    46,   123,   125,    44,    63,    58,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    91,    91,    91,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    93,    93,    94,    94,
      94,    94,    94,    94,    95,    95,    95,    95,    95,    95,
      96,    96,    97,    97,    97,    97,    98,    98,    98,    99,
      99,    99,   100,   100,   100,   100,   100,   101,   101,   101,
     102,   102,   103,   103,   104,   104,   105,   105,   106,   106,
     107,   107,   108,   108,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   110,   110,   111,   112,   112,
     113,   113,   113,   113,   113,   113,   113,   113,   114,   114,
     115,   115,   116,   116,   116,   116,   116,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   118,   118,   118,   119,   119,   120,   120,   121,
     122,   122,   122,   122,   123,   123,   124,   124,   124,   125,
     125,   125,   125,   125,   126,   126,   127,   127,   128,   128,
     128,   129,   130,   130,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   132,   132,   132,
     132,   133,   133,   134,   134,   135,   135,   136,   136,   136,
     137,   137,   138,   138,   139,   139,   139,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   141,   141,
     141,   142,   142,   142,   142,   143,   144,   144,   145,   145,
     146,   146,   146,   146,   146,   146,   147,   147,   147,   148,
     148,   149,   149,   150,   150,   151,   151,   152,   152,   152,
     153,   153,   153,   153,   153,   153,   154,   154,   154,   154,
     154,   155,   156,   156,   157,   157,   158,   158,   159,   159
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     6,     7,     1,     3,     1,     2,
       2,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     3,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     4,     2,     1,     1,     1,     2,     3,
       2,     1,     2,     1,     1,     3,     1,     2,     3,     4,
       5,     5,     6,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     2,     1,     1,     3,     5,     4,     4,     6,
       6,     5,     4,     3,     4,     4,     3,     1,     2,     2,
       3,     1,     2,     1,     3,     1,     3,     2,     2,     1,
       1,     3,     1,     2,     1,     1,     2,     3,     2,     3,
       3,     4,     3,     4,     2,     3,     3,     4,     1,     3,
       4,     1,     2,     3,     4,     2,     1,     2,     3,     2,
       1,     1,     1,     1,     1,     1,     3,     4,     3,     2,
       3,     1,     2,     1,     1,     1,     2,     5,     7,     5,
       5,     7,     6,     7,     6,     7,     3,     2,     2,     2,
       3,     1,     1,     2,     1,     1,     4,     3,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   111,    92,    93,    94,    95,    96,   141,   139,    98,
      99,   100,   101,   104,   105,   102,   103,   138,   140,    97,
     106,   107,   108,   115,   116,     0,   235,     0,    80,    82,
     109,     0,   110,    84,    86,     0,   231,   232,   234,   133,
       0,   144,   157,     0,    78,     0,    88,    90,   143,     0,
      81,    83,   114,     0,    85,    87,     1,   233,     0,   136,
       0,   134,   161,   159,   158,     0,     0,    79,     0,     0,
     238,     0,   237,     0,     0,     0,   142,     0,   121,     0,
     117,     0,   123,     0,     0,   129,     0,   162,   160,   145,
      89,    90,     2,     3,     4,     0,     0,     0,    24,    25,
      26,    27,    28,    29,     0,     0,     6,    18,    30,     0,
      32,    36,    39,    42,    47,    50,    52,    54,    56,    58,
      60,    62,   188,    91,     2,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   209,   215,    75,     0,
     213,   214,   200,   201,     0,   211,   202,   203,   204,   205,
     239,   236,   170,   156,   169,     0,   163,   165,     0,     0,
      25,   153,     0,     0,     0,   120,   113,   118,     0,     0,
     124,   126,   122,   130,     0,    30,    77,   137,   131,   135,
       0,    22,     0,    19,    20,     0,   172,     0,     0,     0,
     191,     0,     0,     0,   196,     0,    12,    13,     0,     0,
       0,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    64,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   227,   228,   229,     0,     0,   216,   210,   212,
       0,     0,   167,   174,   168,   175,   154,     0,   155,     0,
       0,   152,   148,     0,    25,   147,     0,   112,   127,     0,
     119,     0,   132,     0,     0,     5,     0,   174,   173,     0,
       0,   199,   189,     0,   192,   195,   197,    11,     8,     0,
      16,     0,    10,    63,    33,    34,    35,    37,    38,    40,
      41,    45,    46,    43,    44,    48,    49,    51,    53,    55,
      57,    59,     0,   206,     0,   208,     0,     0,     0,     0,
       0,     0,   226,   230,    76,   184,     0,     0,    25,   178,
       0,   176,     0,     0,   164,   166,   171,     0,     0,   151,
     146,   125,   128,    23,     0,     0,    31,   198,   190,   193,
       0,     9,     0,     7,     0,   207,     0,     0,     0,     0,
       0,     0,   185,   177,   182,   179,   186,     0,    25,   180,
       0,   149,   150,     0,   194,    17,    61,   217,   219,   220,
       0,     0,     0,     0,     0,   187,   183,   181,    14,     0,
       0,     0,   224,     0,   222,     0,    15,   218,   221,   225,
     223
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   106,   107,   289,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   138,   212,
     139,   177,    26,    71,    45,    46,    28,    29,    30,    31,
      79,    80,    81,   169,   170,    32,    60,    61,    33,    34,
      65,    48,    49,    64,   326,   156,   157,   158,   187,   327,
     255,   190,   191,   192,   193,   194,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    35,    36,    37,    38,    73
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -273
static const yytype_int16 yypact[] =
{
    1361,  -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,
    -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,
    -273,  -273,  -273,  -273,  -273,    13,  -273,    10,  1361,  1361,
    -273,    20,  -273,  1361,  1361,    78,  1361,  -273,  -273,   -29,
      79,  -273,   145,    32,  -273,    -6,  -273,  1172,   -25,    49,
    -273,  -273,    28,  1279,  -273,  -273,  -273,  -273,    79,    53,
     -18,  -273,  -273,  -273,   145,    44,    32,  -273,   686,   306,
    -273,    10,  -273,  1229,   907,   724,   -25,  1279,  1279,   672,
    -273,     6,  1279,   173,  1094,  -273,    21,  -273,  -273,  -273,
    -273,    82,  -273,  -273,  -273,  1102,  1120,  1120,  -273,  -273,
    -273,  -273,  -273,  -273,  1030,   604,  -273,   168,   387,  1094,
    -273,    26,   211,   261,   120,   265,   124,    66,   119,   172,
       3,  -273,  -273,  -273,   116,  1094,   136,   141,   152,   164,
     489,   177,   259,   176,   180,   496,  -273,  -273,  -273,    54,
    -273,  -273,  -273,  -273,   393,  -273,  -273,  -273,  -273,  -273,
    -273,  -273,  -273,  -273,    55,   197,   202,  -273,   -27,   102,
     210,  -273,   216,   781,   962,  -273,  -273,  -273,  1094,   113,
    -273,   214,  -273,  -273,    24,  -273,  -273,  -273,  -273,  -273,
    1030,  -273,  1030,  -273,  -273,   -11,    -9,   219,  1094,   301,
    -273,   196,   686,    -4,  -273,   302,  -273,  -273,   909,  1094,
     303,  -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,
    -273,  -273,  1094,  -273,  1094,  1094,  1094,  1094,  1094,  1094,
    1094,  1094,  1094,  1094,  1094,  1094,  1094,  1094,  1094,  1094,
    1094,  1094,  1094,   489,   225,   489,  1094,  1094,  1094,   244,
     480,   228,  -273,  -273,  -273,   139,  1094,  -273,  -273,  -273,
     853,   788,  -273,    63,  -273,    90,  -273,  1333,  -273,   315,
    1087,  -273,  -273,  1094,   237,  -273,   238,  -273,  -273,     6,
    -273,  1094,  -273,   241,   245,  -273,  1254,   151,  -273,   693,
     246,  -273,  -273,   585,  -273,  -273,  -273,  -273,  -273,   112,
    -273,   129,  -273,  -273,  -273,  -273,  -273,    26,    26,   211,
     211,   261,   261,   261,   261,   120,   120,   265,   124,    66,
     119,   172,   153,  -273,   489,  -273,   115,   127,   132,   248,
     578,   578,  -273,  -273,  -273,  -273,   249,   250,   251,  -273,
     277,    90,  1308,   796,  -273,  -273,  -273,   284,   285,  -273,
    -273,  -273,  -273,   247,   247,   604,  -273,  -273,  -273,  -273,
     686,  -273,  1094,  -273,  1094,  -273,   489,   489,   489,  1094,
     916,   973,  -273,  -273,  -273,  -273,  -273,   288,   287,  -273,
     289,  -273,  -273,   201,  -273,  -273,  -273,   300,  -273,  -273,
     147,   489,   149,   489,   160,  -273,  -273,  -273,  -273,   592,
     489,   283,  -273,   489,  -273,   489,  -273,  -273,  -273,  -273,
    -273
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -273,  -273,  -273,  -273,   -65,  -273,   -94,    73,    74,    31,
      75,   159,   148,   158,   162,   157,  -273,   -80,   -67,  -273,
     -64,  -104,   -30,     0,  -273,   323,  -273,    23,  -273,  -273,
     316,   -57,   -41,  -273,   125,  -273,   342,   -79,   144,  -273,
     -24,   -44,   -16,   -61,   -68,  -273,   146,  -273,    62,  -136,
    -204,   -66,    70,  -272,  -273,   223,  -120,  -273,   -22,  -273,
     273,  -228,  -273,  -273,  -273,  -273,  -273,   382,  -273,  -273
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      27,   122,   123,    47,   176,    76,   155,   179,   162,    41,
     239,   350,   321,    41,   163,   213,    39,    70,   254,   175,
     231,   234,   167,    52,    59,    72,    63,    59,    50,    51,
     181,   183,   184,    54,    55,    41,    27,   165,   122,   140,
     185,   172,    91,   150,   175,   176,    42,    91,    88,   331,
     278,   151,    41,   258,    74,    58,    75,   171,    41,   259,
     175,    42,   285,   186,   268,    42,    41,    85,    86,   275,
     276,   245,   251,   331,   154,   246,    78,   188,    56,   189,
      66,   214,    59,    67,   280,    43,   215,    42,   176,    43,
     232,   216,   360,   361,   168,   179,   266,    40,   260,    44,
      78,    78,    78,   175,    53,    78,   178,   167,   176,   272,
      42,    43,    77,   313,   140,   315,   185,   350,   185,    84,
     294,   295,   296,   175,    89,   122,   284,    78,    43,   228,
     252,   290,   221,   222,   250,   291,   251,     8,   253,   186,
     246,   186,   250,   247,   251,   293,    17,    18,    68,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   342,   312,   332,
     277,   333,   316,   317,   318,   195,   196,   197,   227,   324,
       8,   223,   224,   229,   330,   346,    62,    78,   230,    17,
      18,   176,   351,   337,   355,   356,   338,    82,   352,   269,
      42,   246,   270,    78,   233,    78,   175,   357,    87,    76,
     320,   353,   358,   246,   175,   246,   122,   349,   246,    62,
     236,    82,    82,    82,   235,   246,    82,   391,   323,   393,
     276,   237,   251,   246,   253,   246,   377,   378,   379,   246,
     395,   354,   273,   238,   274,   171,   246,   198,    82,   199,
     154,   200,   301,   302,   303,   304,   240,   154,   173,   174,
     277,   392,   241,   394,   367,   242,   370,   217,   218,   243,
     397,   219,   220,   399,   376,   400,   154,   256,   122,   225,
     226,   282,   283,   122,   374,   375,   388,   389,   257,   175,
     297,   298,   261,   299,   300,   380,   382,   384,   262,   279,
     305,   306,   271,    62,   281,   287,   292,    87,    82,   124,
      93,    94,    95,   314,    96,    97,   319,   322,   336,   339,
     340,   343,   122,   349,    82,   344,    82,   359,   347,   362,
     363,   345,   154,   364,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   365,
      98,    99,   100,   101,   102,   103,   371,   372,   385,   386,
     390,   387,   398,   125,   126,   127,   308,   128,   129,   130,
     131,   132,   133,   134,   135,   104,   307,   309,   311,    90,
      69,   136,   310,   164,   341,   137,   124,    93,    94,    95,
      83,    96,    97,   335,    87,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   373,   286,   249,    57,     0,
       0,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,    98,    99,   100,
     101,   102,   103,   211,     0,     0,     0,     0,     0,     0,
     125,   126,   127,     0,   128,   129,   130,   131,   132,   133,
     134,   135,   104,     0,     0,     0,     0,    69,   248,     0,
       0,     0,   137,    92,    93,    94,    95,     0,    96,    97,
       0,     0,   124,    93,    94,    95,     0,    96,    97,    92,
      93,    94,    95,     0,    96,    97,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,    98,    99,   100,   101,   102,   103,
       0,     0,     0,    98,    99,   100,   101,   102,   103,     0,
      98,    99,   100,   101,   102,   103,   125,   126,   127,   104,
     128,   129,   130,   131,   132,   133,   134,   135,   104,   137,
       0,     0,     0,    69,     0,   104,     0,     0,   137,     0,
       0,    92,    93,    94,    95,   244,    96,    97,    92,    93,
      94,    95,     0,    96,    97,    92,    93,    94,    95,     0,
      96,    97,     0,     0,     0,     0,     0,    92,    93,    94,
      95,     0,    96,    97,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,    98,
      99,   100,   101,   102,   103,     0,    98,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,   104,    98,    99,
     100,   101,   102,   103,   104,     0,   188,   137,   189,   105,
     348,   104,     0,   188,     0,   189,   105,   396,     0,     0,
       0,     0,     0,   104,     0,   188,     0,   189,   105,    92,
      93,    94,    95,     0,    96,    97,    92,    93,    94,    95,
       1,    96,    97,     0,     0,     0,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,     0,    92,    93,    94,
      95,     0,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,     0,    98,    99,   100,
     101,   102,   103,     0,     0,   159,     0,   166,     0,     8,
       0,     0,     0,     0,     0,   104,     0,     0,    17,    18,
     105,     0,   104,     0,     0,     0,     0,   345,    98,   160,
     100,   101,   102,   103,    92,    93,    94,    95,     0,    96,
      97,    92,    93,    94,    95,     0,    96,    97,     0,    92,
      93,    94,    95,   104,    96,    97,   161,     0,     0,     0,
       0,     0,   263,     0,     0,     0,     8,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    18,     0,     0,     0,
       0,     0,     0,     0,     0,    98,   264,   100,   101,   102,
     103,     0,    98,   328,   100,   101,   102,   103,     0,     0,
      98,   368,   100,   101,   102,   103,    41,     0,     0,     0,
     104,     0,     0,   265,     0,     0,     0,   104,     0,     0,
     329,     0,     0,     0,     0,   104,     0,     0,   369,     0,
       0,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,    42,     0,
     152,     0,    92,    93,    94,    95,     0,    96,    97,    92,
      93,    94,    95,     0,    96,    97,     0,     0,     0,     0,
       0,     0,   250,   325,   251,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,    98,    99,   100,   101,   102,   103,     0,
      98,    99,   100,   101,   102,   103,    92,    93,    94,    95,
       0,    96,    97,     0,     0,     0,     0,   153,   104,   288,
       1,     0,     0,     0,     0,   104,   381,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,    92,    93,    94,    95,     0,    96,    97,
       0,     0,     0,     0,     0,     0,     0,   267,     0,     0,
       0,     0,   104,   383,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,    98,    99,   100,   101,   102,   103,
      92,    93,    94,    95,     0,    96,    97,    92,    93,    94,
      95,     0,    96,    97,     0,    92,    93,    94,    95,   104,
      96,    97,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,    92,    93,    94,    95,     0,    96,    97,
       0,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,     0,    98,    99,
     100,   101,   102,   103,     0,     0,    98,    99,   100,   101,
     102,   103,     0,     0,     0,     0,   104,     0,     0,     0,
       0,     0,     0,   104,    98,    99,   100,   101,   102,   103,
       0,   180,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   182,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     1,     0,    42,
       0,     0,     0,    69,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,   276,   325,   251,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   334,     0,   366,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25
};

static const yytype_int16 yycheck[] =
{
       0,    68,    68,    27,    84,    49,    74,    86,    75,     3,
     130,   283,   240,     3,    75,   109,     3,    47,   154,    84,
      17,   125,    79,     3,     3,    47,    42,     3,    28,    29,
      95,    96,    97,    33,    34,     3,    36,    78,   105,    69,
     104,    82,    66,    73,   109,   125,    55,    71,    64,   253,
     186,    73,     3,    80,    79,    84,    81,    81,     3,    86,
     125,    55,    66,   104,   168,    55,     3,    85,    86,    80,
      79,   135,    81,   277,    74,    86,    53,    81,     0,    83,
      86,    55,     3,    89,   188,    79,    60,    55,   168,    79,
      87,    65,   320,   321,    88,   174,   163,    84,   159,    89,
      77,    78,    79,   168,    84,    82,    85,   164,   188,    85,
      55,    79,    84,   233,   144,   235,   180,   389,   182,    66,
     214,   215,   216,   188,    80,   192,   192,   104,    79,    63,
     154,   198,    12,    13,    79,   199,    81,    35,   154,   180,
      86,   182,    79,    89,    81,   212,    44,    45,    66,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   271,   232,    79,
     186,    81,   236,   237,   238,     7,     8,     9,    54,   246,
      35,    61,    62,    64,   251,   279,    42,   164,    16,    44,
      45,   271,    80,   260,   314,    80,   263,    53,    86,    86,
      55,    86,    89,   180,    88,   182,   271,    80,    64,   253,
     240,    82,    80,    86,   279,    86,   283,   283,    86,    75,
      79,    77,    78,    79,    88,    86,    82,    80,    89,    80,
      79,    79,    81,    86,   250,    86,   356,   357,   358,    86,
      80,    88,   180,    79,   182,   269,    86,    79,   104,    81,
     250,    83,   221,   222,   223,   224,    79,   257,    85,    86,
     276,   381,     3,   383,   332,    89,   333,    56,    57,    89,
     390,    10,    11,   393,   354,   395,   276,    80,   345,    14,
      15,    85,    86,   350,   350,   352,    85,    86,    86,   354,
     217,   218,    82,   219,   220,   359,   360,   361,    82,    80,
     225,   226,    88,   159,     3,     3,     3,   163,   164,     3,
       4,     5,     6,    88,     8,     9,    72,    89,     3,    82,
      82,    80,   389,   389,   180,    80,   182,    79,    82,    80,
      80,    84,   332,    82,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    82,
      54,    55,    56,    57,    58,    59,    82,    82,    80,    82,
      70,    82,    89,    67,    68,    69,   228,    71,    72,    73,
      74,    75,    76,    77,    78,    79,   227,   229,   231,    66,
      84,    85,   230,    77,   269,    89,     3,     4,     5,     6,
      58,     8,     9,   257,   260,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   345,   193,   144,    36,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    -1,    -1,    -1,    -1,    84,    85,    -1,
      -1,    -1,    89,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,     3,     4,     5,     6,    -1,     8,     9,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    56,    57,    58,    59,
      -1,    -1,    -1,    54,    55,    56,    57,    58,    59,    -1,
      54,    55,    56,    57,    58,    59,    67,    68,    69,    79,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    89,
      -1,    -1,    -1,    84,    -1,    79,    -1,    -1,    89,    -1,
      -1,     3,     4,     5,     6,    89,     8,     9,     3,     4,
       5,     6,    -1,     8,     9,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,    56,    57,    58,    59,    -1,    54,
      55,    56,    57,    58,    59,    -1,    54,    55,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    -1,    79,    54,    55,
      56,    57,    58,    59,    79,    -1,    81,    89,    83,    84,
      85,    79,    -1,    81,    -1,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    81,    -1,    83,    84,     3,
       4,     5,     6,    -1,     8,     9,     3,     4,     5,     6,
      28,     8,     9,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    56,    57,    58,    59,    -1,    54,    55,    56,
      57,    58,    59,    -1,    -1,    31,    -1,    85,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    44,    45,
      84,    -1,    79,    -1,    -1,    -1,    -1,    84,    54,    55,
      56,    57,    58,    59,     3,     4,     5,     6,    -1,     8,
       9,     3,     4,     5,     6,    -1,     8,     9,    -1,     3,
       4,     5,     6,    79,     8,     9,    82,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    56,    57,    58,
      59,    -1,    54,    55,    56,    57,    58,    59,    -1,    -1,
      54,    55,    56,    57,    58,    59,     3,    -1,    -1,    -1,
      79,    -1,    -1,    82,    -1,    -1,    -1,    79,    -1,    -1,
      82,    -1,    -1,    -1,    -1,    79,    -1,    -1,    82,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    55,    -1,
       3,    -1,     3,     4,     5,     6,    -1,     8,     9,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    80,    81,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    -1,    -1,    54,    55,    56,    57,    58,    59,    -1,
      54,    55,    56,    57,    58,    59,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    80,    79,    80,
      28,    -1,    -1,    -1,    -1,    79,    80,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,
      57,    58,    59,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    -1,    79,    80,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    56,    57,    58,    59,
       3,     4,     5,     6,    -1,     8,     9,     3,     4,     5,
       6,    -1,     8,     9,    -1,     3,     4,     5,     6,    79,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,     3,     4,     5,     6,    -1,     8,     9,
      -1,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    56,    57,    58,    59,    -1,    54,    55,
      56,    57,    58,    59,    -1,    -1,    54,    55,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    54,    55,    56,    57,    58,    59,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    28,    -1,    55,
      -1,    -1,    -1,    84,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    79,    80,    81,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    80,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,   112,   113,   116,   117,
     118,   119,   125,   128,   129,   155,   156,   157,   158,     3,
      84,     3,    55,    79,    89,   114,   115,   130,   131,   132,
     113,   113,     3,    84,   113,   113,     0,   157,    84,     3,
     126,   127,   128,   132,   133,   130,    86,    89,    66,    84,
     112,   113,   148,   159,    79,    81,   131,    84,   117,   120,
     121,   122,   128,   126,    66,    85,    86,   128,   132,    80,
     115,   130,     3,     4,     5,     6,     8,     9,    54,    55,
      56,    57,    58,    59,    79,    84,    91,    92,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   141,     3,    67,    68,    69,    71,    72,
      73,    74,    75,    76,    77,    78,    85,    89,   108,   110,
     112,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     112,   148,     3,    80,   113,   134,   135,   136,   137,    31,
      55,    82,   108,   133,   120,   122,    85,   121,    88,   123,
     124,   130,   122,    85,    86,    94,   107,   111,    85,   127,
      79,    94,    79,    94,    94,   110,   122,   138,    81,    83,
     141,   142,   143,   144,   145,     7,     8,     9,    79,    81,
      83,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    66,   109,    96,    55,    60,    65,    56,    57,    10,
      11,    12,    13,    61,    62,    14,    15,    54,    63,    64,
      16,    17,    87,    88,   111,    88,    79,    79,    79,   146,
      79,     3,    89,    89,    89,   110,    86,    89,    85,   150,
      79,    81,   130,   132,   139,   140,    80,    86,    80,    86,
     133,    82,    82,    31,    55,    82,   108,    85,   111,    86,
      89,    88,    85,   138,   138,    80,    79,   132,   139,    80,
     111,     3,    85,    86,   141,    66,   145,     3,    80,    93,
     108,   110,     3,   108,    96,    96,    96,    97,    97,    98,
      98,    99,    99,    99,    99,   100,   100,   101,   102,   103,
     104,   105,   110,   146,    88,   146,   110,   110,   110,    72,
     112,   151,    89,    89,   108,    80,   134,   139,    55,    82,
     108,   140,    79,    81,    53,   136,     3,   108,   108,    82,
      82,   124,   111,    80,    80,    84,    96,    82,    85,   141,
     143,    80,    86,    82,    88,   146,    80,    80,    80,    79,
     151,   151,    80,    80,    82,    82,    80,   134,    55,    82,
     108,    82,    82,   142,   141,   108,   107,   146,   146,   146,
     110,    80,   110,    80,   110,    80,    82,    82,    85,    86,
      70,    80,   146,    80,   146,    80,    85,   146,    89,   146,
     146
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 45 "compiler.y"
    {(yyval.Node)=new node("primary_expression",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 3:
#line 46 "compiler.y"
    {(yyval.Node)=new node("primary_expression",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 4:
#line 47 "compiler.y"
    {(yyval.Node)=new node("primary_expression",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 5:
#line 48 "compiler.y"
    {(yyval.Node)=(yyvsp[(2) - (3)].Node);;}
    break;

  case 6:
#line 52 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 7:
#line 53 "compiler.y"
    {node* t=(yyvsp[(1) - (4)].Node);while(t->next)t=t->next;t->next=(yyvsp[(3) - (4)].Node);;}
    break;

  case 9:
#line 55 "compiler.y"
    {node* t=(yyvsp[(1) - (4)].Node);while(t->next)t=t->next;t->next=(yyvsp[(3) - (4)].Node);;}
    break;

  case 16:
#line 65 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 17:
#line 66 "compiler.y"
    {node* t=(yyvsp[(1) - (3)].Node);while(t->next)t=t->next;t->next=(yyvsp[(3) - (3)].Node);;}
    break;

  case 18:
#line 70 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 24:
#line 79 "compiler.y"
    {(yyval.Node)=new node("unary_operator",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 25:
#line 80 "compiler.y"
    {(yyval.Node)=new node("unary_operator",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 26:
#line 81 "compiler.y"
    {(yyval.Node)=new node("unary_operator",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 27:
#line 82 "compiler.y"
    {(yyval.Node)=new node("unary_operator",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 28:
#line 83 "compiler.y"
    {(yyval.Node)=new node("unary_operator",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 29:
#line 84 "compiler.y"
    {(yyval.Node)=new node("unary_operator",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 30:
#line 88 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 32:
#line 93 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 33:
#line 94 "compiler.y"
    {(yyval.Node)=new node("multiplicative_expression",NULL,0); (yyval.Node)->addSub(3,(yyvsp[(1) - (3)].Node),new node("unary_operator",NULL,1,(yyvsp[(2) - (3)].Element)),(yyvsp[(3) - (3)].Node));;}
    break;

  case 34:
#line 95 "compiler.y"
    {(yyval.Node)=new node("multiplicative_expression",NULL,0); (yyval.Node)->addSub(3,(yyvsp[(1) - (3)].Node),new node("unary_operator",NULL,1,(yyvsp[(2) - (3)].Element)),(yyvsp[(3) - (3)].Node));;}
    break;

  case 35:
#line 96 "compiler.y"
    {(yyval.Node)=new node("multiplicative_expression",NULL,0); (yyval.Node)->addSub(3,(yyvsp[(1) - (3)].Node),new node("unary_operator",NULL,1,(yyvsp[(2) - (3)].Element)),(yyvsp[(3) - (3)].Node));;}
    break;

  case 36:
#line 100 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 37:
#line 101 "compiler.y"
    {(yyval.Node)=new node("additive_expression",NULL,0); (yyval.Node)->addSub(3,(yyvsp[(1) - (3)].Node),new node("unary_operator",NULL,1,(yyvsp[(2) - (3)].Element)),(yyvsp[(3) - (3)].Node));;}
    break;

  case 38:
#line 102 "compiler.y"
    {(yyval.Node)=new node("additive_expression",NULL,0); (yyval.Node)->addSub(3,(yyvsp[(1) - (3)].Node),new node("unary_operator",NULL,1,(yyvsp[(2) - (3)].Element)),(yyvsp[(3) - (3)].Node));;}
    break;

  case 39:
#line 106 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 40:
#line 107 "compiler.y"
    {(yyval.Node)=new node("shift_expression",NULL,0); (yyval.Node)->addSub(3,(yyvsp[(1) - (3)].Node),new node("unary_operator",NULL,1,(yyvsp[(2) - (3)].Element)),(yyvsp[(3) - (3)].Node));;}
    break;

  case 41:
#line 108 "compiler.y"
    {(yyval.Node)=new node("shift_expression",NULL,0); (yyval.Node)->addSub(3,(yyvsp[(1) - (3)].Node),new node("unary_operator",NULL,1,(yyvsp[(2) - (3)].Element)),(yyvsp[(3) - (3)].Node));;}
    break;

  case 42:
#line 112 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 43:
#line 113 "compiler.y"
    {(yyval.Node)=new node("relational_expression",NULL,0); (yyval.Node)->addSub(3,(yyvsp[(1) - (3)].Node),new node("unary_operator",NULL,1,(yyvsp[(2) - (3)].Element)),(yyvsp[(3) - (3)].Node));;}
    break;

  case 44:
#line 114 "compiler.y"
    {(yyval.Node)=new node("relational_expression",NULL,0); (yyval.Node)->addSub(3,(yyvsp[(1) - (3)].Node),new node("unary_operator",NULL,1,(yyvsp[(2) - (3)].Element)),(yyvsp[(3) - (3)].Node));;}
    break;

  case 45:
#line 115 "compiler.y"
    {(yyval.Node)=new node("relational_expression",NULL,0); (yyval.Node)->addSub(3,(yyvsp[(1) - (3)].Node),new node("unary_operator",NULL,1,(yyvsp[(2) - (3)].Element)),(yyvsp[(3) - (3)].Node));;}
    break;

  case 46:
#line 116 "compiler.y"
    {(yyval.Node)=new node("relational_expression",NULL,0); (yyval.Node)->addSub(3,(yyvsp[(1) - (3)].Node),new node("unary_operator",NULL,1,(yyvsp[(2) - (3)].Element)),(yyvsp[(3) - (3)].Node));;}
    break;

  case 47:
#line 120 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 48:
#line 121 "compiler.y"
    {(yyval.Node)=new node("equality_expression",NULL,0); (yyval.Node)->addSub(3,(yyvsp[(1) - (3)].Node),new node("unary_operator",NULL,1,(yyvsp[(2) - (3)].Element)),(yyvsp[(3) - (3)].Node));;}
    break;

  case 49:
#line 122 "compiler.y"
    {(yyval.Node)=new node("equality_expression",NULL,0); (yyval.Node)->addSub(3,(yyvsp[(1) - (3)].Node),new node("unary_operator",NULL,1,(yyvsp[(2) - (3)].Element)),(yyvsp[(3) - (3)].Node));;}
    break;

  case 50:
#line 126 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 51:
#line 127 "compiler.y"
    {(yyval.Node)=new node("and_expression",NULL,0); (yyval.Node)->addSub(3,(yyvsp[(1) - (3)].Node),new node("unary_operator",NULL,1,(yyvsp[(2) - (3)].Element)),(yyvsp[(3) - (3)].Node));;}
    break;

  case 52:
#line 131 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 53:
#line 132 "compiler.y"
    {(yyval.Node)=new node("exclusive_or_expression",NULL,0); (yyval.Node)->addSub(3,(yyvsp[(1) - (3)].Node),new node("unary_operator",NULL,1,(yyvsp[(2) - (3)].Element)),(yyvsp[(3) - (3)].Node));;}
    break;

  case 54:
#line 136 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 55:
#line 137 "compiler.y"
    {(yyval.Node)=new node("exclusive_or_expression",NULL,0); (yyval.Node)->addSub(3,(yyvsp[(1) - (3)].Node),new node("unary_operator",NULL,1,(yyvsp[(2) - (3)].Element)),(yyvsp[(3) - (3)].Node));;}
    break;

  case 56:
#line 141 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 57:
#line 142 "compiler.y"
    {(yyval.Node)=new node("logical_and_expression",NULL,0); (yyval.Node)->addSub(3,(yyvsp[(1) - (3)].Node),new node("unary_operator",NULL,1,(yyvsp[(2) - (3)].Element)),(yyvsp[(3) - (3)].Node));;}
    break;

  case 58:
#line 146 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 59:
#line 147 "compiler.y"
    {(yyval.Node)=new node("logical_or_expression",NULL,0); (yyval.Node)->addSub(3,(yyvsp[(1) - (3)].Node),new node("unary_operator",NULL,1,(yyvsp[(2) - (3)].Element)),(yyvsp[(3) - (3)].Node));;}
    break;

  case 60:
#line 151 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 61:
#line 152 "compiler.y"
    {(yyval.Node)=new node("conditional_expression",NULL,0); (yyval.Node)->addSub(3,(yyvsp[(1) - (5)].Node),(yyvsp[(3) - (5)].Node),(yyvsp[(5) - (5)].Node));;}
    break;

  case 62:
#line 156 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 63:
#line 157 "compiler.y"
    {(yyval.Node)=new node("assignment_expression",NULL,0);(yyval.Node)->addContents(3,(yyvsp[(1) - (3)].Node),(yyvsp[(2) - (3)].Node),(yyvsp[(3) - (3)].Node));;}
    break;

  case 64:
#line 161 "compiler.y"
    {(yyval.Node)=new node("assignment_operator",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 65:
#line 162 "compiler.y"
    {(yyval.Node)=new node("assignment_operator",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 66:
#line 163 "compiler.y"
    {(yyval.Node)=new node("assignment_operator",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 67:
#line 164 "compiler.y"
    {(yyval.Node)=new node("assignment_operator",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 68:
#line 165 "compiler.y"
    {(yyval.Node)=new node("assignment_operator",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 69:
#line 166 "compiler.y"
    {(yyval.Node)=new node("assignment_operator",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 70:
#line 167 "compiler.y"
    {(yyval.Node)=new node("assignment_operator",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 71:
#line 168 "compiler.y"
    {(yyval.Node)=new node("assignment_operator",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 72:
#line 169 "compiler.y"
    {(yyval.Node)=new node("assignment_operator",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 73:
#line 170 "compiler.y"
    {(yyval.Node)=new node("assignment_operator",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 74:
#line 171 "compiler.y"
    {(yyval.Node)=new node("assignment_operator",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 75:
#line 175 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 77:
#line 180 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 79:
#line 185 "compiler.y"
    {(yyval.Node)=new node("declaration",NULL,0);(yyval.Node)->addContents(2,(yyvsp[(1) - (3)].Node),(yyvsp[(2) - (3)].Node));;}
    break;

  case 80:
#line 189 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 81:
#line 190 "compiler.y"
    {(yyval.Node)=new node("declaration_specifiers",NULL,0);(yyval.Node)->addContents(2,(yyvsp[(1) - (2)].Node),(yyvsp[(2) - (2)].Node));;}
    break;

  case 82:
#line 191 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 83:
#line 192 "compiler.y"
    {(yyval.Node)=new node("declaration_specifiers",NULL,0);(yyval.Node)->addContents(2,(yyvsp[(1) - (2)].Node),(yyvsp[(2) - (2)].Node));;}
    break;

  case 84:
#line 193 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 85:
#line 194 "compiler.y"
    {(yyval.Node)=new node("declaration_specifiers",NULL,0);(yyval.Node)->addContents(2,(yyvsp[(1) - (2)].Node),(yyvsp[(2) - (2)].Node));;}
    break;

  case 86:
#line 195 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 87:
#line 196 "compiler.y"
    {(yyval.Node)=new node("declaration_specifiers",NULL,0);(yyval.Node)->addContents(2,(yyvsp[(1) - (2)].Node),(yyvsp[(2) - (2)].Node));;}
    break;

  case 88:
#line 200 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 89:
#line 201 "compiler.y"
    {(yyval.Node)=new node("init_declarator_list",NULL,0);(yyval.Node)->addContents(2,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node));;}
    break;

  case 90:
#line 205 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 91:
#line 206 "compiler.y"
    {(yyval.Node)=new node("init_declarator",NULL,0);(yyval.Node)->addContents(2,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node));;}
    break;

  case 92:
#line 210 "compiler.y"
    {(yyval.Node)=new node("storage_class_specifier",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 93:
#line 211 "compiler.y"
    {(yyval.Node)=new node("storage_class_specifier",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 94:
#line 212 "compiler.y"
    {(yyval.Node)=new node("storage_class_specifier",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 95:
#line 213 "compiler.y"
    {(yyval.Node)=new node("storage_class_specifier",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 96:
#line 214 "compiler.y"
    {(yyval.Node)=new node("storage_class_specifier",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 97:
#line 218 "compiler.y"
    {(yyval.Node)=new node("type_specifier",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 98:
#line 219 "compiler.y"
    {(yyval.Node)=new node("type_specifier",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 99:
#line 220 "compiler.y"
    {(yyval.Node)=new node("type_specifier",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 100:
#line 221 "compiler.y"
    {(yyval.Node)=new node("type_specifier",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 101:
#line 222 "compiler.y"
    {(yyval.Node)=new node("type_specifier",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 102:
#line 223 "compiler.y"
    {(yyval.Node)=new node("type_specifier",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 103:
#line 224 "compiler.y"
    {(yyval.Node)=new node("type_specifier",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 104:
#line 225 "compiler.y"
    {(yyval.Node)=new node("type_specifier",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 105:
#line 226 "compiler.y"
    {(yyval.Node)=new node("type_specifier",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 106:
#line 227 "compiler.y"
    {(yyval.Node)=new node("type_specifier",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 138:
#line 292 "compiler.y"
    {(yyval.Node)=new node("type_qualifier",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 139:
#line 293 "compiler.y"
    {(yyval.Node)=new node("type_qualifier",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 140:
#line 294 "compiler.y"
    {(yyval.Node)=new node("type_qualifier",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 141:
#line 298 "compiler.y"
    {(yyval.Node)=new node("function_specifier",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 143:
#line 303 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 144:
#line 308 "compiler.y"
    {(yyval.Node)=new node("direct_declarator",NULL,1,(yyvsp[(1) - (1)].Element));;}
    break;

  case 154:
#line 318 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (4)].Node);(yyval.Node)->addSub(1,(yyvsp[(3) - (4)].Node));;}
    break;

  case 156:
#line 320 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (3)].Node);;}
    break;

  case 163:
#line 337 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 165:
#line 342 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 166:
#line 343 "compiler.y"
    {node* t=(yyvsp[(1) - (3)].Node);while(t->next)t=t->next;t->next=(yyvsp[(3) - (3)].Node);;}
    break;

  case 167:
#line 347 "compiler.y"
    {(yyval.Node)=new node("parameter_declaration",NULL,0);(yyval.Node)->addContents(2,(yyvsp[(1) - (2)].Node),(yyvsp[(2) - (2)].Node));;}
    break;

  case 188:
#line 383 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 202:
#line 412 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 203:
#line 413 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 204:
#line 414 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 210:
#line 426 "compiler.y"
    {(yyval.Node)=(yyvsp[(2) - (3)].Node);;}
    break;

  case 211:
#line 430 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 212:
#line 431 "compiler.y"
    {node* t=(yyvsp[(1) - (2)].Node);while(t->next)t=t->next;t->next=(yyvsp[(2) - (2)].Node);;}
    break;

  case 213:
#line 435 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 214:
#line 436 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 216:
#line 441 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (2)].Node);;}
    break;

  case 217:
#line 445 "compiler.y"
    {(yyval.Node)=new node("if_statement", NULL, 0); (yyval.Node)->addSub(2,(yyvsp[(3) - (5)].Node),(yyvsp[(5) - (5)].Node));;}
    break;

  case 218:
#line 446 "compiler.y"
    {(yyval.Node)=new node("if_else_statement", NULL, 0); (yyval.Node)->addSub(3,(yyvsp[(3) - (7)].Node),(yyvsp[(5) - (7)].Node),(yyvsp[(7) - (7)].Node));;}
    break;

  case 219:
#line 447 "compiler.y"
    {(yyval.Node)=new node("switch_statement", NULL, 0); (yyval.Node)->addSub(2,(yyvsp[(3) - (5)].Node),(yyvsp[(5) - (5)].Node));;}
    break;

  case 220:
#line 451 "compiler.y"
    {(yyval.Node)=new node("while_statement", NULL, 0); (yyval.Node)->addSub(2,(yyvsp[(3) - (5)].Node),(yyvsp[(5) - (5)].Node));;}
    break;

  case 221:
#line 452 "compiler.y"
    {(yyval.Node)=new node("do_while_statement", NULL, 0); (yyval.Node)->addSub(2,(yyvsp[(2) - (7)].Node),(yyvsp[(5) - (7)].Node));;}
    break;

  case 222:
#line 453 "compiler.y"
    {(yyval.Node)=new node("for_statement_exp2", NULL, 0); (yyval.Node)->addSub(3,(yyvsp[(3) - (6)].Node),(yyvsp[(4) - (6)].Node),(yyvsp[(6) - (6)].Node));;}
    break;

  case 223:
#line 454 "compiler.y"
    {(yyval.Node)=new node("for_statement_exp3", NULL, 0); (yyval.Node)->addSub(4,(yyvsp[(3) - (7)].Node),(yyvsp[(4) - (7)].Node),(yyvsp[(5) - (7)].Node),(yyvsp[(7) - (7)].Node));;}
    break;

  case 224:
#line 455 "compiler.y"
    {(yyval.Node)=new node("for_statement_dcl2", NULL, 0); (yyval.Node)->addSub(3,(yyvsp[(3) - (6)].Node),(yyvsp[(4) - (6)].Node),(yyvsp[(6) - (6)].Node));;}
    break;

  case 225:
#line 456 "compiler.y"
    {(yyval.Node)=new node("for_statement_dcl3", NULL, 0); (yyval.Node)->addSub(4,(yyvsp[(3) - (7)].Node),(yyvsp[(4) - (7)].Node),(yyvsp[(5) - (7)].Node),(yyvsp[(7) - (7)].Node));;}
    break;

  case 231:
#line 468 "compiler.y"
    {root=(yyvsp[(1) - (1)].Node);;}
    break;

  case 232:
#line 471 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 233:
#line 472 "compiler.y"
    {node* t=(yyvsp[(1) - (2)].Node);while(t->next)t=t->next;t->next=(yyvsp[(2) - (2)].Node);;}
    break;

  case 234:
#line 476 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 235:
#line 477 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);;}
    break;

  case 237:
#line 482 "compiler.y"
    {(yyval.Node)=new node("function_definition",NULL,0);(yyval.Node)->addContents(2,(yyvsp[(1) - (3)].Node),(yyvsp[(2) - (3)].Node));(yyval.Node)->addSub(1,(yyvsp[(3) - (3)].Node));;}
    break;


/* Line 1267 of yacc.c.  */
#line 2703 "compiler.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 491 "compiler.y"

void yyerror(char const *s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}


