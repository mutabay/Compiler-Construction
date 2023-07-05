%option noyywrap

%{
    /* Lexical Analyse Generator - Converter

    The goal of this exercise is to build a lexical analyser and convert some keys for a small Pascal-like programming language
    An example program sample.pas in the “Mini-Pascal” language can be used for testing.

    Convertion:
    1. capitalises all keywords;
    2. writes all identifiers in lower case letters;
    3. eliminates all redundant whitespaces (multiple empty lines, space- and tab- characters)
    4. transform all comments into old style Pascal comments
     */

#include <stdio.h>
#include <ctype.h>

int i;

%}
DIGIT    [0-9]
ALPHA   [A-Za-z]

ID       (_|{ALPHA})+(_|{ALPHA}|{DIGIT})*
KEYWORD (if|else|while|var|then|begin|end|procedure|function|const|type|program|integer|array|of|real)

COMMENT    ("{"[^}\n]*"}")
WHITESPACE  ([ \t]+)
%%

{KEYWORD}        {
            printf(" ");
            for(i=0; i<yyleng;i++)
                {
                printf("%c", toupper(yytext[i]));
                }
            printf(" ");
            }

{ID}        {
            for(i=0; i<yyleng;i++)
                printf("%c", tolower(yytext[i]));
            }

{WHITESPACE}   {
                for(i=0; i<yyleng;i++)
                    printf("");
                }

{COMMENT}     {
              printf("(*");
              for(i=1; i<yyleng-1;i++)
                  {
                  printf("%c", yytext[i]);
                  }
              printf("*)");
              }

%%
int main(int argc, char **argv) {
    yylex();

    return 0;
}
