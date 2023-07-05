//
// Created by gville on 02/06/2023.
//

#ifndef TD7_DISPLAY_TREE_H
#define TD7_DISPLAY_TREE_H

void print_program(N_PROG *);
void print_var_decl(ENTRY *, char);
void print_type(DATA_TYPE);
void print_sub_program(N_PROG *);
void print_sub_prog_head(ENTRY *);
void print_cmp_stmt(N_STMT *);
void print_ident(N_VAR_REF *);
void print_assign(N_ASSIGN *);
void print_if(N_IF *);
void print_while(N_WHILE *);
void print_call(N_CALL *);
void print_expr_list(N_EXPR *, char);
void print_expr(N_EXPR *);
void print_op(int);

#endif //TD7_DISPLAY_TREE_H
