#include "AlgoRunner.h"

void AlgoRunner::run(char* algoname)
{
	DIR *dir;
	struct dirent *ent;
	
	vector<int> nums = {3,7,4,2,5,1,6};
	cout<<nums;
	quickSort(nums);
	cout<<nums;
}
