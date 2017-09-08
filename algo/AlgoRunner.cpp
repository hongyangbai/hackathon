#include "AlgoRunner.h"

void AlgoRunner::run(char* algoname)
{
	DIR *dir;
	struct dirent *ent;

	vector<int> nums = {3,7,-10,10000,-352,9,0,0,1};
	//vector<int> nums = {3};
	//vector<int> nums = {3,2,1};
	//vector<int> nums = {3,2,5,4,1,6};
	vector<int> sortednum = mergeSort(nums);
	cout<<sortednum;
}
