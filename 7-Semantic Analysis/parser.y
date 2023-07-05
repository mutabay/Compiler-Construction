%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"
#include "display_tree.h"
#include "semantic.h"
extern int yylineno;
extern char *yytext;

int yylex();
void yyerror(char *);

int global_block = 0;
SYMTABLE * symtable;

ENTRY *entry;

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


%}

%union {
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
}

%token			PROG
%token			VAR ARRAY TO OF
%token			FUNC PROC
%token			INT REAL BOOL
%token			START END
%token			IF THEN ELSE
%token			WHILE DO
%token <string>		IDENT
%token <number>		NUM
%token			COLON SCOLON COMMA DOT
%token			LBRA RBRA LPAR RPAR
%token			ASSIGN
%token			LT LE GT GE EQ NE
%token			PLUS MINUS TIMES SLASH DIV MOD
%token			NOT AND OR
%token			TRUE FALSE

%type <symtab>		varDec varDecList identListType identList type subProgHead args parList
%type <prog>		subProgList
%type <stmt>		compStmt stmtList stmt elsePart
%type <call_stmt>	subProgCall
%type <assign_stmt>	assStmt
%type <if_stmt>		ifStmt
%type <while_stmt>	whileStmt
%type <exp>		params exprList expr index simpleExpr term factor
%type <integer>		simpleType relOp addOp mulOp 

%start			program

%%

program: PROG IDENT SCOLON varDec subProgList compStmt DOT	{ ast->symtab = (ENTRY *) malloc(sizeof(ENTRY));
								  ast->symtab->data_type = _VOID;
								  ast->symtab->base.id = $2;
								  ast->symtab->ext.prog.par_list = 0;
								  ast->symtab->next = $4;
								  ast->stmt = $6;
								  ast->next = $5;
								}
		;

varDec: VAR varDecList						{ $$ = $2;
                                              global_block = 2; //from now every new declared variables will be inside a function
                                            }
		|						{ $$ = 0; }
		;
varDecList: varDecList identListType SCOLON			{ append_entry($1, $2); }
		| identListType SCOLON				{ $$ = $1; }
		;

identListType: identList COLON type				{ for(entry = $1; entry != 0; entry = entry->next) {
								    entry->typ = $3->typ;
								    entry->data_type = $3->data_type;
								    if($3->typ == _ARRAY) {
								      entry->ext.bounds.low = $3->ext.bounds.low;
								      entry->ext.bounds.upp = $3->ext.bounds.upp;
								    }
								  }
								  $$ = $1;
								  free($3);
								}
		;

identList: identList COMMA IDENT				{ $$ = (ENTRY *) malloc(sizeof(ENTRY));
								  $$->base.id = $3;
								  $$->next = $1;
								  SYMTABLE * var = (SYMTABLE *) malloc(sizeof(SYMTABLE));
                                  var->id = $3;
                                  var->block = global_block;
                                  append_to_symbol_table(var, yylineno);
								}
		| IDENT						{ $$ = (ENTRY *) malloc(sizeof(ENTRY));
								  $$->base.id = $1;
								  $$->next = 0;
								  SYMTABLE * var = (SYMTABLE *) malloc(sizeof(SYMTABLE));
								  var->id = $1;
								  var->block = global_block;
								  append_to_symbol_table(var, yylineno);
								}
		;

type: simpleType						{ $$ = (ENTRY *) malloc(sizeof(ENTRY));
								  $$->typ = _VAR;
								  $$->data_type = $1;
								}
		| ARRAY LBRA NUM TO NUM RBRA OF simpleType	{ $$ = (ENTRY *) malloc(sizeof(ENTRY));
								  $$->typ = _ARRAY;
								  $$->data_type = $8;
								  if ((int) $3 == $3 && (int) $5 == $5){
								     if ($3 > $5){
								        printf("Error on line %d : upper bound is lower than greater bound", yylineno);
								        exit(0);
								     }
								     else{
								     	$$->ext.bounds.low = (int) $3;
                                        $$->ext.bounds.upp = (int) $5;
								     }
								  }
								  else{
								    printf("Error on line %d : type of indexes must be integer", yylineno);
								    exit(0);
								  }
								}
		;

simpleType: INT							{ $$ = _INT; }
		| REAL						{ $$ = _REAL; }
	        | BOOL						{ $$ = _BOOL; }
		;

subProgList: subProgList subProgHead varDec compStmt SCOLON	{
                                  $$ = (N_PROG *) malloc(sizeof(N_PROG));
								  $$->symtab = $2;
								  $2->next = $3;
								  $$->stmt = $4;
								  $$->next = $1;
								}
		|						{

		                          $$ = 0;}
		;

