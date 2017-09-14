#include "Solution.h"

class longestIncreasingPath : public Solution
{
	int dfs(vector<vector<int>> matrix, int x, int y, vector<vector<int>>& dp);
	int solveLongestIncreasingPath(vector<vector<int>>& matrix);
public:
	void solve();
};
