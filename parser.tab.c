/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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

//Bison stuff I assume... IDK what it does
extern int yylex();
extern int yyparse();
extern FILE* yyin;

FILE * IRcode;
FILE * GarbageMIPS;

//Some global variables
void yyerror(const char* s);
char currentScope[50] = "GLOBAL"; // global or the name of the function
int semanticCheckPassed = 1; // flags to record correctness of semantic checks
char typeTemp[50];

int count = 0;


#line 100 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_SEMICOLON = 4,                  /* SEMICOLON  */
  YYSYMBOL_EQ = 5,                         /* EQ  */
  YYSYMBOL_PLUS = 6,                       /* PLUS  */
  YYSYMBOL_NUMBER = 7,                     /* NUMBER  */
  YYSYMBOL_WRITE = 8,                      /* WRITE  */
  YYSYMBOL_FUNC = 9,                       /* FUNC  */
  YYSYMBOL_MINUS = 10,                     /* MINUS  */
  YYSYMBOL_TIMES = 11,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 12,                    /* DIVIDE  */
  YYSYMBOL_LBRACKET = 13,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 14,                  /* RBRACKET  */
  YYSYMBOL_LPAREN = 15,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 16,                    /* RPAREN  */
  YYSYMBOL_LCURLY = 17,                    /* LCURLY  */
  YYSYMBOL_RCURLY = 18,                    /* RCURLY  */
  YYSYMBOL_INT = 19,                       /* INT  */
  YYSYMBOL_CHAR = 20,                      /* CHAR  */
  YYSYMBOL_FLOAT = 21,                     /* FLOAT  */
  YYSYMBOL_RETURN = 22,                    /* RETURN  */
  YYSYMBOL_WRITELN = 23,                   /* WRITELN  */
  YYSYMBOL_CHARACTER = 24,                 /* CHARACTER  */
  YYSYMBOL_YYACCEPT = 25,                  /* $accept  */
  YYSYMBOL_Program = 26,                   /* Program  */
  YYSYMBOL_27_1 = 27,                      /* $@1  */
  YYSYMBOL_VarDeclList = 28,               /* VarDeclList  */
  YYSYMBOL_VarDecl = 29,                   /* VarDecl  */
  YYSYMBOL_FunDeclList = 30,               /* FunDeclList  */
  YYSYMBOL_FunDecl = 31,                   /* FunDecl  */
  YYSYMBOL_32_2 = 32,                      /* $@2  */
  YYSYMBOL_FuncRun = 33,                   /* FuncRun  */
  YYSYMBOL_ParamDecList = 34,              /* ParamDecList  */
  YYSYMBOL_ParamDecListTail = 35,          /* ParamDecListTail  */
  YYSYMBOL_ParamDecl = 36,                 /* ParamDecl  */
  YYSYMBOL_Block = 37,                     /* Block  */
  YYSYMBOL_Type = 38,                      /* Type  */
  YYSYMBOL_StmtList = 39,                  /* StmtList  */
  YYSYMBOL_Stmt = 40,                      /* Stmt  */
  YYSYMBOL_Expr = 41,                      /* Expr  */
  YYSYMBOL_ParamList = 42,                 /* ParamList  */
  YYSYMBOL_43_3 = 43,                      /* $@3  */
  YYSYMBOL_Primary = 44,                   /* Primary  */
  YYSYMBOL_UnaryOp = 45,                   /* UnaryOp  */
  YYSYMBOL_BinOp = 46                      /* BinOp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   93

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  25
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  83

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   279


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
       0,    84,    84,    84,    92,    93,   100,   115,   135,   136,
     143,   143,   146,   166,   167,   174,   175,   182,   196,   214,
     222,   223,   224,   230,   231,   242,   243,   244,   245,   246,
     251,   252,   263,   264,   265,   266,   269,   270,   270,   276,
     277,   278,   279,   281,   284,   285,   286,   287
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "SEMICOLON",
  "EQ", "PLUS", "NUMBER", "WRITE", "FUNC", "MINUS", "TIMES", "DIVIDE",
  "LBRACKET", "RBRACKET", "LPAREN", "RPAREN", "LCURLY", "RCURLY", "INT",
  "CHAR", "FLOAT", "RETURN", "WRITELN", "CHARACTER", "$accept", "Program",
  "$@1", "VarDeclList", "VarDecl", "FunDeclList", "FunDecl", "$@2",
  "FuncRun", "ParamDecList", "ParamDecListTail", "ParamDecl", "Block",
  "Type", "StmtList", "Stmt", "Expr", "ParamList", "$@3", "Primary",
  "UnaryOp", "BinOp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-51)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      62,   -51,   -51,   -51,     5,   -51,    62,     6,   -51,    -3,
     -51,     3,    62,   -51,    -3,   -51,     1,    10,   -51,     8,
     -51,    13,    16,   -51,    62,   -51,     7,   -51,    62,    34,
      21,   -51,    30,    62,   -51,    40,    11,   -51,    47,   -51,
     -51,    17,   -51,    17,    17,    43,   -51,    26,    11,    55,
     -51,    17,    17,    17,    33,    64,    39,    67,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,    17,    81,    81,    74,
     -51,    37,   -51,   -51,   -51,   -51,    81,    51,   -51,    33,
      17,   -51,    81
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    20,    22,    21,     0,     2,     4,     0,     1,     0,
       5,     0,     0,     3,     8,     6,     0,     0,     9,     0,
      10,     0,     0,     7,    13,    11,     0,    14,    15,     0,
       0,    16,    17,     4,    12,     0,     0,    18,    39,    25,
      40,     0,    43,     0,     0,     0,    41,     0,    23,     0,
      30,     0,     0,     0,    36,     0,     0,     0,    29,    19,
      24,    26,    44,    45,    46,    47,     0,    31,    33,     0,
      39,     0,    37,    28,    42,    27,    32,     0,    34,    36,
       0,    38,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,   -51,    -5,   -51,    44,   -51,   -51,   -51,   -51,
      35,   -51,   -51,    18,    24,   -51,   -41,   -15,   -51,   -50,
     -51,   -51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     9,     5,     6,    13,    14,    22,    25,    26,
      27,    28,    34,     7,    47,    48,    49,    71,    79,    50,
      51,    66
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      55,    10,    56,    57,    72,     8,    12,    15,    19,    11,
      67,    68,    69,    20,    38,    39,    16,    23,    40,    41,
      38,    42,    21,    30,    40,    76,    43,    42,    36,    72,
      17,    24,    43,    44,    45,    46,    70,    32,    33,    82,
      40,    46,    29,    35,    59,    62,    29,    58,    43,    63,
      64,    65,    52,    78,    37,    74,    80,    46,    18,    61,
      53,    62,    54,    31,    81,    63,    64,    65,    73,     0,
      62,    75,    60,    62,    63,    64,    65,    63,    64,    65,
      62,     1,     2,     3,    63,    64,    65,    62,    77,     0,
       0,    63,    64,    65
};

static const yytype_int8 yycheck[] =
{
      41,     6,    43,    44,    54,     0,     9,     4,     7,     3,
      51,    52,    53,     3,     3,     4,    13,     4,     7,     8,
       3,    10,    14,    16,     7,    66,    15,    10,    33,    79,
      12,    15,    15,    22,    23,    24,     3,     3,    17,    80,
       7,    24,    24,    13,    18,     6,    28,     4,    15,    10,
      11,    12,     5,    16,    14,    16,     5,    24,    14,     4,
      13,     6,    15,    28,    79,    10,    11,    12,     4,    -1,
       6,     4,    48,     6,    10,    11,    12,    10,    11,    12,
       6,    19,    20,    21,    10,    11,    12,     6,    14,    -1,
      -1,    10,    11,    12
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    20,    21,    26,    28,    29,    38,     0,    27,
      28,     3,     9,    30,    31,     4,    13,    38,    30,     7,
       3,    14,    32,     4,    15,    33,    34,    35,    36,    38,
      16,    35,     3,    17,    37,    13,    28,    14,     3,     4,
       7,     8,    10,    15,    22,    23,    24,    39,    40,    41,
      44,    45,     5,    13,    15,    41,    41,    41,     4,    18,
      39,     4,     6,    10,    11,    12,    46,    41,    41,    41,
       3,    42,    44,     4,    16,     4,    41,    14,    16,    43,
       5,    42,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    25,    27,    26,    28,    28,    29,    29,    30,    30,
      32,    31,    33,    34,    34,    35,    35,    36,    36,    37,
      38,    38,    38,    39,    39,    40,    40,    40,    40,    40,
      41,    41,    41,    41,    41,    41,    42,    43,    42,    44,
      44,    44,    44,    45,    46,    46,    46,    46
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     0,     2,     3,     6,     1,     2,
       0,     5,     4,     0,     1,     1,     2,     2,     4,     4,
       1,     1,     1,     1,     2,     1,     2,     3,     3,     2,
       1,     2,     3,     3,     4,     6,     0,     0,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_ID: /* ID  */
