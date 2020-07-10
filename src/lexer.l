%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "parser.tab.h"
    int g = 0;
    int lineno = 1; // initialize to 1
    void yyerror();
%}

%x ML_COMMENT

alpha       [a-zA-Z]
digit       [0-9]
alnum       {alpha}|{digit}
alnumSp     {alpha}|{digit}|"_"
print       [ -~]

ID          {alpha}+{alnumSp}*+"!"?
ICONST      "0"|[0-9]{digit}*
FCONST      "0"|{digit}*"."{digit}+
CCONST      (\'{print}\')|(\'\\[nftrbv]\')
STRING      \"{print}*\"

%%

"//".*                  {  }

"/*"                    { BEGIN(ML_COMMENT); }
<ML_COMMENT>"*/"        {  BEGIN(INITIAL); }
<ML_COMMENT>[^*\n]+
<ML_COMMENT>"*"
<ML_COMMENT>"\n"        { lineno += 1; }




"as"   		       	{  return KEYWORD_STRICT_AS;  }
"break"		        {  return KEYWORD_STRICT_BREAK;  }
"const"		      	{  return KEYWORD_STRICT_CONST;  }
"continue"			  {  return KEYWORD_STRICT_CONTINUE;  }
"crate"           {  return KEYWORD_STRICT_CRATE;  }
"else"           	{  return KEYWORD_STRICT_ELSE;  }
"enum"           	{  return KEYWORD_STRICT_ENUM;  }
"extern"          {  return KEYWORD_STRICT_EXTERN;  }
"false"           {  return KEYWORD_STRICT_FALSE;  }
"fn"           		{  return KEYWORD_STRICT_FN;  }
"for"         		{  return KEYWORD_STRICT_FOR;  }
"if"           		{  return KEYWORD_STRICT_IF;  }
"impl"           	{  return KEYWORD_STRICT_IMPL;  }
"in"           		{  return KEYWORD_STRICT_IN;  }
"let"         		{  return KEYWORD_STRICT_LET;  }
"loop"         		{  return KEYWORD_STRICT_LOOP;  }
"match"        		{  return KEYWORD_STRICT_MATCH;  }
"mod"         		{  return KEYWORD_STRICT_MOD;  }
"move"         		{  return KEYWORD_STRICT_MOVE;  }
"mut"         		{  return KEYWORD_STRICT_MUT;  }
"pub"         		{  return KEYWORD_STRICT_PUB;  }
"ref"         		{  return KEYWORD_STRICT_REF;  }
"return"       		{  return KEYWORD_STRICT_RETURN;  }
"self"         		{  return KEYWORD_STRICT_SELFVALUE;  }
"Self"         		{  return KEYWORD_STRICT_SELFTYPE;  }
"static"         	{  return KEYWORD_STRICT_STATIC;  }
"struct"         	{  return KEYWORD_STRICT_STRUCT;  }
"super"         	{  return KEYWORD_STRICT_SUPER;  }
"trait"         	{  return KEYWORD_STRICT_TRAIT;  }
"true"         		{  return KEYWORD_STRICT_TRUE;  }
"type"         		{  return KEYWORD_STRICT_TYPE;  }
"unsafe"         	{  return KEYWORD_STRICT_UNSAFE;  }
"use"         		{  return KEYWORD_STRICT_USE;  }
"where"         	{  return KEYWORD_STRICT_WHERE;  }
"while"         	{  return KEYWORD_STRICT_WHILE;  }

"async"         	{  return KEYWORD_STRICT_ASYNC;  }
"await"         	{  return KEYWORD_STRICT_AWAIT;  }
"dyn"	         	  {  return KEYWORD_STRICT_DYN;  }


"abstract"        {  return KEYWORD_RES_ABSTRACT;  }
"become"          {  return KEYWORD_RES_BECOME;  }
"box"             {  return KEYWORD_RES_BOX;  }
"do"              {  return KEYWORD_RES_DO;  }
"final"           {  return KEYWORD_RES_FINAL;  }
"macro"           {  return KEYWORD_RES_MACRO;  }
"override"        {  return KEYWORD_RES_OVERRIDE;  }
"priv"            {  return KEYWORD_RES_PRIV;  }
"typeof"          {  return KEYWORD_RES_TYPEOF;  }
"unsized"         {  return KEYWORD_RES_UNSIZED;  }
"virtual"         {  return KEYWORD_RES_VIRTUAL;  }
"yield"           {  return KEYWORD_RES_YILED;  }

"try"             {  return KEYWORD_RES_TRY;  }

"union"           {  return KEYWORD_WEAK_UNION;  }



"+"			{  return ADDOP;   }
"-"                     {  return SUBOP;   }
"*"                     {  return MULOP;   }
"/"                     {  return DIVOP;   }
"%"                     {  return MODOP;   }
"++" 			{  return INCR;   }
"--"                    {  return DECR;   }
"||"                    {  return OROP;   }
"&&"                    {  return ANDOP;   }
"!"                     {  return NOTOP;   }
"=="                    {  return EQUOP;   }
"!="			{  return NEQUOP;   }
">"		        {  return GT;   }
"<"			{  return LT;   }
">="			{  return GTEQ;   }
"<="			{  return LTEQ;   }
":"             {  return COLON;   }
"("             {  return LPAREN;    }
")"             {  return RPAREN;   }
"]"             {  return LBRACK;   }
"["             {  return RBRACK;   }
"{"             {  return LBRACE;   }
"}"             {  return RBRACE;   }
";"             {  return SEMI;   }
".."             {  return DOTDOT;   }
"."             {  return DOT;   }
","             {  return COMMA;   }
"="             {  return ASSIGN;   }
"&"             {  return REFER;   }
"_"             { return UNDERSCORE; }
"#"             { return HASH;}
"->"            { return ARROW; }
{ID}            {  return ID;   }
{ICONST}        {  return ICONST;   }
{FCONST}        {  return FCONST;   }
{CCONST}        {  return CCONST;   }
{STRING}        {  return STRING;   }

<<EOF>>         { g=1; return -1;}
"\n"            { lineno += 1; }
[ \t\r\f]+          /* eat up whitespace */

.               { yyerror("Unrecognized character"); }

%%


void yyerror(char *message){
    printf("Error: \"%s\" in line %d. Token = %s\n", message, lineno, yytext);
    exit(1);
}

