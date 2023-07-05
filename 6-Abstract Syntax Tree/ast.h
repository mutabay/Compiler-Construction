
/* Abstract Syntax Tree (AST) for Mini-Pascal */

typedef enum { _FALSE=0, _TRUE } _BOOLEAN;
typedef enum { _BOOL=0, _INT, _REAL, _VOID, _MAIN} _DATA_TYPE;
typedef enum { NO_OP=0, EQ_OP, NEQ_OP, GT_OP, GEQ_OP, LT_OP, LEQ_OP, PLUS_OP, MINUS_OP, MULTI_OP, SLASH_OP, DIV_OP, MOD_OP, AND_OP, OR_OP, NOT_OP } _OPERATOR;

/* 0. Entry */

typedef struct tENTRY{
    enum {_CONST = 0, _VAR, _ARRAY, _PROG, _CALL} typ;
    _DATA_TYPE dataType;
    union uEntryBase{
        char *id;
        int intVal;
        float floatVal;
        _BOOLEAN boolVal;
    } base;
    union uEntryExt{
        struct tEntryBounds{
            int low;
            int high;
        } bounds;
        union uEntrySubProg{
            struct tENTRY *parList;
            struct tN_PROG *ast;
        } prog;
    }ext;
    struct tENTRY *next;
}ENTRY;


/* 1. Reference to a (scalar or array) variable */

typedef struct tN_VAR_REF {
    char *id; /* id of variable */
    struct tN_EXPR *index; /* one or two index expressions, null in case of scalar */
} N_VAR_REF;


/* 2. Expression */

typedef struct tN_EXPR {
    enum { CONSTANT=0, VAR_REF, OP, FUNC_CALL } typ;
    union uExprDesc{
        char* constant; /* string value of the constant */
        N_VAR_REF *var_ref; /* reference to a variable */
        struct tExprOp{
            struct tN_EXPR *expr; /* one or two operands; must not be null! */
            _OPERATOR op; /* operator */
        } operation;
        struct tN_CALL *func_call; /* function call */
    } description;
    int paranthesis;
    struct tN_EXPR *next; /* in case of expression list */
} N_EXPR;


/* 3. Assignment statement */

typedef struct tN_ASSIGN {
    N_VAR_REF *var_ref; /* reference to a variable */
    N_EXPR *rhs_expr; /* right hand side expression */
} N_ASSIGN;


/* 4. If statement */

typedef struct tN_IF {
    N_EXPR *expr;
    struct tN_STMT *then_part;
    struct tN_STMT *else_part;
} N_IF;


/* 5. While statement */
typedef struct tN_WHILE {
    N_EXPR *expr;
    struct tN_STMT *stmt;
} N_WHILE;


/* 6. Function or procedure call */

typedef struct tN_CALL {
    char *id; /* id of function or procedure */
    N_EXPR *par_list; /* actual parameters */
} N_CALL;


/* 7. Statement */

typedef struct tN_STMT {
    enum { _ASSIGN=0, _IF, _WHILE, _PROC_CALL } typ;
    union uNodes{
        N_ASSIGN *assign_stmt;
        N_IF *if_stmt;
        N_WHILE *while_stmt;
        N_CALL *proc_call;
    } node;
    struct tN_STMT *next; /* in case of statement list */
} N_STMT;


/* 8. Root node of a program's AST */

typedef struct tN_PROG {
    ENTRY *entry;
    N_STMT *stmt; /* first statement */
    struct tN_PROG *next; /* next subprogram */
} N_PROG;

