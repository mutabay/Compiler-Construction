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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    PROG = 258,                    /* PROG  */
    VAR = 259,                     /* VAR  */
    ARRAY = 260,                   /* ARRAY  */
    TO = 261,                      /* TO  */
    OF = 262,                      /* OF  */
    FUNC = 263,                    /* FUNC  */
    PROC = 264,                    /* PROC  */
    INT = 265,                     /* INT  */
    REAL = 266,                    /* REAL  */
    BOOL = 267,                    /* BOOL  */
    START = 268,                   /* START  */
    END = 269,                     /* END  */
    IF = 270,                      /* IF  */
    THEN = 271,                    /* THEN  */
    ELSE = 272,                    /* ELSE  */
    WHILE = 273,                   /* WHILE  */
    DO = 274,                      /* DO  */
    IDENT = 275,                   /* IDENT  */
    NUM = 276,                     /* NUM  */
    COLON = 277,                   /* COLON  */
    SCOLON = 278,                  /* SCOLON  */
    COMMA = 279,                   /* COMMA  */
    DOT = 280,                     /* DOT  */
    LBRA = 281,                    /* LBRA  */
    RBRA = 282,                    /* RBRA  */
    LPAR = 283,                    /* LPAR  */
    RPAR = 284,                    /* RPAR  */
    ASSIGN = 285,                  /* ASSIGN  */
    LT = 286,                      /* LT  */
    LE = 287,                      /* LE  */
    GT = 288,                      /* GT  */
    GE = 289,                      /* GE  */
    EQ = 290,                      /* EQ  */
    NE = 291,                      /* NE  */
    PLUS = 292,                    /* PLUS  */
    MINUS = 293,                   /* MINUS  */
    TIMES = 294,                   /* TIMES  */
    SLASH = 295,                   /* SLASH  */
    DIV = 296,                     /* DIV  */
    MOD = 297,                     /* MOD  */
    NOT = 298,                     /* NOT  */
    AND = 299,                     /* AND  */
    OR = 300,                      /* OR  */
    TRUE = 301,                    /* TRUE  */
    FALSE = 302                    /* FALSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 47 "parser.y"

  int integer;
  char *string;
  float number;
  struct tENTRY *symtab;
  struct tN_PROG *prog;
  struct tN_STMT *stmt;
  struct tN_CALL *call_stmt;
  struct tN_ASSIGN *assign_stmt;
  struct tN_IF *if_stmt;
  struct tN_WHILE *while_stmt;
  struct tN_EXPR *exp;

#line 125 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
