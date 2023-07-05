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
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "print_assembly.h"

extern int yylineno;
extern char *yytext;

int yylex();
void yyerror(char *);

ENTRY *entry;
N_PROG* ast;


ENTRY *append_entry(ENTRY *list1, ENTRY *list2) {
  ENTRY *it = list1;
  if(list1 == 0) return list2;
  while(it->next != 0) it = it->next;
  it->next = list2;
  return list1;
}


N_STMT *append_stmt(N_STMT *list, N_STMT *elem) {
  N_STMT *it = list;
  if(list == 0) return elem;
  while(it->next != 0) it = it->next;
  it->next = elem;
  elem->next = 0;
  return list;
}


N_EXPR *append_expr(N_EXPR *list, N_EXPR *elem) {
  N_EXPR *it = list;
  if(list == 0) return elem;
  while(it->next != 0) it = it->next;
  it->next = elem;
  elem->next = 0;
  return list;
}


#line 117 "parser.tab.c"

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
  YYSYMBOL_PROG = 3,                       /* PROG  */
  YYSYMBOL_VAR = 4,                        /* VAR  */
  YYSYMBOL_ARRAY = 5,                      /* ARRAY  */
  YYSYMBOL_TO = 6,                         /* TO  */
  YYSYMBOL_OF = 7,                         /* OF  */
  YYSYMBOL_FUNC = 8,                       /* FUNC  */
  YYSYMBOL_PROC = 9,                       /* PROC  */
  YYSYMBOL_INT = 10,                       /* INT  */
  YYSYMBOL_REAL = 11,                      /* REAL  */
  YYSYMBOL_BOOL = 12,                      /* BOOL  */
  YYSYMBOL_START = 13,                     /* START  */
  YYSYMBOL_END = 14,                       /* END  */
  YYSYMBOL_IF = 15,                        /* IF  */
  YYSYMBOL_THEN = 16,                      /* THEN  */
  YYSYMBOL_ELSE = 17,                      /* ELSE  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_DO = 19,                        /* DO  */
  YYSYMBOL_IDENT = 20,                     /* IDENT  */
  YYSYMBOL_NUM = 21,                       /* NUM  */
  YYSYMBOL_COLON = 22,                     /* COLON  */
  YYSYMBOL_SCOLON = 23,                    /* SCOLON  */
  YYSYMBOL_COMMA = 24,                     /* COMMA  */
  YYSYMBOL_DOT = 25,                       /* DOT  */
  YYSYMBOL_LBRA = 26,                      /* LBRA  */
  YYSYMBOL_RBRA = 27,                      /* RBRA  */
  YYSYMBOL_LPAR = 28,                      /* LPAR  */
  YYSYMBOL_RPAR = 29,                      /* RPAR  */
  YYSYMBOL_ASSIGN = 30,                    /* ASSIGN  */
  YYSYMBOL_LT = 31,                        /* LT  */
  YYSYMBOL_LE = 32,                        /* LE  */
  YYSYMBOL_GT = 33,                        /* GT  */
  YYSYMBOL_GE = 34,                        /* GE  */
  YYSYMBOL_EQ = 35,                        /* EQ  */
  YYSYMBOL_NE = 36,                        /* NE  */
  YYSYMBOL_PLUS = 37,                      /* PLUS  */
  YYSYMBOL_MINUS = 38,                     /* MINUS  */
  YYSYMBOL_TIMES = 39,                     /* TIMES  */
  YYSYMBOL_SLASH = 40,                     /* SLASH  */
  YYSYMBOL_DIV = 41,                       /* DIV  */
  YYSYMBOL_MOD = 42,                       /* MOD  */
  YYSYMBOL_NOT = 43,                       /* NOT  */
  YYSYMBOL_AND = 44,                       /* AND  */
  YYSYMBOL_OR = 45,                        /* OR  */
  YYSYMBOL_TRUE = 46,                      /* TRUE  */
  YYSYMBOL_FALSE = 47,                     /* FALSE  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_program = 49,                   /* program  */
  YYSYMBOL_varDec = 50,                    /* varDec  */
  YYSYMBOL_varDecList = 51,                /* varDecList  */
  YYSYMBOL_identListType = 52,             /* identListType  */
  YYSYMBOL_identList = 53,                 /* identList  */
  YYSYMBOL_type = 54,                      /* type  */
  YYSYMBOL_simpleType = 55,                /* simpleType  */
  YYSYMBOL_subProgList = 56,               /* subProgList  */
  YYSYMBOL_subProgHead = 57,               /* subProgHead  */
  YYSYMBOL_args = 58,                      /* args  */
  YYSYMBOL_parList = 59,                   /* parList  */
  YYSYMBOL_compStmt = 60,                  /* compStmt  */
  YYSYMBOL_stmtList = 61,                  /* stmtList  */
  YYSYMBOL_stmt = 62,                      /* stmt  */
  YYSYMBOL_subProgCall = 63,               /* subProgCall  */
  YYSYMBOL_params = 64,                    /* params  */
  YYSYMBOL_assStmt = 65,                   /* assStmt  */
  YYSYMBOL_index = 66,                     /* index  */
  YYSYMBOL_ifStmt = 67,                    /* ifStmt  */
  YYSYMBOL_elsePart = 68,                  /* elsePart  */
  YYSYMBOL_whileStmt = 69,                 /* whileStmt  */
  YYSYMBOL_exprList = 70,                  /* exprList  */
  YYSYMBOL_expr = 71,                      /* expr  */
  YYSYMBOL_simpleExpr = 72,                /* simpleExpr  */
  YYSYMBOL_term = 73,                      /* term  */
  YYSYMBOL_factor = 74,                    /* factor  */
  YYSYMBOL_relOp = 75,                     /* relOp  */
  YYSYMBOL_addOp = 76,                     /* addOp  */
  YYSYMBOL_mulOp = 77                      /* mulOp  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   112

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  131

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    92,    92,   102,   105,   107,   108,   111,   123,   127,
     133,   137,   145,   146,   147,   150,   156,   159,   167,   177,
     178,   181,   182,   185,   188,   189,   194,   198,   202,   203,
     207,   213,   217,   223,   226,   232,   240,   241,   247,   254,
     255,   258,   264,   265,   270,   276,   279,   285,   288,   294,
     297,   302,   307,   312,   318,   324,   330,   335,   340,   346,
     348,   350,   352,   354,   356,   359,   361,   363,   366,   368,
     370,   372,   374
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
  "\"end of file\"", "error", "\"invalid token\"", "PROG", "VAR", "ARRAY",
  "TO", "OF", "FUNC", "PROC", "INT", "REAL", "BOOL", "START", "END", "IF",
  "THEN", "ELSE", "WHILE", "DO", "IDENT", "NUM", "COLON", "SCOLON",
  "COMMA", "DOT", "LBRA", "RBRA", "LPAR", "RPAR", "ASSIGN", "LT", "LE",
  "GT", "GE", "EQ", "NE", "PLUS", "MINUS", "TIMES", "SLASH", "DIV", "MOD",
  "NOT", "AND", "OR", "TRUE", "FALSE", "$accept", "program", "varDec",
  "varDecList", "identListType", "identList", "type", "simpleType",
  "subProgList", "subProgHead", "args", "parList", "compStmt", "stmtList",
  "stmt", "subProgCall", "params", "assStmt", "index", "ifStmt",
  "elsePart", "whileStmt", "exprList", "expr", "simpleExpr", "term",
  "factor", "relOp", "addOp", "mulOp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       6,   -10,    40,    11,   -65,    33,    23,   -65,   -65,    23,
      45,    57,    12,    51,   -65,    34,    36,    60,    63,    46,
      33,    32,   -65,    59,   -65,   -65,   -65,   -65,   -65,   -65,
      58,    58,    -5,    -5,    37,   -65,    -6,   -65,   -65,   -65,
     -65,   -65,    47,   -65,    67,    23,    65,    68,    -4,   -65,
      -5,    -5,    -5,   -65,   -65,    73,    17,    31,   -65,    71,
      -5,    -5,    -5,   -65,    62,   -65,    46,    70,    88,   -65,
     -16,    34,   -65,   -65,   -65,    69,   -65,   -65,    46,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,    -5,    -5,
     -65,   -65,   -65,   -65,   -65,    -5,    46,     0,     2,   -65,
     -65,    -5,   -65,   -65,    74,    23,   -65,    76,   -65,    80,
     -26,    31,   -65,   -65,    -5,   -65,    -5,   -65,   -65,    75,
     -65,   -65,    46,   -65,    77,   -65,    93,   -65,   -65,    66,
     -65
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,    16,     9,     3,
       0,     0,     0,     0,     6,     0,     0,     0,     0,     0,
       4,     0,     5,     0,    12,    13,    14,     7,    10,     8,
      20,    20,     0,     0,    31,    28,     0,    25,    26,    27,
      29,    30,     0,     2,     0,     0,     0,     0,    53,    50,
       0,     0,     0,    52,    51,     0,    45,    47,    49,     0,
       0,     0,     0,    32,     0,    23,     0,     0,     0,    22,
       0,     0,    18,    55,    54,     0,    57,    56,     0,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,     0,
      68,    69,    70,    71,    72,     0,     0,     0,     0,    43,
      34,     0,    24,    15,     0,     0,    19,     0,    58,    40,
      44,    46,    48,    41,     0,    36,     0,    33,    35,     0,
      21,    17,     0,    38,     0,    42,     0,    39,    37,     0,
      11
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,    81,   -65,    -9,   -65,    35,   -24,   -65,   -65,
      72,   -65,    -7,   -65,   -64,   -65,    61,   -65,    64,   -65,
     -65,   -65,   -65,   -32,    19,    21,   -48,   -65,   -65,   -65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     7,     9,    10,    11,    27,    28,    12,    20,
      46,    70,    35,    36,    37,    38,    63,    39,    64,    40,
     123,    41,    98,    55,    56,    57,    58,    88,    89,    95
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      13,    59,   102,    76,    77,    21,   114,   105,    65,     1,
       3,    85,    86,   106,   109,    48,    49,    66,    75,    87,
      17,    18,    60,    50,    61,    19,   116,   115,    97,    99,
     100,   117,   113,    51,     5,    67,    69,     6,    52,    23,
       4,    53,    54,     8,    24,    25,    26,   112,    79,    80,
      81,    82,    83,    84,    85,    86,    29,    43,   127,    19,
      19,    32,    87,    60,    33,    61,    34,    62,    14,   118,
      90,    91,    92,    93,    22,    94,    24,    25,    26,    15,
      30,    16,   124,    31,   125,    44,    45,    71,    68,    78,
      96,    72,   101,   103,   104,   119,   120,   122,   108,   121,
     129,    42,   126,    47,   128,   130,   107,   110,     0,    73,
     111,     0,    74
};

static const yytype_int16 yycheck[] =
{
       9,    33,    66,    51,    52,    12,     6,    23,    14,     3,
      20,    37,    38,    29,    78,    20,    21,    23,    50,    45,
       8,     9,    26,    28,    28,    13,    24,    27,    60,    61,
      62,    29,    96,    38,    23,    42,    45,     4,    43,     5,
       0,    46,    47,    20,    10,    11,    12,    95,    31,    32,
      33,    34,    35,    36,    37,    38,    20,    25,   122,    13,
      13,    15,    45,    26,    18,    28,    20,    30,    23,   101,
      39,    40,    41,    42,    23,    44,    10,    11,    12,    22,
      20,    24,   114,    20,   116,    26,    28,    22,    21,    16,
      19,    23,    30,    23,     6,    21,   105,    17,    29,    23,
       7,    20,    27,    31,    27,   129,    71,    88,    -1,    48,
      89,    -1,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    49,    20,     0,    23,     4,    50,    20,    51,
      52,    53,    56,    52,    23,    22,    24,     8,     9,    13,
      57,    60,    23,     5,    10,    11,    12,    54,    55,    20,
      20,    20,    15,    18,    20,    60,    61,    62,    63,    65,
      67,    69,    50,    25,    26,    28,    58,    58,    20,    21,
      28,    38,    43,    46,    47,    71,    72,    73,    74,    71,
      26,    28,    30,    64,    66,    14,    23,    60,    21,    52,
      59,    22,    23,    64,    66,    71,    74,    74,    16,    31,
      32,    33,    34,    35,    36,    37,    38,    45,    75,    76,
      39,    40,    41,    42,    44,    77,    19,    71,    70,    71,
      71,    30,    62,    23,     6,    23,    29,    54,    29,    62,
      72,    73,    74,    62,     6,    27,    24,    29,    71,    21,
      52,    23,    17,    68,    71,    71,    27,    62,    27,     7,
      55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    52,    53,    53,
      54,    54,    55,    55,    55,    56,    56,    57,    57,    58,
      58,    59,    59,    60,    61,    61,    62,    62,    62,    62,
      62,    63,    63,    64,    65,    65,    66,    66,    67,    68,
      68,    69,    70,    70,    71,    71,    72,    72,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    75,
      75,    75,    75,    75,    75,    76,    76,    76,    77,    77,
      77,    77,    77
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     2,     0,     3,     2,     3,     3,     1,
       1,     8,     1,     1,     1,     5,     0,     6,     4,     3,
       0,     3,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     3,     4,     3,     5,     5,     2,
       0,     4,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
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
  YY_USE (yykind);
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
  case 2: /* program: PROG IDENT SCOLON varDec subProgList compStmt DOT  */
