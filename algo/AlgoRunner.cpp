#include "AlgoRunner.h"

void AlgoRunner::run(char* algoname)
{
	DIR *dir;
	struct dirent *ent;
	
	//vector<int> nums = {3,1,2,5,7,5,6};
	vector<int> nums = {3,3,3,3};
	cout<<nums;
	quickSort(nums);
	cout<<nums;
}
