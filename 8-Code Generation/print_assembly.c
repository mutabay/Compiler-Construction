#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "print_assembly.h"

ENTRY* symTable;

void assignSymTable(ENTRY* entry){
    symTable = entry;
}

void print_prog(N_PROG* ast){
    printf(".data\n\n");
    print_data(ast->symtab->next);
    printf("\n.text\n.global main\n\nmain:\n");
    print_stmt(ast->stmt);
}

void print_data(ENTRY* head){
    while(head != 0){
        if (head->typ != _ARRAY){
            printf("%s:\t\t", head->base.id);
            switch(head->data_type){
                case _INT: printf(".word 0\n"); break;
                case _BOOL: printf(".byte 0\n"); break;
                case _REAL: printf(".float 0\n"); break;
            }
        }
        else{
            int size;
            switch(head->data_type){
                case _INT: size = 4; break;
                case _BOOL: size = 1; break;
                case _REAL: size = 8; break;
            }
            printf("%s:\t\t.space %d\n", head->base.id, (head->ext.bounds.upp - head->ext.bounds.low + 1) * size);
        }
        head = head->next;
    }
}

char print_expr(N_EXPR* node){
    if (node->typ == CONSTANT){
        char* value = node->desc.constant;
        if (strcmp(value, "TRUE") == 0){
            printf("li\t$t0, #1\n");
            return 't';
        }
        if (strcmp(value, "FALSE") == 0){
            printf("li\t$t0, #0\n");
            return 't';
        }
        float num = atof(value);
        int decimal = (int) (num * 10000) % 10000;
        if (decimal == 0){
            //the constant is an integer
            printf("li\t$t0, #%s\n", value);
            return 't';
        }
        else{
            //the constant is a real
            printf("li\t$f0, #%s\n", value);
            return 'f';
        }
    }
    else if (node->typ == VAR_REF){
        ENTRY* entry = find_identifier(node->desc.var_ref->id);
        char typ;
        if (entry->data_type==_INT||entry->data_type==_BOOL){
            typ='t';
        }
        else{
            typ='f';
        }
        if (node->desc.var_ref->index == NULL){
            printf("lw\t$%c0, %s\n", typ, node->desc.var_ref->id);
        }
        else{
            put_array_element_in_register(node->desc.var_ref, entry);
        }
        return typ;
    }
    else{
        //node->typ == OP
        if(node->desc.operation.expr->next != NULL){
            //two operands
            char typLeft = print_expr(node->desc.operation.expr);
            push_to_stack(typLeft == 't' ? "t0" : "f0");
            char typRight = print_expr(node->desc.operation.expr->next);
            pop_from_stack("t1");
            char typ;
            if (typLeft=='t' && typRight=='t'){
                typ = 't';
            }
            else{
                typ ='f';
            }
            switch (node->desc.operation.op) {
                case PLUS_OP :
                    printf("add\t$%c0, $%c0, $%c1\n", typ, typ, typ);
                    break;
                case MINUS_OP :
                    printf("sub\t$%c0, $%c0, $%c1\n", typ, typ, typ);
                    break;
                case MULT_OP :
                    printf("mul\t$%c0, $%c0, $%c1\n", typ, typ, typ);
                    break;
                case DIV_OP : {
                    printf("div\t$%c0, $%c1\n", typ, typ);
                    printf("mflo\t$%c0\n", typ);
                    break;
                }
                case MOD_OP : {
                    printf("div\t$%c0, $%c1\n", typ, typ);
                    printf("mfhi\t$%c0\n", typ);
                    break;
                }
                case EQ_OP :
                    printf("seq\t$%c0, $%c1, $%c0\n", typ, typ, typ);
                    break;
                case NE_OP :
                    printf("sne\t$%c0, $%c1, $%c0\n", typ, typ, typ);
                    break;
                case GE_OP :
                    printf("sge\t$%c0, $%c1, $%c0\n", typ, typ, typ);
                    break;
                case GT_OP :
                    printf("sgt\t$%c0, $%c1, $%c0\n", typ, typ, typ);
                    break;
                case LE_OP :
                    printf("sle\t$%c0, $%c1, $%c0\n", typ, typ, typ);
                    break;
                case LT_OP :
                    printf("slt\t$%c0, $%c1, $%c0\n", typ, typ, typ);
                    break;
                case AND_OP :
                    printf("and\t$%c0, $%c1, $%c0\n", typ, typ, typ);
                    break;
                case OR_OP :
                    printf("or\t$%c0, $%c1, $%c0\n", typ, typ, typ);
                    break;
                default: {
                    printf("error : invalid operand");
                    exit(1);
                }
            }
            return typ;
        }
        else{
            char typ = print_expr(node->desc.operation.expr);
            switch(node->desc.operation.op){
                case NOT_OP: printf("not\t$%c0 $%c0\n", typ, typ); break;
                case MINUS_OP : {
                    printf("li\t$t1 #-1\n");
                    printf("mult\t$%c0, $%c0, $t1\n", typ, typ);
                    break;
                }
            }
            return typ;
        }
    }
}

