#include "predictTheWinner.h"

void predictTheWinner::solve()
{
	//vector<int> nums = {1,5,2};
	vector<int> nums = {1,5,233, 7};
	if(solvePredictTheWinner(nums))
		cout<<"TRUE"<<endl;
	else
		cout<<"FALSE"<<endl;
}

bool predictTheWinner::solvePredictTheWinner(vector<int>& nums)
{
	int n = nums.size();
	vector<vector<int>> dp(n, vector<int>(n));

	for(int i = 0; i < n; ++i)
		dp[i][i] = nums[i];

	for(int i = 1; i < n; ++i)
	{
		for(int j = 0; i+j < n; ++j)
			dp[j][j+i] = max(nums[j+i]-dp[j][j+i-1], nums[j]-dp[j+1][j+i]);
	}

	return dp[0][n-1] > 0;
}
