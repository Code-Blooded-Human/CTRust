/*

global variable token (type Struct Token) contains new token data when nextToken() is called.
Do not write to token variable.


global variable available from different source files:
  token : type: struct Token
    Contains token data after nextToken() is called.
    ReadOnly
  -------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------
functions with return type and parameters from different source files:
  int initLexer(FILE *fileDesc) from lex.yy.c defined in lex.h
    Initialises the lexer with source file.
  --------------------------------------------------------------------
  int nextToken() from lex.yy.c defined in lex.h
    variable token is set with token data.
  --------------------------------------------------------------------
  void printToken(Token tok)  from lex.yy.c defined in lex.h
    Prints the token data to stdout.
  --------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------------------
includes lex.h from lexer.l
*/
#include<stdio.h>
#include<stdlib.h>


#include "token.h"

extern struct Token token; // Struct Token is defined in token.h and token is declared in lexer.l (lex.yy.c)
extern int initLexer(FILE *fileDesc); // FROM lex.yy.c Defined in lex.h (Lex.h is included in lexer.l (lex.yy.c))
extern int nextToken(); // FROM lex.yy.c Defined in lex.h (Lex.h is included in lexer.l (lex.yy.c))
extern void printToken(struct Token tok);// FROM lex.yy.c Defined in lex.h (Lex.h is included in lexer.l (lex.yy.c))



void checkArgs(int nArgs,char* args[]);

int main(int argc, char *argv[])
{
    checkArgs(argc,argv);
    FILE *fileDesc = fopen(argv[1], "r");
    if( initLexer(fileDesc) < 0) //Initialize tokenizer
    {
      fclose(fileDesc);
      exit(-1);
    }

    while(nextToken() >= 0)
    {
      printToken(token);
    }

    printf("All tokens finished. Terminating successfully. \n");
    fclose(fileDesc);
    return 0;
}



/*
	Filename should be supplied as an argument.
*/
void checkArgs(int nArgs, char* args[])
{
	if(nArgs != 2)
	{
		printf("[ERROR]: Incorrect number of arguments specified. \n[USAGE]: %s filename.rs \n",args[0]);
		exit(-1);
	}
}
