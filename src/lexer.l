%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "lex.h"
    #include "token.h"


    int lineno = 1; // initialize to 1
    int isLexerInit = 0;
    struct Token token;
    int ret_print(char *token_type);
    void yyerror();
%}

%x ML_COMMENT

alpha       [a-zA-Z]
digit       [0-9]
alnum       {alpha}|{digit}
print       [ -~]

ID          {alpha}+{alnum}*
ICONST      "0"|[0-9]{digit}*
FCONST      "0"|{digit}*"."{digit}+
CCONST      (\'{print}\')|(\'\\[nftrbv]\')
STRING      \"{print}*\"

%%

"//".*                  { printf("Eat up comment at line %d\n", lineno); }

"/*"                    { printf("Eat up comment from line %d ", lineno); BEGIN(ML_COMMENT); }
<ML_COMMENT>"*/"        { printf("to line %d\n", lineno); BEGIN(INITIAL); }
<ML_COMMENT>[^*\n]+
<ML_COMMENT>"*"
<ML_COMMENT>"\n"        { lineno += 1; }


"char"|"CHAR"           { ret_print("KEYWORD_CHAR"); return 0;}
"int"|"INT"             { ret_print("KEYWORD_INT"); return 0; }
"float"|"FLOAT"         { ret_print("KEYWORD_FLOAT"); return 0; }
"double"|"DOUBLE"       { ret_print("KEYWORD_DOUBLE"); return 0; }
"if"|"IF"               { ret_print("KEYWORD_IF"); return 0; }
"else"|"ELSE"           { ret_print("KEYWORD_ELSE"); return 0; }
"while"|"WHILE"         { ret_print("KEYWORD_WHILE"); return 0; }
"for"|"FOR"             { ret_print("KEYWORD_FOR"); return 0; }
"continue"|"CONTINUE"   { ret_print("KEYWORD_CONTINUE"); return 0; }
"break"|"BREAK"         { ret_print("KEYWORD_BREAK"); return 0; }
"void"|"VOID"           { ret_print("KEYWORD_VOID"); return 0; }
"return"|"RETURN"       { ret_print("KEYWORD_RETURN"); return 0; }


"+"|"-"                 { ret_print("ADDOP"); return 0; }
"*"                     { ret_print("MULOP"); return 0; }
"/"                     { ret_print("DIVOP"); return 0; }
"++"|"--"               { ret_print("INCR");  return 0;}
"||"                    { ret_print("OROP"); return 0; }
"&&"                    { ret_print("ANDOP"); return 0; }
"!"                     { ret_print("NOTOP");  return 0;}
"=="|"!="               { ret_print("EQUOP"); return 0; }
">"|"<"|">="|"<="       { ret_print("RELOP"); return 0; }


"("             { ret_print("LPAREN");  return 0; }
")"             { ret_print("RPAREN");  return 0;}
"]"             { ret_print("LBRACK"); return 0; }
"["             { ret_print("RBRACK");  return 0;}
"{"             { ret_print("LBRACE"); return 0; }
"}"             { ret_print("RBRACE"); return 0; }
";"             { ret_print("SEMI");  return 0;}
"."             { ret_print("DOT"); return 0; }
","             { ret_print("COMMA"); return 0; }
"="             { ret_print("ASSIGN");  return 0;}
"&"             { ret_print("REFER"); return 0; }


{ID}            { ret_print("ID"); return 0; }
{ICONST}        { ret_print("ICONST");  return 0;}
{FCONST}        { ret_print("FCONST"); return 0; }
{CCONST}        { ret_print("CCONST"); return 0; }
{STRING}        { ret_print("STRING"); return 0; }

<<EOF>>         { ret_print("EOF"); return -1;}
"\n"            { lineno += 1; }
[ \t\r\f]+          /* eat up whitespace */

.               { yyerror("Unrecognized character"); }

%%

int ret_print(char *token_type){
    setToken(&token,token_type,lineno,yyleng,yytext);

    return 0;
}

void yyerror(char *message){
    printf("Error: \"%s\" in line %d. Token = %s\n", message, lineno, yytext);
    exit(1);
}
