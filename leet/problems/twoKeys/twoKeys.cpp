#include "twoKeys.h"

void twoKeys::solve()
{
	for(int i = 1; i < 11; ++i)
		printf("n = %d: %d\n", i, minSteps(i));
}

int twoKeys::minSteps(int n)
{
	vector<int> dp(n+1, 0);
	for(int i = 1; i <=n; ++i)
		dp[i] = i;
	dp[1] = 0;
	
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= i/2; ++j)
		{
			if(i % j  == 0)
				dp[i] = min(dp[i], dp[j] + i/j);
		}
	}
					
	return dp[n];
}
