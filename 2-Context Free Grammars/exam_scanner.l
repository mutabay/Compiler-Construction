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
int closedErrorNumber = 0;
int commentCount = 0;
int maxNestedCommentNumber = 0;

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

BEGIN_COMMENT "(""*"
END_COMMENT "*"")"

WHITESPACE  ([ \t]+)
%%

{BEGIN_COMMENT} {commentCount++; currentPoint++; if (currentPoint > maxNestedCommentNumber) maxNestedCommentNumber = currentPoint; BEGIN(nestedComments);}
<nestedComments>{
    {BEGIN_COMMENT} {currentPoint++; if (currentPoint > maxNestedCommentNumber) maxNestedCommentNumber = currentPoint;}
    {END_COMMENT} {currentPoint--; if (currentPoint == 0) BEGIN(INITIAL);}
    \n yylineno++;
    .
}
{SIGNED_INTEGER}    {
            printf( "Signed integer: %s (%d)\n", yytext,
                    atoi( yytext ) );
            }
FLOAT   {
            printf( "Float number: %s (%g)\n", yytext,
                    atof( yytext ) );
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

{END_COMMENT} {closedErrorNumber++; printf("Error on line %d : a comment is closed without opening\n", yylineno);}

. printf( "!!!Error!!! Unrecognized character: %s, In the line of [%d]\n", yytext, yylineno);

%%
int main(int argc, char **argv) {
    yylex();

    if (!currentPoint && !closedErrorNumber){
        printf("Comment Count : %d\n", commentCount);
        printf("Maximum nested comment number: %d\n", maxNestedCommentNumber);
    }
    return 0;
}
