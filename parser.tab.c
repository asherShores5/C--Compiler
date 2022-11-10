/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 5 "parser.y"

//Standard libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Other Files 
// Need tp add IR + MIPS Code??
#include "symbolTable.h"
#include "AST.h"
#include "IRcode.h"
#include "MIPScode.h"
#include "Calculator.h"

//Bison stuff I assume... IDK what it does
extern int yylex();
extern int yyparse();
extern FILE* yyin;

FILE * IRcode;
FILE * GarbageMIPS;

//Some global variables
int computeEquation(int val1, int val2, char operator);
void yyerror(const char* s);
char currentScope[50] = "GLOBAL"; // global or the name of the function
int semanticCheckPassed = 1; // flags to record correctness of semantic checks
char typeTemp[50];
struct AST * lastVar; 

int count = 0;


#line 104 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    SEMICOLON = 259,
    EQ = 260,
    NUMBER = 261,
    WRITE = 262,
    FUNC = 263,
    PLUS = 264,
    MINUS = 265,
    TIMES = 266,
    DIVIDE = 267,
    LBRACKET = 268,
    RBRACKET = 269,
    LPAREN = 270,
    RPAREN = 271,
    LCURLY = 272,
    RCURLY = 273,
    INT = 274,
    CHAR = 275,
    FLOAT = 276,
    RETURN = 277,
    WRITELN = 278,
    CHARACTER = 279
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "parser.y"

	//Tokens declared in C so we can declare them in C--... I think
	int number;
	char character;
	char* string;
	struct AST* ast;

#line 189 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   118

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  25
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  96

#define YYUNDEFTOK  2
#define YYMAXUTOK   279


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   111,   111,   120,   136,   141,   162,   163,   164,   173,
     202,   243,   245,   256,   256,   296,   298,   307,   309,   318,
     354,   362,   363,   364,   369,   371,   381,   385,   387,   393,
     404,   415,   417,   479,   517,   520,   551,   555,   571,   573,
     589,   602,   604,   619,   637,   649,   664,   680,   681,   681,
     688,   691,   697,   698,   700,   703,   704,   705,   706
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "SEMICOLON", "EQ", "NUMBER",
  "WRITE", "FUNC", "PLUS", "MINUS", "TIMES", "DIVIDE", "LBRACKET",
  "RBRACKET", "LPAREN", "RPAREN", "LCURLY", "RCURLY", "INT", "CHAR",
  "FLOAT", "RETURN", "WRITELN", "CHARACTER", "$accept", "Program",
  "DeclList", "Decl", "VarDecl", "FunDeclList", "FunDecl", "$@1",
  "ParamDecList", "ParamDecListTail", "ParamDecl", "Block", "Type",
  "StmtList", "Stmt", "Expr", "MathExpr", "AddSub", "MultDiv", "ParamList",
  "$@2", "Primary", "UnaryOp", "BinOp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279
};
# endif

