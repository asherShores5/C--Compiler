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
#line 9 "parser.y"

//Standard libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Other Files 
#include "symbolTable.h"
#include "AST.h"
#include "IRcode.h"
#include "MIPScode.h"

//Bison stuff I assume... IDK what it does
extern int yylex();
extern int yyparse();
extern FILE* yyin;

//Some global variables
int computeEquation(int val1, int val2, char operator);
int evalCondition(struct AST* x, struct AST* y, char logOp[5]);
void yyerror(const char* s);
char currentScope[50] = "GLOBAL"; // global or the name of the function
char currReturnType[10];
int semanticCheckPassed = 1; // flags to record correctness of semantic checks
int gotToElse = 0;
char typeTemp[50];
struct AST * lastVar; 

int count = 0;


#line 103 "parser.tab.c"

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
  YYSYMBOL_INTEGER = 6,                    /* INTEGER  */
  YYSYMBOL_DECIMAL = 7,                    /* DECIMAL  */
  YYSYMBOL_WRITE = 8,                      /* WRITE  */
  YYSYMBOL_FUNC = 9,                       /* FUNC  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_PLUS = 12,                      /* PLUS  */
  YYSYMBOL_MINUS = 13,                     /* MINUS  */
  YYSYMBOL_TIMES = 14,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 15,                    /* DIVIDE  */
  YYSYMBOL_LOGICOP = 16,                   /* LOGICOP  */
  YYSYMBOL_LBRACKET = 17,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 18,                  /* RBRACKET  */
  YYSYMBOL_LPAREN = 19,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 20,                    /* RPAREN  */
  YYSYMBOL_LCURLY = 21,                    /* LCURLY  */
  YYSYMBOL_RCURLY = 22,                    /* RCURLY  */
  YYSYMBOL_INT = 23,                       /* INT  */
  YYSYMBOL_CHAR = 24,                      /* CHAR  */
  YYSYMBOL_FLOAT = 25,                     /* FLOAT  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_WRITELN = 27,                   /* WRITELN  */
  YYSYMBOL_CHARACTER = 28,                 /* CHARACTER  */
  YYSYMBOL_YYACCEPT = 29,                  /* $accept  */
  YYSYMBOL_Program = 30,                   /* Program  */
  YYSYMBOL_DeclList = 31,                  /* DeclList  */
  YYSYMBOL_Decl = 32,                      /* Decl  */
  YYSYMBOL_VarDecl = 33,                   /* VarDecl  */
  YYSYMBOL_FunDeclList = 34,               /* FunDeclList  */
  YYSYMBOL_FunDecl = 35,                   /* FunDecl  */
  YYSYMBOL_36_1 = 36,                      /* $@1  */
  YYSYMBOL_ParamDecList = 37,              /* ParamDecList  */
  YYSYMBOL_ParamDecListTail = 38,          /* ParamDecListTail  */
  YYSYMBOL_ParamDecl = 39,                 /* ParamDecl  */
  YYSYMBOL_Block = 40,                     /* Block  */
  YYSYMBOL_Type = 41,                      /* Type  */
  YYSYMBOL_StmtList = 42,                  /* StmtList  */
  YYSYMBOL_Stmt = 43,                      /* Stmt  */
  YYSYMBOL_IfStmt = 44,                    /* IfStmt  */
  YYSYMBOL_Condition = 45,                 /* Condition  */
  YYSYMBOL_Else = 46,                      /* Else  */
  YYSYMBOL_ArrayExpr = 47,                 /* ArrayExpr  */
  YYSYMBOL_Expr = 48,                      /* Expr  */
  YYSYMBOL_Primary = 49,                   /* Primary  */
  YYSYMBOL_MathExpr = 50,                  /* MathExpr  */
  YYSYMBOL_Trm = 51,                       /* Trm  */
  YYSYMBOL_Factor = 52,                    /* Factor  */
  YYSYMBOL_ParamList = 53,                 /* ParamList  */
  YYSYMBOL_54_2 = 54,                      /* $@2  */
  YYSYMBOL_UnaryOp = 55                    /* UnaryOp  */
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
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   119

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  106

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   106,   106,   115,   125,   130,   151,   154,   157,   169,
     208,   255,   257,   268,   268,   327,   329,   338,   340,   349,
     391,   399,   400,   401,   406,   408,   418,   427,   430,   450,
     483,   490,   507,   532,   535,   553,   595,   633,   635,   637,
     639,   656,   747,   753,   757,   764,   771,   782,   784,   799,
     817,   833,   848,   865,   869,   876,   881,   882,   882,   890
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
  "EQ", "INTEGER", "DECIMAL", "WRITE", "FUNC", "IF", "ELSE", "PLUS",
  "MINUS", "TIMES", "DIVIDE", "LOGICOP", "LBRACKET", "RBRACKET", "LPAREN",
  "RPAREN", "LCURLY", "RCURLY", "INT", "CHAR", "FLOAT", "RETURN",
  "WRITELN", "CHARACTER", "$accept", "Program", "DeclList", "Decl",
  "VarDecl", "FunDeclList", "FunDecl", "$@1", "ParamDecList",
  "ParamDecListTail", "ParamDecl", "Block", "Type", "StmtList", "Stmt",
  "IfStmt", "Condition", "Else", "ArrayExpr", "Expr", "Primary",
  "MathExpr", "Trm", "Factor", "ParamList", "$@2", "UnaryOp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-92)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-46)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       9,    66,   -92,     6,   -92,     1,    67,     2,   -92,    55,
     -92,   -92,   -92,     1,    45,   -92,    24,   -92,     9,   -92,
     -92,    54,    75,   -92,    38,   -92,   -92,    78,   -92,    27,
      39,   -92,     1,    49,    80,    20,    83,    81,    20,   -92,
     -92,    47,    85,   -92,   -92,   -92,   -92,    21,   -92,   -92,
      55,    55,    55,    55,   -92,    76,   -92,    79,   -92,   -92,
     -92,    74,   -92,    77,    82,    84,   -92,   -92,   -92,    92,
      39,    39,   -92,   -92,    93,    96,    20,   -92,   -92,    86,
      20,    87,    88,    20,   -92,    67,     9,    97,   -92,    99,
      96,   -92,    89,   -92,    67,   101,    90,    86,   -92,   -92,
      86,   -92,   -92,   -92,   -92,   -92
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    53,    26,    54,    44,     0,     0,     0,    59,     0,
      21,    23,    22,     0,     0,    46,     0,     2,     4,     6,
       5,    11,     0,     7,    24,     8,    39,     0,    37,    38,
      47,    50,     0,     0,     0,    56,     0,     0,     0,    53,
      54,     0,     0,    30,     1,     3,    12,     0,    25,    27,
       0,     0,     0,     0,    40,    53,    41,     0,    43,    45,
      57,     0,    29,     0,     0,     0,    55,    28,     9,     0,
      49,    48,    51,    52,     0,     0,    56,    42,    13,     0,
       0,     0,     0,     0,    58,    15,     0,    33,    32,     0,
      36,    35,     0,    16,    17,     0,     0,     0,    31,    10,
       0,    18,    19,    20,    34,    14
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -92,   -92,   -17,   -92,   -92,    94,   -92,   -92,   -92,    16,
     -92,   -91,    -6,    95,   -92,   -92,   -92,   -92,   -92,    -2,
     -33,   102,    22,    23,    37,   -92,   -92
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    16,    17,    18,    19,    20,    21,    85,    92,    93,
      94,    87,    22,    23,    24,    25,    64,    98,    26,    27,
      28,    29,    30,    31,    61,    76,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      37,    45,    60,    36,     1,    65,   104,     3,     4,   105,
     -45,    42,     1,     2,     8,     3,     4,     5,     6,     7,
       9,    38,     8,    58,    44,    68,    59,     4,     9,    15,
      54,    56,    10,    11,    12,    13,    14,    15,    69,    50,
      51,     1,     2,    60,     3,     4,     5,    88,    15,    43,
      91,     8,    55,    52,    53,     3,     4,     9,    39,    50,
      51,    40,     8,     6,    13,    14,    15,    66,     9,    96,
     -43,    33,    70,    71,     9,    72,    73,    15,    47,    95,
     -43,    33,    49,    34,    63,    35,    57,    62,    95,    67,
      10,    11,    12,    74,    77,    35,    78,    75,    81,    82,
      80,    83,    79,    99,   102,    89,    90,    86,    97,   100,
     101,    41,   103,    84,     0,    46,     0,     0,     0,    48
};

