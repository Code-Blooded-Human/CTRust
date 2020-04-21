#include<stdio.h>






extern int yyin;
extern int yylex(); //This comes from lex.yy.c which is obtained
extern void printToken();
extern struct Token token;

int initLexer(int fileDesc);
int nextToken();

// Global variable declarations;
int isLexerInit = 0;





int initLexer(int fileDesc)
{
	if(fileDesc >0)
	{
		yyin = fileDesc;
		isLexerInit = 1;
		return 0;
	}else
	{
		printf("[ERROR](initLexer@lexer.c): Invalid file descriptor passed to initLexer function. \n");
		return -1;
	}
}


/*
nextToken()

Desc:
	Searches for new token and saves it in global variable token (passed by reference);

Return Code | Desc
0			Success
-1		No Tokens left
-2		initLexer not called or failed
*/

int nextToken()
{
	if(isLexerInit == 0)
	{
		printf("[ERROR](at if(isLexerInit) nextToken@lexer.c): initLexer not called or failed. \n");
		return -2;
	}
	if(yylex() < 0){
		printf("[ALERT](nextToken@lexer.c): End of file, no more tokens available.");
		return -1;
	}
	
	return 0;
}
