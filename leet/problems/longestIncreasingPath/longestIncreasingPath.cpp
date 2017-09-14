#include "longestIncreasingPath.h"

void longestIncreasingPath::solve()
{
	vector<vector<int>> matrix = {{9,9,4},
								  {6,6,8},
								  {2,1,1}};

	cout<<matrix;
	cout<<solveLongestIncreasingPath(matrix)<<endl;
}

int longestIncreasingPath::dfs(vector<vector<int>> matrix, int x, int y, vector<vector<int>>& dp)
{
	
	if(dp[x][y] > 0)
		return dp[x][y];

	vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
	for(auto dir:dirs)
	{
		int newx = x+dir.first;
		int newy = y+dir.second;
		if(newx<0 || newy <0 || newx>=matrix.size() || newy>=matrix[0].size() || matrix[newx][newy] <= matrix[x][y])
			continue;
		dp[x][y] = max(dp[x][y], dfs(matrix, newx, newy, dp));
		cout<<dp[x][y]<<":"<<x<<" "<<y<<endl;
	}

	return ++dp[x][y];
}

int longestIncreasingPath::solveLongestIncreasingPath(vector<vector<int>>& matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();

	vector<vector<int>> dp(n, vector<int>(m,0));

	int res = 0;
	for(int i = 0; i < matrix.size(); ++i)
	{
		for(int j = 0; j < matrix[i].size(); ++j)
			res = max(res, dfs(matrix, i, j, dp));
	}
	return res;
}
