%{
#include "calc_ast.h"
#include "calc.tab.h" 
%}

%%
[0-9]+ {yylval.i = atoi(yytext);return NUMBER;}
"+"|"-"|"*"|"/"|"|"|"("|")"|"=" {return yytext[0];}
[a-zA-Z_][a-zA-Z0-9]* {yylval.v=lookup(yytext);return IDENT;}
\n {return EOL;}
[ \t] {}
. {printf("Unknown Character: %s\n",yytext);}
%%

