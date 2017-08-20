#include "Solution.h"

class countBattleships : public Solution
{
	void dfs(vector<vector<char>>& board, int x, int y, int n, int m, int dir);
public:
	void solve();
	int solveCountBattleships(vector<vector<char>>& board);
};
