/* A Bison parser, made by GNU Bison 3.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 11 "parser.y"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define YYSTYPE char*

extern int yylex();
extern void yyerror(char const *s);
extern char *yytext;
extern int lineno;

int fdlineno =0;

struct fnIdent
{
    char * name;
    int paramNo;
    int lineNo;
} fIdent[100], cIdent[100];
int fSize = 0;
int cSize = 0;
void saveFnIdent(char *name,int paramNo,int lineNo)
{
    for( int i=0; i<fSize;i++)
    {
        if(strcmp(name,fIdent[i].name)==0)
        {
            printf(" Error: Function %s already defined. \n.",name);
        }
    }
    fIdent[fSize].name = malloc(50*sizeof(char));
    strcpy(fIdent[fSize].name,name);
    fIdent[fSize].paramNo = paramNo;
    fSize++;
}
void saveCIdent(char *name,int paramNo,int lineNo)
{
    cIdent[cSize].name = malloc(50*sizeof(char));
    strcpy(cIdent[cSize].name,name);
    cIdent[cSize].paramNo = paramNo;
    cIdent[cSize].lineNo = lineNo;
    cSize++;
}
void printFnIndent()
{
    for(int i=0;i<fSize;i++)
    {
        printf(" {%s} %d \n",fIdent[i].name,fIdent[i].paramNo);
    }
}
void printCIndent()
{
    for(int i=0;i<cSize;i++)
    {
        printf(" {%s} %d \n",cIdent[i].name,cIdent[i].paramNo);
    }
}

void fnDeclared()
{
    for(int i = 0; i < cSize;i++)
    {
        int d = 0;
        for(int j=0;j<fSize;j++)
        {
            if(strcmp(cIdent[i].name,fIdent[j].name)==0)
            {
                if(cIdent[i].paramNo != fIdent[i].paramNo)
                {
                    printf("Error:  function call: %s at line %d  has wrong number of parameters passed. \n",cIdent[i].name,cIdent[i].lineNo );
                }
                d = 1;
            }
        }
        if ( d == 0)
        {
            printf("Error:  %s is not defined but used on line: %d \n",cIdent[i].name,cIdent[i].lineNo);
        }
    }
}


int isDebug = 0;
void debug(char* s)
{
    if(isDebug == 1)
    {
        printf("%s \n",s);
    }
}





#line 167 "parser.tab.c"

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    KEYWORD_STRICT_AS = 258,
    KEYWORD_STRICT_BREAK = 259,
    KEYWORD_STRICT_CONST = 260,
    KEYWORD_STRICT_CONTINUE = 261,
    KEYWORD_STRICT_CRATE = 262,
    KEYWORD_STRICT_ELSE = 263,
    KEYWORD_STRICT_ENUM = 264,
    KEYWORD_STRICT_EXTERN = 265,
    KEYWORD_STRICT_FALSE = 266,
    KEYWORD_STRICT_FN = 267,
    KEYWORD_STRICT_FOR = 268,
    KEYWORD_STRICT_IF = 269,
    KEYWORD_STRICT_IMPL = 270,
    KEYWORD_STRICT_IN = 271,
    KEYWORD_STRICT_LET = 272,
    KEYWORD_STRICT_LOOP = 273,
    KEYWORD_STRICT_MATCH = 274,
    KEYWORD_STRICT_MOD = 275,
    KEYWORD_STRICT_MOVE = 276,
    KEYWORD_STRICT_MUT = 277,
    KEYWORD_STRICT_PUB = 278,
    KEYWORD_STRICT_REF = 279,
    KEYWORD_STRICT_RETURN = 280,
    KEYWORD_STRICT_SELFVALUE = 281,
    KEYWORD_STRICT_SELFTYPE = 282,
    KEYWORD_STRICT_STATIC = 283,
    KEYWORD_STRICT_STRUCT = 284,
    KEYWORD_STRICT_SUPER = 285,
    KEYWORD_STRICT_TRAIT = 286,
    KEYWORD_STRICT_TRUE = 287,
    KEYWORD_STRICT_TYPE = 288,
    KEYWORD_STRICT_UNSAFE = 289,
    KEYWORD_STRICT_USE = 290,
    KEYWORD_STRICT_WHERE = 291,
    KEYWORD_STRICT_WHILE = 292,
    KEYWORD_STRICT_ASYNC = 293,
    KEYWORD_STRICT_AWAIT = 294,
    KEYWORD_STRICT_DYN = 295,
    KEYWORD_RES_ABSTRACT = 296,
    KEYWORD_RES_BECOME = 297,
    KEYWORD_RES_BOX = 298,
    KEYWORD_RES_DO = 299,
    KEYWORD_RES_FINAL = 300,
    KEYWORD_RES_MACRO = 301,
    KEYWORD_RES_OVERRIDE = 302,
    KEYWORD_RES_PRIV = 303,
    KEYWORD_RES_TYPEOF = 304,
    KEYWORD_RES_UNSIZED = 305,
    KEYWORD_RES_VIRTUAL = 306,
    KEYWORD_RES_YILED = 307,
    KEYWORD_RES_TRY = 308,
    KEYWORD_WEAK_UNION = 309,
    KEYWORD_WEAK_STATICLIFETIME = 310,
    KEYWORD_WEAK_DYN = 311,
    ADDOP = 312,
    SUBOP = 313,
    MULOP = 314,
    DIVOP = 315,
    INCR = 316,
    DECR = 317,
    OROP = 318,
    ANDOP = 319,
    MODOP = 320,
    NOTOP = 321,
    EQUOP = 322,
    NEQUOP = 323,
    GT = 324,
    LT = 325,
    GTEQ = 326,
    LTEQ = 327,
    COLON = 328,
    LPAREN = 329,
    RPAREN = 330,
    LBRACK = 331,
    RBRACK = 332,
    LBRACE = 333,
    RBRACE = 334,
    SEMI = 335,
    DOTDOT = 336,
    DOT = 337,
    COMMA = 338,
    ASSIGN = 339,
    REFER = 340,
    ID = 341,
    UNDERSCORE = 342,
    HASH = 343,
    ARROW = 344,
    ICONST = 345,
    FCONST = 346,
    CCONST = 347,
    STRING = 348
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



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
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   423

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  128
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  247

#define YYUNDEFTOK  2
#define YYMAXUTOK   348

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   205,   205,   206,   207,   208,   209,   217,   218,   222,
     223,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   255,   258,   261,
     262,   265,   266,   272,   273,   274,   275,   276,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     293,   294,   295,   296,   297,   298,   299,   300,   303,   304,
     305,   306,   311,   312,   317,   320,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   337,   340,   341,   344,   345,
     346,   349,   350,   353,   360,   364,   366,   367,   369,   370,
     374,   375,   379,   381,   383,   385,   386,   388,   389,   394,
     395,   398,   399,   402,   403,   406,   407,   417,   422,   423,
     427,   428,   429,   430,   431,   432,   433,   434,   435
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KEYWORD_STRICT_AS",
  "KEYWORD_STRICT_BREAK", "KEYWORD_STRICT_CONST",
  "KEYWORD_STRICT_CONTINUE", "KEYWORD_STRICT_CRATE", "KEYWORD_STRICT_ELSE",
  "KEYWORD_STRICT_ENUM", "KEYWORD_STRICT_EXTERN", "KEYWORD_STRICT_FALSE",
  "KEYWORD_STRICT_FN", "KEYWORD_STRICT_FOR", "KEYWORD_STRICT_IF",
  "KEYWORD_STRICT_IMPL", "KEYWORD_STRICT_IN", "KEYWORD_STRICT_LET",
  "KEYWORD_STRICT_LOOP", "KEYWORD_STRICT_MATCH", "KEYWORD_STRICT_MOD",
  "KEYWORD_STRICT_MOVE", "KEYWORD_STRICT_MUT", "KEYWORD_STRICT_PUB",
  "KEYWORD_STRICT_REF", "KEYWORD_STRICT_RETURN",
  "KEYWORD_STRICT_SELFVALUE", "KEYWORD_STRICT_SELFTYPE",
  "KEYWORD_STRICT_STATIC", "KEYWORD_STRICT_STRUCT", "KEYWORD_STRICT_SUPER",
  "KEYWORD_STRICT_TRAIT", "KEYWORD_STRICT_TRUE", "KEYWORD_STRICT_TYPE",
  "KEYWORD_STRICT_UNSAFE", "KEYWORD_STRICT_USE", "KEYWORD_STRICT_WHERE",
  "KEYWORD_STRICT_WHILE", "KEYWORD_STRICT_ASYNC", "KEYWORD_STRICT_AWAIT",
  "KEYWORD_STRICT_DYN", "KEYWORD_RES_ABSTRACT", "KEYWORD_RES_BECOME",
  "KEYWORD_RES_BOX", "KEYWORD_RES_DO", "KEYWORD_RES_FINAL",
  "KEYWORD_RES_MACRO", "KEYWORD_RES_OVERRIDE", "KEYWORD_RES_PRIV",
  "KEYWORD_RES_TYPEOF", "KEYWORD_RES_UNSIZED", "KEYWORD_RES_VIRTUAL",
  "KEYWORD_RES_YILED", "KEYWORD_RES_TRY", "KEYWORD_WEAK_UNION",
  "KEYWORD_WEAK_STATICLIFETIME", "KEYWORD_WEAK_DYN", "ADDOP", "SUBOP",
  "MULOP", "DIVOP", "INCR", "DECR", "OROP", "ANDOP", "MODOP", "NOTOP",
  "EQUOP", "NEQUOP", "GT", "LT", "GTEQ", "LTEQ", "COLON", "LPAREN",
  "RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE", "SEMI", "DOTDOT",
  "DOT", "COMMA", "ASSIGN", "REFER", "ID", "UNDERSCORE", "HASH", "ARROW",
  "ICONST", "FCONST", "CCONST", "STRING", "$accept", "main", "ident",
  "exp", "extendExp", "if_expr", "if_main", "else_expr", "else_if_expr",
  "exprs", "expr", "expression", "term", "while_loop", "for_loop",
  "for_range", "for_exp", "struct_dec", "struct_def", "struct_tuple",
  "struct_block", "data_type", "funDecr", "param", "maybeParamList",
  "paramList", "maybeFnReturn", "funCall", "funcCallStmt", "callParam",
  "maybeCallParamList", "callParamList", "varDec", "maybeMut", "maybeType",
  "maybeAssign", "varAssign", "breakStmt", "block", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348
};
# endif

#define YYPACT_NINF -145

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-145)))

#define YYTABLE_NINF -60

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      58,   -80,   -80,    -5,   -80,  -145,    49,   -60,    58,    58,
      58,  -145,    40,   -10,  -145,   -80,    67,  -145,   -80,   148,
    -145,  -145,  -145,   -80,   -19,   -80,    40,   -80,   -80,  -145,
       9,  -145,   148,  -145,   243,   243,   243,   243,  -145,  -145,
    -145,    19,    15,   342,  -145,  -145,  -145,     9,   148,    16,
      42,  -145,    32,    25,   -19,   -71,    36,    64,    52,    88,
     342,   342,   342,   323,   148,  -145,   243,   243,   243,   243,
    -145,  -145,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   144,  -145,  -145,   -80,    79,   -80,    92,   -80,    94,
     -80,  -145,   242,  -145,  -145,  -145,   101,    95,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,     2,  -145,     9,   -80,   103,  -145,  -145,  -145,  -145,
       9,    99,   187,   -80,   122,    74,    -1,   242,   242,   242,
     242,   135,   242,   242,   242,   242,   145,  -145,   148,   242,
    -145,     9,   242,   -80,  -145,   143,   -11,   242,  -145,  -145,
     210,    74,  -145,  -145,  -145,     9,   147,   -29,   299,   283,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,   156,   157,  -145,  -145,   -54,   158,   210,  -145,   151,
      14,   255,    61,   242,    74,    74,   210,   210,   210,   210,
     210,   210,   221,   221,   221,   221,   221,  -145,  -145,   -54,
    -145,  -145,     9,   162,    98,  -145,   168,  -145,   -12,     4,
    -145,   166,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
     221,  -145,  -145,  -145,  -145,  -145,   233,   242,   -54,   -54,
     -54,   -54,   -54,   -54,  -145,  -145,   175,  -145,   172,   358,
     358,   358,   358,   358,   358,  -145,  -145
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,   111,     0,     7,     0,     0,     2,     2,
       2,     6,   113,     0,   112,     0,     0,     1,     0,     0,
       5,     3,     4,     0,   115,    96,   113,    88,    91,    85,
       8,    13,     0,    12,     0,     0,     0,     0,    14,    15,
       9,    11,     0,    10,    17,    41,    16,   114,     0,     0,
       0,    98,     0,    97,   115,    90,     0,     0,     0,     0,
      32,    33,    31,     0,   105,   117,     0,     0,     0,     0,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    39,   116,   110,     0,   100,     0,     0,    88,     0,
       0,    86,   120,    36,   104,   107,     0,   106,    21,    20,
      18,    19,    30,    29,    22,    23,    24,    25,    27,    26,
      28,     0,    37,    95,     0,     0,    99,   109,    89,    87,
      93,     0,     0,     0,     0,     0,     0,   120,   120,   120,
     120,     0,   120,   120,   120,   120,     0,   102,     0,   120,
      42,   101,   120,    91,   118,     0,     0,   120,    55,    54,
       0,     0,    71,    70,    69,    68,     0,    43,    57,    65,
     121,   125,   122,   126,   103,   123,   124,   128,   127,    38,
     108,     0,     0,    92,   119,     0,     0,     0,    56,     0,
       0,    57,    65,   120,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    40,    94,     0,
      77,    78,    76,     0,     0,    73,     0,    46,    47,    67,
      66,     0,    45,    44,    48,    49,    50,    51,    52,    53,
       0,    62,    63,    60,    61,    64,     0,   120,     0,     0,
       0,     0,     0,     0,    59,    72,     0,    84,     0,    82,
      81,    79,    80,    83,    75,    67,    74
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,   203,     0,    -6,   284,   -89,   141,  -145,  -145,  -137,
     188,    93,  -144,  -145,  -145,  -145,   -26,    21,  -145,   170,
     119,  -145,  -145,   177,  -145,  -145,  -145,   -73,  -145,   126,
    -145,  -145,   161,  -145,   239,   212,   208,  -145,   -30
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,    41,    94,    43,    44,    45,   112,    81,   156,
     157,   158,   159,   128,   129,   203,   204,   130,    29,    56,
      58,   121,     9,    51,    52,    53,   115,    46,   132,    95,
      96,    97,   133,    15,    24,    49,   134,   135,   136
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       7,    12,    13,   127,    16,   175,     5,   182,     7,     7,
       7,    18,    88,    42,   179,    26,    32,    14,    30,   131,
     199,     8,    18,    47,    19,    50,    59,    55,    57,     8,
       8,     8,     5,   182,   184,   185,   200,   201,   127,   127,
     127,   127,    82,   127,   127,   127,   127,   212,   213,    17,
     127,   -59,   -59,   127,   131,   131,   131,   131,   127,   131,
     131,   131,   131,     1,    25,    48,   131,   -58,   -58,   131,
       2,    18,    18,    64,   131,     3,   182,   184,   185,   -58,
     139,    18,   -58,    19,   113,   148,    50,     4,    55,   208,
     120,    18,   126,    64,   127,    65,    83,   160,   161,   162,
     163,    18,   165,   166,   167,   168,   149,    85,    86,   171,
     131,    89,   172,    23,   141,    84,   145,   176,   192,   193,
     194,   195,    18,   146,    18,   155,   196,   126,   126,   126,
     126,    91,   126,   126,   126,   126,   210,    90,   127,   126,
     150,    27,   126,    57,     5,    28,    18,   126,   151,    18,
     155,   155,   111,   211,   131,   228,   229,   230,   231,    31,
       5,    10,    32,   232,   152,   153,    92,   154,   114,    10,
      10,    10,   117,   226,   119,   202,   137,   155,   138,   233,
      33,   142,   143,   126,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   238,    31,   202,
     147,    32,   239,   240,   241,   242,   243,   244,    11,    34,
      35,    20,    21,    22,    36,   164,    11,    11,    11,    33,
     155,   148,    37,   174,   169,   183,   207,   126,   202,   202,
     202,   202,   202,   202,     5,   197,   198,   205,    38,    39,
     227,    40,   149,   234,   181,   235,   122,     1,    34,    35,
     245,   246,   140,    36,    31,   123,    32,    32,   118,     3,
     124,    37,   173,   116,   170,    54,    87,   144,     0,     0,
     181,     4,     0,     5,     0,    33,   150,    38,    39,   125,
      40,     0,     0,     0,   177,   221,   222,   223,   224,   225,
     228,   229,   230,   231,     0,   220,     5,     0,   232,     0,
     152,   153,     0,   154,    34,    35,     0,     5,   237,    36,
       0,   152,   153,   236,   154,     0,     0,    37,    60,    61,
      62,    63,   186,   187,   188,   189,   190,   191,     5,     5,
     209,     0,     0,    38,    39,     0,     0,     0,   178,   180,
     192,   193,   194,   195,     0,     0,     0,     0,   196,     0,
      98,    99,   100,   101,     0,     0,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   206,   186,   187,   188,   189,
     190,   191,     0,     0,   214,   215,   216,   217,   218,   219,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     0,
      75,    76,    77,    78,    79,    80,     0,     0,    93,    66,
      67,    68,    69,    70,    71,    72,    73,    74,     0,    75,
      76,    77,    78,    79,    80,   228,   229,   230,   231,     0,
       0,     0,     0,   232
};

static const yytype_int16 yycheck[] =
{
       0,     1,     2,    92,     4,    16,    86,   151,     8,     9,
      10,    82,    83,    19,   151,    15,    14,    22,    18,    92,
      74,     0,    82,    23,    84,    25,    32,    27,    28,     8,
       9,    10,    86,   177,    63,    64,    90,    91,   127,   128,
     129,   130,    48,   132,   133,   134,   135,   184,   185,     0,
     139,    63,    64,   142,   127,   128,   129,   130,   147,   132,
     133,   134,   135,     5,    74,    84,   139,    63,    64,   142,
      12,    82,    82,    74,   147,    17,   220,    63,    64,    75,
      78,    82,    78,    84,    84,    11,    86,    29,    88,    75,
      90,    82,    92,    74,   183,    80,    80,   127,   128,   129,
     130,    82,   132,   133,   134,   135,    32,    75,    83,   139,
     183,    75,   142,    73,   114,    73,   122,   147,    57,    58,
      59,    60,    82,   123,    82,   125,    65,   127,   128,   129,
     130,    79,   132,   133,   134,   135,    75,    73,   227,   139,
      66,    74,   142,   143,    86,    78,    82,   147,    74,    82,
     150,   151,     8,   183,   227,    57,    58,    59,    60,    11,
      86,     0,    14,    65,    90,    91,    78,    93,    89,     8,
       9,    10,    80,   199,    80,   175,    75,   177,    83,    81,
      32,    78,    83,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   227,    11,   199,
      78,    14,   228,   229,   230,   231,   232,   233,     0,    61,
      62,     8,     9,    10,    66,    80,     8,     9,    10,    32,
     220,    11,    74,    80,    79,    78,    75,   227,   228,   229,
     230,   231,   232,   233,    86,    79,    79,    79,    90,    91,
      78,    93,    32,    75,   151,    79,     4,     5,    61,    62,
      75,    79,   111,    66,    11,    13,    14,    14,    88,    17,
      18,    74,   143,    86,   138,    26,    54,    80,    -1,    -1,
     177,    29,    -1,    86,    -1,    32,    66,    90,    91,    37,
      93,    -1,    -1,    -1,    74,   192,   193,   194,   195,   196,
      57,    58,    59,    60,    -1,    74,    86,    -1,    65,    -1,
      90,    91,    -1,    93,    61,    62,    -1,    86,    75,    66,
      -1,    90,    91,   220,    93,    -1,    -1,    74,    34,    35,
      36,    37,    67,    68,    69,    70,    71,    72,    86,    86,
      75,    -1,    -1,    90,    91,    -1,    -1,    -1,   150,   151,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    65,    -1,
      66,    67,    68,    69,    -1,    -1,    72,    73,    74,    75,
      76,    77,    78,    79,    80,   177,    67,    68,    69,    70,
      71,    72,    -1,    -1,   186,   187,   188,   189,   190,   191,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    -1,
      67,    68,    69,    70,    71,    72,    -1,    -1,    75,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    65
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    12,    17,    29,    86,    95,    96,   111,   116,
     126,   130,    96,    96,    22,   127,    96,     0,    82,    84,
      95,    95,    95,    73,   128,    74,    96,    74,    78,   112,
      96,    11,    14,    32,    61,    62,    66,    74,    90,    91,
      93,    96,    97,    98,    99,   100,   121,    96,    84,   129,
      96,   117,   118,   119,   128,    96,   113,    96,   114,    97,
      98,    98,    98,    98,    74,    80,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    67,    68,    69,    70,    71,
      72,   102,    97,    80,    73,    75,    83,   129,    83,    75,
      73,    79,    78,    75,    97,   123,   124,   125,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,     8,   101,    96,    89,   120,   117,    80,   113,    80,
      96,   115,     4,    13,    18,    37,    96,    99,   107,   108,
     111,   121,   122,   126,   130,   131,   132,    75,    83,    78,
     100,    96,    78,    83,    80,    97,    96,    78,    11,    32,
      66,    74,    90,    91,    93,    96,   103,   104,   105,   106,
     132,   132,   132,   132,    80,   132,   132,   132,   132,    79,
     123,   132,   132,   114,    80,    16,   132,    74,   104,   103,
     104,   105,   106,    78,    63,    64,    67,    68,    69,    70,
      71,    72,    57,    58,    59,    60,    65,    79,    79,    74,
      90,    91,    96,   109,   110,    79,   104,    75,    75,    75,
      75,   132,   103,   103,   104,   104,   104,   104,   104,   104,
      74,   105,   105,   105,   105,   105,   110,    78,    57,    58,
      59,    60,    65,    81,    75,    79,   105,    75,   132,   110,
     110,   110,   110,   110,   110,    75,    79
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    95,    95,    95,    95,    96,    96,    97,
      97,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    99,   100,   101,
     101,   102,   102,   103,   103,   103,   103,   103,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     105,   105,   105,   105,   105,   105,   105,   105,   106,   106,
     106,   106,   107,   107,   108,   109,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   111,   112,   112,   113,   113,
     113,   114,   114,   115,   116,   117,   118,   118,   119,   119,
     120,   120,   121,   122,   123,   124,   124,   125,   125,   126,
     126,   127,   127,   128,   128,   129,   129,   130,   131,   131,
     132,   132,   132,   132,   132,   132,   132,   132,   132
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     2,     3,     3,     5,     0,
       4,     0,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     2,     1,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     1,
       1,     1,     5,     4,     7,     3,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     0,     3,
       1,     0,     5,     1,     9,     3,     0,     1,     1,     3,
       0,     2,     4,     2,     1,     0,     1,     1,     3,     6,
       5,     0,     1,     0,     2,     0,     2,     4,     2,     3,
       0,     2,     2,     2,     2,     2,     2,     2,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 7:
#line 217 "parser.y"
    { yyval = malloc(100*sizeof(char)); strcpy(yyval,yytext); }
#line 1626 "parser.tab.c"
    break;

  case 85:
#line 337 "parser.y"
    {debug("Found struct dec");}
#line 1632 "parser.tab.c"
    break;

  case 94:
#line 360 "parser.y"
    {saveFnIdent(yyvsp[-7],atoi(yyvsp[-5]),fdlineno);debug("FOUND FUNCTION DEC");}
#line 1638 "parser.tab.c"
    break;

  case 96:
#line 366 "parser.y"
    {yyval = "0"; fdlineno = lineno;}
#line 1644 "parser.tab.c"
    break;

  case 97:
#line 367 "parser.y"
    {yyval = yyvsp[0]; fdlineno = lineno;}
#line 1650 "parser.tab.c"
    break;

  case 98:
#line 369 "parser.y"
    { yyval = "1";}
#line 1656 "parser.tab.c"
    break;

  case 99:
#line 370 "parser.y"
    { char *g = malloc(10*sizeof(char)); sprintf(g, "%d", atoi(yyvsp[-2])+1); yyval = g;}
#line 1662 "parser.tab.c"
    break;

  case 102:
#line 379 "parser.y"
    {saveCIdent(yyvsp[-3],atoi(yyvsp[-1]),lineno);}
#line 1668 "parser.tab.c"
    break;

  case 103:
#line 381 "parser.y"
    {}
#line 1674 "parser.tab.c"
    break;

  case 105:
#line 385 "parser.y"
    {yyval = "0";}
#line 1680 "parser.tab.c"
    break;

  case 106:
#line 386 "parser.y"
    {yyval = yyvsp[0];}
#line 1686 "parser.tab.c"
    break;

  case 107:
#line 388 "parser.y"
    { yyval = "1";}
#line 1692 "parser.tab.c"
    break;

  case 108:
#line 389 "parser.y"
    { char *a = malloc(10*sizeof(char)); sprintf(a, "%d", atoi(yyvsp[-2])+1); yyval = a;}
#line 1698 "parser.tab.c"
    break;

  case 109:
#line 394 "parser.y"
    { debug("FOUND varDec"); }
#line 1704 "parser.tab.c"
    break;

  case 110:
#line 395 "parser.y"
    { debug("FOUND varDec const"); }
#line 1710 "parser.tab.c"
    break;

  case 117:
#line 417 "parser.y"
    {debug("var assign");}
#line 1716 "parser.tab.c"
    break;

  case 121:
#line 428 "parser.y"
    {debug("FOUND IF DEC");}
#line 1722 "parser.tab.c"
    break;

  case 122:
#line 429 "parser.y"
    {debug("FOUND FOR LOOP");}
#line 1728 "parser.tab.c"
    break;

  case 125:
#line 432 "parser.y"
    {debug("Found while loop");}
#line 1734 "parser.tab.c"
    break;


#line 1738 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 444 "parser.y"


void main() 
 { 
  yyparse(); 

  fnDeclared();
 } 