void print_stmt(N_STMT* stmt){
    while (stmt != 0){
        switch (stmt->typ){
            case _ASSIGN : print_assign(stmt->node.assign_stmt); break;
            case _IF : print_if(stmt->node.if_stmt); break;
            case _WHILE : print_while(stmt->node.while_stmt); break;
        }
        stmt = stmt->next;
    }
}

void print_assign(N_ASSIGN* assign){
    ENTRY* entry = find_identifier(assign->var_ref->id);
    char typ;
    if (assign->var_ref->index==0){
        typ = print_expr(assign->rhs_expr);
    }
    else{
        put_array_element_in_register(assign->var_ref, entry);

        if (entry->data_type==_INT||entry->data_type==_BOOL){
            typ='t';
        }
        else{
            typ='f';
        }
    }
    printf("sw\t$%c0, %s\n", typ, assign->var_ref->id);
}

void print_while(N_WHILE* node){
    char typ = print_expr(node->expr);
    printf("L1:\n");
    printf("beqz\t$t0, L2\n");
    print_stmt(node->stmt);
    printf("j\tL1\n");
    printf("L2:\n");
}

void print_if(N_IF* node){
    char typ = print_expr(node->expr);
    printf("beqz\t$t0, L1\n");
    print_stmt(node->then_part);
    printf("j\tL2\n");
    printf("L1:\n");
    print_stmt(node->else_part);
    printf("L2:\n");
}


ENTRY* find_identifier(char* name){
    ENTRY* node = symTable;
    while(node!=0){
        if (strcmp(node->base.id, name) == 0){
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void put_array_element_in_register(N_VAR_REF* var, ENTRY* entry){
    char typ;
    if (entry->data_type==_INT||entry->data_type==_BOOL){
        typ='t';
    }
    else{
        typ='f';
    }
    printf("la\t$gp, %s\n", var->id);
    print_expr(var->index);
    int lower_bound = entry->ext.bounds.low;
    printf("li\t$t1, #%d\n", lower_bound);
    printf("sub\t$t0, $t0, $t1\n");
    int size;
    switch(entry->data_type){
        case _BOOL: size=1; break;
        case _INT: size=4; break;
        case _REAL: size=8; break;
    }
    printf("li\t$t1, #%d\n", size);
    printf("mul\t$t0, $t0, $t1\n");
    printf("add\t$gp, $gp, $t0\n");
    printf("lw\t$%c0, 0($gp)\n", typ);
}

void push_to_stack(char* reg){
    printf("# push %s to stack\n", reg);
    printf("addi\t$sp, $sp, -4\n");
    printf("sw\t$%s, 0($sp)\n", reg);
}

void pop_from_stack(char* reg){
    printf("# pop from stack to %s\n", reg);
    printf("lw\t$%s, 0($sp)\n", reg);
    printf("addi\t$sp, $sp, 4\n");
}
