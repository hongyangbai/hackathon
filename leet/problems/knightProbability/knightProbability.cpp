#include "knightProbability.h"

void knightProbability::solve()
{
	cout<<solveKnightProbability(3,2,0,0)<<endl;
	//cout<<findProbability(1,1,1)<<endl;
}

double knightProbability::findProbability(int x, int y, int k)
{
	int N = 8;
	vector<vector<vector<double>>> dp(N, vector<vector<double>>(N, vector<double>(k+1, 0)));
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
			dp[i][j][0] = 1;
	}


	vector<pair<int, int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
	for(int s = 1; s <= k; ++s)
	{
		for(int i = 0; i < N; ++i)
		{
			for(int j = 0; j < N; ++j)
			{
				double prob = 0;
				for(int l = 0; l < 8; ++l)
				{
					pair<int, int> dir = dirs[l];
					int newx = i+dir.first;
					int newy = j+dir.second;

					if(newx >= 0 && newx < N && newy >= 0 && newy < N)
						prob += dp[newx][newy][s-1]/8.0;
				}

				dp[i][j][s] = prob;
			}
		}
	}

	return dp[x][y][k];
}

double knightProbability::solveKnightProbability(int N, int K, int r, int c)
{
	vector<vector<vector<double>>> dp(N, vector<vector<double>>(N, vector<double>(K+1, 0)));

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
			dp[i][j][0] = 1;
	}

	vector<pair<int, int>> dirs = {{1,2}, {2,1}, {-1,2}, {-2,1}, {-1,-2}, {-2,-1}, {1,-2}, {2,-1}};

	for(int k = 1; k <= K; ++k)
	{
		for(int i = 0; i < N; ++i)
		{
			for(int j = 0; j < N; ++j)
			{
				double prob = 0.0;
				for(int d = 0; d < 8; ++d)
				{
					int x = i+dirs[d].first;
					int y = j+dirs[d].second;
					if(x >= 0 && y >= 0 && x < N && y < N)
						prob += dp[x][y][k-1]/8.0;
				}
				dp[i][j][k] = prob;
			}
		}
	}
	return dp[r][c][K];
}
