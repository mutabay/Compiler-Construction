%option noyywrap
%{
    /* Lexical Analyse Generator

    Declare the set of tokens in an enumerated type and modify the lexical analyser from
    Homework 1 to return the correct token when matching a regular expression;
     */
#include <stdio.h>

enum
{NUMBER, IDENTIFIER, COMMENT, PROGRAM,
VAR, ARRAY, OF, FUNCTION, PROCEDURE,
AND, OR, NOT, BEGINTOKEN, WHILE,
IF, THEN, ELSE, END, DO, TRUE, FALSE,
DIV, MOD, BOOLEAN, INTEGER, REAL, COMMA,
COLON, SEMICOLON, DOT, SQ_BRACKET_OPEN, SQ_BRACKET_CLOSE,
BRACKET_OPEN, BRACKET_CLOSE, DOUBLEDOT, PLUS, MINUS,
MULTIPLICATION, DIVISION, LT, GT, LE, GE, EQUAL, DIFFERENT, ASSIGNMENT};


%}
digit    [0-9]
alpha   [A-Za-z]
alpha_num   ({alpha}|{digit})
id (_|{alpha})+(_|{alpha}|{digit})*
keyword "program"|"var"|"array"|"of"|"function"|"and"|"procedure"|"begin"|"while"|"if"|"then"|"else"|"end"|"do"|"true"|"false"|"div"|"boolean"|"integer"|"real"
symbol ","|":"|";"|"."|"["|"]"|"("|")"|".."|"+"|"-"|"*"|"/"|"<"|">"|"<="|">="|"<>"|"="|":="
integer ({digit}+)
signed_integer  ("+"|"-")?{integer}
number {signed_integer}("."{integer})?(E{signed_integer})?
comment ("{"[^}\n]*"}")
whitespace ([ \t]+)

%%
"program" return PROGRAM;
"var" return VAR;
"if" return IF;
"then" return THEN;
"else" return ELSE;
"end" return END;
"do" return DO;
"true" return TRUE;
"false" return FALSE;
"div" return DIV;
"mod" return MOD;
"boolean" return BOOLEAN;
"integer" return INTEGER;
"array" return ARRAY;
"of" return OF;
"function" return FUNCTION;
"procedure" return PROCEDURE;
"and" return AND;
"or" return OR;
"not" return NOT;
"begin" return BEGINTOKEN;
"while" return WHILE;

"real" return REAL;
".." return DOUBLEDOT;
"=" return EQUAL;
":=" return ASSIGNMENT;
"," return COMMA;
":" return COLON;
";" return SEMICOLON;
"." return DOT;
"+" return PLUS;
"-" return MINUS;
"*" return MULTIPLICATION;
"/" return DIVISION;
"<" return LT;
">" return GT;
"<=" return LE;
">=" return GE;
"<>" return DIFFERENT;
"[" return SQ_BRACKET_OPEN;
"]" return SQ_BRACKET_CLOSE;
"(" return BRACKET_OPEN;
")" return BRACKET_CLOSE;

{number} return NUMBER;
{id} return IDENTIFIER;
{whitespace}+
{comment}
\n yylineno++;
. printf("Lexical error on line %d : %s\n", yylineno, yytext);

%%
