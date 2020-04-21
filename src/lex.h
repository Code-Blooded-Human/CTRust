/*
ToDo:
  [1] Remove token by reference and directly use global token inside fuctions, this will ensure automatic freeing of token.
  [2] Convert type to poiner.
  [3] add strlen on value to remove lvalue
*/


#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "token.h"

//Global declarations --------------

//----------------------------------

//Extern functions ------------------
extern int isLexerInit; //Defined in lex.yy.c
extern FILE  *yyin; // Defined in lex.yy.c
extern struct Token token; //Defined in lex.yy.c
extern int yylex(); // Defined in lex.yy.c

// ------------------------------------

int initLexer(FILE *fileDesc);
int nextToken();
int setToken(struct Token *tok,char* type,int lineNo,int lValue,char* value);
int freeToken(struct Token *tok);

//Helper Functions
void printToken(struct Token tok);





int initLexer(FILE *fileDesc)
{
	if(fileDesc != NULL)
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



/*
setToken()extern struct Token token;
Desc:
  Set the value to a token passed by reference.

*/
int setToken(struct Token *tok,char* type,int lineNo,int lValue,char* value)
{
  freeToken(tok); // frees if token is already set.
  tok->tokenId = 0;
  tok->lineNo = lineNo;
  strcpy(tok->type,type);
  tok->value = malloc(lValue*sizeof(char)+1);
  strcpy(tok->value,value);
  // printToken(token); //For debugging
  return 0;
}

int freeToken(struct Token *tok)
{
  if(tok != NULL)
  {
    if(tok->value != NULL)
    {
      free(tok->value);
    }
  }
  return 0;
}


void printToken(struct Token tok)
{
  printf("Token Data \n-------------------\ntokenId: %d \nlineNo: %d \ntype: %s \nvalue: %s \n-------------------\n",tok.tokenId,tok.lineNo,tok.type,tok.value);
}
