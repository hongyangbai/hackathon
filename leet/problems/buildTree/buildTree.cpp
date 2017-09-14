#include "buildTree.h"

void buildTree::solve()
{

}

TreeNode* buildTree::recursive(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr)
{
	if(il > ir || pl > pr)
		return NULL;

	TreeNode* node = new TreeNode(postorder[pr]);
	int j = il;
	while(j<=ir && inorder[j] != postorder[pr])
		++j;


	int dist = j-il-1;
	node->left = recursive(inorder, postorder, il, j-1, pl, pl+dist);
	node->right= recursive(inorder, postorder, j+1, ir, pl+dist+1, pr-1);

	return node;
}

TreeNode* buildTree::solveBuildTree(vector<int>& inorder, vector<int>& postorder)
{
	if(inorder.empty() || postorder.empty())	return NULL;
	
	return recursive(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
}