static const yytype_int8 yycheck[] =
{
       6,    18,    35,     5,     3,    38,    97,     6,     7,   100,
       4,    13,     3,     4,    13,     6,     7,     8,     9,    10,
      19,    19,    13,     3,     0,     4,     6,     7,    19,    28,
      32,    33,    23,    24,    25,    26,    27,    28,    17,    12,
      13,     3,     4,    76,     6,     7,     8,    80,    28,     4,
      83,    13,     3,    14,    15,     6,     7,    19,     3,    12,
      13,     6,    13,     9,    26,    27,    28,    20,    19,    86,
       4,     5,    50,    51,    19,    52,    53,    28,     3,    85,
       4,     5,     4,    17,     3,    19,     6,     4,    94,     4,
      23,    24,    25,    17,    20,    19,    19,    18,     6,     6,
      16,     5,    20,     4,     3,    18,    18,    21,    11,    20,
      94,     9,    22,    76,    -1,    21,    -1,    -1,    -1,    24
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     6,     7,     8,     9,    10,    13,    19,
      23,    24,    25,    26,    27,    28,    30,    31,    32,    33,
      34,    35,    41,    42,    43,    44,    47,    48,    49,    50,
      51,    52,    55,     5,    17,    19,    48,    41,    19,     3,
       6,    50,    48,     4,     0,    31,    34,     3,    42,     4,
      12,    13,    14,    15,    48,     3,    48,     6,     3,     6,
      49,    53,     4,     3,    45,    49,    20,     4,     4,    17,
      51,    51,    52,    52,    17,    18,    54,    20,    19,    20,
      16,     6,     6,     5,    53,    36,    21,    40,    49,    18,
      18,    49,    37,    38,    39,    41,    31,    11,    46,     4,
      20,    38,     3,    22,    40,    40
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    29,    30,    31,    31,    31,    32,    32,    32,    33,
      33,    34,    34,    36,    35,    37,    37,    38,    38,    39,
      40,    41,    41,    41,    42,    42,    43,    43,    43,    43,
      43,    44,    45,    46,    46,    47,    47,    48,    48,    48,
      48,    48,    48,    49,    49,    49,    49,    50,    50,    50,
      51,    51,    51,    52,    52,    52,    53,    54,    53,    55
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       6,     1,     2,     0,     8,     0,     1,     1,     2,     2,
       3,     1,     1,     1,     1,     2,     1,     2,     3,     3,
       2,     6,     3,     0,     2,     6,     6,     1,     1,     1,
       2,     3,     4,     1,     1,     1,     1,     1,     3,     3,
       1,     3,     3,     1,     1,     3,     0,     0,     3,     1
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
#line 94 "parser.y"
         { fprintf(yyoutput, "%s", ((*yyvaluep).string)); }
#line 832 "parser.tab.c"
        break;

    case YYSYMBOL_INTEGER: /* INTEGER  */
#line 95 "parser.y"
         { fprintf(yyoutput, "%d", ((*yyvaluep).number)); }
#line 838 "parser.tab.c"
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
  case 2: /* Program: DeclList  */
#line 106 "parser.y"
                 {
		
		(yyval.ast) = (yyvsp[0].ast);
		// printAST($$, 3);

	}
#line 1233 "parser.tab.c"
    break;

  case 3: /* DeclList: Decl DeclList  */
#line 115 "parser.y"
                      { 

		// printf("\nTest debug DECLDECLLIST\n");
		(yyvsp[-1].ast)->right = (yyvsp[0].ast);
		(yyval.ast) = (yyvsp[-1].ast);
		// printf("LINK DECLLIST\n");
		// printNode($$->right);

	}
#line 1247 "parser.tab.c"
    break;

  case 4: /* DeclList: Decl  */
#line 125 "parser.y"
               {
		(yyval.ast) = (yyvsp[0].ast);
		// printf("DECL\n");
	}
#line 1256 "parser.tab.c"
    break;

  case 6: /* Decl: VarDecl  */
#line 151 "parser.y"
                {}
#line 1262 "parser.tab.c"
    break;

  case 7: /* Decl: StmtList  */
#line 154 "parser.y"
                   {
	}
#line 1269 "parser.tab.c"
    break;

  case 8: /* Decl: IfStmt  */
#line 157 "parser.y"
                 {
		// printf("pls help\n");
	}
#line 1277 "parser.tab.c"
    break;

  case 9: /* VarDecl: Type ID SEMICOLON  */
#line 169 "parser.y"
                          {

		printf("\nRECOGNIZED RULE: VARIABLE declaration %s\n\n", (yyvsp[-1].string));


		// ----- SYMBOL TABLE ----- //
		symTabAccess();
		int inSymTab = found((yyvsp[-1].string), currentScope);
		//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
		

		// ------ SEMANTIC CHECKS ------ //
		if (inSymTab == 0)  {
			addItem((yyvsp[-1].string), "Var", (yyvsp[-2].ast)->nodeType, currentScope);
			showSymTable();
		}
		else {
			printf("SEMANTIC ERROR: Var %s is already in the symbol table\n", (yyvsp[-1].string));
			semanticCheckPassed = 0;
		}


		// ------  AST  ------ //
		if (semanticCheckPassed) {

			(yyval.ast) = AST_Type("TYPE", (yyvsp[-2].ast)->nodeType, (yyvsp[-1].string));


			// ---- CODE GENERATION ---- //
			// code generation occurs when variable 
			// recieves a value to save space
			
		}

		semanticCheckPassed = 1;
	}
#line 1318 "parser.tab.c"
    break;

  case 10: /* VarDecl: Type ID LBRACKET INTEGER RBRACKET SEMICOLON  */
#line 208 "parser.y"
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

			showSymTable();
		} else {
			printf("SEMANTIC ERROR: Var %s is already in the symbol table\n", (yyvsp[-4].string));
		}


		// ----- AST ----- //
		char intVal[50]; 
		sprintf(intVal, "%d", (yyvsp[-2].number));
		(yyval.ast) = AST_assignment("ARR", intVal, (yyvsp[-4].string));


		// ----- CODE GENERATION ----- //
		
		// ---- IR CODE ---- //
		// emitArrayDecl($2, $4);


		// ---- MIPS CODE ---- //
		emitMIPSArrayDecl((yyvsp[-4].string), (yyvsp[-2].number));

		semanticCheckPassed = 1;
	}
