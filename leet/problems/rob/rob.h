#include "Solution.h"
#include "Tree.h"

class rob : public Solution
{
	int solveRob(vector<int>& nums);
	int solveRob2(vector<int>& nums);
	int solveRob3(TreeNode* root);
	int robHelper(vector<int>& nums, int start, int end);
	int rob3Helper(TreeNode* root, int& l, int& r);
public:
	void solve();
};
