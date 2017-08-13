#pragma once

#include "utils.h"

using namespace std;

class Solution
{
	static Solution *s;
	Solution() {}
public:
	static Solution *instance();

 	int singleNonDuplicate(vector<int>& nums);
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);
	string replaceWords(vector<string>& dict, string sentence);
};
