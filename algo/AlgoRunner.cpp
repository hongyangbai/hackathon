#include "AlgoRunner.h"

void AlgoRunner::run(char* algoname)
{
	DIR *dir;
	struct dirent *ent;
	
	vector<int> nums = {3,1,2,5,7,4,6};
	cout<<nums;
	insertionSort(nums);
	cout<<nums;
}
