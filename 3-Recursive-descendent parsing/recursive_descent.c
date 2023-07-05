//
// Created by mutabay on 18.04.23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexical.yy.c"

// function prototypes
void match(int expectedToken);

void start();
void varDec();
void varDecList();
void identListType();
void identList();
void type();
void subProgList();
void subProgHead();
void args();
void parList();
void compStmt();
void stmtList();
void statement();
void statement1();
void params();
void assignStmt();
void myIndex();
void myIndex1();
void ifStmt();
void whileStmt();
void exprList();
void expr();
void simpleExpr();
void term();
void factor();
void factor1();
int lookahead;

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s input_file\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    yyin = input_file;

    token = yylex();

    start();

    fclose(input_file);

    return 0;
}

void match(int expected_token) {
    if (token==expectedToken){
        token = getToken();
    }
    else{
        printf("Syntax error: unexpected token '%s'\n", yytext);
        exit(1);
    }
}

void start() {
    match(PROGRAM);
    match(IDENTIFIER);
    match(SEMICOLON);
    varDec();
    subProgList();
    compStmt();
    match(DOT);
}

void varDec() {
    if (token == VAR){
        match(VAR);
        varDecList();
    }
}

void varDecList() {
    identListType();
    match(SEMICOLON);
    while (token == IDENTIFIER){
        identListType();
        match(SEMICOLON);
    }
}

void identListType() {
    identList();
    match(COLON);
    type();
}

void identList() {
    match(IDENTIFIER);
    while (token == COMMA){
        match(COMMA);
        match(IDENTIFIER);
    }
}

void type() {
    if (token == INTEGER || token == REAL || token == BOOLEAN){
        match(token);
    }
    else if (token == ARRAY){
        match(ARRAY);
        match(SQ_BRACKET_OPEN);
        match(NUMBER);
        match(DOUBLEDOT);
        match(NUMBER);
        match(BRACKET_CLOSE);
        match(OF);
        if (token == INTEGER || token == REAL || token == BOOLEAN){
            match(token);
        }
        else{
            printf("Syntax error: unexpected token [number]'%s'\n", token);
            exit(1);
        }
    }
    else{
        eprintf("Syntax error: unexpected token [number] '%s'\n", token);
        exit(1);
    }
}

void simpleType() {
    if (lookahead == INTEGER || lookahead == REAL || lookahead == BOOLEAN) {
        match(lookahead);
    } else {
        printf("Syntax error: unexpected token '%s'\n", yytext);
        exit(1);
    }
}

void subProgList() {
    while (token == FUNCTION || token == PROCEDURE){
        subProgHead();
        varDec();
        compStmt();
        match(SEMICOLON);
    }
}

void subProgHead() {
    if (token == FUNCTION){
        match(FUNCTION);
        match(IDENTIFIER);
        args();
        match(COLON);
        type();
        match(SEMICOLON);
    }
    else if (token == PROCEDURE){
        match(PROCEDURE);
        match(IDENTIFIER);
        args();
        match(SEMICOLON);
    }
    else{
        printf("Syntax error: unexpected token [Function or procedure]'%s'\n", yytext);
        exit(1);
    }
    simpleType();
}

void args(){
    if (token == BRACKET_OPEN){
        match(BRACKET_OPEN);
        parList();
        match(BRACKET_CLOSE);
    }
}

void parList(){
    identListType();
    while (token == SEMICOLON){
        match(SEMICOLON);
        identListType();
    }
}

void compStmt(){
    match(BEGINTOKEN);
    stmtList();
    match(END);
}

void stmtList(){
    statement();
    while (token == SEMICOLON){
        match(SEMICOLON);
        statement();
    }
}
void statement(){
    if (token == IDENTIFIER){
        match(IDENTIFIER);
        statement1();
    }
    else if (token == BEGINTOKEN){
        compStmt();
    }
    else if (token == IF){
        ifStmt();
    }
    else if (token == WHILE){
        whileStmt();
    }
    else{
        printf("Syntax error: unexpected token '%s'\n", yytext);
        exit(1);
    }
}
void statement1(){
    if (token == BRACKET_OPEN){
        params();
    }
    else if (token == ASSIGNMENT || token == SQ_BRACKET_OPEN){
        assignStmt();
    }
}
void params(){
    match(BRACKET_OPEN);
    exprList();
    match(BRACKET_CLOSE);
}

void assignStmt(){
    if (token == ASSIGNMENT){
        match(ASSIGNMENT);
        expr();
    }
    else if (token == SQ_BRACKET_OPEN){
        myIndex();
        match(ASSIGNMENT);
        expr();
    }
    else{
        error(":= or [");
    }
};

void myIndex(){
    match(SQ_BRACKET_OPEN);
    expr();
    myIndex1();
}

void myIndex1(){
    if (token == BRACKET_CLOSE){
        match(BRACKET_CLOSE);
    }
    else if (token == DOUBLEDOT){
        match(DOUBLEDOT);
        expr();
        match(BRACKET_CLOSE);
    }
}

void ifStmt(){
    match(IF);
    expr();
    match(THEN);
    statement();
    if (token == ELSE){
        match(ELSE);
        statement();
    }
}

void whileStmt(){
    match(WHILE);
    expr();
    match(DO);
    statement();
}

void exprList(){
    expr();
    while (token == COMMA){
        match(COMMA);
        expr();
    }
}

void expr(){
    simpleExpr();
    if (token == LT || token == GT || token == LE || token == GE || token == EQUAL || token == DIFFERENT){
        match(token);
        simpleExpr();
    }
}

void simpleExpr(){
    term();
    while (token == PLUS || token == MINUS || token == OR){
        match(token);
        term();
    }
}

void term(){
    factor();
    while (token == MULTIPLICATION || token == DIVISION || token == DIV || token == MOD || token == AND){
        match(token);
        factor();
    }
}

void factor(){
    while (token == NOT || token == MINUS){
        match(token);
    }
    if (token == NUMBER || token == FALSE || token == TRUE){
        match(token);
    }
    else if (token == BRACKET_OPEN){
        match(BRACKET_OPEN);
        expr();
        match(BRACKET_CLOSE);
    }
    else if (token == IDENTIFIER){
        match(IDENTIFIER);
        factor1();
    }
    else{
        error("number, identifier, true, false or (");
    }
}

void factor1(){
    if (token == SQ_BRACKET_OPEN){
        myIndex();
    }
    if (token == BRACKET_OPEN){
        params();
    }
}