#line 92 "parser.y"
                                                                { ast->symtab = (ENTRY *) malloc(sizeof(ENTRY));
								  ast->symtab->data_type = _VOID;
								  ast->symtab->base.id = (yyvsp[-5].string);
								  ast->symtab->ext.prog.par_list = 0;
								  ast->symtab->next = (yyvsp[-3].symtab);
								  ast->stmt = (yyvsp[-1].stmt);
								  ast->next = (yyvsp[-2].prog);
								}
#line 1274 "parser.tab.c"
    break;

  case 3: /* varDec: VAR varDecList  */
#line 102 "parser.y"
                                                                { (yyval.symtab) = (yyvsp[0].symtab);
								assignSymTable((yyvsp[0].symtab));
 								}
#line 1282 "parser.tab.c"
    break;

  case 4: /* varDec: %empty  */
#line 105 "parser.y"
                                                                { (yyval.symtab) = 0; }
#line 1288 "parser.tab.c"
    break;

  case 5: /* varDecList: varDecList identListType SCOLON  */
#line 107 "parser.y"
                                                                { append_entry((yyvsp[-2].symtab), (yyvsp[-1].symtab)); }
#line 1294 "parser.tab.c"
    break;

  case 6: /* varDecList: identListType SCOLON  */
#line 108 "parser.y"
                                                                { (yyval.symtab) = (yyvsp[-1].symtab); }
