#pragma once

#include "utils.h"

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

TreeNode* createTree(vector<char*>& nums);
void deleteTree(TreeNode* root);

class Tree
{
public:
	Tree() {}
	void insertNode();
};
