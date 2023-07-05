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

#line 177 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
