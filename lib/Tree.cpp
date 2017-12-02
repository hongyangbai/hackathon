#include "Tree.h"

TreeNode* createTreeRecursive(vector<char*>& nums, int i)
{
	if(i >= nums.size())	return NULL;
	if(nums[i] == NULL)	return NULL;
	TreeNode* node = new TreeNode(stoi(nums[i]));
	node->left = createTreeRecursive(nums, ++i);
	node->right = createTreeRecursive(nums, ++i);

	return node;
}

TreeNode* createTree(vector<char*>& nums)
{
	if(nums.empty())	return NULL;
	if(nums[0] == NULL)	return NULL;

	TreeNode* root = createTreeRecursive(nums, 0);

	return root;
}

void deleteTree(TreeNode* root)
{
	if(!root)	return;
	deleteTree(root->left);
	deleteTree(root->right);
	
	delete root;
}

void Tree::insertNode()
{
}