#line 1362 "parser.tab.c"
    break;

  case 12: /* FunDeclList: FunDecl FunDeclList  */
#line 257 "parser.y"
                              {
		
		//TODO AST stuff idk what to do about this yet

	}
#line 1372 "parser.tab.c"
    break;

  case 13: /* $@1: %empty  */
#line 268 "parser.y"
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
			
			addItem((yyvsp[-1].string), "FUNC", (yyvsp[-2].ast)->nodeType, currentScope);
			showSymTable();

		} 
		else {
			printf("SEMANTIC ERROR: Function %s is already in the symbol table\n", (yyvsp[-2].ast)->nodeType);
			semanticCheckPassed = 0;
		}

		// ---- MIPS CODE ---- //
		emitMIPSFunc((yyvsp[-1].string));
	}
#line 1406 "parser.tab.c"
    break;

  case 14: /* FunDecl: FUNC Type ID LPAREN $@1 ParamDecList RPAREN Block  */
#line 298 "parser.y"
                                  {

		// ----- AST ----- //
		if (semanticCheckPassed) {
			(yyval.ast) = AST_assignment("FUNC", (yyvsp[-6].ast)->nodeType, (yyvsp[-5].string));		

			// printNode($$);

			// ---- CODE GENERATION ---- //

			// ---- IR CODE ---- //


		}

		// Leave Function in MIPScode.h
		endOfFunction();
	
		semanticCheckPassed = 1;

	}
