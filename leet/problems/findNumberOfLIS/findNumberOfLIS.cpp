#include "findNumberOfLIS.h"

void findNumberOfLIS::solve()
{
	//vector<int> nums = {10,5,6,7,1};
	//vector<int> nums = {1,3,5,4,7};
	//vector<int> nums = {1,3,4,7,5,8};
	vector<int> nums = {2,2,2,2,2};
	//vector<int> nums = {1,3,5,7,6};
	cout<<solveFindNumberOfLIS(nums)<<endl;
}

int findNumberOfLIS::solveFindNumberOfLIS(vector<int>& nums)
{
	vector<pair<int, int>> dp(nums.size(), {1,1}); 
	int res = 0;
	int maxlen = 0;
	for(int i = 0; i < nums.size(); ++i)
	{
		for(int j = 0; j < i ; ++j)
		{
			if(nums[i] > nums[j])
			{
				if(dp[i].first == dp[j].first+1)
					dp[i].second += dp[j].second;
				if(dp[i].first < dp[j].first+1)
					dp[i] = {dp[j].first+1, dp[j].second};
			}
		}

		if(dp[i].first> maxlen)
		{
			res = 0;
			res += dp[i].second;
			maxlen = dp[i].first;
		}
		else if(dp[i].first == maxlen)
			res += dp[i].second;
	}


	return res;
}
