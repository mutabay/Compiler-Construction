%option noyywrap
%x nestedComments
%{
    /* Lexical Analyse Generator - Extended version with Nested Comments

    The goal of this exercise is to build a lexical analyser for a small Pascal-like programming language
    using the scanner generator lex (or its open source implementation flex). An example program
    sample.pas and sample_insertion in the “Mini-Pascal” language is can be used for testing.

     */

#include <stdio.h>
#include <math.h>

int currentPoint = 0;

%}
DIGIT    [0-9]
ALPHA   [A-Za-z]
ALPHA_NUM   ({ALPHA}|{DIGIT})

ID       (_|{ALPHA})+(_|{ALPHA}|{DIGIT})*

INTEGER ({DIGIT}+)
SIGNED_INTEGER  ("+"|"-")?{INTEGER}
FLOAT    ({DIGIT}+"."{DIGIT}*)
REAL_NUMBER {SIGNED_INTEGER}("."{INTEGER})?(E{SIGNED_INTEGER})?

OPERATOR   ("+"|"-"|"*"|"/"|"=")


WHITESPACE  ([ \t]+)
%%

{SIGNED_INTEGER}    {
            printf( "Signed integer: %s (%d)\n", yytext,
                    atoi( yytext ) );
            }
FLOAT   {
            printf( "Float number: %s (%g)\n", yytext,
                    atof( yytext ) );
            }
{ID}        printf( "Identifier: %s\n", yytext );

{OPERATOR}   printf( "Operator: %s\n", yytext );

{WHITESPACE}    /* Supress whitespaces */
\n yylineno++;

%%
int main(int argc, char **argv) {
    yylex();

    if (!currentPoint && !closedErrorNumber){
        printf("Comment Count : %d\n", commentCount);
        printf("Maximum nested comment number: %d\n", maxNestedCommentNumber);
    }
    return 0;
}
















write a free context grammar for an expression supporting for the four basic arithmetic operations and their default precedence, changable using paranthesis. (.l flex file)

Write an attribute grammar in yacc that translates the arithmetic expression into three address code, for example
Expressions
(1+2) * 3-4 -5 / 6
Three-address code 
t1=1+2
t2=t1*3
t3=5/6
t4=t1-4
t5=t4-t3