#line 1432 "parser.tab.c"
    break;

  case 15: /* ParamDecList: %empty  */
#line 327 "parser.y"
                            {printf("No ParamDeclList (EPSILON)\n\n");}
#line 1438 "parser.tab.c"
    break;

  case 16: /* ParamDecList: ParamDecListTail  */
#line 329 "parser.y"
                           {}
#line 1444 "parser.tab.c"
    break;

  case 17: /* ParamDecListTail: ParamDecl  */
#line 338 "parser.y"
                  {}
#line 1450 "parser.tab.c"
    break;

  case 18: /* ParamDecListTail: ParamDecl ParamDecListTail  */
#line 340 "parser.y"
                                     {(yyvsp[-1].ast)->right = (yyvsp[0].ast); (yyval.ast) = (yyvsp[-1].ast);}
#line 1456 "parser.tab.c"
    break;

  case 19: /* ParamDecl: Type ID  */
#line 349 "parser.y"
                {

		printf("\nRECOGNIZED RULE: Parameter VARIABLE declaration %s\n", (yyvsp[0].string));

		//Asher's Semantic Checks
		// ---- Symbol Table ---- //
		symTabAccess();

		//Var Decl Check
		int inSymTab = found((yyvsp[0].string), currentScope);
		//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);

		if (inSymTab == 0) {
			addItem((yyvsp[0].string), "Var", (yyvsp[-1].ast)->nodeType, currentScope);
			showSymTable();
		} 
		else {
			printf("\nSEMANTIC ERROR: Var %s is already in the symbol table\n", (yyvsp[0].string));
		} 

	}
