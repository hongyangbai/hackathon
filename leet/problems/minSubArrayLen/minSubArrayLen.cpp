#include "minSubArrayLen.h"

void minSubArrayLen::solve()
{
	vector<int> nums = {2,3,1,2,4,3};
	cout<<nums;
	cout<<solveMinSubArrayLen(7, nums)<<endl;
}

int minSubArrayLen::solveMinSubArrayLen(int s, vector<int>& nums)
{
	int ptr = 0;
	int cursum = 0;
	int minsize = INT_MAX;
	for(unsigned int i = 0; i < nums.size(); ++i)
	{
		cursum += nums[i];
		while(cursum >= s)
		{
			minsize = min(minsize, (int)i-ptr+1);
			cursum -= nums[ptr];
			++ptr;
		}
	}
	return minsize == INT_MAX ? 0:minsize;
}

