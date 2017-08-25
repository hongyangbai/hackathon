#include "Solution.h"

class numMatrix: public Solution
{
	vector<vector<int>> accum;
public:
	numMatrix();
	void solve();
	void init(vector<vector<int>> matrix);
	int sumRegion(int row1, int col1, int row2, int col2);
};
