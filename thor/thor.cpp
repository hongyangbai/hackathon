#include "LeetRunner.h"
#include "AlgoRunner.h"

using namespace std;

const char* homedir;

void errorPrintUsage()
{
	printf("usage: thor [leet | algo | ...] [problem | algorithm | ...]\n");
}

int main(int argc, char *argv[])
{	
	if(argc < 2)
	{
		errorPrintUsage();
		return 0;
	}

	// Set homedir
	if ((homedir = getenv("HOME")) == NULL)
		homedir = getpwuid(getuid())->pw_dir;

	if(strcmp(argv[1], "leet") == 0)
	{
		if(argc < 3)
		{
			errorPrintUsage();
			return 0;
		}
		LeetRunner runner;
		runner.run(argv[2]);
	}
	else if(strcmp(argv[1], "algo") == 0)
	{
		if(argc < 3)
		{
			errorPrintUsage();
			return 0;
		}
		AlgoRunner runner;
		runner.run(argv[2]);
	}
	else
		printf("Error: unrecognized operation type\n");

	return 0;
}
