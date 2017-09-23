#include "AlgoRunner.h"

void AlgoRunner::run(char* algoname)
{
	DIR *dir;
	struct dirent *ent;

	vector<int> nums = {3,2,5,1,4};

	cout<<nums;
	heapSort(nums);
	cout<<nums;
}
