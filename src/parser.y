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
#include<string.h>
#include<stdlib.h>

#define YYSTYPE char*

extern int yylex();
extern void yyerror(char const *s);
extern char *yytext;
extern int lineno;

int fdlineno =0;

void red () {
  printf("\033[1;31m");
}

void yellow() {
  printf("\033[1;33m");
}

void reset () {
  printf("\033[0m");
}
struct fnIdent
{
    char * name;
    int paramNo;
    int lineNo;
    int used;
} fIdent[100], cIdent[100];
int fSize = 0;
int cSize = 0;
void saveFnIdent(char *name,int paramNo,int lineNo)
{
    for( int i=0; i<fSize;i++)
    {
        if(strcmp(name,fIdent[i].name)==0)
        {
            printf(" Error: Function %s already defined. \n.",name);
        }
    }
    fIdent[fSize].name = malloc(50*sizeof(char));
    strcpy(fIdent[fSize].name,name);
    fIdent[fSize].paramNo = paramNo;
    fIdent[fSize].used = 0;
    fSize++;
}
void saveCIdent(char *name,int paramNo,int lineNo)
{
    cIdent[cSize].name = malloc(50*sizeof(char));
    strcpy(cIdent[cSize].name,name);
    cIdent[cSize].paramNo = paramNo;
    cIdent[cSize].lineNo = lineNo;
    cIdent[cSize].used = 0;
    cSize++;
}
void printFnIndent()
{
    for(int i=0;i<fSize;i++)
    {
        printf(" {%s} %d \n",fIdent[i].name,fIdent[i].paramNo);
    }
}
void printCIndent()
{
    for(int i=0;i<cSize;i++)
    {
        printf(" {%s} %d \n",cIdent[i].name,cIdent[i].paramNo);
    }
}

void fnDeclared()
{
    for(int i = 0; i < cSize;i++)
    {
        int d = 0;
        if(strcmp(cIdent[i].name,"main")==0)
        {
            red();
            printf("Error: Function main cannot be called! \n");
            reset();
        }
        for(int j=0;j<fSize;j++)
        {

            if(strcmp(cIdent[i].name,fIdent[j].name)==0)
            {
                if(cIdent[i].paramNo != fIdent[j].paramNo)
                {
                    red();
                    printf("Error:  function call: %s at line %d  has wrong number of parameters passed. expected %d, recivied %d \n",cIdent[i].name,cIdent[i].lineNo,fIdent[j].paramNo,cIdent[i].paramNo );
                    reset();
                }
                d = 1;
                fIdent[j].used = 1;
            }
        }
        if ( d == 0)
        {
            red();
            printf("Error:  %s is not defined but used on line: %d \n",cIdent[i].name,cIdent[i].lineNo);
            reset();
        }
    }
    int m = 0;
    for(int i=0; i< fSize;i++)
    {
        if( strcmp(fIdent[i].name,"main")==0)
        {
            m=1;
        }
        else if(fIdent[i].used == 0)
        {
            yellow();
            printf("Warning: Function %s is declared but never used! \n",fIdent[i].name);
            reset();
        }
    }
    if(m==0)
    {
        red();
        printf("ERROR: Main function not defined! \n");
        reset();
    }
}


int isDebug = 0;
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
%token MODOP
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
        | struct_dec main
        | varAssign main
    ;




// because of structures idents can be of type ident.ident
    
    ident: ID { yyval = malloc(100*sizeof(char)); strcpy(yyval,yytext); }
        | ident DOT ident
        ; 

// exp stands for anything that can come after =
    exp: STRING
        | extendExp
    ;
    extendExp: ident
        | KEYWORD_STRICT_TRUE
        | KEYWORD_STRICT_FALSE
        | ICONST
        | FCONST
        | funCall
        | if_expr
        | extendExp MULOP extendExp
        | extendExp DIVOP extendExp
        | extendExp SUBOP extendExp
        | extendExp ADDOP extendExp
        | extendExp MODOP extendExp
        | extendExp EQUOP extendExp
        | extendExp NEQUOP extendExp 
        | extendExp GT extendExp 
        | extendExp GTEQ extendExp 
        | extendExp LT extendExp 
        | extendExp LTEQ extendExp 
        | extendExp ANDOP extendExp
        | extendExp OROP extendExp
        | NOTOP extendExp
        | INCR extendExp
        | DECR extendExp
        | extendExp INCR
        | extendExp DECR
        | LPAREN extendExp RPAREN
    ;
   
//IF ELSE BLOCK https://doc.rust-lang.org/stable/rust-by-example/flow_control/if_else.html

        if_expr: if_main else_if_expr else_expr
               ;

        if_main: KEYWORD_STRICT_IF exp LBRACE block RBRACE
               ; 

        else_expr: 
                 | KEYWORD_STRICT_ELSE LBRACE block RBRACE 
                 ;

        else_if_expr: 
                 | else_if_expr KEYWORD_STRICT_ELSE if_main
                 ;


