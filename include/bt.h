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

class BT
{
	void printVec(vector<TreeNode*>& vec);

public:
	TreeNode *root;
	size_t size;
	
	BT() : root(NULL), size(0) {}
	
	bool insert(int val);
	void print();
	void prettyPrint();
	void dfsPrint(TreeNode* node, int level, vector<string>& lines, bool isleft);
};