#line 1482 "parser.tab.c"
    break;

  case 20: /* Block: LCURLY DeclList RCURLY  */
#line 391 "parser.y"
                               {
		(yyval.ast) = (yyvsp[-1].ast);
		// printf("right: %s\n", $$->right->RHS);
	}
#line 1491 "parser.tab.c"
    break;

  case 21: /* Type: INT  */
#line 399 "parser.y"
          {}
#line 1497 "parser.tab.c"
    break;

  case 22: /* Type: FLOAT  */
#line 400 "parser.y"
                {}
#line 1503 "parser.tab.c"
    break;

  case 23: /* Type: CHAR  */
#line 401 "parser.y"
               {}
#line 1509 "parser.tab.c"
    break;

  case 25: /* StmtList: Stmt StmtList  */
#line 408 "parser.y"
                        {
		(yyvsp[-1].ast)->right = (yyvsp[0].ast);
		(yyval.ast) = (yyvsp[-1].ast);
		// printNode($$);
	}
#line 1519 "parser.tab.c"
    break;

  case 26: /* Stmt: SEMICOLON  */
#line 418 "parser.y"
                  {
		printf("\nRECOGNIZED RULE: SEMICOLON %s\n", (yyvsp[0].string));	
	}
#line 1527 "parser.tab.c"
    break;

  case 27: /* Stmt: Expr SEMICOLON  */
#line 427 "parser.y"
                         {}
#line 1533 "parser.tab.c"
    break;

  case 28: /* Stmt: RETURN Expr SEMICOLON  */
#line 430 "parser.y"
                                {		

		printf("RETURN Statement Recognized!\n");


		// ----- AST ----- //
		(yyval.ast) = AST_assignment("RETURN", "", (yyvsp[-1].ast)->RHS);


		// ---- CODE GENERATION ---- //

		// ---- IR CODE ---- //


		// ---- MIPS CODE ---- //
		// TODO figure out how we want to determine return type smile

	}
#line 1556 "parser.tab.c"
    break;

  case 29: /* Stmt: WRITE Expr SEMICOLON  */
#line 450 "parser.y"
                               {
		printf("\nRECOGNIZED RULE: Write Statement\n");

		(yyval.ast) = AST_Write("WRITE", "", (yyvsp[-1].ast)->RHS);

		// ------     IR CODE     ------ //
		 //emitIRWriteId($2->LHS, getVariableType($2->LHS, currentScope));
		// ------ ¯\_(ツ)_/¯ ------ //

			// ---- MIPS CODE ---- //
		// Printing an ID ------>
		printf("%s\n\n", (yyvsp[-1].ast)->nodeType);
		if (!strcmp((yyvsp[-1].ast)->nodeType,"id")) {

			//emitMIPSWriteId($2->RHS, getVariableType($2->RHS, currentScope));

		}

		else if (!strcmp((yyvsp[-1].ast)->nodeType, "int")) {

			//emitMIPSWriteInt(atoi($2->RHS));

		}

		else if (!strcmp((yyvsp[-1].ast)->nodeType, "char")) {

			//emitMIPSWriteId($2->RHS, getVariableType($2->RHS, currentScope));

		}
		
	}
#line 1592 "parser.tab.c"
    break;

  case 30: /* Stmt: WRITELN SEMICOLON  */
#line 483 "parser.y"
                            {
		printf("\nRECOGNIZED RULE: Write Line %s\n", (yyvsp[-1].string));
	}
#line 1600 "parser.tab.c"
    break;

  case 31: /* IfStmt: IF LPAREN Condition RPAREN Block Else  */
#line 490 "parser.y"
                                              {

		if ((yyvsp[-3].ast)) {
			
			printf("IfStmt Executed ----->\n");			
			
		}

		else {
			printf("GoTo Else statment----->\n");
		}		

	}
#line 1618 "parser.tab.c"
    break;

  case 32: /* Condition: Primary LOGICOP Primary  */
#line 507 "parser.y"
                                {

		// ----- SEMANTIC CHECKS ----- //

		// TODO 1.If primaries are ID's, check 
		// if they have been declared
		// 2. Make sure primaries are of same type

		int cond = evalCondition((yyvsp[-2].ast), (yyvsp[0].ast), (yyvsp[-1].string));

		printf("The condition %s %s %s is ", (yyvsp[-2].ast)->RHS, (yyvsp[-1].string), (yyvsp[0].ast)->RHS);

		if (cond) {
			printf("True\n");
			(yyval.ast) = 1;
		}
		 else {
			printf("False\n");
			(yyval.ast) = 0;
		}
	}