#define YYPACT_NINF (-34)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-52)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       6,    77,   -34,    84,    44,    82,   -34,    44,   -34,   -34,
     -34,    44,    13,   -34,    20,   -34,     6,   -34,   -34,    28,
      42,   -34,    34,    65,   -34,    14,   -34,    57,    44,    44,
     -34,   -34,   -34,   -34,    47,    36,    49,    59,    59,    68,
      45,    64,    71,   -34,   -34,   -34,   -34,    28,    18,   -34,
     -34,    59,    59,   -34,   -34,    90,   -34,   -34,    75,   -34,
      88,   -34,   -34,    67,   -34,   -34,   -34,    46,   -34,   -34,
     -34,    99,   -34,   -34,    58,   -34,    36,   -34,    92,    36,
     -34,    82,   103,   -34,    93,   -34,    82,   105,   -34,    94,
     -34,   -34,     6,   -34,    95,   -34
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    39,    26,    40,     0,     0,    54,     0,    21,    23,
      22,     0,     0,    52,     0,     2,     4,     6,     5,     8,
       0,     7,    24,     0,    36,    38,    41,    31,     0,     0,
      55,    56,    57,    58,     0,    47,     0,     0,     0,     0,
       0,     0,     0,    30,     1,     3,    12,    11,     0,    25,
      27,     0,     0,    32,    33,     0,    50,    51,     0,    48,
      39,    37,    44,    51,    45,    46,    29,     0,    53,    28,
       9,     0,    43,    42,     0,    34,    47,    13,     0,     0,
      49,    15,     0,    35,     0,    16,    17,     0,    10,     0,
      18,    19,     0,    14,     0,    20
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -34,   -34,   -15,   -34,   -34,   -13,   -12,   -34,   -34,    24,
     -34,   -34,    -5,    96,   -34,     4,    76,   -34,    33,    38,
     -34,   -33,   -34,   -34
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    18,    19,    81,    84,    85,
      86,    93,    20,    21,    22,    23,    24,    25,    26,    58,
      76,    27,    28,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      40,    45,    59,    62,    62,    62,    46,    47,    39,     1,
       2,    41,     3,     4,     5,    42,     6,    43,    62,    62,
      44,     7,    70,    51,    52,     8,     9,    10,    11,    12,
      13,    71,    53,    54,    46,    47,     5,     1,     2,    56,
       3,     4,    57,    59,     6,    48,    83,     1,    67,     7,
       3,     7,    60,    55,     6,     3,    11,    12,    13,     7,
      13,    77,    56,    79,     7,    63,   -44,   -44,    13,    50,
      64,    65,    66,    13,     7,    69,    87,    94,    37,    38,
      68,    87,    29,    13,    72,    73,    30,    31,    32,    33,
      34,    75,    35,   -51,   -51,    37,    38,    30,    31,    32,
      33,     8,     9,    10,    74,    78,    82,    88,    91,    89,
      90,    92,    61,    95,    80,     0,     0,     0,    49
};

