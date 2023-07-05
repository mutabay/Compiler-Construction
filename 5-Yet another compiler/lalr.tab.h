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

#ifndef YY_YY_LALR_TAB_H_INCLUDED
# define YY_YY_LALR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    PROGRAM = 258,                 /* PROGRAM  */
    VAR = 259,                     /* VAR  */
    INTEGER = 260,                 /* INTEGER  */
    ARRAY = 261,                   /* ARRAY  */
    OF = 262,                      /* OF  */
    REAL = 263,                    /* REAL  */
    FUNCTION = 264,                /* FUNCTION  */
    BEGIN_TOKEN = 265,             /* BEGIN_TOKEN  */
    WHILE = 266,                   /* WHILE  */
    DO = 267,                      /* DO  */
    IF = 268,                      /* IF  */
    THEN = 269,                    /* THEN  */
    ELSE = 270,                    /* ELSE  */
    END = 271,                     /* END  */
    BOOLEAN = 272,                 /* BOOLEAN  */
    BOOL_FALSE = 273,              /* BOOL_FALSE  */
    BOOL_TRUE = 274,               /* BOOL_TRUE  */
    PROCEDURE = 275,               /* PROCEDURE  */
    DIV = 276,                     /* DIV  */
    GREATER = 277,                 /* GREATER  */
    LESS = 278,                    /* LESS  */
    LESS_EQUAL = 279,              /* LESS_EQUAL  */
    GREATER_EQUAL = 280,           /* GREATER_EQUAL  */
    NOT_EQUAL = 281,               /* NOT_EQUAL  */
    EQUAL = 282,                   /* EQUAL  */
    PLUS = 283,                    /* PLUS  */
    MINUS = 284,                   /* MINUS  */
    DIVISION = 285,                /* DIVISION  */
    MULTIPLICATION = 286,          /* MULTIPLICATION  */
    SQUARE_BRACKETS_OPEN = 287,    /* SQUARE_BRACKETS_OPEN  */
    SQUARE_BRACKETS_CLOSE = 288,   /* SQUARE_BRACKETS_CLOSE  */
    BRACKETS_OPEN = 289,           /* BRACKETS_OPEN  */
    BRACKETS_CLOSE = 290,          /* BRACKETS_CLOSE  */
    DOT = 291,                     /* DOT  */
    COLON = 292,                   /* COLON  */
    ASSIGNMENT = 293,              /* ASSIGNMENT  */
    SEMICOLON = 294,               /* SEMICOLON  */
    COMMA = 295,                   /* COMMA  */
    DOUBLE_DOTS = 296,             /* DOUBLE_DOTS  */
    IDENTIFIER = 297,              /* IDENTIFIER  */
    NUMBER = 298,                  /* NUMBER  */
    NOT = 299,                     /* NOT  */
    MOD = 300,                     /* MOD  */
    AND = 301,                     /* AND  */
    OR = 302,                      /* OR  */
    DOLLAR = 303                   /* DOLLAR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LALR_TAB_H_INCLUDED  */
