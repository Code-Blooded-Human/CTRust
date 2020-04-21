int main(int argc,char* argv[]){
	checkArgs(argc,argv);
	yyin = fopen(argv[])


	return 0;
}


/*
	Filename should be supplied as an argument.
*/
void checkArgs(int nArgs, char* args[])
{
	if(nArgs != 2)
	{
		printf("[ERROR]: Incorrect number of arguments specified. \n [USAGE]: %s filename.rs",args[0]);
		exit(-1);
	}
}
