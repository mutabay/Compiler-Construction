//
// Created by Mustafa on 20.05.23.
//

#ifndef ABSTRACT_SYNTAX_TREE_VERIFY_H
#define ABSTRACT_SYNTAX_TREE_VERIFY_H


#include "ast.h"
#include "y.tab.h"
#include <stdio.h>
#include <string.h>

extern int yyparse();
extern N_PROG *ast;

_DATA_TYPE mainType;
char* inFun;
char* mainDef;
int indentLevel;
_DATA_TYPE returnType;

void printIndent();
char * typeToStr(_DATA_TYPE type);
char *operatorToStr(_OPERATOR o);
void printVarRef(N_VAR_REF *input);
void printIf(N_IF *input, int ignore_indent);
void printWhile(N_WHILE *input, int ignore_indent);
void printCall(N_CALL *input, char* separator, int ignore_indent);
void printAssign(N_ASSIGN *input, int ignore_indent);
void printStatement(N_STMT* input, int ignore_marker, int ignore_indent);
void printExpr(N_EXPR *input, char* separator);
void printEntry(ENTRY *input);
void printProgramBase(N_PROG *input);
void printProgram(N_PROG *input);
void printArgs(ENTRY *input);
void printOp(N_EXPR *input);
void printExprInner(N_EXPR *input, char* separator);
void run();


#endif //ABSTRACT_SYNTAX_TREE_VERIFY_H
