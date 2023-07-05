#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "tokens.h"

int token;

char* value(int token)
{
    switch (token)
    {
        case IDENTIFIER: return "identifier";
        case NUMBER: return "number";
        case COMMENT : return "comment";
        case PROGRAM: return "program";
        case VAR: return "var";
        case ARRAY : return "array";
        case OF: return "of";
        case FUNCTION : return "function";
        case PROCEDURE: return "procedure";
        case AND: return "and";
        case OR : return "or";
        case NOT: return "not";
        case BEGINTOKEN : return "begin";
        case WHILE: return "while";
        case IF : return "if";
        case THEN: return "then";
        case ELSE: return "else";
        case END : return "end";
        case DO: return "do";
        case TRUE : return "true";
        case FALSE: return "false";
        case DIV: return "div";
        case MOD : return "mod";
        case BOOLEAN : return "boolean";
        case INTEGER: return "integer";
        case REAL : return "real";
        case COMMA: return ",";
        case COLON: return ":";
        case SEMICOLON : return ";";
        case DOT: return ".";
        case OPSQUBRACK : return "[";
        case CLSQUBRACK: return "]";
        case OPBRACKET: return "(";
        case CLBRACKET : return ")";
        case DOUBLEDOT: return "..";
        case PLUS : return "+";
        case MINUS: return "-";
        case TIMES: return "*";
        case DIVISION : return "/";
        case LT: return "<";
        case GT : return ">";
        case LE: return "<=";
        case GE: return ">=";
        case EQUAL : return "=";
        case DIFFERENT: return "<>";
        case ASSIGNMENT : return ":=";
        case ENDPROGRAM : return "error : end of the program"; // if this lign is executed, it means there is an error since getToken() has been called too many times
    }
    return "unknown token"; //lign never executed in theory
}

TokenSet first(char* nonTerminal){
    if (nonTerminal == "start"){
        TokenSet rep = {1, 0, {PROGRAM}};
        return rep;
    }
    if (nonTerminal == "varDec"){
        TokenSet rep = {1, 1, {VAR}};
        return rep;
    }
    if (nonTerminal == "varDecList"){
        TokenSet rep = {1, 0, {IDENTIFIER}};
        return rep;
    }
    if (nonTerminal == "identListType"){
        TokenSet rep = {1, 0, {IDENTIFIER}};
        return rep;
    }
    if (nonTerminal == "identList"){
        TokenSet rep = {1, 0, {IDENTIFIER}};
        return rep;
    }
    if (nonTerminal == "type"){
        TokenSet rep = {4, 0, {ARRAY, INTEGER, REAL, BOOLEAN}};
        return rep;
    }
    if (nonTerminal == "simpleType"){
        TokenSet rep = {3, 0, {INTEGER, REAL, BOOLEAN}};
        return rep;
    }
    if (nonTerminal == "subProgList"){
        TokenSet rep = {2, 1, {FUNCTION, PROCEDURE}};
        return rep;
    }
    if (nonTerminal == "subProgHead"){
        TokenSet rep = {2, 0, {FUNCTION, PROCEDURE}};
        return rep;
    }
    if (nonTerminal == "args"){
        TokenSet rep = {1, 1, {CLBRACKET}};
        return rep;
    }
    if (nonTerminal == "parList"){
        TokenSet rep = {1, 0, {IDENTIFIER}};
        return rep;
    }
    if (nonTerminal == "compStmt"){
        TokenSet rep = {1, 0, {BEGINTOKEN}};
        return rep;
    }
    if (nonTerminal == "stmtList"){
        TokenSet rep = {4, 0, {IDENTIFIER, BEGINTOKEN, IF, WHILE}};
        return rep;
    }
    if (nonTerminal == "statement"){
        TokenSet rep = {4, 0, {IDENTIFIER, BEGINTOKEN, IF, WHILE}};
        return rep;
    }
    if (nonTerminal == "statement1"){
        TokenSet rep = {3, 1, {ASSIGNMENT, OPBRACKET, OPSQUBRACK}};
        return rep;
    }
    if (nonTerminal == "pocCall"){
        TokenSet rep = {1, 1, {OPBRACKET}};
        return rep;
    }
    if (nonTerminal == "params"){
        TokenSet rep = {1, 0, {OPBRACKET}};
        return rep;
    }
    if (nonTerminal == "assignStmt"){
        TokenSet rep = {2, 0, {ASSIGNMENT, OPSQUBRACK}};
        return rep;
    }
    if (nonTerminal == "myIndex"){
        TokenSet rep = {1, 0, {OPSQUBRACK}};
        return rep;
    }
    if (nonTerminal == "myIndex1"){
        TokenSet rep = {2, 0, {CLSQUBRACK, DOUBLEDOT}};
        return rep;
    }
    if (nonTerminal == "ifStmt"){
        TokenSet rep = {1, 0, {IF}};
        return rep;
    }
    if (nonTerminal == "elsePart"){
        TokenSet rep = {1, 1, {ELSE}};
        return rep;
    }
    if (nonTerminal == "whileStmt"){
        TokenSet rep = {1, 0, {WHILE}};
        return rep;
    }
    if (nonTerminal == "exprList"){
        TokenSet rep = {7, 0, {NOT, MINUS, NUMBER, FALSE, TRUE, OPBRACKET, IDENTIFIER}};
        return rep;
    }
    if (nonTerminal == "expr"){
        TokenSet rep = {7, 0, {NOT, MINUS, NUMBER, FALSE, TRUE, OPBRACKET, IDENTIFIER}};
        return rep;
    }
    if (nonTerminal == "simpleExpr"){
        TokenSet rep = {7, 0, {NOT, MINUS, NUMBER, FALSE, TRUE, OPBRACKET, IDENTIFIER}};
        return rep;
    }
    if (nonTerminal == "term"){
        TokenSet rep = {7, 0, {NOT, MINUS, NUMBER, FALSE, TRUE, OPBRACKET, IDENTIFIER}};
        return rep;
    }
    if (nonTerminal == "factor"){
        TokenSet rep = {7, 0, {NOT, MINUS, NUMBER, FALSE, TRUE, OPBRACKET, IDENTIFIER}};
        return rep;
    }
    if (nonTerminal == "factor1"){
        TokenSet rep = {2, 1, {OPBRACKET, OPSQUBRACK}};
        return rep;
    }
    if (nonTerminal == "relOp"){
        TokenSet rep = {6, 0, {LT, LE, GT, GE, EQUAL, DIFFERENT}};
        return rep;
    }
    if (nonTerminal == "addOp"){
        TokenSet rep = {3, 0, {PLUS, MINUS, OR}};
        return rep;
    }
    if (nonTerminal == "mulOp"){
        TokenSet rep = {5, 0, {TIMES, DIVISION, DIV, MOD, AND}};
        return rep;
    }
    else{
        //in theory never executed
        Token* t;
        TokenSet rep = {t, 0, 0};
        return rep;
    }
}

