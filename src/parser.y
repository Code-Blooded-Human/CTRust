// Copyright 2015 The Rust Project Developers. See the COPYRIGHT
// file at the top-level directory of this distribution and at
// http://rust-lang.org/COPYRIGHT.
//
// Licensed under the Apache License, Version 2.0 <LICENSE-APACHE or
// http://www.apache.org/licenses/LICENSE-2.0> or the MIT license
// <LICENSE-MIT or http://opensource.org/licenses/MIT>, at your
// option. This file may not be copied, modified, or distributed
// except according to those terms.

%{
#include<stdio.h>
extern int yylex();
extern void yyerror(char const *s);
extern char *yytext;

int isDebug = 1;
void debug(char* s)
{
    if(isDebug == 1)
    {
        printf("%s \n",s);
    }
}

%}


%token KEYWORD_STRICT_AS
%token KEYWORD_STRICT_BREAK
%token KEYWORD_STRICT_CONST
%token KEYWORD_STRICT_CONTINUE
%token KEYWORD_STRICT_CRATE
%token KEYWORD_STRICT_ELSE
%token KEYWORD_STRICT_ENUM
%token KEYWORD_STRICT_EXTERN
%token KEYWORD_STRICT_FALSE
%token KEYWORD_STRICT_FN
%token KEYWORD_STRICT_FOR
%token KEYWORD_STRICT_IF
%token KEYWORD_STRICT_IMPL
%token KEYWORD_STRICT_IN
%token KEYWORD_STRICT_LET
%token KEYWORD_STRICT_LOOP
%token KEYWORD_STRICT_MATCH
%token KEYWORD_STRICT_MOD
%token KEYWORD_STRICT_MOVE
%token KEYWORD_STRICT_MUT
%token KEYWORD_STRICT_PUB
%token KEYWORD_STRICT_REF
%token KEYWORD_STRICT_RETURN
%token KEYWORD_STRICT_SELFVALUE
%token KEYWORD_STRICT_SELFTYPE
%token KEYWORD_STRICT_STATIC
%token KEYWORD_STRICT_STRUCT
%token KEYWORD_STRICT_SUPER
%token KEYWORD_STRICT_TRAIT
%token KEYWORD_STRICT_TRUE
%token KEYWORD_STRICT_TYPE
%token KEYWORD_STRICT_UNSAFE
%token KEYWORD_STRICT_USE
%token KEYWORD_STRICT_WHERE
%token KEYWORD_STRICT_WHILE
%token KEYWORD_STRICT_ASYNC
%token KEYWORD_STRICT_AWAIT
%token KEYWORD_STRICT_DYN
%token KEYWORD_RES_ABSTRACT
%token KEYWORD_RES_BECOME
%token KEYWORD_RES_BOX
%token KEYWORD_RES_DO
%token KEYWORD_RES_FINAL
%token KEYWORD_RES_MACRO
%token KEYWORD_RES_OVERRIDE
%token KEYWORD_RES_PRIV
%token KEYWORD_RES_TYPEOF
%token KEYWORD_RES_UNSIZED
%token KEYWORD_RES_VIRTUAL
%token KEYWORD_RES_YILED
%token KEYWORD_RES_TRY
%token KEYWORD_WEAK_UNION
%token KEYWORD_WEAK_STATICLIFETIME
%token KEYWORD_WEAK_DYN
%token ADDOP
%token SUBOP
%token MULOP
%token DIVOP
%token INCR
%token DECR
%token OROP
%token ANDOP
%token NOTOP
%token EQUOP
%token NEQUOP
%token GT
%token LT
%token GTEQ
%token LTEQ
%token COLON
%token LPAREN
%token RPAREN
%token LBRACK
%token RBRACK
%token LBRACE
%token RBRACE
%token SEMI
%token DOTDOT
%token DOT
%token COMMA
%token ASSIGN
%token REFER
%token ID
%token UNDERSCORE
%token HASH
%token ARROW

%token ICONST
%token FCONST
%token CCONST
%token STRING

%%

// main
    main:
        | funDecr main
        | varDec main
        | if_expr main {debug("FOUND IF DEC");}
        | if_else_expr main {debug("FOUND IF/else DEC");}


//TEST
        if_expr: if_main 
               ;

        if_else_expr: if_main KEYWORD_STRICT_ELSE LBRACE block RBRACE 
                    ;
        
        if_main: KEYWORD_STRICT_IF LPAREN exprs RPAREN LBRACE block RBRACE
               ; 
               
        exprs: expr
             | expr EQUOP expr
             | expr NEQUOP expr
             | expr GT expr
             | expr LT expr
             | expr GTEQ expr
             | expr LTEQ expr
             ;
        expr: ID
            | STRING
            | FCONST
            | ICONST 
            | KEYWORD_STRICT_TRUE
            | KEYWORD_STRICT_FALSE
            ;



// FUNCTION DECLARATION

    funDecr: KEYWORD_STRICT_FN ID LPAREN maybeParamList RPAREN maybeFnReturn LBRACE block RBRACE {debug("FOUND FUNCTION DEC");}
    ;

    //params for function
        param: ID COLON ID
        ;
        maybeParamList:
            |paramList
        ;
        paramList: param
            | paramList COMMA param
        ;
    
    // Function return
    maybeFnReturn:
        | ARROW ID
        ;


// variable and const declaration: https://www.w3adda.com/rust-tutorial/rust-variables#:~:text=Declaring%20Variables%20In%20Rust,to%20hold%20in%20that%20variable.
    
    varDec: KEYWORD_STRICT_LET maybeMut ID maybeType maybeAssign SEMI { debug("FOUND varDec"); }
        | KEYWORD_STRICT_CONST ID maybeType maybeAssign SEMI { debug("FOUND varDec const"); }
    ;
    
    maybeMut:
        | KEYWORD_STRICT_MUT
    ;

    maybeType:
        | COLON ID
    ;

    maybeAssign:
        | ASSIGN var
    ;

    var: ID
        | STRING
        | FCONST
        | ICONST
    ;

// block is grammer for everything that can come btw {}
    block: {debug("FOUND BLOCK");}
    ;


%%

void main() 
 { 
  yyparse(); 
 } 