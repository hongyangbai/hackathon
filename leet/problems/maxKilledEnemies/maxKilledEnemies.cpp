#include "maxKilledEnemies.h"

void maxKilledEnemies::solve()
{
	vector<vector<char>> grid = {{'0','E','0','0'},
								 {'E','0','W','E'},
								 {'0','E','0','0'}};
	cout<<solveMaxKilledEnemies(grid)<<endl;
}

int maxKilledEnemies::solveMaxKilledEnemies(vector<vector<char>>& grid)
{
	int nrow = grid.size();
	if(nrow == 0)	return 0;
	int ncol = grid[0].size();
	if(ncol == 0)	return 0;
	vector<vector<int>> dp(nrow, vector<int>(ncol, 0));

	for(int i = 0; i < nrow; ++i)
	{
		int left = 0;
		int right = 0;
		for(int j = 0; j < ncol; ++j)
		{
			dp[i][j] = grid[i][j] != '0' ? 0:(dp[i][j]+left);
			dp[i][ncol-j-1] = grid[i][ncol-j-1] != '0' ? 0:(dp[i][ncol-j-1]+right);

			left = grid[i][j] == '0' ? left : (grid[i][j] == 'W' ? 0 : left + 1);
			right = grid[i][ncol-j-1] == '0' ? right : (grid[i][ncol-j-1] == 'W' ? 0 : right + 1);
		}
	}

	for(int i = 0; i < ncol; ++i)
	{
		int top = 0;
		int bottom = 0;
		for(int j = 0; j < nrow; ++j)
		{
			dp[j][i] = grid[j][i] != '0'?0:(dp[j][i] + top);
			dp[nrow-j-1][i] = grid[nrow-j-1][i] != '0'?0:(dp[nrow-j-1][i]+bottom);

			top= grid[j][i] == '0' ? top : (grid[j][i] == 'W' ? 0 : top + 1);
			bottom = grid[nrow-j-1][i] == '0' ? bottom : (grid[nrow-j-1][i] == 'W' ? 0 : bottom+ 1);
		}

	}
	int maxe = 0;
	for(int i = 0; i < nrow; ++i)
	{
		for(int j = 0; j < ncol; ++j)
		{
			maxe = max(maxe, dp[i][j]);
		}
	}
	return maxe;
}
