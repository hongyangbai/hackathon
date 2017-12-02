
#include "minSteps.h"

void minSteps::solve()
{
	cout<<solveMinSteps(4)<<endl;
}

int minSteps::solveMinSteps(int n)
{
	int res = n;
	
	vector<int> dp(n+1, NAN);
	for(int i = 1; i <= n; ++i)
		dp[i] = i;
	dp[1] = 0;
	for(int i = 2; i <= n/2; ++i)
	{
		int copies = i;
		int pad = copies;
		int j = dp[copies]+1; 
		while(pad <= n)
		{
			pad += copies;
			dp[pad] = min(dp[pad], ++j);
		}
	}
	return dp[n];
}