static const yytype_int8 yycheck[] =
{
       5,    16,    35,    36,    37,    38,    19,    19,     4,     3,
       4,     7,     6,     7,     8,    11,    10,     4,    51,    52,
       0,    15,     4,     9,    10,    19,    20,    21,    22,    23,
      24,    13,    28,    29,    47,    47,     8,     3,     4,     3,
       6,     7,     6,    76,    10,     3,    79,     3,     3,    15,
       6,    15,     3,     6,    10,     6,    22,    23,    24,    15,
      24,    15,     3,     5,    15,     6,     9,    10,    24,     4,
      37,    38,     4,    24,    15,     4,    81,    92,    11,    12,
      16,    86,     5,    24,    51,    52,     9,    10,    11,    12,
      13,    16,    15,     9,    10,    11,    12,     9,    10,    11,
      12,    19,    20,    21,    14,     6,    14,     4,     3,    16,
      86,    17,    36,    18,    76,    -1,    -1,    -1,    22
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     6,     7,     8,    10,    15,    19,    20,
      21,    22,    23,    24,    26,    27,    28,    29,    30,    31,
      37,    38,    39,    40,    41,    42,    43,    46,    47,     5,
       9,    10,    11,    12,    13,    15,    48,    11,    12,    40,
      37,    40,    40,     4,     0,    27,    30,    31,     3,    38,
       4,     9,    10,    40,    40,     6,     3,     6,    44,    46,
       3,    41,    46,     6,    43,    43,     4,     3,    16,     4,
       4,    13,    43,    43,    14,    16,    45,    15,     6,     5,
      44,    32,    14,    46,    33,    34,    35,    37,     4,    16,
      34,     3,    17,    36,    27,    18
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    25,    26,    27,    27,    27,    28,    28,    28,    29,
      29,    30,    30,    32,    31,    33,    33,    34,    34,    35,
      36,    37,    37,    37,    38,    38,    39,    39,    39,    39,
      39,    40,    40,    40,    40,    40,    40,    41,    41,    41,
      41,    42,    42,    42,    43,    43,    43,    44,    45,    44,
      46,    46,    46,    46,    47,    48,    48,    48,    48
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       6,     1,     2,     0,     8,     0,     1,     1,     2,     2,
       3,     1,     1,     1,     1,     2,     1,     2,     3,     3,
       2,     1,     2,     3,     4,     6,     1,     3,     1,     1,
       1,     1,     3,     3,     1,     3,     3,     0,     0,     3,
       1,     1,     1,     3,     1,     1,     1,     1,     1
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
    case 3: /* ID  */
#line 83 "parser.y"
         { fprintf(yyoutput, "%s", ((*yyvaluep).string)); }
#line 823 "parser.tab.c"
        break;

    case 6: /* NUMBER  */
#line 84 "parser.y"
         { fprintf(yyoutput, "%d", ((*yyvaluep).number)); }
#line 829 "parser.tab.c"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
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
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
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

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
  case 2:
#line 111 "parser.y"
                 {
		
		(yyval.ast) = (yyvsp[0].ast);
		// printAST($$, 3);

	}
#line 1450 "parser.tab.c"
    break;

  case 3:
#line 120 "parser.y"
                      { 

		// printf("\nTest debug DECLDECLLIST\n");
		(yyvsp[-1].ast)->right = (yyvsp[0].ast);
		(yyval.ast) = (yyvsp[-1].ast);
		// printf("LINK DECLLIST\n");
		// printNode($$->right);
	
	// } | StmtList DeclList  { 

	// 	// printf("Test debug STMTDECLLIST\n");
	// 	$1->right = $2;
	// 	$$ = $1;

	}
#line 1470 "parser.tab.c"
    break;

  case 4:
#line 136 "parser.y"
               {
		(yyval.ast) = (yyvsp[0].ast);
		// printf("DECL\n");
	}
#line 1479 "parser.tab.c"
    break;

  case 9:
#line 173 "parser.y"
                          {

		printf("\nRECOGNIZED RULE: VARIABLE declaration %s\n\n", (yyvsp[-1].string));


		// ----- SYMBOL TABLE ----- //
		symTabAccess();
		int inSymTab = found((yyvsp[-1].string), currentScope);
		//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
		

		// ------ SEMANTIC CHECKS ------ //
		if (inSymTab == 0) 
			addItem((yyvsp[-1].string), "Var", (yyvsp[-2].ast)->nodeType, currentScope);
		else
			printf("SEMANTIC ERROR: Var %s is already in the symbol table\n", (yyvsp[-1].string));

		showSymTable();


		// ------  AST  ------ //
		(yyval.ast) = AST_Type("TYPE", (yyvsp[-2].ast)->nodeType, (yyvsp[-1].string));
		lastVar = (yyval.ast);
		//printf("--------> Node:%s, %s\n", $$->nodeType, $$->RHS);

	}
#line 1510 "parser.tab.c"
    break;

  case 10:
#line 202 "parser.y"
                                                     {
		
		printf("\nRECOGNIZED RULE: ARRAY declaration %s\n\n", (yyvsp[-4].string));

		// ----- SYMBOL TABLE ----- //
		symTabAccess();

		int inSymTab = found((yyvsp[-4].string), currentScope);

		if (inSymTab == 0) {
			char arrIndex[12];
			for (int i = 0; i < (yyvsp[-2].number); i++) {
				sprintf(arrIndex, "%s[%d]", (yyvsp[-4].string), i);
				addItem(arrIndex, "ARRAY", (yyvsp[-5].ast)->nodeType, currentScope);				
			}
			// addItem($2, "ARRAY", $1, $4, currentScope);
			showSymTable();
		} else {
			printf("SEMANTIC ERROR: Var %s is already in the symbol table\n", (yyvsp[-4].string));
		}


		// ----- AST ----- //
		char intVal[50]; 
		sprintf(intVal, "%d", (yyvsp[-2].number));
		(yyval.ast) = AST_assignment("ARR", intVal, (yyvsp[-4].string));

		lastVar = (yyval.ast);


// 		// ----- CODE GENERATION ----- //
// 		// emitArrayDecl($2, $4, getItemID($2, currentScope));
		}
#line 1548 "parser.tab.c"
    break;

  case 12:
#line 245 "parser.y"
                              {
		
		//TODO AST stuff idk what to do about this yet

	}
#line 1558 "parser.tab.c"
    break;

  case 13:
#line 256 "parser.y"
                            {
		printf("\nRECOGNIZED RULE: FUNCTION declaration %s\n\n", (yyvsp[-1].string));
		printf("ID = %s\n", (yyvsp[-1].string));
		strcpy(currentScope, (yyvsp[-1].string));
		printf("\n------------------- Scope Change --> ");
		printf("%s", currentScope);
		printf(" -------------------\n");


		// ----- SYMBOL TABLE ----- //
		symTabAccess();
		int inSymTab = found((yyvsp[-1].string), currentScope);

		// ------ SEMANTIC CHECKS ------ //
 		if (inSymTab == 0) {
			
			addItem((yyvsp[-1].string), "FUNC", (yyvsp[-2].ast), currentScope);
			showSymTable();
		} else {
			printf("SEMANTIC ERROR: Function %s is already in the symbol table\n", (yyvsp[-2].ast));
		}
	}
#line 1585 "parser.tab.c"
    break;

  case 14:
#line 279 "parser.y"
                                  {

		// ----- AST ----- //
		(yyval.ast) = AST_assignment("FUNC", (yyvsp[-6].ast), (yyvsp[-5].string));		
		

		// printf("TEST %s\n", $6);
		(yyval.ast) -> right = (yyvsp[-2].ast);
	}
#line 1599 "parser.tab.c"
    break;

  case 15:
#line 296 "parser.y"
                            {printf("No ParamDeclList (EPSILON)\n\n");}
#line 1605 "parser.tab.c"
    break;

  case 16:
#line 298 "parser.y"
                           {}
#line 1611 "parser.tab.c"
    break;

  case 17:
#line 307 "parser.y"
                  {}
#line 1617 "parser.tab.c"
    break;

  case 18:
#line 309 "parser.y"
                                     {(yyvsp[-1].ast)->right = (yyvsp[0].ast); (yyval.ast) = (yyvsp[-1].ast);}
#line 1623 "parser.tab.c"
    break;

  case 19:
#line 318 "parser.y"
                {
		printf("\nRECOGNIZED RULE: Parameter VARIABLE declaration %s\n", (yyvsp[0].string));
		//Asher's Semantic Checks
		//Symbol Table
		symTabAccess();
		//Var Decl Check
		int inSymTab = found((yyvsp[0].string), currentScope);
		//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
		if (inSymTab == 0) {
			addItem((yyvsp[0].string), "Var", (yyvsp[-1].ast), currentScope);
		} else {
			printf("\nSEMANTIC ERROR: Var %s is already in the symbol table\n", (yyvsp[0].string));
		} 
		showSymTable();
	}
#line 1643 "parser.tab.c"
    break;

  case 20:
#line 354 "parser.y"
                               {
		(yyval.ast) = (yyvsp[-1].ast);
		// printf("right: %s\n", $$->right->RHS);
	}
#line 1652 "parser.tab.c"
    break;

  case 21:
#line 362 "parser.y"
          {}
#line 1658 "parser.tab.c"
    break;

  case 22:
#line 363 "parser.y"
                {}
#line 1664 "parser.tab.c"
    break;

  case 23:
#line 364 "parser.y"
               {}
#line 1670 "parser.tab.c"
    break;

  case 25:
#line 371 "parser.y"
                        {
		(yyvsp[-1].ast)->right = (yyvsp[0].ast);
		(yyval.ast) = (yyvsp[-1].ast);
		// printNode($$);
	}
#line 1680 "parser.tab.c"
    break;

  case 26:
#line 381 "parser.y"
                  {
		printf("\nRECOGNIZED RULE: SEMICOLON %s\n", (yyvsp[0].string));	
	}
#line 1688 "parser.tab.c"
    break;

  case 27:
#line 385 "parser.y"
                         {}
#line 1694 "parser.tab.c"
    break;

  case 28:
#line 387 "parser.y"
                                {		
		(yyval.ast) = AST_assignment("RETURN", "", (yyvsp[-1].ast));
		// printNode($$);
		
	}
#line 1704 "parser.tab.c"
    break;

  case 29:
#line 393 "parser.y"
                               {
		printf("\nRECOGNIZED RULE: Write Statement\n");

		// printf("EXpr: %s\n", $2);
		(yyval.ast) = AST_Write("WRITE", "", (yyvsp[-1].ast));
		

		// ------ CODE GENERATION ------ //
		// emitMIPSWrite
	}
#line 1719 "parser.tab.c"
    break;

  case 30:
#line 404 "parser.y"
                            {
		printf("\nRECOGNIZED RULE: Write Line %s\n", (yyvsp[-1].string));
	}
#line 1727 "parser.tab.c"
    break;

  case 32:
#line 417 "parser.y"
                       { 

		//Asher's Semantic Checls
		// ------- SYMBOL TABLE ------- //
		symTabAccess();
		int inSymTab = found((yyvsp[0].ast), currentScope);
		//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
		if (inSymTab == 0) {
			printf("\nSEMANTIC ERROR: Expr %s is NOT in the symbol table\n", (yyvsp[0].ast)->nodeType);
		}
		showSymTable();

		(yyval.ast) = (yyvsp[0].ast);

	}
#line 1747 "parser.tab.c"
    break;

  case 33:
#line 479 "parser.y"
                     {
		printf("\nRECOGNIZED RULE: Assignment Statement ----> %s\n", (yyvsp[-2].string));
		int inSymTab = found((yyvsp[-2].string), currentScope);
	

		// ------ SEMANTIC CHECKS ------ //
		if (inSymTab == 0) {
			printf("\nSEMANTIC ERROR: Var %s is NOT in the symbol table\n", (yyvsp[-1].string));
			semanticCheckPassed = 0;
		} else {
			printf("\nITEM IS IN SYMTABLE\n");
		}

		printNode((yyvsp[0].ast));
		if (strcmp(getVariableType((yyvsp[-2].string), currentScope), (yyvsp[0].ast)) == 0) {
			printf("TYPES ARE COMPATIBLE\n");
		} else {
			printf("Error: INCOMPATIBLE TYPES\n");
			semanticCheckPassed = 0;
		}


		// ------- SYMBOL TABLE ------- //
		if (semanticCheckPassed) {
			setItemValue((yyvsp[-2].string), (yyvsp[0].ast)->RHS, currentScope);
		}
		

		// ------ AST ------ //
		(yyval.ast) = AST_assignment("=", (yyvsp[-2].string), (yyvsp[0].ast)->RHS);
		// printNode($$);


		// ------ CODE GENERATION ------ //

		semanticCheckPassed = 1;
	}
#line 1789 "parser.tab.c"
    break;

  case 34:
#line 517 "parser.y"
                                     {printf("\nRECOGNIZED RULE: Function Call %s\n", (yyvsp[-3].string));}
#line 1795 "parser.tab.c"
    break;

  case 35:
#line 520 "parser.y"
                                                 {

		printf("\nRECOGNIZED RULE: ARRAY assignment %s\n", (yyvsp[-5].string));

		//Asher's Semantic Checks
		symTabAccess();
		int inSymTab = found((yyvsp[-5].string), currentScope);

		if (inSymTab != 0) {
			printf("\nSEMANTIC ERROR: ARR %s is NOT in the symbol table\n", (yyvsp[-4].string));
			semanticCheckPassed = 0;
		} else {
			printf("\nSEMANTIC CHECK PASSED\n");
			
			//emitArrayAssignment();
		}
		// ------ SYMBOL TABLE ------ //

		// Setting array value in the symbol table
		char arrayStmt[10]; char newVal[10];
		sprintf(arrayStmt, "%s%s%d%s", (yyvsp[-5].string), (yyvsp[-4].string), (yyvsp[-3].number), (yyvsp[-2].string));
		// printf("setVal %s\n", $6);
		// sprintf(newVal, "%d", $6);
		setItemValue(arrayStmt, (yyvsp[0].ast), currentScope);


		// ----- AST ----- //
		(yyval.ast) = AST_assignment("=", arrayStmt, newVal);		

	}
#line 1830 "parser.tab.c"
    break;

  case 37:
#line 555 "parser.y"
                          {
		
		int idValue = getValue((yyvsp[-2].string), currentScope);
		printf("idValue = %d\n", idValue);
		// printf("$2 = %c\n", '+');
		// addNumToArray(idValue, $2);


		// -------- SEMANTIC CHECK -------- //
		// printf("ID is an int! rv = %s", getNodeType($1, currentScope));
		if (strcmp(getVariableType((yyvsp[-2].string), currentScope), "int") != 0) {
			semanticCheckPassed = 0;
		}

	}
#line 1850 "parser.tab.c"
    break;

  case 39:
#line 573 "parser.y"
             {

		char* noOp;
		//Get value of ID from symbol table
		int idValue = getValue((yyvsp[0].string), currentScope);
		// addNumToArray(idValue, noOp);

		// -------- SEMANTIC CHECK -------- //
		//printf("ID is an int! rv = %s", getNodeType($1, currentScope));

		if (strcmp(getVariableType((yyvsp[0].string), currentScope), "int") != 0) {
			semanticCheckPassed = 0;
		}

	}
#line 1870 "parser.tab.c"
    break;

  case 40:
#line 589 "parser.y"
                 {
		// printf("Number in mathExpr detected\n");
		char val[5];
		sprintf(val, "%d", (yyvsp[0].number));
		(yyval.ast) = AST_assignment("int", "", val);
		// char* noOp;
		// // printf("Number recog\n");
		// addNumToArray($1, noOp);
	}
#line 1884 "parser.tab.c"
    break;

  case 42:
#line 604 "parser.y"
                               {
		
		char newVal[5];

		// Evaluate expression
		char opArray[3];
		sprintf(opArray, "%s", (yyvsp[-1].string));

		sprintf(newVal, "%d", computeEquation(atoi((yyvsp[-2].ast)->RHS), atoi((yyvsp[0].ast)->RHS), opArray[0]));
		// printf("newVal = %s\n", newVal);

		(yyval.ast) = AST_assignment("int", "", newVal);

	}
#line 1903 "parser.tab.c"
    break;

  case 43:
#line 619 "parser.y"
                              {
		
		char newVal[5];

		// Evaluate expression
		char opArray[3];
		sprintf(opArray, "%s", (yyvsp[-1].string));

		sprintf(newVal, "%d", computeEquation(atoi((yyvsp[-2].ast)->RHS), atoi((yyvsp[0].ast)->RHS), opArray[0]));
		// printf("newVal = %s\n", newVal);

		(yyval.ast) = AST_assignment("int", "", newVal);

	}
#line 1922 "parser.tab.c"
    break;

  case 44:
#line 637 "parser.y"
                {
		char numVal[10];
		if (strcmp((yyvsp[0].ast)->nodeType,"id") == 0) {
			printf("ID Found!\n");
			sprintf(numVal, "%d", getValue((yyvsp[0].ast)->RHS, currentScope));
			(yyval.ast) = AST_assignment("int", "", numVal);
		} else {
			//primary is a number, do nothing
			(yyval.ast) = (yyvsp[0].ast);
		}
	}
#line 1938 "parser.tab.c"
    break;

  case 45:
#line 649 "parser.y"
                               {
		
		char newVal[5];

		// Evaluate expression
		char opArray[3];
		sprintf(opArray, "%s", (yyvsp[-1].string));

		sprintf(newVal, "%d", computeEquation((yyvsp[-2].number), atoi((yyvsp[0].ast)->RHS), opArray[0]));
		// printf("newVal = %s\n", newVal);

		(yyval.ast) = AST_assignment("int", "", newVal);

	}
#line 1957 "parser.tab.c"
    break;

  case 46:
#line 664 "parser.y"
                                {
		
		char newVal[5];

		// Evaluate expression
		char opArray[3];
		sprintf(opArray, "%s", (yyvsp[-1].string));

		sprintf(newVal, "%d", computeEquation((yyvsp[-2].number), atoi((yyvsp[0].ast)->RHS), opArray[0]));
		// printf("newVal = %s\n", newVal);

		(yyval.ast) = AST_assignment("int", "", newVal);

	}
#line 1976 "parser.tab.c"
    break;

  case 47:
#line 680 "parser.y"
                {}
#line 1982 "parser.tab.c"
    break;

  case 48:
#line 681 "parser.y"
                  {printf("\nRECOGNIZED RULE: Parameter\n");}
#line 1988 "parser.tab.c"
    break;

  case 49:
#line 681 "parser.y"
                                                                        {}
#line 1994 "parser.tab.c"
    break;

  case 50:
#line 688 "parser.y"
           {
		(yyval.ast) = AST_assignment("id", "" , (yyvsp[0].string));
	}
#line 2002 "parser.tab.c"
    break;

  case 51:
#line 691 "parser.y"
                 {
		printf("num detected\n");
		char numVal[10];
		sprintf(numVal, "%d", (yyvsp[0].number));
		(yyval.ast) = AST_assignment("int", "", numVal);
	}
#line 2013 "parser.tab.c"
    break;

  case 54:
#line 700 "parser.y"
               {printf("\nRECOGNIZED RULE: Unary Operation, NEGATIVE VALUE %s\n", (yyvsp[0].string));}
#line 2019 "parser.tab.c"
    break;

  case 55:
#line 703 "parser.y"
            {}
#line 2025 "parser.tab.c"
    break;

  case 56:
#line 704 "parser.y"
            {}
#line 2031 "parser.tab.c"
    break;

  case 57:
#line 705 "parser.y"
                {}
#line 2037 "parser.tab.c"
    break;

  case 58:
#line 706 "parser.y"
                 {}
#line 2043 "parser.tab.c"
    break;


#line 2047 "parser.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
                  yystos[+*yyssp], yyvsp);
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
#line 708 "parser.y"