#line 1644 "parser.tab.c"
    break;

  case 34: /* Else: ELSE Block  */
#line 535 "parser.y"
                     {
		// DO STUFF
		//big brain time
	}
#line 1653 "parser.tab.c"
    break;

  case 35: /* ArrayExpr: ID LBRACKET INTEGER RBRACKET EQ Primary  */
#line 553 "parser.y"
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
		setItemValue(arrayStmt, (yyvsp[0].ast)->RHS, currentScope);


		// ----- AST ----- //
		(yyval.ast) = AST_assignment("=", arrayStmt, newVal);		


		// ---- CODE GENERATION ---- //

			// ---- IR CODE ---- //


			// ---- MIPS CODE ---- //
		//TODO we only have functionality to add to ints at the moment 
		emitMIPSIntArrayAssign((yyvsp[-5].string), (yyvsp[-3].number), atoi((yyvsp[0].ast)->RHS));

	}
#line 1698 "parser.tab.c"
    break;

  case 36: /* ArrayExpr: ID EQ ID LBRACKET INTEGER RBRACKET  */
#line 595 "parser.y"
                                             {

		symTabAccess();
		int inSymTab = found((yyvsp[-5].string), currentScope);

		// Getting array value in the symbol table
		if (inSymTab) {

			char arrayStmt[10]; char newVal[10];
			sprintf(arrayStmt, "%s%s%d%s", (yyvsp[-3].string), (yyvsp[-2].string), (yyvsp[-1].number), (yyvsp[0].string));

			int arrayVal = atoi(getValue(arrayStmt, currentScope));
			sprintf(newVal, "%d", arrayVal);


			// ---- SYMBOL TABLE ---- //
			setItemValue((yyvsp[-5].string), newVal, currentScope);


			// ------ AST ------ //
			(yyval.ast) = AST_assignment("=", (yyvsp[-5].string), newVal);


			// ---- CODE GENERATION ---- //

			// ---- IR CODE ---- //
			//TODO

			// ---- MIPS CODE ---- //
			
		}

	}
#line 1736 "parser.tab.c"
    break;

  case 40: /* Expr: UnaryOp Expr  */
#line 639 "parser.y"
                       { 

		//Asher's Semantic Checls
		// ------- SYMBOL TABLE ------- //
		symTabAccess();
		int inSymTab = found((yyvsp[0].ast)->RHS, currentScope);
		//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
		if (inSymTab == 0) {
			printf("\nSEMANTIC ERROR: Expr %s is NOT in the symbol table\n", (yyvsp[0].ast)->nodeType);
		}
		showSymTable();

		//TODO fix negative numbers :)
		// $$ = $2;

	}
#line 1757 "parser.tab.c"
    break;

  case 41: /* Expr: ID EQ Expr  */
#line 656 "parser.y"
                     {

		printf("\nRECOGNIZED RULE: Assignment Statement ----> %s\n", (yyvsp[-2].string));
		int inSymTab = found((yyvsp[-2].string), currentScope);

		// Variable to tell if value has been assigned yet
		int isNullValue = strcmp(getValue((yyvsp[-2].string), currentScope), "NULL");
	

		// ------ SEMANTIC CHECKS ------ //
		if (inSymTab == 0) {

			printf("\nSEMANTIC ERROR: Var %s is NOT in the symbol table\n", (yyvsp[-1].string));
			semanticCheckPassed = 0;

		} 		
		else {
			printf("\nITEM IS IN SYMTABLE\n");
		}

		// Check if types are equal
		if (strcmp(getVariableType((yyvsp[-2].string), currentScope), (yyvsp[0].ast)->nodeType) == 0) {

			printf("TYPES ARE COMPATIBLE\n");

		} else {

			printf("Error: INCOMPATIBLE TYPES\n");
			semanticCheckPassed = 0;

		}


		// ------- SYMBOL TABLE ------- //
		if (semanticCheckPassed) {
			// printNode($3);
			setItemValue((yyvsp[-2].string), (yyvsp[0].ast)->RHS, currentScope);
		}
		

		// ------ AST ------ //
		(yyval.ast) = AST_assignment("=", (yyvsp[-2].string), (yyvsp[0].ast)->RHS);
		// printNode($$);


		// ------ CODE GENERATION ------ //

		if (semanticCheckPassed) {

			char *test = getVariableType((yyvsp[-2].string), currentScope);

 			//¯\_(ツ)_/¯ ¯\_(ツ)_/¯ ¯\_(ツ)_/¯

			// ---- CODE GENERATION ---- //

				// ---- CHAR CODE ---- // 
			if (!strcmp(test, "char")) {

				// ---- IR CODE ---- // 
				emitIRCharDecl((yyvsp[-2].string), (yyvsp[0].ast)->RHS);
				

				// ---- MIPS CODE ---- // 
				if(isNullValue) { //if val isn't null
					setIntVar((yyvsp[-2].string), (yyvsp[0].ast)->RHS);
				} else {
					emitMIPSCharDecl((yyvsp[-2].string), (yyvsp[0].ast)->RHS);
				}

			}

				// ---- INT CODE ---- // 
			else if (!strcmp(test, "int")) {

				// ---- IR CODE ---- //
				emitIntVarIR((yyvsp[-2].string), atoi((yyvsp[0].ast)->RHS));


				// ---- MIPS CODE ---- //
				if(isNullValue) { //if val isn't null
					setIntVar((yyvsp[-2].string), atoi((yyvsp[0].ast)->RHS));
				} else {
					emitIntVar((yyvsp[-2].string), atoi((yyvsp[0].ast)->RHS));
				}
			}

		}

		semanticCheckPassed = 1;
	}
