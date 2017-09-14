#include "Solution.h"
#include "Tree.h"

class buildTree : public Solution
{
	TreeNode* solveBuildTree(vector<int>& inorder, vector<int>& postorder);
	TreeNode* recursive(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr);
public:
	void solve();
};
