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
#line 1 "lalr.y"

#include <stdio.h>
#include "ast.h"

void yyerror(char *s);
int yylex();
extern int yylineno;
N_PROG *ast;


#line 82 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
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
    AND = 258,                     /* AND  */
    ARRAY = 259,                   /* ARRAY  */
    BEG = 260,                     /* BEG  */
    DIV = 261,                     /* DIV  */
    DO = 262,                      /* DO  */
    ELSE = 263,                    /* ELSE  */
    END = 264,                     /* END  */
    FUNCTION = 265,                /* FUNCTION  */
    IF = 266,                      /* IF  */
    MOD = 267,                     /* MOD  */
    NOT = 268,                     /* NOT  */
    OF = 269,                      /* OF  */
    OR = 270,                      /* OR  */
    PROCEDURE = 271,               /* PROCEDURE  */
    PROGRAM = 272,                 /* PROGRAM  */
    THEN = 273,                    /* THEN  */
    VAR = 274,                     /* VAR  */
    WHILE = 275,                   /* WHILE  */
    INTEGER = 276,                 /* INTEGER  */
    REAL = 277,                    /* REAL  */
    BOOLEAN = 278,                 /* BOOLEAN  */
    TRUE = 279,                    /* TRUE  */
    FALSE = 280,                   /* FALSE  */
    COMMENT = 281,                 /* COMMENT  */
    BRAC_OPEN = 282,               /* BRAC_OPEN  */
    BRAC_CLOSE = 283,              /* BRAC_CLOSE  */
    PARENTH_OPEN = 284,            /* PARENTH_OPEN  */
    PARENTH_CLOSE = 285,           /* PARENTH_CLOSE  */
    COLON = 286,                   /* COLON  */
    SEMICOLON = 287,               /* SEMICOLON  */
    COMA = 288,                    /* COMA  */
    DOT = 289,                     /* DOT  */
    RANGE = 290,                   /* RANGE  */
    PLUS = 291,                    /* PLUS  */
    MINUS = 292,                   /* MINUS  */
    MULTI = 293,                   /* MULTI  */
    DIV_SIGN = 294,                /* DIV_SIGN  */
    NEQ = 295,                     /* NEQ  */
    EQ = 296,                      /* EQ  */
    LT = 297,                      /* LT  */
    GT = 298,                      /* GT  */
    LEQ = 299,                     /* LEQ  */
    GEQ = 300,                     /* GEQ  */
    ASSIGN = 301,                  /* ASSIGN  */
    ID = 302,                      /* ID  */
    NUM = 303                      /* NUM  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define AND 258
#define ARRAY 259
#define BEG 260
#define DIV 261
#define DO 262
#define ELSE 263
#define END 264
#define FUNCTION 265
#define IF 266
#define MOD 267
#define NOT 268
#define OF 269
#define OR 270
#define PROCEDURE 271
#define PROGRAM 272
#define THEN 273
#define VAR 274
#define WHILE 275
#define INTEGER 276
#define REAL 277
#define BOOLEAN 278
#define TRUE 279
#define FALSE 280
#define COMMENT 281
#define BRAC_OPEN 282
#define BRAC_CLOSE 283
#define PARENTH_OPEN 284
#define PARENTH_CLOSE 285
#define COLON 286
#define SEMICOLON 287
#define COMA 288
#define DOT 289
#define RANGE 290
#define PLUS 291
#define MINUS 292
#define MULTI 293
#define DIV_SIGN 294
#define NEQ 295
#define EQ 296
#define LT 297
#define GT 298
#define LEQ 299
#define GEQ 300
#define ASSIGN 301
#define ID 302
#define NUM 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "lalr.y"

	int number_i;
	float number_f;
	char *string;
	struct tENTRY *entry;
	struct tN_PROG *prog;
	struct tN_STMT *stmt;
	struct tN_CALL *call_stmt;
	struct tN_ASSIGN *assign_stmt;
	struct tN_IF *if_stmt;
	struct tN_WHILE *while_stmt;
	struct tN_EXPR *expr;

#line 245 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_AND = 3,                        /* AND  */
  YYSYMBOL_ARRAY = 4,                      /* ARRAY  */
  YYSYMBOL_BEG = 5,                        /* BEG  */
  YYSYMBOL_DIV = 6,                        /* DIV  */
  YYSYMBOL_DO = 7,                         /* DO  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_END = 9,                        /* END  */
  YYSYMBOL_FUNCTION = 10,                  /* FUNCTION  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_MOD = 12,                       /* MOD  */
  YYSYMBOL_NOT = 13,                       /* NOT  */
  YYSYMBOL_OF = 14,                        /* OF  */
  YYSYMBOL_OR = 15,                        /* OR  */
  YYSYMBOL_PROCEDURE = 16,                 /* PROCEDURE  */
  YYSYMBOL_PROGRAM = 17,                   /* PROGRAM  */
  YYSYMBOL_THEN = 18,                      /* THEN  */
  YYSYMBOL_VAR = 19,                       /* VAR  */
  YYSYMBOL_WHILE = 20,                     /* WHILE  */
  YYSYMBOL_INTEGER = 21,                   /* INTEGER  */
  YYSYMBOL_REAL = 22,                      /* REAL  */
  YYSYMBOL_BOOLEAN = 23,                   /* BOOLEAN  */
  YYSYMBOL_TRUE = 24,                      /* TRUE  */
  YYSYMBOL_FALSE = 25,                     /* FALSE  */
  YYSYMBOL_COMMENT = 26,                   /* COMMENT  */
  YYSYMBOL_BRAC_OPEN = 27,                 /* BRAC_OPEN  */
  YYSYMBOL_BRAC_CLOSE = 28,                /* BRAC_CLOSE  */
  YYSYMBOL_PARENTH_OPEN = 29,              /* PARENTH_OPEN  */
  YYSYMBOL_PARENTH_CLOSE = 30,             /* PARENTH_CLOSE  */
  YYSYMBOL_COLON = 31,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 32,                 /* SEMICOLON  */
  YYSYMBOL_COMA = 33,                      /* COMA  */
  YYSYMBOL_DOT = 34,                       /* DOT  */
  YYSYMBOL_RANGE = 35,                     /* RANGE  */
  YYSYMBOL_PLUS = 36,                      /* PLUS  */
  YYSYMBOL_MINUS = 37,                     /* MINUS  */
  YYSYMBOL_MULTI = 38,                     /* MULTI  */
  YYSYMBOL_DIV_SIGN = 39,                  /* DIV_SIGN  */
  YYSYMBOL_NEQ = 40,                       /* NEQ  */
  YYSYMBOL_EQ = 41,                        /* EQ  */
  YYSYMBOL_LT = 42,                        /* LT  */
  YYSYMBOL_GT = 43,                        /* GT  */
  YYSYMBOL_LEQ = 44,                       /* LEQ  */
  YYSYMBOL_GEQ = 45,                       /* GEQ  */
  YYSYMBOL_ASSIGN = 46,                    /* ASSIGN  */
  YYSYMBOL_ID = 47,                        /* ID  */
  YYSYMBOL_NUM = 48,                       /* NUM  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_start = 50,                     /* start  */
  YYSYMBOL_varDec = 51,                    /* varDec  */
  YYSYMBOL_varDecList = 52,                /* varDecList  */
  YYSYMBOL_identListType = 53,             /* identListType  */
  YYSYMBOL_identList = 54,                 /* identList  */
  YYSYMBOL_type = 55,                      /* type  */
  YYSYMBOL_simpleType = 56,                /* simpleType  */
  YYSYMBOL_subProgList = 57,               /* subProgList  */
  YYSYMBOL_subProgHead = 58,               /* subProgHead  */
  YYSYMBOL_args = 59,                      /* args  */
  YYSYMBOL_parList = 60,                   /* parList  */
  YYSYMBOL_compStmt = 61,                  /* compStmt  */
  YYSYMBOL_stmtList = 62,                  /* stmtList  */
  YYSYMBOL_stmt = 63,                      /* stmt  */
  YYSYMBOL_procCall = 64,                  /* procCall  */
  YYSYMBOL_params = 65,                    /* params  */
  YYSYMBOL_assignStmt = 66,                /* assignStmt  */
  YYSYMBOL_index = 67,                     /* index  */
  YYSYMBOL_ifStmt = 68,                    /* ifStmt  */
  YYSYMBOL_elsePart = 69,                  /* elsePart  */
  YYSYMBOL_whileStmt = 70,                 /* whileStmt  */
  YYSYMBOL_exprList = 71,                  /* exprList  */
  YYSYMBOL_expr = 72,                      /* expr  */
  YYSYMBOL_simpleExpr = 73,                /* simpleExpr  */
  YYSYMBOL_term = 74,                      /* term  */
  YYSYMBOL_factor = 75,                    /* factor  */
  YYSYMBOL_relOp = 76,                     /* relOp  */
  YYSYMBOL_addOp = 77,                     /* addOp  */
  YYSYMBOL_mulOp = 78                      /* mulOp  */
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
#define YYLAST   114

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


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
      45,    46,    47,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    51,    51,    64,    65,    67,    80,    82,    97,   103,
     110,   118,   128,   129,   130,   132,   133,   142,   151,   161,
     162,   164,   177,   179,   181,   185,   187,   193,   199,   200,
     206,   213,   220,   221,   223,   232,   242,   243,   248,   256,
     257,   259,   265,   269,   271,   287,   289,   302,   304,   319,
     323,   334,   341,   348,   358,   368,   378,   387,   391,   392,
     393,   394,   395,   396,   398,   399,   400,   402,   403,   404,
     405,   406
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
  "\"end of file\"", "error", "\"invalid token\"", "AND", "ARRAY", "BEG",
  "DIV", "DO", "ELSE", "END", "FUNCTION", "IF", "MOD", "NOT", "OF", "OR",
  "PROCEDURE", "PROGRAM", "THEN", "VAR", "WHILE", "INTEGER", "REAL",
  "BOOLEAN", "TRUE", "FALSE", "COMMENT", "BRAC_OPEN", "BRAC_CLOSE",
  "PARENTH_OPEN", "PARENTH_CLOSE", "COLON", "SEMICOLON", "COMA", "DOT",
  "RANGE", "PLUS", "MINUS", "MULTI", "DIV_SIGN", "NEQ", "EQ", "LT", "GT",
  "LEQ", "GEQ", "ASSIGN", "ID", "NUM", "$accept", "start", "varDec",
  "varDecList", "identListType", "identList", "type", "simpleType",
  "subProgList", "subProgHead", "args", "parList", "compStmt", "stmtList",
  "stmt", "procCall", "params", "assignStmt", "index", "ifStmt",
  "elsePart", "whileStmt", "exprList", "expr", "simpleExpr", "term",
  "factor", "relOp", "addOp", "mulOp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -6,   -31,    26,    -1,   -76,    17,    22,     3,    33,   -76,
      39,    41,    23,    27,    68,    17,    22,    22,    21,    46,
      46,    -2,    42,    68,   -76,   -76,    50,   -76,   -76,   -76,
     -76,   -76,    22,    47,    51,    10,    10,   -17,   -76,    70,
      52,   -76,   -76,   -76,   -76,   -76,    53,    34,    54,    57,
      30,   -76,    10,   -76,   -76,    10,    38,   -76,    71,    19,
      12,     2,    81,    10,     8,    10,   -76,    44,   -76,    -2,
       3,    56,    22,   -76,    60,   -76,    63,   -76,   -76,    -2,
     -76,   -76,   -76,   -76,   -76,   -76,    10,   -76,   -76,   -76,
      10,   -76,   -76,   -76,   -76,   -76,    10,    -2,   -11,   -76,
      64,    62,   -76,    10,   -76,   -76,    48,   -76,   -76,   -76,
      89,   -76,   -76,   -76,   -76,   -76,    10,   -76,    10,   -76,
      72,    -2,   -76,    73,   -76,    84,   -76,   -76,    30,   -76
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     3,     0,    15,     9,     4,
       0,     0,     0,     0,     0,     3,     0,     6,     0,    19,
      19,     0,     0,     0,     8,     5,     0,    12,    13,    14,
       7,    10,     0,     0,     0,     0,     0,     0,    28,     0,
      25,    26,    27,    29,    30,     2,     0,     0,    22,     0,
       0,    18,     0,    52,    51,     0,    53,    50,     0,    45,
      47,    49,     0,     0,     0,     0,    31,     0,    23,     0,
      15,     0,     0,    20,     0,    56,     0,    55,    54,     0,
      61,    60,    58,    59,    63,    62,     0,    66,    64,    65,
       0,    71,    69,    70,    67,    68,     0,     0,     0,    33,
       0,    43,    34,     0,    24,    16,     0,    21,    17,    57,
      39,    44,    46,    48,    41,    36,     0,    32,     0,    35,
       0,     0,    38,     0,    42,     0,    40,    37,     0,    11
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -76,   -76,    87,    82,   -25,    88,   -76,   -48,    35,   -76,
      83,    36,    -8,    37,   -75,   -76,    55,   -76,    58,   -76,
     -76,   -76,    -9,   -35,   -36,    11,    61,   -76,   -76,   -76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     7,     9,    10,    11,    30,    31,    14,    15,
      33,    49,    38,    39,    40,    41,    66,    42,    67,    43,
     122,    44,   100,   101,    59,    60,    61,    86,    90,    96
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      58,    62,    74,    21,   110,    91,    22,    48,    92,    35,
      63,     1,    64,    12,    93,    46,     3,   115,    36,    13,
      76,    52,   114,    52,   116,    26,     4,    87,    98,    65,
     102,     5,    53,    54,    53,    54,     6,    55,    99,    55,
      94,    95,    27,    28,    29,    37,   126,    48,    88,    89,
     111,    27,    28,    29,   112,    56,    57,    56,    57,    80,
      81,    82,    83,    84,    85,    63,    16,    64,   119,     8,
      19,    17,    18,    21,    20,    32,    45,    47,    50,    68,
     129,   123,    71,    51,    69,    70,    72,    73,    97,    79,
     103,   106,   108,   109,   117,   118,   120,   121,   128,    25,
     125,   127,    23,    34,    24,   105,   104,   113,   107,   124,
       0,    77,     0,    75,    78
};

