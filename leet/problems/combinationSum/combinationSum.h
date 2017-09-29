#include "Solution.h"

class combinationSum : public Solution
{
	void backTracking(vector<int>& candidates, int idx, int target, vector<int> subres, vector<vector<int>>& res);
	void backTracking4(vector<int>& candidates, int idx, int target, vector<int> subres, vector<vector<int>>& res);
	void backTracking(int idx, int k, int n, vector<int> subres, vector<vector<int>>& res);
	vector<vector<int>> solveCombinationSum(vector<int>& candidates, int target);
	vector<vector<int>> solveCombinationSum3(int k, int n);
	vector<vector<int>> solveCombinationSum4(vector<int>& candidates, int target);
public:
	void solve();
};