TokenSet follow(char* nonTerminal){
    if (nonTerminal == "start"){
        TokenSet rep = {1, 0, {ENDPROGRAM}};
        //ENDPROGRAM is not a token but I added it in the Token enum type to facilitate programing
        return rep;
    }
    if (nonTerminal == "varDec"){
        TokenSet rep = {3, 0, {FUNCTION, PROCEDURE, BEGINTOKEN}};
        return rep;
    }
    if (nonTerminal == "varDecList"){
        TokenSet rep = {3, 0, {FUNCTION, PROCEDURE, BEGINTOKEN}};
        return rep;
    }
    if (nonTerminal == "identListType"){
        TokenSet rep = {2, 0, {SEMICOLON, CLBRACKET}};
        return rep;
    }
    if (nonTerminal == "identList"){
        TokenSet rep = {1, 0, {COLON}};
        return rep;
    }
    if (nonTerminal == "type"){
        TokenSet rep = {2, 0, {SEMICOLON, CLBRACKET}};
        return rep;
    }
    if (nonTerminal == "simpleType"){
        TokenSet rep = {2, 0, {SEMICOLON, CLBRACKET}};
        return rep;
    }
    if (nonTerminal == "subProgList"){
        TokenSet rep = {1, 0, {BEGINTOKEN}};
        return rep;
    }
    if (nonTerminal == "subProgHead"){
        TokenSet rep = {2, 0, {VAR, BEGINTOKEN}};
        return rep;
    }
    if (nonTerminal == "args"){
        TokenSet rep = {2, 0, {COLON, SEMICOLON}};
        return rep;
    }
    if (nonTerminal == "parList"){
        TokenSet rep = {1, 0, {CLBRACKET}};
        return rep;
    }
    if (nonTerminal == "compStmt"){
        TokenSet rep = {4, 0, {DOT, SEMICOLON, END, ELSE}};
        return rep;
    }
    if (nonTerminal == "stmtList"){
        TokenSet rep = {1, 0, {END}};
        return rep;
    }
    if (nonTerminal == "statement"){
        TokenSet rep = {3, 0, {SEMICOLON, END, ELSE}};
        return rep;
    }
    if (nonTerminal == "statement1"){
        TokenSet rep = {3, 0, {SEMICOLON, END, ELSE}};
        return rep;
    }
    if (nonTerminal == "pocCall"){
        TokenSet rep = {3, 0, {SEMICOLON, END, ELSE}};
        return rep;
    }
    if (nonTerminal == "params"){
        TokenSet rep = {23, 0, {SEMICOLON, END, TIMES, DIVISION, DIV, MOD, AND, CLSQUBRACK, DOUBLEDOT, THEN, DO, COMMA, CLBRACKET, LE, LT, GE, GT, EQUAL, DIFFERENT, PLUS, MINUS, OR, ELSE}};
        return rep;
    }
    if (nonTerminal == "assignStmt"){
        TokenSet rep = {3, 0, {SEMICOLON, END, ELSE}};
        return rep;
    }
    if (nonTerminal == "myIndex"){
        TokenSet rep = {24, 0, {ASSIGNMENT, SEMICOLON, END, TIMES, DIVISION, DIV, MOD, AND, CLSQUBRACK, DOUBLEDOT, THEN, DO, COMMA, CLBRACKET, LE, LT, GE, GT, EQUAL, DIFFERENT, PLUS, MINUS, OR, ELSE}};
        return rep;
    }
    if (nonTerminal == "myIndex1"){
        TokenSet rep = {24, 0, {ASSIGNMENT, SEMICOLON, END, TIMES, DIVISION, DIV, MOD, AND, CLSQUBRACK, DOUBLEDOT, THEN, DO, COMMA, CLBRACKET, LE, LT, GE, GT, EQUAL, DIFFERENT, PLUS, MINUS, OR, ELSE}};
        return rep;
    }
    if (nonTerminal == "ifStmt"){
        TokenSet rep = {3, 0, {SEMICOLON, END, ELSE}};
        return rep;
    }
    if (nonTerminal == "elsePart"){
        TokenSet rep = {3, 0, {SEMICOLON, END, ELSE}};
        return rep;
    }
    if (nonTerminal == "whileStmt"){
        TokenSet rep = {3, 0, {SEMICOLON, END, ELSE}};
        return rep;
    }
    if (nonTerminal == "exprList"){
        TokenSet rep = {1, 0, {CLBRACKET}};
        return rep;
    }
    if (nonTerminal == "expr"){
        TokenSet rep = {9, 0, {SEMICOLON, END, CLSQUBRACK, DOUBLEDOT, THEN, DO, COMMA, CLBRACKET, ELSE}};
        return rep;
    }
    if (nonTerminal == "simpleExpr"){
        TokenSet rep = {15, 0, {SEMICOLON, END, CLSQUBRACK, DOUBLEDOT, THEN, DO, COMMA, CLBRACKET, LT, LE, GT, GE, EQUAL, DIFFERENT, ELSE}};
        return rep;
    }
    if (nonTerminal == "term"){
        TokenSet rep = {18, 0, {SEMICOLON, END, CLSQUBRACK, DOUBLEDOT, THEN, DO, COMMA, CLBRACKET, LT, LE, GT, GE, EQUAL, DIFFERENT, ELSE, PLUS, MINUS, OR}};
        return rep;
    }
    if (nonTerminal == "factor"){
        TokenSet rep = {23, 0, {TIMES, DIVISION, DIV, MOD, AND, SEMICOLON, END, CLSQUBRACK, DOUBLEDOT, THEN, DO, COMMA, CLBRACKET, LT, LE, GT, GE, EQUAL, DIFFERENT, PLUS, MINUS, OR, ELSE }};
        return rep;
    }
    if (nonTerminal == "factor1"){
        TokenSet rep = {23, 0, {TIMES, DIVISION, DIV, MOD, AND, SEMICOLON, END, CLSQUBRACK, DOUBLEDOT, THEN, DO, COMMA, CLBRACKET, LT, LE, GT, GE, EQUAL, DIFFERENT, PLUS, MINUS, OR, ELSE }};
        return rep;
    }
    if (nonTerminal == "relOp"){
        TokenSet rep = {7, 0, {NOT, MINUS, NUMBER, FALSE, TRUE, OPBRACKET, IDENTIFIER}};
        return rep;
    }
    if (nonTerminal == "addOp"){
        TokenSet rep = {7, 0, {NOT, MINUS, NUMBER, FALSE, TRUE, OPBRACKET, IDENTIFIER}};
        return rep;
    }
    if (nonTerminal == "mulOp"){
        TokenSet rep = {7, 0, {NOT, MINUS, NUMBER, FALSE, TRUE, OPBRACKET, IDENTIFIER}};
        return rep;
    }
    else{
        //in theory never executed
        Token* t;
        TokenSet rep = {t, 0, 0};
        return rep;
    }
}



