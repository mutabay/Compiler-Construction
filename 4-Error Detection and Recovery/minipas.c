
#include <stdio.h>
#include "tokens.h"


extern int yylex();
extern int yylineno;
extern char *yytext;


Token token = ERROR;


Token first_sets[26][8] = { { PROG, ERROR },/* start */
			    { VAR, EPSILON, ERROR },/* var_dec */
			    { IDENT, ERROR },/* var_dec_list */
			    { IDENT, ERROR },/* ident_list_type */
			    { IDENT, ERROR },/* ident_list */
			    { ARRAY, INT, REAL, BOOL, ERROR },/* type */
			    { ARRAY, INT, REAL, BOOL, ERROR },/* simple_type */
			    { EPSILON, FUNC, PROC, ERROR },/* sub_prog_list */
			    { FUNC, PROC, ERROR },/* sub_prog_head */
			    { LPAR, EPSILON, ERROR },/* args */
			    { IDENT, ERROR },/* par_list */
			    { START, ERROR },/* comp_stmt */
			    { IDENT, START, IF, WHILE, ERROR },/* stmt_list */
			    { IDENT, START, IF, WHILE, ERROR },/* stmt */
			    { ASSIGN, LBRA, LPAR, EPSILON, ERROR },/* stmt_tail */
			    { LPAR, ERROR },/* params */
			    { LBRA, ERROR },/* array_index */
			    { RBRA, TO, ERROR},/*array_index_tail */
			    { IF, ERROR },/* if_stmt */
			    { WHILE, ERROR },/* while_stmt */
			    { NUM, FALSE, TRUE, IDENT, NOT, MINUS, LPAR, ERROR },/* exp_list */
			    { NUM, FALSE, TRUE, IDENT, NOT, MINUS, LPAR, ERROR },/* expr */
			    { NUM, FALSE, TRUE, IDENT, NOT, MINUS, LPAR, ERROR },/* simple_expr */
			    { NUM, FALSE, TRUE, IDENT, NOT, MINUS, LPAR, ERROR },/* term */
			    { NUM, FALSE, TRUE, IDENT, NOT, MINUS, LPAR, ERROR },/* factor */
			    { LBRA, LPAR, EPSILON, ERROR }/* factor_tail */
};


Token follow_sets[26][19] = { { EOF, ERROR },/* start */
			    { FUNC, PROC, START, ERROR },/* var_dec */
			    { FUNC, PROC, START, IDENT, ERROR },/* var_dec_list */
			    { SCOLON, RBRA, ERROR },/* ident_list_type */
			    { COLON, COMMA, ERROR },/* ident_list */
			    { SCOLON, RPAR, ERROR },/* type */
			    { SCOLON, RPAR, ERROR },/* simple_type */
			    { FUNC, PROC, ERROR },/* sub_prog_list */
			    { VAR, START, ERROR },/* sub_prog_head */
			    { RPAR, EPSILON, ERROR },/* args */
			    { RPAR, SCOLON, ERROR },/* par_list */
			    { END, ERROR },/* comp_stmt */
			    { END, SCOLON, ERROR },/* stmt_list */
			    { END, SCOLON, ELSE, ERROR },/* stmt */ 
			    { END, SCOLON, ELSE, ERROR },/* stmt_tail */
			    { END, SCOLON, ELSE, ERROR },/* params */
			    { END, SCOLON, RBRA, TO, ERROR },/* array_index */
			    { END, SCOLON, RBRA, TO, ERROR },/* array_index_tail */
			    { END, SCOLON, ELSE, ERROR },/* if_stmt */
			    { END, SCOLON, ELSE, ERROR },/* while_stmt */
			    { RBRA, COMMA, ERROR },/* exp_list */
			    { END, SCOLON, RBRA, TO, THEN, DO, COMMA, ELSE, ERROR },/* expr */
			    { END, SCOLON, RBRA, TO, THEN, DO, LT, LE, GT, GE, EQ, NE, PLUS, MINUS, OR, ERROR },/* simple_type */
			    { END, SCOLON, RBRA, DO, LT, LE, GT, GE, EQ, NE, PLUS, MINUS, OR, TIMES, SLASH, DIV, MOD, AND, ERROR },/* term */
			    { END, SCOLON, RBRA, DO, LT, LE, GT, GE, EQ, NE, PLUS, MINUS, OR, TIMES, SLASH, DIV, MOD, AND, ERROR },/* factor */
			    { END, SCOLON, RBRA, DO, LT, LE, GT, GE, EQ, NE, PLUS, MINUS, OR, TIMES, SLASH, DIV, MOD, AND, ERROR },/* factor_tail */
};