#line 73 "parser.y"
         { fprintf(yyoutput, "%s", ((*yyvaluep).string)); }
#line 805 "parser.tab.c"
        break;

    case YYSYMBOL_NUMBER: /* NUMBER  */
#line 74 "parser.y"
         { fprintf(yyoutput, "%d", ((*yyvaluep).number)); }
#line 811 "parser.tab.c"
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
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* $@1: %empty  */
#line 84 "parser.y"
                     {}
#line 1201 "parser.tab.c"
    break;

  case 3: /* Program: VarDeclList $@1 FunDeclList  */
#line 85 "parser.y"
            {}
#line 1207 "parser.tab.c"
    break;

  case 4: /* VarDeclList: %empty  */
#line 92 "parser.y"
                           { /*printf("\nNo VarDeclList (EPSILON)\n"); */}
#line 1213 "parser.tab.c"
    break;

  case 5: /* VarDeclList: VarDecl VarDeclList  */
#line 93 "parser.y"
                                                {}
#line 1219 "parser.tab.c"
    break;

  case 6: /* VarDecl: Type ID SEMICOLON  */
#line 100 "parser.y"
                           {printf("\nRECOGNIZED RULE: VARIABLE declaration %s\n\n", (yyvsp[-1].string));

							//Asher's Semantic Checks
							//Symbol Table
							symTabAccess();
							//Var Decl Check
							int inSymTab = found((yyvsp[-1].string), currentScope);
							//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
							if (inSymTab == 0) {
								addItem((yyvsp[-1].string), "Var", (yyvsp[-2].ast), 0, currentScope);
							} else {
								printf("\nSEMANTIC ERROR: Var %s is already in the symbol table\n", (yyvsp[-1].string));
							} 
							showSymTable();
}
#line 1239 "parser.tab.c"
    break;

  case 7: /* VarDecl: Type ID LBRACKET NUMBER RBRACKET SEMICOLON  */
