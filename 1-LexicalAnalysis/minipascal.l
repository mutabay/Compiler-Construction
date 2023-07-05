%option noyywrap

%{
    /* Lexical Analyse Generator

    The goal of this exercise is to build a lexical analyser for a small Pascal-like programming language
    using the scanner generator lex (or its open source implementation flex). An example program
    sample.pas and sample_insertion in the “Mini-Pascal” language is can be used for testing.

     */

#include <stdio.h>
#include <math.h>

%}
DIGIT    [0-9]
ALPHA   [A-Za-z]
ALPHA_NUM   ({ALPHA}|{DIGIT})

ID       (_|{ALPHA})+(_|{ALPHA}|{DIGIT})*

INTEGER ({DIGIT}+)
SIGNED_INTEGER  ("+"|"-")?{INTEGER}
FLOAT    ({DIGIT}+"."{DIGIT}*)
REAL_NUMBER {SIGNED_INTEGER}("."{INTEGER})?(E{SIGNED_INTEGER})?

KEYWORD (if|else|while|var|then|begin|end|procedure|function|const|type|program|integer|array|of|real)
OPERATOR   ("+"|"-"|"*"|"/"|"%"|"&"|">"|"<"|"<="|">="|"<>"|"["|"]"|"."|"("|")"|":"|":="|";"|","|"=")

RANGE   {INTEGER}".."{INTEGER}
COMMENT    ("{"[^}\n]*"}")
WHITESPACE  ([ \t]+)
%%

{INTEGER}    {
            printf( "integer: %s (%d)\n", yytext,
                    atoi( yytext ) );
            }
{SIGNED_INTEGER}    {
            printf( "Signed integer: %s (%d)\n", yytext,
                    atoi( yytext ) );
            }
{FLOAT}   {
            printf( "Float number: %s (%g)\n", yytext,
                    atof( yytext ) );
            }
            
{REAL_NUMBER}   {
            printf( "Real number: %s (%g)\n", yytext,
                    atof( yytext ) );
            return REAL_NUMBER_TOKEN;
            }

{RANGE}   printf( "Range: %s\n", yytext );

{KEYWORD}        {
            printf( "Keyword: %s\n", yytext );
            }

{ID}        printf( "Identifier: %s\n", yytext );

{OPERATOR}   printf( "Operator: %s\n", yytext );

{COMMENT}     printf( "Comment : %s\n", yytext );

{WHITESPACE}    /* Supress whitespaces */
\n yylineno++;
.           printf( "!!!Error!!! Unrecognized character: %s, In the line of [%d]\n", yytext, yylineno);

%%
int main(int argc, char **argv) {
    yylex();

    return 0;
}
