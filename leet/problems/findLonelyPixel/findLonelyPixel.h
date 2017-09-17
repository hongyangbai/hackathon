#include "Solution.h"

class findLonelyPixel : public Solution
{
	vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

	int solveFindLonelyPixel(vector<vector<char>>& picture);
	int dfs(vector<vector<char>>& picture, int x, int y, int diri);
public:
	void solve();
};