static const yytype_int16 yycheck[] =
{
      35,    36,    50,     5,    79,     3,    14,    32,     6,    11,
      27,    17,    29,    10,    12,    23,    47,    28,    20,    16,
      55,    13,    97,    13,    35,     4,     0,    15,    63,    46,
      65,    32,    24,    25,    24,    25,    19,    29,    30,    29,
      38,    39,    21,    22,    23,    47,   121,    72,    36,    37,
      86,    21,    22,    23,    90,    47,    48,    47,    48,    40,
      41,    42,    43,    44,    45,    27,    33,    29,   103,    47,
      47,    32,    31,     5,    47,    29,    34,    27,    31,     9,
     128,   116,    48,    32,    32,    32,    32,    30,     7,    18,
      46,    35,    32,    30,    30,    33,    48,     8,    14,    17,
      28,    28,    15,    20,    16,    70,    69,    96,    72,   118,
      -1,    56,    -1,    52,    56
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    17,    50,    47,     0,    32,    19,    51,    47,    52,
      53,    54,    10,    16,    57,    58,    33,    32,    31,    47,
      47,     5,    61,    51,    54,    52,     4,    21,    22,    23,
      55,    56,    29,    59,    59,    11,    20,    47,    61,    62,
      63,    64,    66,    68,    70,    34,    61,    27,    53,    60,
      31,    32,    13,    24,    25,    29,    47,    48,    72,    73,
      74,    75,    72,    27,    29,    46,    65,    67,     9,    32,
      32,    48,    32,    30,    56,    75,    72,    65,    67,    18,
      40,    41,    42,    43,    44,    45,    76,    15,    36,    37,
      77,     3,     6,    12,    38,    39,    78,     7,    72,    30,
      71,    72,    72,    46,    62,    57,    35,    60,    32,    30,
      63,    73,    73,    74,    63,    28,    35,    30,    33,    72,
      48,     8,    69,    72,    71,    28,    63,    28,    14,    56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    53,    54,    54,
      55,    55,    56,    56,    56,    57,    57,    58,    58,    59,
      59,    60,    60,    61,    62,    62,    63,    63,    63,    63,
      63,    64,    65,    65,    66,    66,    67,    67,    68,    69,
      69,    70,    71,    71,    72,    72,    73,    73,    74,    74,
      75,    75,    75,    75,    75,    75,    75,    75,    76,    76,
      76,    76,    76,    76,    77,    77,    77,    78,    78,    78,
      78,    78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     0,     2,     3,     2,     3,     3,     1,
       1,     8,     1,     1,     1,     0,     5,     6,     4,     0,
       3,     3,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     2,     3,     2,     3,     4,     3,     5,     5,     0,
       2,     4,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     2,     2,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
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
  case 2: /* start: PROGRAM ID SEMICOLON varDec subProgList compStmt DOT  */
#line 51 "lalr.y"
                                                                        {
                                                                            ast = (N_PROG*) malloc(sizeof (struct tN_PROG));
                                                                            ENTRY * entry = (ENTRY*) malloc(sizeof (struct tENTRY));
                                                                            entry->typ = _PROG;
                                                                            entry->dataType = _MAIN;
                                                                            entry->base.id = (yyvsp[-5].string);
                                                                            entry->ext.prog.parList = NULL;
                                                                            entry->next= (yyvsp[-3].entry);
                                                                            ast->entry = entry;
                                                                            ast->stmt = (yyvsp[-1].stmt);
                                                                            ast->next = (yyvsp[-2].prog);
                                                                        }
#line 1397 "y.tab.c"
    break;

  case 3: /* varDec: %empty  */
#line 64 "lalr.y"
                                        { (yyval.entry) = NULL; }
#line 1403 "y.tab.c"
    break;

  case 4: /* varDec: VAR varDecList  */
#line 65 "lalr.y"
                                        { (yyval.entry) = (yyvsp[0].entry); }
#line 1409 "y.tab.c"
    break;

  case 5: /* varDecList: identListType SEMICOLON varDecList  */
#line 67 "lalr.y"
                                                        {
                                                            ENTRY * n = (yyvsp[-2].entry) -> next;
                                                            if(n == NULL){
                                                                (yyvsp[-2].entry)->next = (yyvsp[0].entry);
                                                            }
                                                            else{
                                                                while(n->next != NULL){
                                                                    n = (ENTRY *)(n->next);
                                                                }
                                                                n->next = (yyvsp[0].entry);
                                                            }
                                                            (yyval.entry) = (yyvsp[-2].entry);
                                                        }
#line 1427 "y.tab.c"
    break;

  case 6: /* varDecList: identListType SEMICOLON  */
#line 80 "lalr.y"
                                                        { (yyval.entry) = (yyvsp[-1].entry); }
#line 1433 "y.tab.c"
    break;

  case 7: /* identListType: identList COLON type  */
#line 82 "lalr.y"
                                       {
                                           ENTRY *idListType = (yyvsp[-2].entry);
                                           ENTRY *returnVal = idListType;
                                           while(idListType != NULL){
                                               idListType->typ = (yyvsp[0].entry)->typ;
                                               idListType->dataType = (yyvsp[0].entry)->dataType;
                                               if(idListType->typ == _ARRAY){
                                                   idListType->ext.bounds.low = (yyvsp[0].entry)->ext.bounds.low;
                                                   idListType->ext.bounds.high = (yyvsp[0].entry)->ext.bounds.high;
                                               }
                                               idListType = (ENTRY *)(idListType->next);
                                           }
                                           (yyval.entry) = returnVal;
                                       }
#line 1452 "y.tab.c"
    break;

  case 8: /* identList: ID COMA identList  */
#line 97 "lalr.y"
                                        {
					ENTRY *idList = (ENTRY *)(malloc(sizeof(struct tENTRY)));
					idList->base.id = (yyvsp[-2].string);
					idList->next = (yyvsp[0].entry);
					(yyval.entry) = idList;
					}
#line 1463 "y.tab.c"
    break;

  case 9: /* identList: ID  */
#line 103 "lalr.y"
                                        {
					ENTRY *idList = (ENTRY *)(malloc(sizeof(struct tENTRY)));
					idList->base.id = (yyvsp[0].string);
					idList->next = NULL;
					(yyval.entry) = idList;
					}
#line 1474 "y.tab.c"
    break;

  case 10: /* type: simpleType  */
#line 110 "lalr.y"
                                                                                {
                                                                                    ENTRY *type = (ENTRY *)(malloc(sizeof(struct tENTRY)));
                                                                                    type->typ = _VAR;

                                                                                    type->dataType = (yyvsp[0].number_i);
                                                                                    type->next = NULL;
                                                                                    (yyval.entry) = type;
                                                                                }
#line 1487 "y.tab.c"
    break;

  case 11: /* type: ARRAY BRAC_OPEN NUM RANGE NUM BRAC_CLOSE OF simpleType  */
#line 118 "lalr.y"
                                                                                {
                                                                                    ENTRY *type = (ENTRY *)(malloc(sizeof(struct tENTRY)));
                                                                                    type->typ = _ARRAY;
                                                                                    type->dataType = (yyvsp[0].number_i);
                                                                                    type->ext.bounds.low = (int)((yyvsp[-5].number_f));
                                                                                    type->ext.bounds.high = (int)((yyvsp[-3].number_f));
                                                                                    type->next = NULL;
                                                                                    (yyval.entry) = type;
                                                                                }
#line 1501 "y.tab.c"
    break;

  case 12: /* simpleType: INTEGER  */
#line 128 "lalr.y"
                                {(yyval.number_i) = _INT;}
#line 1507 "y.tab.c"
    break;

  case 13: /* simpleType: REAL  */
#line 129 "lalr.y"
                                {(yyval.number_i) = _REAL;}
#line 1513 "y.tab.c"
    break;

  case 14: /* simpleType: BOOLEAN  */
#line 130 "lalr.y"
                                {(yyval.number_i) = _BOOL;}
#line 1519 "y.tab.c"
    break;

  case 15: /* subProgList: %empty  */
#line 132 "lalr.y"
                        {(yyval.prog) = NULL; }
#line 1525 "y.tab.c"
    break;

  case 16: /* subProgList: subProgHead varDec compStmt SEMICOLON subProgList  */
#line 133 "lalr.y"
                                                                     {
                                                                         N_PROG* prog = (N_PROG *)(malloc(sizeof(struct tN_PROG)));
                                                                         prog->entry = (yyvsp[-4].entry);
                                                                         prog->entry->next = (yyvsp[-3].entry);
                                                                         prog->stmt = (yyvsp[-2].stmt);
                                                                         prog->next = (yyvsp[0].prog);
                                                                         (yyval.prog) = prog;
                                                                     }
#line 1538 "y.tab.c"
    break;

  case 17: /* subProgHead: FUNCTION ID args COLON simpleType SEMICOLON  */
#line 142 "lalr.y"
                                                                        {
                                                                            ENTRY * func = (ENTRY*) malloc(sizeof (struct tENTRY));
                                                                            func->typ = _CALL;
                                                                            func->dataType = (yyvsp[-1].number_i);
                                                                            func->base.id = (yyvsp[-4].string);
                                                                            func->ext.prog.parList = (yyvsp[-3].entry);
                                                                            func->next = NULL;
                                                                            (yyval.entry) = func;
                                                                        }
#line 1552 "y.tab.c"
    break;

  case 18: /* subProgHead: PROCEDURE ID args SEMICOLON  */
#line 151 "lalr.y"
                                                                {
                                                                    ENTRY * func = (ENTRY*) malloc(sizeof (struct tENTRY));
                                                                    func->typ = _CALL;
                                                                    func->dataType = _VOID;
                                                                    func->base.id = (yyvsp[-2].string);
                                                                    func->ext.prog.parList = (yyvsp[-1].entry);
                                                                    func->next = NULL;
                                                                    (yyval.entry) = func;
                                                                }
#line 1566 "y.tab.c"
    break;

  case 19: /* args: %empty  */
#line 161 "lalr.y"
                        { (yyval.entry) = NULL; }
#line 1572 "y.tab.c"
    break;

  case 20: /* args: PARENTH_OPEN parList PARENTH_CLOSE  */
#line 162 "lalr.y"
                                                        { (yyval.entry) = (yyvsp[-1].entry); }
#line 1578 "y.tab.c"
    break;

  case 21: /* parList: identListType SEMICOLON parList  */
#line 164 "lalr.y"
                                                        {
							    ENTRY * n = (yyvsp[-2].entry) -> next;
							    if(n == NULL){
								(yyvsp[-2].entry)->next = (yyvsp[0].entry);
							    }
							    else{
								while(n->next != NULL){
								    n = (ENTRY *)(n->next);
								}
								n->next = (yyvsp[0].entry);
							    }
							    (yyval.entry) = (yyvsp[-2].entry);
							}
#line 1596 "y.tab.c"
    break;

  case 22: /* parList: identListType  */
#line 177 "lalr.y"
                                                        { (yyval.entry) = (yyvsp[0].entry); }
#line 1602 "y.tab.c"
    break;

  case 23: /* compStmt: BEG stmtList END  */
#line 179 "lalr.y"
                                   { (yyval.stmt) = (yyvsp[-1].stmt); }
#line 1608 "y.tab.c"
    break;

  case 24: /* stmtList: stmt SEMICOLON stmtList  */
#line 181 "lalr.y"
                                                {
						    (yyvsp[-2].stmt)->next =  (yyvsp[0].stmt);
                                                    (yyval.stmt) = (yyvsp[-2].stmt);
                                                }
#line 1617 "y.tab.c"
    break;

  case 25: /* stmtList: stmt  */
#line 185 "lalr.y"
                                                {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1623 "y.tab.c"
    break;

  case 26: /* stmt: procCall  */
#line 187 "lalr.y"
                                {
                                    	N_STMT * stmt = malloc(sizeof(struct tN_STMT));
					stmt->typ = _PROC_CALL;
					stmt->node.proc_call = (yyvsp[0].call_stmt);
					(yyval.stmt) = stmt;
                                }
#line 1634 "y.tab.c"
    break;

  case 27: /* stmt: assignStmt  */
#line 193 "lalr.y"
                                {
                                    	N_STMT * stmt = malloc(sizeof(struct tN_STMT));
					stmt->typ = _ASSIGN;
					stmt->node.assign_stmt = (yyvsp[0].assign_stmt);
					(yyval.stmt) = stmt;
                                }
#line 1645 "y.tab.c"
    break;

  case 28: /* stmt: compStmt  */
#line 199 "lalr.y"
                                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1651 "y.tab.c"
    break;

  case 29: /* stmt: ifStmt  */
#line 200 "lalr.y"
                                {
                                    	N_STMT * stmt = malloc(sizeof(struct tN_STMT));
					stmt->typ = _IF;
					stmt->node.if_stmt = (yyvsp[0].if_stmt);
					(yyval.stmt) = stmt;
                                }
#line 1662 "y.tab.c"
    break;

  case 30: /* stmt: whileStmt  */
#line 206 "lalr.y"
                                {
                                    	N_STMT * stmt = malloc(sizeof(struct tN_STMT));
					stmt->typ = _WHILE;
					stmt->node.while_stmt = (yyvsp[0].while_stmt);
					(yyval.stmt) = stmt;
				}
#line 1673 "y.tab.c"
    break;

  case 31: /* procCall: ID params  */
#line 213 "lalr.y"
                                {
                                    N_CALL* call = malloc(sizeof (struct tN_CALL));
                                    call->id = (yyvsp[-1].string);
                                    call->par_list = (yyvsp[0].expr);
                                    (yyval.call_stmt) = call;
                                }
#line 1684 "y.tab.c"
    break;

  case 32: /* params: PARENTH_OPEN exprList PARENTH_CLOSE  */
#line 220 "lalr.y"
                                                        {(yyval.expr) = (yyvsp[-1].expr);}
#line 1690 "y.tab.c"
    break;

  case 33: /* params: PARENTH_OPEN PARENTH_CLOSE  */
#line 221 "lalr.y"
                                                        {(yyval.expr) = NULL;}
#line 1696 "y.tab.c"
    break;

  case 34: /* assignStmt: ID ASSIGN expr  */
#line 223 "lalr.y"
                                                {
						N_VAR_REF* var = malloc(sizeof(struct tN_VAR_REF));
						var->id = (yyvsp[-2].string);
						var->index = NULL;
						N_ASSIGN* assign = malloc(sizeof (struct tN_ASSIGN));
						assign->var_ref = var;
						assign->rhs_expr = (yyvsp[0].expr);
						(yyval.assign_stmt) = assign;
						}
#line 1710 "y.tab.c"
    break;

  case 35: /* assignStmt: ID index ASSIGN expr  */
#line 232 "lalr.y"
                                                {
                                                    N_VAR_REF* var = malloc(sizeof(struct tN_VAR_REF));
                                                    var->id = (yyvsp[-3].string);
                                                    var->index = (yyvsp[-2].expr);
                                                    N_ASSIGN* assign = malloc(sizeof (struct tN_ASSIGN));
                                                    assign->var_ref = var;
                                                    assign ->rhs_expr = (yyvsp[0].expr);
                                                    (yyval.assign_stmt) = assign;
                                                }
#line 1724 "y.tab.c"
    break;

  case 36: /* index: BRAC_OPEN expr BRAC_CLOSE  */
#line 242 "lalr.y"
                                                        {(yyval.expr) = (yyvsp[-1].expr);}
#line 1730 "y.tab.c"
    break;

  case 37: /* index: BRAC_OPEN expr RANGE expr BRAC_CLOSE  */
#line 243 "lalr.y"
                                                        {
                                                            (yyvsp[-3].expr)->next = (yyvsp[-1].expr);
                                                            (yyval.expr) = (yyvsp[-3].expr);
                                                        }
#line 1739 "y.tab.c"
    break;

  case 38: /* ifStmt: IF expr THEN stmt elsePart  */
#line 248 "lalr.y"
                                                {
                                                    N_IF *i = malloc(sizeof (struct tN_IF));
                                                    i->expr = (yyvsp[-3].expr);
                                                    i->then_part = (yyvsp[-1].stmt);
                                                    i->else_part = (yyvsp[0].stmt);
                                                    (yyval.if_stmt) = i;
                                                }
#line 1751 "y.tab.c"
    break;

  case 39: /* elsePart: %empty  */
#line 256 "lalr.y"
                                        {(yyval.stmt) = NULL;}
#line 1757 "y.tab.c"
    break;

  case 40: /* elsePart: ELSE stmt  */
#line 257 "lalr.y"
                                        {(yyval.stmt) = (yyvsp[0].stmt);}
#line 1763 "y.tab.c"
    break;

  case 41: /* whileStmt: WHILE expr DO stmt  */
#line 259 "lalr.y"
                                        {
					    (yyval.while_stmt) = malloc(sizeof(struct tN_WHILE));
                                            (yyval.while_stmt)->expr = (yyvsp[-2].expr);
                                            (yyval.while_stmt)->stmt = (yyvsp[0].stmt);
					}
#line 1773 "y.tab.c"
    break;

  case 42: /* exprList: expr COMA exprList  */
#line 265 "lalr.y"
                                        {
                                            (yyvsp[-2].expr)->next = (yyvsp[0].expr);
                                            (yyval.expr) = (yyvsp[-2].expr);
                                        }
#line 1782 "y.tab.c"
    break;

  case 43: /* exprList: expr  */
#line 269 "lalr.y"
                                        {(yyval.expr) = (yyvsp[0].expr);}
#line 1788 "y.tab.c"
    break;

  case 44: /* expr: simpleExpr relOp simpleExpr  */
#line 271 "lalr.y"
                                                {
                                                    N_EXPR * expr = malloc(sizeof(struct tN_EXPR));
                                                    expr->typ = OP;
                                                    expr->description.operation.expr = (yyvsp[-2].expr);
                                                    switch((yyvsp[-1].number_i)){
                                                        case '=': expr->description.operation.op = EQ_OP; break;
                                                        case '!': expr->description.operation.op = NEQ_OP; break;
                                                        case '<': expr->description.operation.op = LT_OP; break;
                                                        case '>': expr->description.operation.op = GT_OP; break;
                                                        case '{': expr->description.operation.op = LEQ_OP; break;
                                                        case '}': expr->description.operation.op = GEQ_OP; break;
                                                    }
                                                    expr->description.operation.expr->next = (yyvsp[0].expr);
                                                    expr->next = NULL;
                                                    (yyval.expr) = expr;
                                                }
#line 1809 "y.tab.c"
    break;

  case 45: /* expr: simpleExpr  */
#line 287 "lalr.y"
                                                {(yyval.expr) = (yyvsp[0].expr);}
#line 1815 "y.tab.c"
    break;

  case 46: /* simpleExpr: term addOp simpleExpr  */
#line 289 "lalr.y"
                                       {
                                           N_EXPR * expr = malloc(sizeof(struct tN_EXPR));
                                           expr->typ = OP;
                                           expr->description.operation.expr = (yyvsp[-2].expr);
                                           switch((yyvsp[-1].number_i)){
                                               case '+': expr->description.operation.op = PLUS_OP; break;
                                               case '-': expr->description.operation.op = MINUS_OP; break;
                                               case '|': expr->description.operation.op = OR_OP; break;
                                           }
                                           expr->description.operation.expr->next = (yyvsp[0].expr);
                                           expr->next = NULL;
                                           (yyval.expr) = expr;
                                       }
#line 1833 "y.tab.c"
    break;

  case 47: /* simpleExpr: term  */
#line 302 "lalr.y"
                                        {(yyval.expr) = (yyvsp[0].expr);}
#line 1839 "y.tab.c"
    break;

  case 48: /* term: factor mulOp term  */
#line 304 "lalr.y"
                                        {
                                            N_EXPR * expr = malloc(sizeof(struct tN_EXPR));
                                            expr->typ = OP;
                                            expr->description.operation.expr = (yyvsp[-2].expr);
                                            switch((yyvsp[-1].number_i)){
                                                case '*':   expr->description.operation.op = MULTI_OP; break;
                                                case '/':   expr->description.operation.op = SLASH_OP; break;
                                                case '\\':  expr->description.operation.op = DIV_OP; break;
                                                case '%':   expr->description.operation.op = MOD_OP; break;
                                                case '&':   expr->description.operation.op = AND_OP; break;
                                            }
                                            expr->description.operation.expr->next = (yyvsp[0].expr);
                                            expr->next = NULL;
                                            (yyval.expr) = expr;
                                        }
#line 1859 "y.tab.c"
    break;

  case 49: /* term: factor  */
#line 319 "lalr.y"
                                        {
					(yyval.expr) = (yyvsp[0].expr);
					}
#line 1867 "y.tab.c"
    break;

  case 50: /* factor: NUM  */
#line 323 "lalr.y"
                                        {
                                            N_EXPR * expr = malloc(sizeof(struct tN_EXPR));
                                            expr->typ = CONSTANT;
                                            float num = (yyvsp[0].number_f);
					    int len = snprintf(NULL, 0, "%f", num);
					    char* res = (char *)(malloc(len + 1));
					    snprintf(res, len+1, "%f", num);
                                            expr->description.constant = res;
                                            expr->next = NULL;
                                            (yyval.expr) = expr;
                                        }
#line 1883 "y.tab.c"
    break;

  case 51: /* factor: FALSE  */
#line 334 "lalr.y"
                                        {
                                            N_EXPR * expr = malloc(sizeof(struct tN_EXPR));
                                            expr->typ = CONSTANT;
                                            expr->description.constant = "false";
                                            expr->next = NULL;
                                            (yyval.expr) = expr;
                                        }
#line 1895 "y.tab.c"
    break;

  case 52: /* factor: TRUE  */
#line 341 "lalr.y"
                                        {
                                            N_EXPR * expr = malloc(sizeof(struct tN_EXPR));
                                            expr->typ = CONSTANT;
                                            expr->description.constant = "true";
                                            expr->next = NULL;
                                            (yyval.expr) = expr;
                                        }
#line 1907 "y.tab.c"
    break;

  case 53: /* factor: ID  */
#line 348 "lalr.y"
                                        {
                                            N_EXPR * expr = malloc(sizeof(struct tN_EXPR));
                                            N_VAR_REF * var = malloc(sizeof(struct tN_VAR_REF));
                                            var->id = (yyvsp[0].string);
                                            var->index = NULL;
                                            expr->typ = VAR_REF;
                                            expr->description.var_ref = var;
                                            expr->next = NULL;
                                            (yyval.expr) = expr;
                                        }
#line 1922 "y.tab.c"
    break;

  case 54: /* factor: ID index  */
#line 358 "lalr.y"
                                        {
                                            N_EXPR * expr = malloc(sizeof(struct tN_EXPR));
                                            N_VAR_REF * var = malloc(sizeof(struct tN_VAR_REF));
                                            var->id = (yyvsp[-1].string);
                                            var->index = (yyvsp[0].expr);
                                            expr->typ = VAR_REF;
                                            expr->description.var_ref = var;
                                            expr->next = NULL;
                                            (yyval.expr) = expr;
                                        }
#line 1937 "y.tab.c"
    break;

  case 55: /* factor: ID params  */
#line 368 "lalr.y"
                                        {
                                            N_EXPR * expr = malloc(sizeof(struct tN_EXPR));
                                            N_CALL * call = malloc(sizeof(struct tN_CALL));
                                            call->id = (yyvsp[-1].string);
                                            call->par_list = (yyvsp[0].expr);
                                            expr->typ = FUNC_CALL;
                                            expr->description.func_call = call;
                                            expr->next = NULL;
                                            (yyval.expr) = expr;
                                        }
#line 1952 "y.tab.c"
    break;

  case 56: /* factor: NOT factor  */
#line 378 "lalr.y"
                                        {
                                            N_EXPR * expr =  malloc(sizeof(struct tN_EXPR));
                                            expr->typ = OP;
                                            expr->description.operation.op = NOT_OP;
                                            expr->description.operation.expr = (yyvsp[0].expr);
                                            expr->paranthesis = (yyvsp[0].expr)->paranthesis;
                                            expr->next = NULL;
                                            (yyval.expr) = expr;
                                        }
#line 1966 "y.tab.c"
    break;

  case 57: /* factor: PARENTH_OPEN expr PARENTH_CLOSE  */
#line 387 "lalr.y"
                                                  {
							(yyval.expr) = (yyvsp[-1].expr);
						  }
#line 1974 "y.tab.c"
    break;

  case 58: /* relOp: LT  */
#line 391 "lalr.y"
                                {(yyval.number_i) = '<';}
#line 1980 "y.tab.c"
    break;

  case 59: /* relOp: GT  */
#line 392 "lalr.y"
                                {(yyval.number_i) = '>';}
#line 1986 "y.tab.c"
    break;

  case 60: /* relOp: EQ  */
#line 393 "lalr.y"
                                {(yyval.number_i) = '=';}
#line 1992 "y.tab.c"
    break;

  case 61: /* relOp: NEQ  */
#line 394 "lalr.y"
                                {(yyval.number_i) = '!';}
#line 1998 "y.tab.c"
    break;

  case 62: /* relOp: GEQ  */
#line 395 "lalr.y"
                                {(yyval.number_i) = '}';}
#line 2004 "y.tab.c"
    break;

  case 63: /* relOp: LEQ  */
#line 396 "lalr.y"
                                {(yyval.number_i) = '{';}
#line 2010 "y.tab.c"
    break;

  case 64: /* addOp: PLUS  */
#line 398 "lalr.y"
                                {(yyval.number_i) = '+';}
#line 2016 "y.tab.c"
    break;

  case 65: /* addOp: MINUS  */
#line 399 "lalr.y"
                                {(yyval.number_i) = '-';}
#line 2022 "y.tab.c"
    break;

  case 66: /* addOp: OR  */
#line 400 "lalr.y"
                                {(yyval.number_i) = '|';}
#line 2028 "y.tab.c"
    break;

  case 67: /* mulOp: MULTI  */
#line 402 "lalr.y"
                                {(yyval.number_i) = '*';}
#line 2034 "y.tab.c"
    break;

  case 68: /* mulOp: DIV_SIGN  */
#line 403 "lalr.y"
                                {(yyval.number_i) = '/';}
#line 2040 "y.tab.c"
    break;

  case 69: /* mulOp: DIV  */
#line 404 "lalr.y"
                                {(yyval.number_i) = '\\';}
#line 2046 "y.tab.c"
    break;

  case 70: /* mulOp: MOD  */
#line 405 "lalr.y"
                                {(yyval.number_i) = '%';}
#line 2052 "y.tab.c"
    break;

  case 71: /* mulOp: AND  */
#line 406 "lalr.y"
                                {(yyval.number_i) = '&';}
#line 2058 "y.tab.c"
    break;


#line 2062 "y.tab.c"

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

#line 408 "lalr.y"


void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
	printf("error in line %d\n", yylineno);
	}