#line 1852 "parser.tab.c"
    break;

  case 42: /* Expr: ID LPAREN ParamList RPAREN  */
#line 747 "parser.y"
                                     {printf("\nRECOGNIZED RULE: Function Call %s\n", (yyvsp[-3].string));}
#line 1858 "parser.tab.c"
    break;

  case 43: /* Primary: ID  */
#line 753 "parser.y"
           {
		(yyval.ast) = AST_assignment("id", "" , (yyvsp[0].string));
	}
#line 1866 "parser.tab.c"
    break;

  case 44: /* Primary: DECIMAL  */
#line 757 "parser.y"
                  {
		printf("float detected: %f\n", (yyvsp[0].floatValue));
		char numVal[10];
		sprintf(numVal, "%f", (yyvsp[0].floatValue));
		(yyval.ast) = AST_assignment("float", "", numVal);
	}
#line 1877 "parser.tab.c"
    break;

  case 45: /* Primary: INTEGER  */
#line 764 "parser.y"
                  {
		// printf("int detected\n");
		char numVal[10];
		sprintf(numVal, "%d", (yyvsp[0].number));
		(yyval.ast) = AST_assignment("int", "", numVal);
	}
#line 1888 "parser.tab.c"
    break;

  case 46: /* Primary: CHARACTER  */
#line 771 "parser.y"
                      {

		(yyval.ast) = AST_assignment("char", "", (yyvsp[0].string));

	}
#line 1898 "parser.tab.c"
    break;

  case 48: /* MathExpr: MathExpr MINUS Trm  */
#line 784 "parser.y"
                             {
		
		char newVal[5];

		// Evaluate expression
		char opArray[3];
		sprintf(opArray, "%s", (yyvsp[-1].string));

		sprintf(newVal, "%d", computeEquation(atoi((yyvsp[-2].ast)->RHS), atoi((yyvsp[0].ast)->RHS), opArray[0]));
		// printf("newVal = %s\n", newVal);

		(yyval.ast) = AST_assignment("int", "", newVal);

	}
#line 1917 "parser.tab.c"
    break;

  case 49: /* MathExpr: MathExpr PLUS Trm  */
#line 799 "parser.y"
                            {
		
		char newVal[5];

		// Evaluate expression
		char opArray[3];
		sprintf(opArray, "%s", (yyvsp[-1].string));

		sprintf(newVal, "%d", computeEquation(atoi((yyvsp[-2].ast)->RHS), atoi((yyvsp[0].ast)->RHS), opArray[0]));
		// printf("newVal = %s\n", newVal);

		(yyval.ast) = AST_assignment("int", "", newVal);

	}
#line 1936 "parser.tab.c"
    break;

  case 50: /* Trm: Factor  */
#line 817 "parser.y"
               {
		char numVal[10];
		if (strcmp((yyvsp[0].ast)->nodeType,"id") == 0) {
			// printf("ID Found!\n");
			sprintf(numVal, "%s", getValue((yyvsp[0].ast)->RHS, currentScope));
			(yyval.ast) = AST_assignment("=", (yyvsp[0].ast)->RHS, atoi(numVal));

			// Set item to used 
			setItemUsed((yyvsp[0].ast)->RHS, currentScope);

		} else {
			//primary is a number, do nothing
			(yyval.ast) = (yyvsp[0].ast);
		}
	}
