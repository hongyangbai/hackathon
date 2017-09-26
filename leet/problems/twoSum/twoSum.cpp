#include "twoSum.h"

void twoSum::solve()
{
	vector<int> nums = {3,2,1,4,2};
	cout<<numPair(nums, 5)<<endl;
}

int twoSum::numPair(vector<int>& nums, int k)
{
	unordered_map<int, int> ht;
	int counter = 0;
	for(int i = 0; i < nums.size(); ++i)
	{
		if(ht.find(nums[i]) == ht.end())
			ht[k-nums[i]] = i;
		else
			++counter;
	}

	return counter;
}
