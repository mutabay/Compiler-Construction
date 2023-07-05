%{
#include <stdio.h>
#include <stdlib.h>

int labelCount = 1;
int buffer = 10;


void Print3AddressCode(const char* op, const char* element1, const char* element2, const char* result) {
    printf("%s=%s%s%s\n", result, element1, op, element2);
}

%}

%union {
    int num;
    char* id;
}

%token <num> NUMBER
%token LPAR RPAR PLUS MINUS MULTIPLY DIVIDE
%token EOL

%type <id> expression term factor

%start program

%%


program: expression EOL {
    printf("-------EOL-------");
}

expression: term {
    $$ = $1;
}

expression: expression PLUS term {
    char* temp = (char*)malloc(sizeof(char) * buffer);
    snprintf(temp, buffer, "t%d", labelCount++);
    Print3AddressCode("+", $1, $3, temp);
    $$ = temp;
}

expression: expression MINUS term {
    char* temp = (char*)malloc(sizeof(char) * buffer);
    snprintf(temp, buffer, "t%d", labelCount++);
    Print3AddressCode("-", $1, $3, temp);
    $$ = temp;
}

term: factor {
    $$ = $1;
}

term: term MULTIPLY factor {
    char* temp = (char*)malloc(sizeof(char) * buffer);
    snprintf(temp, buffer, "t%d", labelCount++);
    Print3AddressCode("*", $1, $3, temp);
    $$ = temp;
}

term: term DIVIDE factor {
    char* temp = (char*)malloc(sizeof(char) * buffer);
    snprintf(temp, buffer, "t%d", labelCount++);
    Print3AddressCode("/", $1, $3, temp);
    $$ = temp;
}

factor: NUMBER {
    char* temp = (char*)malloc(sizeof(char) * buffer);
    snprintf(temp, buffer, "%d", $1);
    $$ = temp;
}

factor: LPAR expression RPAR {
    $$ = $2;
}

%%

int main() {
    printf("Please Enter the expression\n");
    printf("Three-address code\n");
    yyparse();

    return 0;
}

int yyerror(const char* msg) {
    fprintf(stderr, "Error: %s\n", msg);
    return 0;
}
