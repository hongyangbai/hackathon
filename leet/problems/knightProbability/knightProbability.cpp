#include "knightProbability.h"

void knightProbability::solve()
{
	cout<<findProbability(1,1,1)<<endl;
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