#line 1300 "parser.tab.c"
    break;

  case 7: /* identListType: identList COLON type  */
#line 111 "parser.y"
                                                                { for(entry = (yyvsp[-2].symtab); entry != 0; entry = entry->next) {
								    entry->typ = (yyvsp[0].symtab)->typ;
								    entry->data_type = (yyvsp[0].symtab)->data_type;
								    if((yyvsp[0].symtab)->typ == _ARRAY) {
								      entry->ext.bounds.low = (yyvsp[0].symtab)->ext.bounds.low;
								      entry->ext.bounds.upp = (yyvsp[0].symtab)->ext.bounds.upp;
								    }
								  }
								  (yyval.symtab) = (yyvsp[-2].symtab);
								}
#line 1315 "parser.tab.c"
    break;

  case 8: /* identList: identList COMMA IDENT  */
#line 123 "parser.y"
                                                                { (yyval.symtab) = (ENTRY *) malloc(sizeof(ENTRY));
								  (yyval.symtab)->base.id = (yyvsp[0].string);
								  (yyval.symtab)->next = (yyvsp[-2].symtab);
								}
#line 1324 "parser.tab.c"
    break;

  case 9: /* identList: IDENT  */
#line 127 "parser.y"
                                                                { (yyval.symtab) = (ENTRY *) malloc(sizeof(ENTRY));
								  (yyval.symtab)->base.id = (yyvsp[0].string);
								  (yyval.symtab)->next = 0;
								}
