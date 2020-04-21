#ifndef TOKEN
#define TOKEN 1
struct Token
{
	int tokenId;
	int lineNo;
	char type[30];
	char *value;

};
#endif