#line 115 "parser.y"
                                                             {printf("\nRECOGNIZED RULE: ARRAY declaration %s\n\n", (yyvsp[-4].string));
		
							//Asher's Semantic Checks
							//Symbol Table
							symTabAccess();
							int inSymTab = found((yyvsp[-4].string), currentScope);
							//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
							if (inSymTab == 0) {
								addItem((yyvsp[-4].string), "ARRAY", (yyvsp[-5].ast), (yyvsp[-2].number), currentScope);
							} else {
								printf("\nSEMANTIC ERROR: ARR %s is already in the symbol table\n", (yyvsp[-4].string));
							} 
							showSymTable();
}
#line 1258 "parser.tab.c"
    break;

  case 8: /* FunDeclList: FunDecl  */
#line 135 "parser.y"
                     {(yyval.ast) = (yyvsp[0].ast);}
#line 1264 "parser.tab.c"
    break;

  case 9: /* FunDeclList: FunDecl FunDeclList  */
#line 136 "parser.y"
                                              {(yyval.ast) = (yyvsp[-1].ast);}
#line 1270 "parser.tab.c"
    break;

  case 10: /* $@2: %empty  */
#line 143 "parser.y"
                      {strcpy(currentScope, (yyvsp[0].string));}
#line 1276 "parser.tab.c"
    break;

  case 12: /* FuncRun: LPAREN ParamDecList RPAREN Block  */
#line 146 "parser.y"
                                          {
			printf("\nRECOGNIZED RULE: FUNCTION declaration %s\n\n", (yyvsp[-1].string));
			//Asher's Semantic Checks
			//Symbol Table
			symTabAccess();
			int inSymTab = found(currentScope, currentScope);
			//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
			if (inSymTab == 0) {
				addItem(currentScope, "FUNC", "Func", 0, currentScope);
			} else {
				printf("\nSEMANTIC ERROR: FUNC %s is already in the symbol table\n", (yyvsp[-2].ast));
			} 
			showSymTable();
			strcpy(currentScope, "GLOBAL");
	}