void program();
void var_dec();
void var_dec_list();
void ident_list_type();
void ident_list();
void type();
void simple_type();
void sub_prog_list();
void sub_prog_head();
void args();
void par_list();
void comp_stmt();
void stmt_list();
void stmt();
void stmt_tail();
void params();
void array_index();
void array_index_tail();
void if_stmt();
void while_stmt();
void expr_list();
void expr();
void simple_expr();
void term();
void factor();
void factor_tail();
void check_input(Token[], Token[]);
int is_member(Token, Token[]);
void match(Token);
char *token2string(Token);


void program() {
  check_input(first_sets[0], follow_sets[0]);
  if(is_member(token, first_sets[0])) {
    match(PROG);
    match(IDENT);
    match(SCOLON);
    var_dec();
    sub_prog_list();
    comp_stmt();
    match(DOT);
  }
}


void var_dec() {
  check_input(first_sets[1], follow_sets[1]);
  if(is_member(token, first_sets[1]))
    if(token == VAR) {
      match(VAR);
      var_dec_list();
    }
}


void var_dec_list() {
  check_input(first_sets[2], follow_sets[2]);
  if(is_member(token, first_sets[2]))
    do {
      ident_list_type();
      match(SCOLON);
    } while(token == IDENT);
}


void ident_list_type() {
  check_input(first_sets[3], follow_sets[3]);
  if(is_member(token, first_sets[3])) {
    ident_list();
    match(COLON);
    type();
  }
}


void ident_list() {
  check_input(first_sets[4], follow_sets[4]);
  if(is_member(token, first_sets[4])) {
    match(IDENT);
    while(token == COMMA) {
      match(COMMA);
      match(IDENT);
    }
  }
}


void type() {
  check_input(first_sets[5], follow_sets[5]);
  if(is_member(token, first_sets[5]))
    if(token == ARRAY) {
      match(ARRAY);
      match(LBRA);
      match(NUM);
      match(TO);
      match(NUM);
      match(RBRA);
      match(OF);
      simple_type();
    } else simple_type();
}


void simple_type() {
  check_input(first_sets[6], follow_sets[6]);
  if(is_member(token, first_sets[6]))
    switch(token) {
    case INT  : match(INT); break;
    case REAL : match(REAL); break;
    default   : match(BOOL);
    }
}


void sub_prog_list() {
  check_input(first_sets[7], follow_sets[7]);
  if(is_member(token, first_sets[7]))
    while(token == FUNC || token == PROC) {
      sub_prog_head();
      var_dec();
      comp_stmt();
      match(SCOLON);
    }
}


void sub_prog_head() {
  check_input(first_sets[8], follow_sets[8]);
  if(is_member(token, first_sets[8]))
    if(token == FUNC) {
      match(FUNC);
      match(IDENT);
      args();
      match(COLON);
      type();
      match(SCOLON);
    } else {
      match(PROC);
      match(IDENT);
      args();
      match(SCOLON);
    }
}


void args() {
  check_input(first_sets[9], follow_sets[9]);
  if(is_member(token, first_sets[9]))
    if(token == LPAR) {
      match(LPAR);
      par_list();
      match(RPAR);
    }
}


void par_list() {
  check_input(first_sets[10], follow_sets[10]);
  if(is_member(token, first_sets[10])) {
    ident_list_type();
    while(token == SCOLON) {
      match(SCOLON);
      ident_list_type();
    }
  }
}


void comp_stmt() {
  check_input(first_sets[11], follow_sets[11]);
  if(is_member(token, first_sets[11])) {
    match(START);
    stmt_list();
    match(END);
  }
}


void stmt_list() {
  check_input(first_sets[12], follow_sets[12]);
  if(is_member(token, first_sets[12])) {
    stmt();
    while(token == SCOLON) {
      match(SCOLON);
      stmt();
    }
  }
}


void stmt() {
  check_input(first_sets[13], follow_sets[13]);
  if(is_member(token, first_sets[13]))
    switch(token) {
    case IDENT :
      match(IDENT);
      stmt_tail();
      break;
    case START:
      comp_stmt();
      break;
    case IF:
      if_stmt();
      break;
    case WHILE:
      while_stmt();
    }
}


void stmt_tail() {
  check_input(first_sets[14], follow_sets[14]);
  if(is_member(token, first_sets[14]))
    switch(token) {
    case ASSIGN :
      match(ASSIGN);
      expr();
      break;
    case LBRA :
      array_index();
      match(ASSIGN);
      expr();
      break;
    case LPAR :
      params();
    }
}


void params() {
  check_input(first_sets[15], follow_sets[15]);
  if(is_member(token, first_sets[15])) {
    match(LPAR);
    expr_list();
    match(RPAR);
  }
}


void array_index() {
  check_input(first_sets[16], follow_sets[16]);
  if(is_member(token, first_sets[16])) {
    match(LBRA);
    expr();
    array_index_tail();
  }
}


void array_index_tail() {
  check_input(first_sets[17], follow_sets[17]);
  if(is_member(token, first_sets[17]))
    if(token == RBRA)
      match(RBRA);
    else {
      match(TO);
      expr();
      match(RBRA);
    }
}


