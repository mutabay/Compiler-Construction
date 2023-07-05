%{
#include "tokens.h"

%}

%option yylineno

%%

program		return PROG;

var			return VAR;
array			return ARRAY;
".."			return TO;
of			return OF;

integer		return INT;
real			return REAL;
boolean		return BOOL;

function		return FUNC;
procedure		return PROC;

begin			return START;
end			return END;

if			return IF;
then			return THEN;
else			return ELSE;

while			return WHILE;
do			return DO;

true        	return TRUE;
false       	return FALSE;

:			return COLON;
;			return SCOLON;
,			return COMMA;
"."			return DOT;

"["			return LBRA;
"]"			return RBRA;
"("			return LPAR;
")"			return RPAR;

":="			return ASSIGN;

"<"			return LT;
"<="			return LE;
">"			return GT;
">="			return GE;
"="			return EQ;
"<>"			return NE;

"+"			return PLUS;
"-"			return MINUS;
"*"			return TIMES;
"/"			return SLASH;
"div"			return DIV;
"mod"			return MOD;

"not"			return NOT;
"and"			return AND;
"or"			return OR;

[0-9]+("."[0-9]+)?	return NUM;
[a-zA-Z][a-zA-Z_0-9]*	return IDENT;

[ \t\r\n]+
"{"[^"}"]*"}"

%%

