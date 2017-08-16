#include "Solution.h"

using namespace std;

const char* homedir;

int main(int argc, char *argv[])
{	
	if(argc < 2)
	{
		printf("usage: thor [op=leet ...] [problem name]\n");
		return 0;
	}

	// Set homedir
	if ((homedir = getenv("HOME")) == NULL)
		homedir = getpwuid(getuid())->pw_dir;

	if(strcmp(argv[1], "leet") == 0)
	{
		if(argc < 3)
		{
			printf("usage: thor [op=leet ...] [problem name]\n");
			return 0;
		}
		Solution::instance()->run(argv[2]);
	}
	else
		printf("Error: unrecognized operation type\n");
	return 0;
}