void error(char* expectedToken){
    printf("Error on line %d. Expected %s but found %s", yylineno, expectedToken, value(token));
    exit(0);
}

void match(int expectedToken){
    if (token==expectedToken){
        token = getToken();
    }
    else{
        error(value(expectedToken));
    }
}

void match_with_first_set(Token expected, Token *first_set, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (token == first_set[i]) {
            break;
        }
    }
    if (i == size) {
        fprintf(stderr, "Syntax error: line %d, expected one of: ", yylineno);
        for (i = 0; i < size; i++) {
            fprintf(stderr, "%s ", value(first_set[i]));
        }
        fprintf(stderr, "but found %s\n", value(token));
        exit(1);
    }
    if (token == expected) {
        token = yylex();
    } else {
        fprintf(stderr, "Syntax error: line %d, expected %s but found %s\n", yylineno, value(expected), value(token));
        exit(1);
    }
}

int getToken(){
    return yylex();
}
/*
void start(){
    match(PROGRAM);
    match(IDENTIFIER);
    match(SEMICOLON);
    varDec();
    subProgList();
    compStmt();
    match(DOT);
}
*/
void start() {
    Token first_set[] = {PROGRAM};
    match_with_first_set(PROGRAM, first_set, sizeof(first_set)/sizeof(first_set[0]));
    Token first_set2[] = {IDENTIFIER};
    match_with_first_set(IDENTIFIER, first_set2, sizeof(first_set2)/sizeof(first_set2[0]));
    Token first_set3[] = {SEMICOLON};
    match_with_first_set(SEMICOLON, first_set3, sizeof(first_set3)/sizeof(first_set3[0]));
    varDec();
    subProgList();
    compStmt();
    Token first_set4[] = {DOT};
    match_with_first_set(DOT, first_set4, sizeof(first_set4)/sizeof(first_set4[0]));
}

