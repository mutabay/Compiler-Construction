//
// Created by gville on 02/06/2023.
//

#ifndef TD7_SEMANTIC_H
#define TD7_SEMANTIC_H
typedef struct tSYMTABLE{
    char* id;
    union{
        int int_val;
        float real_val;
        BOOLEAN bool_val;
    } value;
    int block; //0 : main program block / 1: function block / 2 : block inside a function
    struct tSYMTABLE* next;
} SYMTABLE;

void free_symbol_table(SYMTABLE * var);
void print_symbol_table();
void append_to_symbol_table(SYMTABLE* var, int yylineno);
void append_multiple_to_symbol_table(ENTRY * node, int lign);
void check_variable_not_declared(char* var, int num_block, int lign);
void check_function_not_declared(char* var, int lign);
void remove_function_variables();
#endif //TD7_SEMANTIC_H
