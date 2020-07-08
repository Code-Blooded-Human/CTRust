%{
  #include <stdio.h>
  #include "calc_ast.h"
  int yylex();
%}

%union {
  struct ast *a;
  int i;
  struct symbol *v;
}

%right '='
%left '+' '-'
%left '*' '/'

%token <i> NUMBER
%token <v> IDENT
%token EOL
%type <a> exp

%%
el:
|el exp EOL {printf("=%d\n>",eval($2));treefree($2);}
;

exp:exp '+' exp {$$=newast('+',$1,$3);}
|exp '-' exp {$$=newast('-',$1,$3);}
|exp '*' exp {$$=newast('*',$1,$3);}
|exp '/' exp {$$=newast('/',$1,$3);}
|NUMBER {$$ = newnum($1);}
|IDENT '=' exp {$$=newasgn($1,$3);}
|'|' exp '|' {$$ = newast('|',$2,NULL);}
|'('exp')' {$$=$2;}
|IDENT  {$$=newref($1);}
;
%%

int main() {
  printf(">");
  yyparse();
  return 0;
}

void yyerror(char *s) {
  fprintf(stderr,"error:%s\n",s);
}
