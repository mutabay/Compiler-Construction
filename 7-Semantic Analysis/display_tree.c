#include <stdio.h>
#include "ast.h"
#include "display_tree.h"

void print_program(N_PROG *prog) {
    N_PROG *sub_prog;
    printf("program %s;\n", prog->symtab->base.id);
    if(prog->symtab->next != 0) printf("var ");
    print_var_decl(prog->symtab->next, '\n');
    for(sub_prog = prog->next; sub_prog != 0; sub_prog = sub_prog->next)
        print_sub_program(sub_prog);
    print_cmp_stmt(prog->stmt);
    printf(".\n");
}


void print_var_decl(ENTRY *symtab, char sep) {
    while(symtab != 0) {
        printf("%s: ", symtab->base.id);
        if(symtab->typ == _ARRAY)
            printf("array[%d..%d] of ", symtab->ext.bounds.low, symtab->ext.bounds.upp);
        print_type(symtab->data_type);
        printf(";%c", sep);
        symtab = symtab->next;
    }
    printf("\n");
}


void print_type(DATA_TYPE data_type) {
    switch(data_type) {
        case _BOOL:  printf("boolean"); break;
        case _INT :  printf("integer"); break;
        case _REAL : printf("real");
    }
}

void print_sub_program(N_PROG *sub_prog) {
    printf("\n\n");
    print_sub_prog_head(sub_prog->symtab);
    if(sub_prog->symtab->next != 0) printf("var ");
    print_var_decl(sub_prog->symtab->next, '\n');
    print_cmp_stmt(sub_prog->stmt);
}



void print_sub_prog_head(ENTRY *head) {
    if(head->data_type == _VOID) printf("procedure ");
    else printf("function ");
    printf("%s", head->base.id);
    if(head->ext.prog.par_list != 0) {
        printf("(");
        print_var_decl(head->ext.prog.par_list, ' ');
        printf(")");
    }
    if(head->data_type != _VOID) {
        printf(": ");
        print_type(head->data_type);
    }
    printf(";\n");
}


void print_cmp_stmt(N_STMT *stmt) {
    printf("begin\n");
    while(stmt != 0) {
        switch(stmt->typ) {
            case _ASSIGN :	print_assign(stmt->node.assign_stmt); break;
            case _IF :		print_if(stmt->node.if_stmt); break;
            case _WHILE :	print_while(stmt->node.while_stmt); break;
            case _PROC_CALL :	print_call(stmt->node.proc_call); break;
        }
        stmt = stmt->next;
    }
    printf("end;\n");
}


void print_ident(N_VAR_REF *var) {
    printf("%s", var->id);
    if(var->index != 0) {
        printf("[");
        print_expr_list(var->index, ':');
        printf("]");
    }
}


void print_assign(N_ASSIGN *stmt) {
    print_ident(stmt->var_ref);
    printf(" := ");
    print_expr(stmt->rhs_expr);
    printf(";\n");
}


void print_if(N_IF *stmt) {
    printf("if(");
    print_expr(stmt->expr);
    printf(") then ");
    print_cmp_stmt(stmt->then_part);
    if(stmt->else_part != 0) {
        printf("else ");
        print_cmp_stmt(stmt->else_part);
    }
}


void print_while(N_WHILE *stmt) {
    printf("while(");
    print_expr(stmt->expr);
    printf(") do\n");
    print_cmp_stmt(stmt->stmt);
}


void print_call(N_CALL *stmt) {
    printf("%s", stmt->id);
    if(stmt->par_list != 0) {
        printf("(");
        print_expr_list(stmt->par_list, ',');
        printf(")");
    }
}


void print_expr_list(N_EXPR *expr, char sep) {
    while(expr != 0) {
        print_expr(expr);
        expr = expr->next;
        if(expr != 0) printf("%c ", sep);
    }
}


void print_expr(N_EXPR *expr) {
    switch(expr->typ) {
        case CONSTANT:
            printf("%s", expr->desc.constant);
            break;
        case VAR_REF:
            print_ident(expr->desc.var_ref);
            break;
        case OP: if(expr->desc.operation.expr->next != 0) {
                printf("(");
                print_expr(expr->desc.operation.expr);
                print_op(expr->desc.operation.op);
                print_expr(expr->desc.operation.expr->next);
                printf(")");
            } else {
                printf("(");
                print_op(expr->desc.operation.op);
                print_expr(expr->desc.operation.expr);
                printf(")");
            }
            break;
        case FUNC_CALL :
            print_call(expr->desc.func_call);
    }
}


void print_op(int op) {
    switch(op) {
        case NO_OP:		break;
        case EQ_OP:		printf(" = "); break;
        case NE_OP:		printf(" <> "); break;
        case GT_OP:		printf(" > "); break;
        case GE_OP:		printf(" >= "); break;
        case LT_OP:		printf(" < "); break;
        case LE_OP:		printf(" <= "); break;
        case PLUS_OP:		printf(" + "); break;
        case MINUS_OP:	printf(" - "); break;
        case MULT_OP:		printf(" * "); break;
        case SLASH_OP:	printf(" / "); break;
        case DIV_OP:		printf(" div "); break;
        case MOD_OP:		printf(" mod "); break;
        case AND_OP:		printf(" and "); break;
        case OR_OP:		printf(" or "); break;
        case NOT_OP:		printf("not "); break;
    }
}//
// Created by gville on 02/06/2023.
//