void if_stmt() {
  check_input(first_sets[18], follow_sets[18]);
  if(is_member(token, first_sets[18])) {
    match(IF);
    expr();
    match(THEN);
    stmt();
    if(token == ELSE) {
      match(ELSE);
      stmt();  
    }
  }
}


void while_stmt() {
  check_input(first_sets[19], follow_sets[19]);
  if(is_member(token, first_sets[19])) {
    match(WHILE);
    expr();
    match(DO);
    stmt();
  }
}


void expr_list() {
  check_input(first_sets[20], follow_sets[20]);
  if(is_member(token, first_sets[20])) {
    expr();
    while(token == COMMA) {
      match(COMMA);
      expr();
    }
  }
}


void expr() {
  check_input(first_sets[21], follow_sets[21]);
  if(is_member(token, first_sets[21])) {
    simple_expr();
    if(token == LT || token == LE || token == GT || token == GE || token == EQ || token == NE) {
      match(token);
      simple_expr();
    }
  }
}


void simple_expr() {
  check_input(first_sets[22], follow_sets[22]);
  if(is_member(token, first_sets[22])) {
    term();
    while(token == PLUS || token == MINUS || token == OR) {
      match(token);
      term();
    }
  }
}


void term() {
  check_input(first_sets[23], follow_sets[23]);
  if(is_member(token, first_sets[23])) {
    factor();
    while(token == TIMES || token == SLASH || token == DIV || token == MOD || token == AND) {
      match(token);
      factor();
    }
  }
}


void factor() {
  check_input(first_sets[24], follow_sets[24]);
  if(is_member(token, first_sets[24]))
    switch(token) {
    case NUM:
    case FALSE :
    case TRUE :
      match(token);
      break;
    case IDENT:
      match(IDENT);
      factor_tail();
      break;
    case NOT:
      match(NOT);
      factor();
      break;
    case MINUS :
      match(MINUS);
      factor();
      break;
    default:
      match(LPAR);
      expr();
      match(RPAR);
    }
}


void factor_tail() {
  check_input(first_sets[25], follow_sets[25]);
  if(is_member(token, first_sets[25]))
    if(token == LBRA)
      array_index();
    else if(token == LPAR)
      params();
}


void check_input(Token first_set[], Token follow_set[]) {
  int i;
  if(! is_member(token, first_set) && ! is_member(EPSILON, first_set)) {
    fprintf(stderr, "Syntax error in line %d: token %s is not part of the expected first set: {", yylineno, yytext);
    for(i = 0; first_set[i] != ERROR; i++)
      printf(" %s", token2string(first_set[i]));
    puts(" }");
    while(! is_member(token, first_set) && ! is_member(token, follow_set))
      token = yylex();
  }
}


int is_member(Token token, Token first_set[]) {
  int i;
  for(i = 0; first_set[i] != ERROR; i++)
    if(token == first_set[i])
      return 1;
  return 0;
}


void match(Token expected_token) {
  if(token == expected_token)
    token = yylex();
  else {
    fprintf(stderr, "Syntax error in line %d: illegal token %s; expected token: %s\n", yylineno, yytext, token2string(expected_token));
  }
}


char *token2string(Token token) {
  switch(token) {
  case PROG    : return "program";
  case VAR     : return "var";
  case ARRAY   : return "array";
  case TO      : return "to";
  case OF      : return "of";
  case FUNC    : return "function";
  case PROC    : return "procedure";
  case INT     : return "integer";
  case REAL    : return "real";
  case BOOL    : return "boolean";
  case START   : return "begin";
  case END     : return "end";
  case IF      : return "if";
  case THEN    : return "then";
  case ELSE    : return "else";
  case WHILE   : return "while";
  case DO      : return "do";
  case NOT     : return "!";
  case AND     : return "and";
  case OR      : return "or";
  case DIV     : return "div";
  case MOD     : return "mod";
  case IDENT   : return "identifier";
  case NUM     : return "number";
  case COLON   : return ":";
  case SCOLON  : return ";";
  case COMMA   : return ",";
  case DOT     : return ".";
  case LBRA    : return "[";
  case RBRA    : return "]";
  case LPAR    : return "(";
  case RPAR    : return ")";
  case ASSIGN  : return ":=";
  case LT      : return ",";
  case LE      : return "<=";
  case GT      : return ">";
  case GE      : return ">=";
  case EQ      : return "=";
  case NE      : return "<>";
  case PLUS    : return "+";
  case MINUS   : return "-";
  case TIMES   : return "*";
  case SLASH   : return "/";
  case TRUE    : return "true";
  case FALSE   : return "false";
  case EPSILON : return "";
  default      : return "error";
  }
}


int main(int argc, char** argv) {
  token = yylex();
  program();
}