#line 1333 "parser.tab.c"
    break;

  case 10: /* type: simpleType  */
#line 133 "parser.y"
                                                                { (yyval.symtab) = (ENTRY *) malloc(sizeof(ENTRY));
								  (yyval.symtab)->typ = _VAR;
								  (yyval.symtab)->data_type = (yyvsp[0].integer);
								}
#line 1342 "parser.tab.c"
    break;

  case 11: /* type: ARRAY LBRA NUM TO NUM RBRA OF simpleType  */
#line 137 "parser.y"
                                                                { (yyval.symtab) = (ENTRY *) malloc(sizeof(ENTRY));
								  (yyval.symtab)->typ = _ARRAY;
								  (yyval.symtab)->data_type = (yyvsp[0].integer);
								  (yyval.symtab)->ext.bounds.low = (int) (yyvsp[-5].number);
								  (yyval.symtab)->ext.bounds.upp = (int) (yyvsp[-3].number);
								}
#line 1353 "parser.tab.c"
    break;

  case 12: /* simpleType: INT  */
#line 145 "parser.y"
                                                                { (yyval.integer) = _INT; }
#line 1359 "parser.tab.c"
    break;

  case 13: /* simpleType: REAL  */
#line 146 "parser.y"
                                                                { (yyval.integer) = _REAL; }
#line 1365 "parser.tab.c"
    break;

  case 14: /* simpleType: BOOL  */
#line 147 "parser.y"
                                                                { (yyval.integer) = _BOOL; }
#line 1371 "parser.tab.c"
    break;

  case 15: /* subProgList: subProgList subProgHead varDec compStmt SCOLON  */
#line 150 "parser.y"
                                                                { (yyval.prog) = (N_PROG *) malloc(sizeof(N_PROG));
								  (yyval.prog)->symtab = (yyvsp[-3].symtab);
								  (yyvsp[-3].symtab)->next = (yyvsp[-2].symtab);
								  (yyval.prog)->stmt = (yyvsp[-1].stmt);
								  (yyval.prog)->next = (yyvsp[-4].prog);
								}
