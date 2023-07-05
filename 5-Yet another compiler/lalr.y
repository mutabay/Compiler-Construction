%{ 
#include <stdio.h>

int yyerror(char *s);
extern int yylex();
extern int yylineno;
extern char* yytext;

%}

%token	PROGRAM VAR INTEGER ARRAY OF REAL FUNCTION BEGIN_TOKEN WHILE DO IF THEN ELSE END BOOLEAN BOOL_FALSE BOOL_TRUE PROCEDURE DIV GREATER LESS LESS_EQUAL GREATER_EQUAL NOT_EQUAL EQUAL PLUS MINUS DIVISION MULTIPLICATION SQUARE_BRACKETS_OPEN SQUARE_BRACKETS_CLOSE BRACKETS_OPEN BRACKETS_CLOSE DOT COLON ASSIGNMENT SEMICOLON COMMA DOUBLE_DOTS IDENTIFIER NUMBER NOT MOD AND OR DOLLAR
%start	start

%%

start			: PROGRAM IDENTIFIER SEMICOLON varDec subProgList compStmt DOT;
varDec			: | VAR varDecList;
varDecList		: varDecList identListType SEMICOLON | identListType SEMICOLON;
subProgList		: | subProgList subProgHead varDec compStmt SEMICOLON;
subProgHead		: FUNCTION IDENTIFIER args COLON type SEMICOLON| PROCEDURE IDENTIFIER args SEMICOLON;
identListType		: identList COLON type;
identList		: identList COMMA IDENTIFIER | IDENTIFIER;
type			: simpleType
			| ARRAY SQUARE_BRACKETS_OPEN NUMBER DOUBLE_DOTS NUMBER SQUARE_BRACKETS_CLOSE OF simpleType;
simpleType		: INTEGER | REAL| BOOLEAN;
args			: | BRACKETS_OPEN parList BRACKETS_CLOSE;
parList			: parList SEMICOLON identListType | identListType;
compStmt		: BEGIN_TOKEN stmtList END;
stmtList		: stmtList SEMICOLON statement | statement;
statement		: IDENTIFIER procCallOrAssign | compStmt | ifStmt | whileStmt;
procCallOrAssign	: | params | assignStmt ;
params			: BRACKETS_OPEN exprList BRACKETS_CLOSE;
exprList		: | exprList COMMA expr | expr;
assignStmt		: ASSIGNMENT expr | index ASSIGNMENT expr;
index			: SQUARE_BRACKETS_OPEN expr index2;
index2			: SQUARE_BRACKETS_CLOSE | DOUBLE_DOTS expr SQUARE_BRACKETS_CLOSE;
ifStmt			: IF expr THEN statement elsePart;
elsePart		: | ELSE statement;
whileStmt		: WHILE expr DO statement;
expr			: simpleExpr expr2;
expr2			: | relOp simpleExpr;
simpleExpr		: simpleExpr addOp term | term ;
term			: term mulOp factor | factor;
factor			: NUMBER | BOOL_FALSE | BOOL_TRUE | IDENTIFIER factor2 | NOT factor
				| MINUS factor
				| BRACKETS_OPEN expr BRACKETS_CLOSE
				;
factor2			: | index | params;
relOp			: LESS | LESS_EQUAL | GREATER | GREATER_EQUAL | EQUAL | NOT_EQUAL;
addOp			: PLUS | MINUS | OR ;
mulOp			: MULTIPLICATION | DIVISION | DIV | MOD | AND ;

%%
int main() { return yyparse(); }

int yyerror(char *s) { 
	fprintf(stderr, "%s\n", s); 
 	printf("Unexpected token [%s] on line %d\n", yytext, yylineno);
	return 0; 
}