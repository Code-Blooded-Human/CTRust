/*
includes lex.h from lexer.c
*/
#include<stdio.h>


extern int initLexer(int fileDesc); // from lexer.c
extern int nextToken(); // from lexer.c


int main(int argc, char *argv[])
{
    int fileDesc = fopen(argv[1], "r");
    initLexer(fileDesc);
    nextToken();

    fclose(fileDesc);
    return 0;
}