#line 1956 "parser.tab.c"
    break;

  case 51: /* Trm: Trm TIMES Factor  */
#line 833 "parser.y"
                           {
		
		char newVal[5];

		// Evaluate expression
		char opArray[3];
		sprintf(opArray, "%s", (yyvsp[-1].string));

		sprintf(newVal, "%d", computeEquation(atoi((yyvsp[-2].ast)->RHS), atoi((yyvsp[0].ast)->RHS), opArray[0]));
		// printf("newVal = %s\n", newVal);

		(yyval.ast) = AST_assignment("int", "", newVal);

	}
#line 1975 "parser.tab.c"
    break;

  case 52: /* Trm: Trm DIVIDE Factor  */
#line 848 "parser.y"
                            {
		
		char newVal[5];

		// Evaluate expression
		char opArray[3];
		sprintf(opArray, "%s", (yyvsp[-1].string));

		sprintf(newVal, "%d", computeEquation(atoi((yyvsp[-2].ast)->RHS), atoi((yyvsp[0].ast)->RHS), opArray[0]));
		// printf("newVal = %s\n", newVal);

		(yyval.ast) = AST_assignment("int", "", newVal);

	}
#line 1994 "parser.tab.c"
    break;

  case 53: /* Factor: ID  */
#line 865 "parser.y"
           {
		(yyval.ast) = AST_assignment("id", "" , (yyvsp[0].string));
	}
#line 2002 "parser.tab.c"
    break;

  case 54: /* Factor: INTEGER  */
#line 869 "parser.y"
                  {
		// printf("int detected\n");
		char numVal[10];
		sprintf(numVal, "%d", (yyvsp[0].number));
		(yyval.ast) = AST_assignment("int", "", numVal);
	}
#line 2013 "parser.tab.c"
    break;

  case 55: /* Factor: LPAREN MathExpr RPAREN  */
#line 876 "parser.y"
                                 {
		(yyval.ast) = AST_assignment("int", "", (yyvsp[-1].ast)->RHS);
	}
#line 2021 "parser.tab.c"
    break;

  case 56: /* ParamList: %empty  */
#line 881 "parser.y"
                {}
#line 2027 "parser.tab.c"
    break;

  case 57: /* $@2: %empty  */
#line 882 "parser.y"
                  {printf("\nRECOGNIZED RULE: Parameter\n");}
#line 2033 "parser.tab.c"
    break;

  case 58: /* ParamList: Primary $@2 ParamList  */
#line 882 "parser.y"
                                                                        {}
#line 2039 "parser.tab.c"
    break;

  case 59: /* UnaryOp: MINUS  */
#line 890 "parser.y"
               {printf("\nRECOGNIZED RULE: Unary Operation, NEGATIVE VALUE %s\n", (yyvsp[0].string));}
#line 2045 "parser.tab.c"
    break;


#line 2049 "parser.tab.c"

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

#line 898 "parser.y"


int evalCondition(struct AST* x, struct AST* y, char logOp[5]) {
	int val1; int val2;
	if (x->nodeType == "id") {

	}
	val1 = atoi(x->RHS);
	val2 = atoi(y->RHS);

	if (!strcmp(logOp, "==")) {
		if (!strcmp(x, y)) {
			return 1;
		}
	} 
	else if (!strcmp(logOp, "!=")) {
		if (strcmp(x, y)) {
			return 1;
		}
	}
	else if (!strcmp(logOp, "<=")) {
		if (val1 <= val2) {
			return 1;
		}
	}
	else if (!strcmp(logOp, ">=")) {
		if (val1 >= val2) {
			return 1;
		}
	}
	else if (!strcmp(logOp, "<")) {
		if (val1 < val2) {
			return 1;
		}
	}
	else if (!strcmp(logOp, ">")) {
		if (val1 > val2) {
			return 1;
		}
	}

	return 0;
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

	/* printf("Newval = %d\n", newVal); */
	return newVal;

}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}

int main(int argc, char**argv)
{
/* 
	#ifdef YYDEBUG
		yydebug = 1;
	#endif */

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

	emitEndOfAssemblyCode();
	emitEndOfAssemblyCodeIR();

	// Merge data and main sections in MIPS
	/* addMainToData(); */
	appendFiles();

	addMainToDataIR();

	showSymTable();
	printf("\n\n##### COMPILER ENDED #####\n\n");


	/* fprintf (GarbageMIPS, "syscall\n"); */
}
