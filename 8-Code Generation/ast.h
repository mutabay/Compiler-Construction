#ifndef AST_H
#define AST_H
/* Abstract Syntax Tree (AST) for Mini-Pascal */

typedef enum { _FALSE=0, _TRUE } BOOLEAN;
typedef enum { _BOOL=0, _INT, _REAL, _VOID } DATA_TYPE;

/* A "module" is the main program or a subprogram (function or procedure).
  A (subprogram) "call" is a function call or a procedure call. */


/* Every module has its own symbol table consisting of a list of entries.
   The first symbol table entry is of type PROG and identifies the module itself. */
typedef struct tENTRY {

/* Entry type:
  	CONST ... constant
	VAR   ... scalar variable
	ARRAY ... array variable
	PROG  ... program module
	CALL  ... function or procedure call */
    enum { _CONST=0, _VAR, _ARRAY, _PROG } typ;

/* Data type (of a constant, variable, or function return value)
	VOID for main program or procedure */
    DATA_TYPE data_type; 
 
/* Base entry information 
	- id of a variable or program module
	- value of a constant */
    union {
        char *id ; 
        int int_val; 
        float real_val;
        BOOLEAN bool_val; 
    } base;

/* Extended entry information for arrays and subprograms */
    union {
        struct { /* array bounds */
            int low; 
            int upp;
        } bounds; 
        union { /* subprogram declaration */
    		struct tENTRY *par_list; 
        	struct tN_PROG *ast;  
	} prog;
    } ext;

/* Next symbol table entry */
    struct tENTRY *next; 
} ENTRY; 


/* Reference to a (scalar or array) variable */
typedef struct tN_VAR_REF {
    char *id; /* variable name */
    struct tN_EXPR *index; /* one or two index expressions, null in case of scalar */
} N_VAR_REF;


/* Expression */
typedef struct tN_EXPR {
    enum { CONSTANT=0, VAR_REF, OP, FUNC_CALL } typ;
    union {
        char *constant; /* constant string value */
        N_VAR_REF * var_ref; /* variable reference */
        struct {
            struct tN_EXPR *expr; /* one ore two operands; must not be null! */
            enum { NO_OP=0, EQ_OP, NE_OP, GT_OP, GE_OP, LT_OP, LE_OP, PLUS_OP, MINUS_OP, MULT_OP, SLASH_OP, DIV_OP, MOD_OP, AND_OP, OR_OP, NOT_OP } op; /* operator */
        } operation;
        struct tN_CALL *func_call; /* function call */
    } desc;
    struct tN_EXPR *next; /* expression list */
} N_EXPR;


/* Assignment statement */
typedef struct tN_ASSIGN {
    N_VAR_REF *var_ref; /* variable reference */
    N_EXPR *rhs_expr; /* right hand side expression */
} N_ASSIGN;


/* If statement */
typedef struct tN_IF {
    N_EXPR * expr;
    struct tN_STMT *then_part;
    struct tN_STMT *else_part;
} N_IF;


/* While statement */
typedef struct tN_WHILE {
    N_EXPR * expr;
    struct tN_STMT * stmt;
} N_WHILE;


/* Function or procedure call */
typedef struct tN_CALL {
    char * id; /* id of function or procedure */
    N_EXPR * par_list; /* actual parameters */
} N_CALL;


/* Statement */
typedef struct tN_STMT {
    enum { _ASSIGN=0, _IF, _WHILE, _PROC_CALL } typ;
    union {
        N_ASSIGN * assign_stmt;
        N_IF * if_stmt;
        N_WHILE * while_stmt;
        N_CALL* proc_call;
    } node;
    struct tN_STMT * next; /* statement list */
} N_STMT;


/* Root node of a program's AST */
typedef struct tN_PROG { 
    ENTRY * symtab; /* symbol entry */
    N_STMT * stmt; /* statement list */
    struct tN_PROG * next; /* subprogram list */
 } N_PROG;


/* Root node of main program's AST */

#endif //AST_H
