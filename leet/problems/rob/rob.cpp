#include "rob.h"

void rob::solve()
{
	vector<char*> nums = {"1","2","3"};
	//vector<char*> nums = {"1",NULL,"2","3","4"};
	TreeNode* root = createTree(nums);
	cout<<solveRob3(root)<<endl;
	deleteTree(root);
}

int rob::robHelper(vector<int>& nums, int start, int end)
{
	if(start > end)	return 0;
	if(nums.empty())	return 0;

	int include = 0;
	int exclude = 0;

	for(int i = start; i < end; ++i)
	{
		int inc = include;
		int exc = exclude;
		include = exc + nums[i];
		exclude = max(inc, exc);
	}

	return max(include, exclude);
}

int rob::solveRob(vector<int>& nums)
{
	if(nums.empty())	return 0;

	int include = 0;
	int exclude = 0;

	for(int i = 0; i < nums.size(); ++i)
	{
		int inc = include;
		int exc = exclude;
		include = exc + nums[i];
		exclude = max(inc, exc);
	}

	return max(include, exclude);
}

int rob::solveRob2(vector<int>& nums)
{
	if(nums.empty())	return 0;
	if(nums.size() == 1)	return nums[0];
	return max(robHelper(nums, 0, nums.size()-1), robHelper(nums, 1, nums.size()));
}

int rob::rob3Helper(TreeNode* root, int& l, int& r)
{
	if(!root)	return 0;

	int ll = 0, lr = 0, rl = 0, rr = 0;
	l = rob3Helper(root->left, ll, lr);
	r = rob3Helper(root->right, rl, rr);

	return max(root->val + ll + lr + rl + rr, l + r);
}

int rob::solveRob3(TreeNode* root)
{
	if(!root)	return 0;
	int l = 0, r = 0;
	return rob3Helper(root, l, r);
}
