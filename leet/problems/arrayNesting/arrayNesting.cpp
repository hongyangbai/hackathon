#include "arrayNesting.h"

void arrayNesting::solve()
{
	vector<int> nums = {5,4,0,3,1,6,2};
	cout<<solveArrayNesting(nums)<<endl;
}

int arrayNesting::solveArrayNesting(vector<int>& nums)
{
	int maxsize = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		int j = i; 
		int cnt = 0;
		while(nums[j]>=0)
		{
			int nxt = nums[j];
			nums[j] = -1;
			j = nxt;
			++cnt;
		}
		maxsize = max(maxsize, cnt);
	}

	return maxsize;
}