int main(int argc, char**argv)
{
/*
	#ifdef YYDEBUG
		yydebug = 1;
	#endif
*/
	printf("\n\n##### COMPILER STARTED #####\n\n");

	// Initialize IR File
	initIRcodeFile();
	// Initialize MIPS.h
	initAssemblyFile();
	
	if (argc > 1){
	  if(!(yyin = fopen(argv[1], "r")))
          {
		perror(argv[1]);
		return(1);
	  }
	}
	yyparse();

	printf("\n\n##### COMPILER ENDED #####\n\n");


	/* fprintf (GarbageMIPS, "syscall\n"); */
}

int computeEquation(int val1, int val2, char operator) {

	/* char newVal[3]; */
	int newVal;
	/* printf("Equation detected: %d %c %d", val1, operator, val2); */

	switch (operator) {
		case '+':
			newVal = val1 + val2;
			/* sprintf(newVal, "%d", val1 + val2); */
			printf("Addtion Expr found!\n");
			break;
		case '-':
			newVal = val1 - val2;
			/* sprintf(newVal, "%d", val1 - val2); */
			printf("Subtraction Expr found!\n");
			break;
		case '*':
			newVal = val1 * val2;
			/* sprintf(newVal, "%d", val1 * val2); */
			printf("Multiplication Expr found!\n");
			break;
		case '/':
			newVal = val1 / val2;
			/* sprintf(newVal, "%d", val1 / val2); */
			printf("Division Expr found!\n");
			break;
	}

	printf("Newval = %d\n", newVal);
	return newVal;

}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}

/* Expr: ID EQ ID {
    // perform semantic checks for declarations and types
    if (semantic check passed){
        fprintf (IRcode, " T1 = T2");

        // print assembly

        fprintf(MIPScode, " mov, $r1, $2")
    }
}

...

int main(){

...
IRcode = fopen("IRcode.ir", "w");
...

} */
