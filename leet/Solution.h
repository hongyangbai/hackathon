#pragma once

#include "utils.h"
#include "Tree.h"

using namespace std;

class Solution
{
	static Solution *s;

	// Singleton implementation
	Solution() {}
	
	static bool pairComp(vector<int> a, vector<int> b);

public:
	static Solution *instance();

	// Easy leet problems
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);
	string replaceWords(vector<string>& dict, string sentence);

	// Medium leet problems
 	int singleNonDuplicate(vector<int>& nums);
	int findLongestChain(vector<vector<int>>& pairs);
	vector<vector<int>> findSubsequences(vector<int>& nums);
};