subProgHead: FUNC IDENT args COLON type SCOLON			{ $$ = (ENTRY *) malloc(sizeof(ENTRY));
								  $$->typ = _PROG;
								  $$->data_type = $5->data_type;
								  $$->base.id = $2;
								  $$->ext.prog.par_list = $3;
								  $$->next = ast->symtab;
								  ast->symtab = $$;
								  SYMTABLE * var = (SYMTABLE *) malloc(sizeof(SYMTABLE));
                                  var->id = $2;
                                  var->block = 1;
                                  append_to_symbol_table(var, yylineno);
								}
		| PROC IDENT args SCOLON			{ $$ = (ENTRY *) malloc(sizeof(ENTRY));
								  $$->typ = _PROG;
								  $$->data_type = _VOID;
								  $$->base.id = $2;
								  $$->ext.prog.par_list = $3;
								  $$->next = ast->symtab;
								  ast->symtab = $$;
								  SYMTABLE * var = (SYMTABLE *) malloc(sizeof(SYMTABLE));
                                  var->id = $2;
                                  var->block = 1;
                                  append_to_symbol_table(var, yylineno);
								}
		;

args: LPAR parList RPAR						{ $$ = $2; }
		|						{ $$ = 0; }
		;

parList: parList SCOLON identListType				{ $$ = append_entry($1, $3); }
		| identListType					{ $$ = $1; }
		;

compStmt: START stmtList END			{ $$ = $2; }
		;

stmtList: stmtList SCOLON stmt			{ $$ = append_stmt($1, $3); }
		| stmt				{ $1->next = 0;
						  $$ = $1;
						}
		;

stmt: subProgCall				{ $$ =(N_STMT *) malloc(sizeof(N_STMT));
						  $$->typ = _PROC_CALL;
						  $$->node.proc_call = $1;
						}
		| assStmt			{ $$ = (N_STMT *) malloc(sizeof(N_STMT));
						  $$->typ = _ASSIGN;
						  $$->node.assign_stmt = $1;
						}
		| compStmt			{ $$ = $1; }
		| ifStmt			{ $$ = (N_STMT *) malloc(sizeof(N_STMT));
						  $$->typ = _IF;
						  $$->node.if_stmt = $1;
						}
		| whileStmt			{ $$ = (N_STMT *) malloc(sizeof(N_STMT));
						  $$->typ = _WHILE;
						  $$->node.while_stmt = $1;
						}
		;

subProgCall: IDENT				{
                          check_function_not_declared($1, yylineno);
                          $$ = (N_CALL *) malloc(sizeof(N_CALL *));
						  $$->id = $1;
						  $$->par_list = 0;
						}
		| IDENT params			{
		                  check_function_not_declared($1, yylineno);
		                  $$ = (N_CALL *) malloc(sizeof(N_CALL *));
						  $$->id = $1;
						  $$->par_list = $2;
						}
		;

params: LPAR exprList RPAR			{ $$ = $2; }
		;

assStmt: IDENT ASSIGN expr			{
                          check_variable_not_declared($1, global_block, yylineno);
                          $$ = (N_ASSIGN *) malloc(sizeof(N_ASSIGN));
						  $$->var_ref = (N_VAR_REF *) malloc(sizeof(N_VAR_REF));
						  $$->var_ref->id = $1;
						  $$->var_ref->index = 0;
						  $$->rhs_expr = $3;
						}
		| IDENT index ASSIGN expr	{
		                  check_variable_not_declared($1, global_block, yylineno);
		                  $$ = (N_ASSIGN *) malloc(sizeof(N_ASSIGN));
						  $$->var_ref = (N_VAR_REF *) malloc(sizeof(N_VAR_REF));
						  $$->var_ref->id = $1;
						  $$->var_ref->index = $2;
						  $$->rhs_expr = $4;
						}
		;

index: LBRA expr RBRA				{ $$ = $2; }
		| LBRA expr TO expr RBRA	{ $2->next = $4;
						  $4->next = 0;
						  $$ = $2;
						} 
		;

ifStmt: IF expr THEN stmt elsePart	{ $$ = (N_IF *) malloc(sizeof(N_IF));
					  $$->expr = $2;
					  $$->then_part = $4;
					  $$->else_part = $5;
					}
		;

elsePart: ELSE stmt			{ $$ = $2; }
		|			{ $$ = 0; }
		;

whileStmt: WHILE expr DO stmt		{ $$ = (N_WHILE *) malloc(sizeof(N_WHILE));
					  $$->expr = $2;
					  $$->stmt = $4;
					}
		;

exprList: exprList COMMA expr		{ $$ = append_expr($1, $3); }
		| expr			{ $1->next = 0;
                                          $$ = $1;
					}
		;