//Adding parenthesis to these expressions led to 6 rr conflicts

        exprs: expr
             | expr ANDOP exprs
             | expr OROP exprs
             | LPAREN exprs RPAREN
             | LPAREN expr RPAREN
             ;

        expr: expression EQUOP expr
             | expression NEQUOP expr
             | expression GT expr
             | expression LT expr
             | expression GTEQ expr
             | expression LTEQ expr
             | KEYWORD_STRICT_TRUE
             | KEYWORD_STRICT_FALSE
             | NOTOP expr
             | expression
             | LPAREN expression RPAREN 
             | LPAREN expr RPAREN 
             ;

        expression: term MULOP expression
                  | term DIVOP expression
                  | term ADDOP expression
                  | term SUBOP expression
                  | term MODOP expression
                  | term
                  | LPAREN term RPAREN 
                  | LPAREN expression RPAREN 


        term: ident
            | STRING
            | FCONST
            | ICONST 
            ;

// While Loop declaration
        
        while_loop: KEYWORD_STRICT_WHILE exprs LBRACE block RBRACE
                  | KEYWORD_STRICT_LOOP LBRACE block RBRACE
                  ;

// For Loop Declaration

        for_loop: KEYWORD_STRICT_FOR ident KEYWORD_STRICT_IN for_range LBRACE block RBRACE
                ;

        for_range: for_exp DOTDOT for_exp
                 ;


        for_exp: ident
               | ICONST
               | FCONST
               | for_exp MULOP for_exp
               | for_exp DIVOP for_exp
               | for_exp SUBOP for_exp
               | for_exp ADDOP for_exp
               | for_exp MODOP for_exp
               | LPAREN for_exp RPAREN
        ;

//struct declaration
  
        struct_dec: KEYWORD_STRICT_STRUCT ident struct_def {debug("Found struct dec");}
                  ;

        struct_def: LBRACE struct_block RBRACE
                  | LPAREN struct_tuple RPAREN SEMI
                  ;

        struct_tuple: 
                    | ident COMMA struct_tuple
                    | ident
                    ;

        struct_block:
                | ident COLON data_type COMMA struct_block
                ;

        data_type: ident
                 ;



// FUNCTION DECLARATION

    funDecr: KEYWORD_STRICT_FN ident LPAREN maybeParamList RPAREN maybeFnReturn LBRACE block RBRACE {saveFnIdent($2,atoi($4),fdlineno);debug("FOUND FUNCTION DEC");}
    ;

    //params for function
        param: ident COLON ident
        ;
        maybeParamList: {$$ = "0"; fdlineno = lineno;}
            |paramList {$$ = $1; fdlineno = lineno;}
        ;
        paramList: param { $$ = "1";}
            | get return code of last command bashparamList COMMA param  { char *g = malloc(10*sizeof(char)); sprintf(g, "%d", atoi($1)+1); $$ = g;}
        ;
    
    // Function return
    maybeFnReturn:
        | ARROW ident
        ;

// Function Call
    funCall: ident LPAREN maybeCallParamList RPAREN {saveCIdent($1,atoi($3),lineno);}
    ;

    funcCallStmt: funCall SEMI {}

    ;
    callParam: exp
    ;
    maybeCallParamList: {$$ = "0";}
        | callParamList {$$ = $1;}
    ;
    callParamList: callParam { $$ = "1";}
        | callParamList COMMA callParam { char *a = malloc(10*sizeof(char)); sprintf(a, "%d", atoi($1)+1); $$ = a;}
    ;

// variable and const declaration: https://www.w3adda.com/rust-tutorial/rust-variables#:~:text=Declaring%20Variables%20In%20Rust,to%20hold%20in%20that%20variable.
    
    varDec: KEYWORD_STRICT_LET maybeMut ident maybeType maybeAssign SEMI { debug("FOUND varDec"); }
        | KEYWORD_STRICT_CONST ident maybeType maybeAssign SEMI { debug("FOUND varDec const"); }
    ;


    
    maybeMut:
        | KEYWORD_STRICT_MUT
    ;

    maybeType:
        | COLON ident
    ;

    maybeAssign:
        | ASSIGN exp
        | ASSIGN ident RBRACK vecValue LBRACK
        | ASSIGN ident COLON COLON funCall
        ;
    ;

//Vectors

    vecValue: vecValueTypeOne
            | vecValueTypeTwo
            ;

    vecValueTypeOne: for_exp
            | for_exp COMMA vecValue
            ;

    vecValueTypeTwo: for_exp SEMI for_exp
            ;


     

    var: ident
        | STRING
        | FCONST
        | ICONST
    ;

// variable assign:
    varAssign : ident ASSIGN exp SEMI {debug("var assign");}
        | ident op ASSIGN exp SEMI
    ;

    op: MULOP
        | ADDOP
        | SUBOP
        | DIVOP
        | MODOP
    ;

// break stmt
    breakStmt: KEYWORD_STRICT_BREAK SEMI
        | KEYWORD_STRICT_BREAK exp SEMI
        ;
// return stmt
    returnStmt: KEYWORD_STRICT_RETURN SEMI
        | KEYWORD_STRICT_RETURN exp SEMI
        ;

// block is grammer for everything that can come btw {}
    block: 
        | if_expr block {debug("FOUND IF DEC");}
        | for_loop block {debug("FOUND FOR LOOP");}
        | funcCallStmt block {debug("FOUND A CALL STATEMENT");}
        | varDec block
        | while_loop block {debug("Found while loop");}
        // | struct_dec block
        | breakStmt block
        | varAssign block
        | returnStmt block
    ;


    
  

    

%%

void main() 
 { 
  yyparse(); 

  fnDeclared();
 } 