#line 1382 "parser.tab.c"
    break;

  case 16: /* subProgList: %empty  */
#line 156 "parser.y"
                                                                { (yyval.prog) = 0; }
#line 1388 "parser.tab.c"
    break;

  case 17: /* subProgHead: FUNC IDENT args COLON type SCOLON  */
#line 159 "parser.y"
                                                                { (yyval.symtab) = (ENTRY *) malloc(sizeof(ENTRY));
								  (yyval.symtab)->typ = _PROG;
								  (yyval.symtab)->data_type = (yyvsp[-1].symtab)->data_type;
								  (yyval.symtab)->base.id = (yyvsp[-4].string);
								  (yyval.symtab)->ext.prog.par_list = (yyvsp[-3].symtab);
								  (yyval.symtab)->next = ast->symtab;
								  ast->symtab = (yyval.symtab);
								}
#line 1401 "parser.tab.c"
    break;

  case 18: /* subProgHead: PROC IDENT args SCOLON  */
#line 167 "parser.y"
                                                                { (yyval.symtab) = (ENTRY *) malloc(sizeof(ENTRY));
								  (yyval.symtab)->typ = _PROG;
								  (yyval.symtab)->data_type = _VOID;
								  (yyval.symtab)->base.id = (yyvsp[-2].string);
								  (yyval.symtab)->ext.prog.par_list = (yyvsp[-1].symtab);
								  (yyval.symtab)->next = ast->symtab;
								  ast->symtab = (yyval.symtab);
								}
#line 1414 "parser.tab.c"
    break;

  case 19: /* args: LPAR parList RPAR  */
#line 177 "parser.y"
                                                                { (yyval.symtab) = (yyvsp[-1].symtab); }
#line 1420 "parser.tab.c"
    break;

  case 20: /* args: %empty  */
#line 178 "parser.y"
                                                                { (yyval.symtab) = 0; }
#line 1426 "parser.tab.c"
    break;

  case 21: /* parList: parList SCOLON identListType  */
#line 181 "parser.y"
                                                                { (yyval.symtab) = append_entry((yyvsp[-2].symtab), (yyvsp[0].symtab)); }
#line 1432 "parser.tab.c"
    break;

  case 22: /* parList: identListType  */
#line 182 "parser.y"
                                                                { (yyval.symtab) = (yyvsp[0].symtab); }
#line 1438 "parser.tab.c"
    break;

  case 23: /* compStmt: START stmtList END  */
#line 185 "parser.y"
                                                { (yyval.stmt) = (yyvsp[-1].stmt); }
#line 1444 "parser.tab.c"
    break;

  case 24: /* stmtList: stmtList SCOLON stmt  */
#line 188 "parser.y"
                                                { (yyval.stmt) = append_stmt((yyvsp[-2].stmt), (yyvsp[0].stmt)); }
#line 1450 "parser.tab.c"
    break;

  case 25: /* stmtList: stmt  */
#line 189 "parser.y"
                                                { (yyvsp[0].stmt)->next = 0;
						  (yyval.stmt) = (yyvsp[0].stmt);
						}
#line 1458 "parser.tab.c"
    break;

  case 26: /* stmt: subProgCall  */
#line 194 "parser.y"
                                                { (yyval.stmt) =(N_STMT *) malloc(sizeof(N_STMT));
						  (yyval.stmt)->typ = _PROC_CALL;
						  (yyval.stmt)->node.proc_call = (yyvsp[0].call_stmt);
						}
#line 1467 "parser.tab.c"
    break;

  case 27: /* stmt: assStmt  */
#line 198 "parser.y"
                                                { (yyval.stmt) = (N_STMT *) malloc(sizeof(N_STMT));
						  (yyval.stmt)->typ = _ASSIGN;
						  (yyval.stmt)->node.assign_stmt = (yyvsp[0].assign_stmt);
						}
#line 1476 "parser.tab.c"
    break;

  case 28: /* stmt: compStmt  */
#line 202 "parser.y"
                                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1482 "parser.tab.c"
    break;

  case 29: /* stmt: ifStmt  */
#line 203 "parser.y"
                                                { (yyval.stmt) = (N_STMT *) malloc(sizeof(N_STMT));
						  (yyval.stmt)->typ = _IF;
						  (yyval.stmt)->node.if_stmt = (yyvsp[0].if_stmt);
						}
#line 1491 "parser.tab.c"
    break;

  case 30: /* stmt: whileStmt  */
#line 207 "parser.y"
                                                { (yyval.stmt) = (N_STMT *) malloc(sizeof(N_STMT));
						  (yyval.stmt)->typ = _WHILE;
						  (yyval.stmt)->node.while_stmt = (yyvsp[0].while_stmt);
						}
