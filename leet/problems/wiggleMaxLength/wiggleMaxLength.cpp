#include "wiggleMaxLength.h"

void wiggleMaxLength::solve()
{
	vector<int> nums = {1,7,4,9,2,5};
	cout<<solveWiggleMaxLength(nums)<<endl;
}

int wiggleMaxLength::solveWiggleMaxLength(vector<int>& nums)
{
	int n = nums.size();
	vector<int> up(n);
	vector<int> down(n);
	up[0] = 1;
	down[0] = 1;
	for(int i = 1; i < nums.size(); ++i)
	{
		if((nums[i] - nums[i-1]) > 0)
		{
			up[i] = down[i-1]+1;
			down[i] = down[i-1];
		}
		else if((nums[i] - nums[i-1]) < 0)
		{
			down[i] = up[i-1]+1;
			up[i] = up[i-1];
		}
		else
		{
			up[i] = up[i-1];
			down[i] = down[i-1];
		}
	}

	return max(up[n-1], down[n-1]);
}