expr: simpleExpr relOp simpleExpr	{ $$ = (N_EXPR *) malloc(sizeof(N_EXPR));
					  $$->typ = OP;
					  $$->desc.operation.op = $2;
					  $$->desc.operation.expr = $1;
					  $$->desc.operation.expr->next = $3;
					}
		| simpleExpr		{ $$ = $1; }
		;

simpleExpr: simpleExpr addOp term	{
                      $$ = (N_EXPR *) malloc(sizeof(N_EXPR));
					  $$->typ = OP;
					  $$->desc.operation.op = $2;
					  $$->desc.operation.expr = $1;
					  $$->desc.operation.expr->next = $3;
					}
		| term			{ $$ = $1; }
		;

term: term mulOp factor			{ $$ = (N_EXPR *) malloc(sizeof(N_EXPR));
					  $$->typ = OP;
					  $$->desc.operation.op = $2;
					  $$->desc.operation.expr = $1;
					  $$->desc.operation.expr->next = $3;
					}
		| factor		{ $$ = $1; }
		;

factor: NUM				{ $$ = (N_EXPR *) malloc(sizeof(N_EXPR));
	                                  $$->typ = CONSTANT;
	                  char * temp = (char *) malloc(100);
	                  $$->desc.constant = (char *) malloc(100); /* ugly */
					  sprintf($$->desc.constant, "%f", $1);
					}
		| FALSE			{ $$ = (N_EXPR *) malloc(sizeof(N_EXPR));
					  $$->typ = CONSTANT;
					  $$->desc.constant = (char *) malloc(6 * sizeof(char));
					  strcpy($$->desc.constant, "FALSE");
					}
		| TRUE			{ $$ = (N_EXPR *) malloc(sizeof(N_EXPR));
					  $$->typ = CONSTANT;
					  $$->desc.constant = (char *) malloc(5 * sizeof(char));
					  strcpy($$->desc.constant, "TRUE");
					}
		| IDENT			{
		              check_variable_not_declared($1, global_block, yylineno);
		              $$ = (N_EXPR *) malloc(sizeof(N_EXPR));
					  $$->typ = VAR_REF;
					  $$->desc.var_ref = (N_VAR_REF *) malloc(sizeof(N_VAR_REF));
					  $$->desc.var_ref->id = $1;
					  $$->desc.var_ref->index = 0;
					}
		| IDENT	index		{
		              check_variable_not_declared($1, global_block, yylineno);
		              $$ = (N_EXPR *) malloc(sizeof(N_EXPR));
					  $$->typ = VAR_REF;
					  $$->desc.var_ref = (N_VAR_REF *) malloc(sizeof(N_VAR_REF));
					  $$->desc.var_ref->id = $1;
                      $$->desc.var_ref->index = $2;
					}
		| IDENT params		{
		              check_function_not_declared($1, yylineno);
		              $$ = (N_EXPR *) malloc(sizeof(N_EXPR));
					  $$->typ = FUNC_CALL;
					  $$->desc.func_call = (N_CALL *) malloc(sizeof(N_CALL));
					  $$->desc.func_call->id = $1;
                      $$->desc.func_call->par_list = $2;
					}
		| NOT factor		{ $$ = (N_EXPR *) malloc(sizeof(N_EXPR));
					  $$->typ = OP;
					  $$->desc.operation.op = NOT_OP;
					  $$->desc.operation.expr = $2;
					}
		| MINUS factor		{ $$ = (N_EXPR *) malloc(sizeof(N_EXPR));
					  $$->typ = OP;
					  $$->desc.operation.op = MINUS_OP;
					  $$->desc.operation.expr = $2;
					}
		| LPAR expr RPAR	{ $$ = (N_EXPR *) malloc(sizeof(N_EXPR));
					  $$->typ = OP;
					  $$->desc.operation.expr = $2;

					}
		;

relOp: LT				{ $$ = LT_OP; }
	|
	LE				{ $$ = LE_OP; }
	|
	GT				{ $$ = GT_OP; }
	|
	GE				{ $$ = GE_OP; }
	|
	EQ				{ $$ = EQ_OP; }
	|
	NE				{ $$ = NE_OP; }
	;

addOp: PLUS				{ $$ = PLUS_OP; }
	|
	MINUS				{ $$ = MINUS_OP; }
	|
	OR				{ $$ = OR_OP; }
	;

mulOp: TIMES				{ $$ = MULT_OP; }
	|
	SLASH				{ $$ = SLASH_OP; }
	|
	DIV				{ $$ = DIV_OP; }
	|
	MOD				{ $$ = MOD_OP; }
	|
	AND				{ $$ = AND_OP; }
	;

%%

void main() {
  ast = (N_PROG *) malloc(sizeof(N_PROG));
  yyparse();
  print_program(ast);
  free_symbol_table(symtable);
}

void yyerror(char *s) {
  printf("\%s in line %d: %s\n", s, yylineno, yytext);
  exit(1);
}