void varDec(){
    if (token == VAR){
        match(VAR);
        varDecList();
    }
}


void varDecList(){
    do {
        Token first_set[] = {IDENTIFIER};
        match_with_first_set(IDENTIFIER, first_set, sizeof(first_set)/sizeof(first_set[0]));
        Token first_set2[] = {COLON};
        match_with_first_set(COLON, first_set2, sizeof(first_set2)/sizeof(first_set2[0]));
        type();
        Token first_set3[] = {SEMICOLON, IDENTIFIER};
    } while(token == IDENTIFIER);
}


void identListType(){
    identList();
    match(COLON);
    type();
}

void identList(){
    match(IDENTIFIER);
    while (token == COMMA){
        match(COMMA);
        match(IDENTIFIER);
    }
}

void type(){
    if (token == INTEGER || token == REAL || token == BOOLEAN){
        match(token);
    }
    else if (token == ARRAY){
        match(ARRAY);
        match(OPSQUBRACK);
        match(NUMBER);
        match(DOUBLEDOT);
        match(NUMBER);
        match(CLSQUBRACK);
        match(OF);
        if (token == INTEGER || token == REAL || token == BOOLEAN){
            match(token);
        }
        else{
            error("integer, real or boolean");
        }
    }
    else{
        error("integer, real, boolean or array");
    }
}

void subProgList(){
    while (token == FUNCTION || token == PROCEDURE){
        subProgHead();
        varDec();
        compStmt();
        match(SEMICOLON);
    }
}

void subProgHead(){
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
        error("function or procedure");
    }
}

void args(){
    if (token == OPBRACKET){
        match(OPBRACKET);
        parList();
        match(CLBRACKET);
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
        error("identifier, begin, if or while");
    }
}

void statement1(){
    if (token == OPBRACKET){
        procCall();
    }
    else if (token == ASSIGNMENT || token == OPSQUBRACK){
        assignStmt();
    }
    else{
        error("(, := or [");
    }
}

void procCall(){
    if (token == OPBRACKET){
        params();
    }
}

void params(){
    match(OPBRACKET);
    exprList();
    match(CLBRACKET);
}

void assignStmt(){
    if (token == OPSQUBRACK){
        myIndex();
    }
    match(ASSIGNMENT);
    expr();
}

void myIndex(){
    match(OPSQUBRACK);
    expr();
    myIndex1();
}

void myIndex1(){
    if (token == CLSQUBRACK){
        match(CLSQUBRACK);
    }
    else if (token == DOUBLEDOT){
        match(DOUBLEDOT);
        expr();
        match(CLSQUBRACK);
    }
    else{
        error("] or ..");
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
    while (token == TIMES || token == DIVISION || token == DIV || token == MOD || token == AND){
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
    else if (token == OPBRACKET){
        match(OPBRACKET);
        expr();
        match(CLBRACKET);
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
    if (token == OPSQUBRACK){
        myIndex();
    }
    if (token == OPBRACKET){
        params();
    }
}

int main() {
    token = yylex();
    start();
    token = yylex();
    printf("%d", token==ENDPROGRAM);
    return 0;
}