#line 1500 "parser.tab.c"
    break;

  case 31: /* subProgCall: IDENT  */
#line 213 "parser.y"
                                                { (yyval.call_stmt) = (N_CALL *) malloc(sizeof(N_CALL *));
						  (yyval.call_stmt)->id = (yyvsp[0].string);
						  (yyval.call_stmt)->par_list = 0;
						}
#line 1509 "parser.tab.c"
    break;

  case 32: /* subProgCall: IDENT params  */
#line 217 "parser.y"
                                                { (yyval.call_stmt) = (N_CALL *) malloc(sizeof(N_CALL *));
						  (yyval.call_stmt)->id = (yyvsp[-1].string);
						  (yyval.call_stmt)->par_list = (yyvsp[0].exp);
						}
#line 1518 "parser.tab.c"
    break;

  case 33: /* params: LPAR exprList RPAR  */
#line 223 "parser.y"
                                                { (yyval.exp) = (yyvsp[-1].exp); }
#line 1524 "parser.tab.c"
    break;

  case 34: /* assStmt: IDENT ASSIGN expr  */
#line 226 "parser.y"
                                                { (yyval.assign_stmt) = (N_ASSIGN *) malloc(sizeof(N_ASSIGN));
						  (yyval.assign_stmt)->var_ref = (N_VAR_REF *) malloc(sizeof(N_VAR_REF));
						  (yyval.assign_stmt)->var_ref->id = (yyvsp[-2].string);
						  (yyval.assign_stmt)->var_ref->index = 0;
						  (yyval.assign_stmt)->rhs_expr = (yyvsp[0].exp);
						}
#line 1535 "parser.tab.c"
    break;

  case 35: /* assStmt: IDENT index ASSIGN expr  */
#line 232 "parser.y"
                                                { (yyval.assign_stmt) = (N_ASSIGN *) malloc(sizeof(N_ASSIGN));
						  (yyval.assign_stmt)->var_ref = (N_VAR_REF *) malloc(sizeof(N_VAR_REF));
						  (yyval.assign_stmt)->var_ref->id = (yyvsp[-3].string);
						  (yyval.assign_stmt)->var_ref->index = (yyvsp[-2].exp);
						  (yyval.assign_stmt)->rhs_expr = (yyvsp[0].exp);
						}
#line 1546 "parser.tab.c"
    break;

  case 36: /* index: LBRA expr RBRA  */
#line 240 "parser.y"
                                                { (yyval.exp) = (yyvsp[-1].exp); }
#line 1552 "parser.tab.c"
    break;

  case 37: /* index: LBRA expr TO expr RBRA  */
#line 241 "parser.y"
                                                { (yyvsp[-3].exp)->next = (yyvsp[-1].exp);
						  (yyvsp[-1].exp)->next = 0;
						  (yyval.exp) = (yyvsp[-3].exp);
						}
#line 1561 "parser.tab.c"
    break;

  case 38: /* ifStmt: IF expr THEN stmt elsePart  */
#line 247 "parser.y"
                                        { (yyval.if_stmt) = (N_IF *) malloc(sizeof(N_IF));
					  (yyval.if_stmt)->expr = (yyvsp[-3].exp);
					  (yyval.if_stmt)->then_part = (yyvsp[-1].stmt);
					  (yyval.if_stmt)->else_part = (yyvsp[0].stmt);
					}
#line 1571 "parser.tab.c"
    break;

  case 39: /* elsePart: ELSE stmt  */
