%{
#include "parser.tab.h" 
%}

%%

[ \t]           ; // Ignore whitespace
[0-9]+          { yylval.num = atoi(yytext); return NUMBER; }
[\n]            { return EOL; }
"("             { return LPAR; }
")"             { return RPAR; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MULTIPLY; }
"/"             { return DIVIDE; }
.               { /* Ignore any other characters */ }

%%

int yywrap() {
    return 1;
}
