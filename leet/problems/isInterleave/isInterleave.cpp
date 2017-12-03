#include "isInterleave.h"

void isInterleave::solve()
{
	//if(solveIsInterleave("ab", "bc", "bbac"))
	if(solveIsInterleave("aabcc", "dbbca", "aadbbbaccc"))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
}

bool isInterleave::solveIsInterleave(string s1, string s2, string s3)
{
	if(s3.size() != (s1.size() + s2.size()))	return false;
	vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1, false));
	for(int i = 0; i <= s1.size(); ++i)
	{
		for(int j = 0; j <= s2.size(); ++j)
		{
			if(i == 0 && j == 0)
			{
				dp[i][j] = true;
			}
			else if(i == 0 && j > 0)
			{
				if(s3[j-1] == s2[j-1])
					dp[i][j] = dp[i][j-1];
			}
			else if(j == 0 && i > 0)
			{
				if(s3[i-1] == s1[i-1])
					dp[i][j] = dp[i-1][j];
			}
			else
			{
				if(s3[i+j-1] == s1[i-1] && dp[i-1][j])
					dp[i][j] = true;
				else if(s3[i+j-1] == s2[j-1] && dp[i][j-1])
					dp[i][j] = true;
			}
		}
	}

	cout<<dp;
	return dp[s1.size()][s2.size()];
}