#line 254 "parser.y"
                                        { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1577 "parser.tab.c"
    break;

  case 40: /* elsePart: %empty  */
#line 255 "parser.y"
                                        { (yyval.stmt) = 0; }
#line 1583 "parser.tab.c"
    break;

  case 41: /* whileStmt: WHILE expr DO stmt  */
#line 258 "parser.y"
                                        { (yyval.while_stmt) = (N_WHILE *) malloc(sizeof(N_WHILE));
					  (yyval.while_stmt)->expr = (yyvsp[-2].exp);
					  (yyval.while_stmt)->stmt = (yyvsp[0].stmt);
					}
#line 1592 "parser.tab.c"
    break;

  case 42: /* exprList: exprList COMMA expr  */
#line 264 "parser.y"
                                        { (yyval.exp) = append_expr((yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1598 "parser.tab.c"
    break;

  case 43: /* exprList: expr  */
#line 265 "parser.y"
                                        { (yyvsp[0].exp)->next = 0;
                                          (yyval.exp) = (yyvsp[0].exp);
					}
#line 1606 "parser.tab.c"
    break;

  case 44: /* expr: simpleExpr relOp simpleExpr  */
#line 270 "parser.y"
                                        { (yyval.exp) = (N_EXPR *) malloc(sizeof(N_EXPR));
					  (yyval.exp)->typ = OP;
					  (yyval.exp)->desc.operation.op = (yyvsp[-1].integer);
					  (yyval.exp)->desc.operation.expr = (yyvsp[-2].exp);
					  (yyval.exp)->desc.operation.expr->next = (yyvsp[0].exp);
					}
#line 1617 "parser.tab.c"
    break;

  case 45: /* expr: simpleExpr  */
#line 276 "parser.y"
                                        { (yyval.exp) = (yyvsp[0].exp); }
#line 1623 "parser.tab.c"
    break;

  case 46: /* simpleExpr: simpleExpr addOp term  */
#line 279 "parser.y"
                                        { (yyval.exp) = (N_EXPR *) malloc(sizeof(N_EXPR));
					  (yyval.exp)->typ = OP;
					  (yyval.exp)->desc.operation.op = (yyvsp[-1].integer);
					  (yyval.exp)->desc.operation.expr = (yyvsp[-2].exp);
					  (yyval.exp)->desc.operation.expr->next = (yyvsp[0].exp);
					}
#line 1634 "parser.tab.c"
    break;

  case 47: /* simpleExpr: term  */
#line 285 "parser.y"
                                        { (yyval.exp) = (yyvsp[0].exp); }
#line 1640 "parser.tab.c"
    break;

  case 48: /* term: term mulOp factor  */
#line 288 "parser.y"
                                        { (yyval.exp) = (N_EXPR *) malloc(sizeof(N_EXPR));
					  (yyval.exp)->typ = OP;
					  (yyval.exp)->desc.operation.op = (yyvsp[-1].integer);
					  (yyval.exp)->desc.operation.expr = (yyvsp[-2].exp);
					  (yyval.exp)->desc.operation.expr->next = (yyvsp[0].exp);
					}
#line 1651 "parser.tab.c"
    break;

  case 49: /* term: factor  */
#line 294 "parser.y"
                                        { (yyval.exp) = (yyvsp[0].exp); }
#line 1657 "parser.tab.c"
    break;

  case 50: /* factor: NUM  */
#line 297 "parser.y"
                                        { (yyval.exp) = (N_EXPR *) malloc(sizeof(N_EXPR));
	                                  (yyval.exp)->typ = CONSTANT;
					  (yyval.exp)->desc.constant = (char *) malloc(100); /* ugly */
					  sprintf((yyval.exp)->desc.constant, "%f", (yyvsp[0].number));
					}
#line 1667 "parser.tab.c"
    break;

  case 51: /* factor: FALSE  */
#line 302 "parser.y"
                                        { (yyval.exp) = (N_EXPR *) malloc(sizeof(N_EXPR));
					  (yyval.exp)->typ = CONSTANT;
					  (yyval.exp)->desc.constant = (char *) malloc(6 * sizeof(char));
					  strcpy((yyval.exp)->desc.constant, "FALSE");
					}
#line 1677 "parser.tab.c"
    break;

  case 52: /* factor: TRUE  */
#line 307 "parser.y"
                                        { (yyval.exp) = (N_EXPR *) malloc(sizeof(N_EXPR));
					  (yyval.exp)->typ = CONSTANT;
					  (yyval.exp)->desc.constant = (char *) malloc(5 * sizeof(char));
					  strcpy((yyval.exp)->desc.constant, "TRUE");
					}
#line 1687 "parser.tab.c"
    break;

  case 53: /* factor: IDENT  */
#line 312 "parser.y"
                                        { (yyval.exp) = (N_EXPR *) malloc(sizeof(N_EXPR));
					  (yyval.exp)->typ = VAR_REF;
					  (yyval.exp)->desc.var_ref = (N_VAR_REF *) malloc(sizeof(N_VAR_REF));
					  (yyval.exp)->desc.var_ref->id = (yyvsp[0].string);
					  (yyval.exp)->desc.var_ref->index = 0;
					}
#line 1698 "parser.tab.c"
    break;

  case 54: /* factor: IDENT index  */
#line 318 "parser.y"
                                        { (yyval.exp) = (N_EXPR *) malloc(sizeof(N_EXPR));
					  (yyval.exp)->typ = VAR_REF;
					  (yyval.exp)->desc.var_ref = (N_VAR_REF *) malloc(sizeof(N_VAR_REF));
					  (yyval.exp)->desc.var_ref->id = (yyvsp[-1].string);
                                          (yyval.exp)->desc.var_ref->index = (yyvsp[0].exp);
					}
#line 1709 "parser.tab.c"
    break;

  case 55: /* factor: IDENT params  */
#line 324 "parser.y"
                                        { (yyval.exp) = (N_EXPR *) malloc(sizeof(N_EXPR));
					  (yyval.exp)->typ = FUNC_CALL;
					  (yyval.exp)->desc.func_call = (N_CALL *) malloc(sizeof(N_CALL));
					  (yyval.exp)->desc.func_call->id = (yyvsp[-1].string);
                                          (yyval.exp)->desc.func_call->par_list = (yyvsp[0].exp);
					}
#line 1720 "parser.tab.c"
    break;

  case 56: /* factor: NOT factor  */
#line 330 "parser.y"
                                        { (yyval.exp) = (N_EXPR *) malloc(sizeof(N_EXPR));
					  (yyval.exp)->typ = OP;
					  (yyval.exp)->desc.operation.op = NOT_OP;
					  (yyval.exp)->desc.operation.expr = (yyvsp[0].exp);
					}
#line 1730 "parser.tab.c"
    break;

  case 57: /* factor: MINUS factor  */
#line 335 "parser.y"
                                        { (yyval.exp) = (N_EXPR *) malloc(sizeof(N_EXPR));
					  (yyval.exp)->typ = OP;
					  (yyval.exp)->desc.operation.op = MINUS_OP;
					  (yyval.exp)->desc.operation.expr = (yyvsp[0].exp);
					}
#line 1740 "parser.tab.c"
    break;

  case 58: /* factor: LPAR expr RPAR  */
#line 340 "parser.y"
                                        { (yyval.exp) = (N_EXPR *) malloc(sizeof(N_EXPR));
					  (yyval.exp)->typ = OP;
					  (yyval.exp)->desc.operation.expr = (yyvsp[-1].exp);
					}
#line 1749 "parser.tab.c"
    break;

  case 59: /* relOp: LT  */
#line 346 "parser.y"
                                        { (yyval.integer) = LT_OP; }
#line 1755 "parser.tab.c"
    break;

  case 60: /* relOp: LE  */
#line 348 "parser.y"
                                        { (yyval.integer) = LE_OP; }
#line 1761 "parser.tab.c"
    break;

  case 61: /* relOp: GT  */
#line 350 "parser.y"
                                        { (yyval.integer) = GT_OP; }
#line 1767 "parser.tab.c"
    break;

  case 62: /* relOp: GE  */
#line 352 "parser.y"
                                        { (yyval.integer) = GE_OP; }
#line 1773 "parser.tab.c"
    break;

  case 63: /* relOp: EQ  */
#line 354 "parser.y"
                                        { (yyval.integer) = EQ_OP; }
#line 1779 "parser.tab.c"
    break;

  case 64: /* relOp: NE  */
#line 356 "parser.y"
                                        { (yyval.integer) = NE_OP; }
#line 1785 "parser.tab.c"
    break;

  case 65: /* addOp: PLUS  */
#line 359 "parser.y"
                                        { (yyval.integer) = PLUS_OP; }
#line 1791 "parser.tab.c"
    break;

  case 66: /* addOp: MINUS  */
#line 361 "parser.y"
                                        { (yyval.integer) = MINUS_OP; }
#line 1797 "parser.tab.c"
    break;

  case 67: /* addOp: OR  */
#line 363 "parser.y"
                                        { (yyval.integer) = OR_OP; }
#line 1803 "parser.tab.c"
    break;

  case 68: /* mulOp: TIMES  */
#line 366 "parser.y"
                                        { (yyval.integer) = MULT_OP; }
#line 1809 "parser.tab.c"
    break;

  case 69: /* mulOp: SLASH  */
#line 368 "parser.y"
                                        { (yyval.integer) = SLASH_OP; }
#line 1815 "parser.tab.c"
    break;

  case 70: /* mulOp: DIV  */
#line 370 "parser.y"
                                        { (yyval.integer) = DIV_OP; }
#line 1821 "parser.tab.c"
    break;

  case 71: /* mulOp: MOD  */
#line 372 "parser.y"
                                        { (yyval.integer) = MOD_OP; }
#line 1827 "parser.tab.c"
    break;

  case 72: /* mulOp: AND  */
#line 374 "parser.y"
                                        { (yyval.integer) = AND_OP; }
#line 1833 "parser.tab.c"
    break;


#line 1837 "parser.tab.c"

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

#line 377 "parser.y"

        
void main() {
  ast = (N_PROG *) malloc(sizeof(N_PROG));
  yyparse();
  print_prog(ast);
}

void yyerror(char *s) {
  printf("\%s in line %d: %s\n", s, yylineno, yytext);
  exit(1);
}

