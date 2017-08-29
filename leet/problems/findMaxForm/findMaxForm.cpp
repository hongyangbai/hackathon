#include "findMaxForm.h"

void findMaxForm::solve()
{
	//vector<string> strs = {"10", "0", "1"};
	vector<string> strs = {"10", "0001", "111001", "1", "0"};
	cout<<solveFindMaxForm(strs, 5, 4)<<endl;
}

pair<int, int> findMaxForm::getCount(const string& s)
{
	pair<int, int> cnt = make_pair(0,0);
	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i] == '0')
			++cnt.first;
		else
			++cnt.second;
	}
	return cnt;
}

int findMaxForm::solveFindMaxForm(vector<string>& strs, int m, int n)
{
	vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
	dp[0][0] = 0;
	int maxform = INT_MIN;
	for(const auto& s:strs)
	{
		pair<int, int> cnt = getCount(s);
		for(int i = m; i >= cnt.first; --i)
		{
			for(int j = n; j >= cnt.second; --j)
			{
				int prevmax = dp[i-cnt.first][j-cnt.second] >= 0 ? dp[i-cnt.first][j-cnt.second]+1:0;
				dp[i][j] = max(dp[i][j], prevmax);
				maxform = max(dp[i][j], maxform);
			}
		}
	}

	return maxform;
}
