#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "ast.h"
#include "display_tree.h"
#include "semantic.h"

extern SYMTABLE * symtable;
extern int global_block;

void free_symbol_table(SYMTABLE * var){
    if (var->next == 0){
        free(var);
    }
    else{
        free_symbol_table(var->next);
        free(var);
    }
}

void print_symbol_table(){
    SYMTABLE * it = symtable;
    printf("\n");
    printf("(%d, %s)\n", it->block, it->id);
    while(it->next != 0){
        it = it->next;
        printf("(%d, %s)\n", it->block, it->id);
    }
}

void append_to_symbol_table(SYMTABLE* var, int yylineno){
    if (var->block == 1){
        remove_function_variables();
    }
    if (symtable == 0){
        symtable = var;
    }
    else{
        SYMTABLE * it = symtable;
        if (strcmp(it->id, var->id) == 0 && it->block == var->block) {
            if (global_block == 1){
                print_symbol_table();
                printf("Error on line %d, function or procedure %s already declared.", yylineno, var->id);
                exit(0);
            }
            else{
                print_symbol_table();
                printf("Error on line %d, variable %s already declared.", yylineno, var->id);
                printf("(%d, %s)\n", var->block, var->id);
                exit(0);
            }
        }
        if (strcmp(it->id, var->id) == 0 && it->block == 1 && var->block == 2 && (it->next == 0 || it->next->block == 2)){ //we are inside the function whose name is overloaded
            print_symbol_table();
            printf("Error on line %d. The variable %s has the same name as the function inside which it is declared", yylineno, var->id);
            exit(0);
        }
        if (strcmp(it->id, var->id) == 0 && it->block == 0 && var->block == 1){ //we are declaring a function with the same name as a variable declared in the main block
            print_symbol_table();
            printf("Error on line %d. The function name %s is already the name of a variable declared in the main block.", yylineno, var->id);
            exit(0);
        }
        while(it->next != 0){
            it = it->next;
            if (strcmp(it->id, var->id) == 0 && it->block == var->block) {
                if (global_block == 1){
                    print_symbol_table();
                    printf("Error on line %d, function or procedure %s already declared.", yylineno, var->id);
                    exit(0);
                }
                else{
                    print_symbol_table();
                    printf("Error on line %d, variable %s already declared.", yylineno, var->id);
                    exit(0);
                }
            }
            if (strcmp(it->id, var->id) == 0 && it->block == 1 && var->block == 2 && (it->next == 0 || it->next->block == 2)){
                print_symbol_table();
                printf("Error on line %d. The variable %s has the same name as the function inside which it is declared", yylineno, var->id);
                exit(0);
            }
            if (strcmp(it->id, var->id) == 0 && it->block == 0 && var->block == 1){
                print_symbol_table();
                printf("Error on line %d. The function name %s is already the name of a variable declared in the main block.", yylineno, var->id);
                exit(0);
            }
        }
        it->next = var;
    }
}

void append_multiple_to_symbol_table(ENTRY * node, int lign){
    ENTRY * it = node;
    while (it != 0){
        ENTRY * temp = it;
        SYMTABLE * var = (SYMTABLE *) malloc(sizeof(SYMTABLE));
        var->id = temp->base.id;
        var->block = global_block;
        append_to_symbol_table(var, lign);
        it = it->next;
    }
}

void check_variable_not_declared(char* var, int num_block, int lign){
    if (symtable == 0){
        print_symbol_table();
        printf("Error on line %d, variable %s not declared.", lign, var);
        exit(0);
    }
    else{
        int trouve = 0;
        SYMTABLE * it = symtable;
        if (num_block == 0){
            if (strcmp(it->id, var) == 0 && it->block==0){
                trouve = 1;
            }
            while (trouve == 0 && it->next != 0){
                it = it->next;
                if (strcmp(it->id, var) == 0 && it->block==0){
                    trouve = 1;
                }
            }
        }
        else{
            //num_block == 2
            if (strcmp(it->id, var) == 0 && (it->block==0 || it->block==2 || (it->block==1 && it->next->block==2))){
                trouve = 1;
            }
            while (trouve == 0 && it->next != 0){
                it = it->next;
                if (strcmp(it->id, var) == 0 && (it->block==0 || it->block==2 || (it->block==1 && it->next->block==2))){
                    trouve = 1;
                }
            }
        }
        if (trouve == 0){
            print_symbol_table();
            printf("Error on line %d, variable %s not declared.", lign, var);
            exit(0);
        }
    }
}

void check_function_not_declared(char* var, int lign){
    if (symtable == 0){
        print_symbol_table();
        printf("Error on line %d, function or procedure %s not declared.", lign, var);
        exit(0);
    }
    else{
        int trouve = 0;
        SYMTABLE * it = symtable;
        if (it->block == 1 && strcmp(it->id, var) == 0){
            trouve = 1;
        }
        while (trouve == 0 && it->next != 0){
            it = it->next;
            if (it->block == 1 && strcmp(it->id, var) == 0){
                trouve = 1;
            }
        }
        if (trouve == 0){
            print_symbol_table();
            printf("Error on line %d, variable %s not declared.", lign, var);
            exit(0);
        }
    }
}

void remove_function_variables(){
    if (symtable != 0){
        SYMTABLE* it = symtable;
        while (it->next != 0 && it->next->block != 2){
            it = it->next;
        }
        if (it->next != 0){
            free_symbol_table(it->next);
        }
        it->next = NULL;
    }
}


