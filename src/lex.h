/*
ToDo:
  [1] Remove token by reference and directly use global token inside fuctions, this will ensure automatic freeing of token.
  [2] Convert type to poiner.
  [3] add strlen on value to remove lvalue
*/


#include<stdlib.h>
#include<stdio.h>
#include<string.h>



struct Token
{
	int tokenId;
	int lineNo;
	char type[30];
	char *value;

};

int setToken(struct Token *tok,char* type,int lineNo,int lValue,char* value);
int freeToken(struct Token *tok);

//Helper Functions
void printToken(struct Token tok);



/*
setToken()
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