#line 1296 "parser.tab.c"
    break;

  case 13: /* ParamDecList: %empty  */
#line 166 "parser.y"
                            {printf("No ParamDeclList (EPSILON)\n");}
#line 1302 "parser.tab.c"
    break;

  case 14: /* ParamDecList: ParamDecListTail  */
#line 167 "parser.y"
                                           {}
#line 1308 "parser.tab.c"
    break;

  case 15: /* ParamDecListTail: ParamDecl  */
#line 174 "parser.y"
                            {}
#line 1314 "parser.tab.c"
    break;

  case 16: /* ParamDecListTail: ParamDecl ParamDecListTail  */
#line 175 "parser.y"
                                                             {}
#line 1320 "parser.tab.c"
    break;

  case 17: /* ParamDecl: Type ID  */
#line 182 "parser.y"
                   {printf("\nRECOGNIZED RULE: Parameter VARIABLE declaration %s\n", (yyvsp[0].string));
			//Asher's Semantic Checks
			//Symbol Table
			symTabAccess();
			//Var Decl Check
			int inSymTab = found((yyvsp[0].string), currentScope);
			//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
			if (inSymTab == 0) {
				addItem((yyvsp[0].string), "Var", (yyvsp[-1].ast), 0, currentScope);
			} else {
				printf("\nSEMANTIC ERROR: Var %s is already in the symbol table\n", (yyvsp[0].string));
			} 
			showSymTable();
}
#line 1339 "parser.tab.c"
    break;

  case 18: /* ParamDecl: Type ID LBRACKET RBRACKET  */
#line 196 "parser.y"
                                             {printf("\n RECOGNIZED RULE: Parameter ARRAY declaration %s\n", (yyvsp[-2].string));
			//Asher's Semantic Checks
			//Symbol Table
			symTabAccess();
			int inSymTab = found((yyvsp[-2].string), currentScope);
			//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
			if (inSymTab == 0) {
				addItem((yyvsp[-2].string), "ARRAY", (yyvsp[-3].ast), (yyvsp[0].string), currentScope);
			} else {
				printf("\nSEMANTIC ERROR: ARR %s is already in the symbol table\n", (yyvsp[-2].string));
			} 
			showSymTable();
}
#line 1357 "parser.tab.c"
    break;

  case 19: /* Block: LCURLY VarDeclList StmtList RCURLY  */
#line 214 "parser.y"
                                          {}
#line 1363 "parser.tab.c"
    break;

  case 20: /* Type: INT  */
#line 222 "parser.y"
          {}
#line 1369 "parser.tab.c"
    break;

  case 21: /* Type: FLOAT  */
#line 223 "parser.y"
                {}
#line 1375 "parser.tab.c"
    break;

  case 22: /* Type: CHAR  */
#line 224 "parser.y"
               {}
#line 1381 "parser.tab.c"
    break;

  case 23: /* StmtList: Stmt  */
#line 230 "parser.y"
               {}
#line 1387 "parser.tab.c"
    break;

  case 24: /* StmtList: Stmt StmtList  */
#line 231 "parser.y"
                        {}
#line 1393 "parser.tab.c"
    break;

  case 25: /* Stmt: SEMICOLON  */
#line 242 "parser.y"
                {}
#line 1399 "parser.tab.c"
    break;

  case 26: /* Stmt: Expr SEMICOLON  */
#line 243 "parser.y"
                         {}
#line 1405 "parser.tab.c"
    break;

  case 27: /* Stmt: RETURN Expr SEMICOLON  */
#line 244 "parser.y"
                                {printf("\nRECOGNIZED RULE: Return Statement\n");}
#line 1411 "parser.tab.c"
    break;

  case 28: /* Stmt: WRITE Expr SEMICOLON  */
#line 245 "parser.y"
                               {printf("\nRECOGNIZED RULE: Write Statement\n");}
#line 1417 "parser.tab.c"
    break;

  case 29: /* Stmt: WRITELN SEMICOLON  */
#line 246 "parser.y"
                            {printf("\nRECOGNIZED RULE: Write Line %s\n", (yyvsp[-1].string));}
