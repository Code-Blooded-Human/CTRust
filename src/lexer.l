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




"as"   		       	{ ret_print("KEYWORD_STRICT_AS"); return 0;}
"break"		        { ret_print("KEYWORD_STRICT_BREAK"); return 0;}
"const"		      	{ ret_print("KEYWORD_STRICT_CONST"); return 0;}
"continue"			  { ret_print("KEYWORD_STRICT_CONTINUE"); return 0;}
"crate"           { ret_print("KEYWORD_STRICT_CRATE"); return 0;}
"else"           	{ ret_print("KEYWORD_STRICT_ELSE"); return 0;}
"enum"           	{ ret_print("KEYWORD_STRICT_ENUM"); return 0;}
"extern"          { ret_print("KEYWORD_STRICT_EXTERN"); return 0;}
"false"           { ret_print("KEYWORD_STRICT_FALSE"); return 0;}
"fn"           		{ ret_print("KEYWORD_STRICT_FN"); return 0;}
"for"         		{ ret_print("KEYWORD_STRICT_FOR"); return 0;}
"if"           		{ ret_print("KEYWORD_STRICT_IF"); return 0;}
"impl"           	{ ret_print("KEYWORD_STRICT_IMPL"); return 0;}
"in"           		{ ret_print("KEYWORD_STRICT_IN"); return 0;}
"let"         		{ ret_print("KEYWORD_STRICT_LET"); return 0;}
"loop"         		{ ret_print("KEYWORD_STRICT_LOOP"); return 0;}
"match"        		{ ret_print("KEYWORD_STRICT_MATCH"); return 0;}
"mod"         		{ ret_print("KEYWORD_STRICT_MOD"); return 0;}
"move"         		{ ret_print("KEYWORD_STRICT_MOVE"); return 0;}
"mut"         		{ ret_print("KEYWORD_STRICT_MUT"); return 0;}
"pub"         		{ ret_print("KEYWORD_STRICT_PUB"); return 0;}
"ref"         		{ ret_print("KEYWORD_STRICT_REF"); return 0;}
"return"       		{ ret_print("KEYWORD_STRICT_RETURN"); return 0;}
"self"         		{ ret_print("KEYWORD_STRICT_SELFVALUE"); return 0;}
"Self"         		{ ret_print("KEYWORD_STRICT_SELFTYPE"); return 0;}
"static"         	{ ret_print("KEYWORD_STRICT_STATIC"); return 0;}
"struct"         	{ ret_print("KEYWORD_STRICT_STRUCT"); return 0;}
"super"         	{ ret_print("KEYWORD_STRICT_SUPER"); return 0;}
"trait"         	{ ret_print("KEYWORD_STRICT_TRAIT"); return 0;}
"true"         		{ ret_print("KEYWORD_STRICT_TRUE"); return 0;}
"type"         		{ ret_print("KEYWORD_STRICT_TYPE"); return 0;}
"unsafe"         	{ ret_print("KEYWORD_STRICT_UNSAFE"); return 0;}
"use"         		{ ret_print("KEYWORD_STRICT_USE"); return 0;}
"where"         	{ ret_print("KEYWORD_STRICT_WHERE"); return 0;}
"while"         	{ ret_print("KEYWORD_STRICT_WHILE"); return 0;}

"async"         	{ ret_print("KEYWORD_STRICT_ASYNC"); return 0;}
"await"         	{ ret_print("KEYWORD_STRICT_AWAIT"); return 0;}
"dyn"	         	  { ret_print("KEYWORD_STRICT_DYN"); return 0;}


"abstract"        { ret_print("KEYWORD_RES_ABSTRACT"); return 0;}
"become"          { ret_print("KEYWORD_RES_BECOME"); return 0;}
"box"             { ret_print("KEYWORD_RES_BOX"); return 0;}
"do"              { ret_print("KEYWORD_RES_DO"); return 0;}
"final"           { ret_print("KEYWORD_RES_FINAL"); return 0;}
"macro"           { ret_print("KEYWORD_RES_MACRO"); return 0;}
"override"        { ret_print("KEYWORD_RES_OVERRIDE"); return 0;}
"priv"            { ret_print("KEYWORD_RES_PRIV"); return 0;}
"typeof"          { ret_print("KEYWORD_RES_TYPEOF"); return 0;}
"unsized"         { ret_print("KEYWORD_RES_UNSIZED"); return 0;}
"virtual"         { ret_print("KEYWORD_RES_VIRTUAL"); return 0;}
"yield"           { ret_print("KEYWORD_RES_YILED"); return 0;}

"try"             { ret_print("KEYWORD_RES_TRY"); return 0;}


"union"           { ret_print("KEYWORD_WEAK_UNION"); return 0;}
"'static"         { ret_print("KEYWORD_WEAK_STATICLIFETIME"); return 0;}

"dyn"           { ret_print("KEYWORD_WEAK_DYN"); return 0;}




"+"			{ ret_print("ADDOP"); return 0; }
"-"                     { ret_print("SUBOP"); return 0; }
"*"                     { ret_print("MULOP"); return 0; }
"/"                     { ret_print("DIVOP"); return 0; }
"++" 			{ ret_print("INCR");  return 0;}
"--"                    { ret_print("DECR");  return 0;}
"||"                    { ret_print("OROP"); return 0; }
"&&"                    { ret_print("ANDOP"); return 0; }
"!"                     { ret_print("NOTOP");  return 0;}
"=="                    { ret_print("EQUOP"); return 0; }
"!="			{ ret_print("NEQUOP"); return 0; }
">"		        { ret_print("GT"); return 0; }
"<"			{ ret_print("LT"); return 0; }
">="			{ ret_print("GTEQ"); return 0; }
"<="			{ ret_print("LTEQ"); return 0; }

"("             { ret_print("LPAREN");  return 0; }
")"             { ret_print("RPAREN");  return 0;}
"]"             { ret_print("LBRACK"); return 0; }
"["             { ret_print("RBRACK");  return 0;}
"{"             { ret_print("LBRACE"); return 0; }
"}"             { ret_print("RBRACE"); return 0; }
";"             { ret_print("SEMI");  return 0;}
".."             { ret_print("DOTDOT"); return 0; }
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
