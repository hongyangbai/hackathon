#include "Solution.h"

class findWords : public Solution
{
	struct TrieNode
	{
		string word;
		vector<TrieNode*> next;
		TrieNode()
		{
			next.resize(26);
			for(int i = 0; i < 26; ++i)
				next[i] = NULL;
		}
	};

	vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
	unordered_set<string> mp;

	void backTracking(vector<vector<char>>& board, int x, int y, TrieNode* node, vector<string>& res);
	vector<string> solveFindWords(vector<vector<char>>& board, vector<string>& words);
	TrieNode* buildTrie(vector<string>& words);


public:
	void solve();
};
