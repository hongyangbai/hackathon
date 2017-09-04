#include "Solution.h"

class updateBoard : public Solution
{
	vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

	vector<vector<char>> solveUpdateBoard(vector<vector<char>>& board, vector<int>& click);
	void recursive(vector<vector<char>>& board, int x, int y);
public:
	void solve();
};
