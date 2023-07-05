//
// Created by gville on 22.06.23.
//

#ifndef TD8_PRINT_ASSEMBLY_H
#define TD8_PRINT_ASSEMBLY_H
#include "ast.h"

void assignSymTable(ENTRY* entry);
void print_prog(N_PROG* ast);
void print_data(ENTRY* head);
char print_expr(N_EXPR* node);
void print_stmt(N_STMT* stmt);
void print_assign(N_ASSIGN* assign);
void print_while(N_WHILE* node);
void print_if(N_IF* node);
ENTRY* find_identifier(char* name);
void put_array_element_in_register(N_VAR_REF* var, ENTRY* entry);
void push_to_stack(char* reg);
void pop_from_stack(char* reg);

#endif //TD8_PRINT_ASSEMBLY_H