#line 1423 "parser.tab.c"
    break;

  case 30: /* Expr: Primary  */
#line 251 "parser.y"
              {}
#line 1429 "parser.tab.c"
    break;

  case 31: /* Expr: UnaryOp Expr  */
#line 252 "parser.y"
                       { //Asher's Semantic Checls
					//Symbol Table
				symTabAccess();
				int inSymTab = found((yyvsp[0].ast), currentScope);
				//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
				if (inSymTab == 0) {
					printf("\nSEMANTIC ERROR: ARR %s is already in the symbol table\n", (yyvsp[0].ast));
				}
				showSymTable();
	
	}
#line 1445 "parser.tab.c"
    break;

  case 32: /* Expr: Expr BinOp Expr  */
#line 263 "parser.y"
                          {}
#line 1451 "parser.tab.c"
    break;

  case 33: /* Expr: ID EQ Expr  */
#line 264 "parser.y"
                     {printf("\nRECOGNIZED RULE: Assignment Statement %s\n", (yyvsp[-2].string));}
#line 1457 "parser.tab.c"
    break;

  case 34: /* Expr: ID LPAREN ParamList RPAREN  */
#line 265 "parser.y"
                                     {printf("\nRECOGNIZED RULE: Function Call %s\n", (yyvsp[-3].string));}
#line 1463 "parser.tab.c"
    break;

  case 35: /* Expr: ID LBRACKET Expr RBRACKET EQ Expr  */
#line 266 "parser.y"
                                            {printf("\nRECOGNIZED RULE: ARRAY assignment %s\n", (yyvsp[-5].string));}
#line 1469 "parser.tab.c"
    break;

  case 36: /* ParamList: %empty  */
#line 269 "parser.y"
                {}
#line 1475 "parser.tab.c"
    break;

  case 37: /* $@3: %empty  */
#line 270 "parser.y"
                  {printf("\nRECOGNIZED RULE: Parameter\n");}
#line 1481 "parser.tab.c"
    break;

  case 38: /* ParamList: Primary $@3 ParamList  */
#line 270 "parser.y"
                                                                        {}
#line 1487 "parser.tab.c"
    break;

  case 39: /* Primary: ID  */
#line 276 "parser.y"
            {}
#line 1493 "parser.tab.c"
    break;

  case 40: /* Primary: NUMBER  */
#line 277 "parser.y"
                         {}
#line 1499 "parser.tab.c"
    break;

  case 41: /* Primary: CHARACTER  */
#line 278 "parser.y"
                            {}
#line 1505 "parser.tab.c"
    break;

  case 42: /* Primary: LPAREN Expr RPAREN  */
#line 279 "parser.y"
                                     {}
#line 1511 "parser.tab.c"
    break;

  case 43: /* UnaryOp: MINUS  */
#line 281 "parser.y"
               {printf("\nRECOGNIZED RULE: Unary Operation, NEGATIVE VALUE %s\n", (yyvsp[0].string));}
#line 1517 "parser.tab.c"
    break;

  case 44: /* BinOp: PLUS  */
#line 284 "parser.y"
            {}
#line 1523 "parser.tab.c"
    break;

  case 45: /* BinOp: MINUS  */
#line 285 "parser.y"
            {}
#line 1529 "parser.tab.c"
    break;

  case 46: /* BinOp: TIMES  */
#line 286 "parser.y"
                {}
#line 1535 "parser.tab.c"
    break;

  case 47: /* BinOp: DIVIDE  */
#line 287 "parser.y"
                 {}
#line 1541 "parser.tab.c"
    break;


#line 1545 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 289 "parser.y"


int main(int argc, char**argv)
{
/*
	#ifdef YYDEBUG
		yydebug = 1;
	#endif
*/
	printf("\n\n##### COMPILER STARTED #####\n\n");

	// Initialize currentScope = "GLOBAL"

	/* IRcode = fopen("IRcode.ir", "w");
	printf("IR File Opened");
	GarbageMIPS = fopen("GarbageMIPS.asm", "w");
	printf("MIPS File Opened");

	//print basic MIPS crap into the file
	fprintf (GarbageMIPS, ".text\n");
	fprintf (GarbageMIPS, "main:\n");

	//fprintf(MIPS, " .text"); */
	
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
