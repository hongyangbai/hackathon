#include "findWords.h"

void findWords::solve()
{
	/*vector<vector<char>> board = {{'o','a','a','n'},
							{'e','t','a','e'},
							{'i','h','k','r'},
							{'i','f','l','v'}};*/
	vector<string> inp = {"seenew","tmriva","obsibd","wmysen","ltsnsa","iezlgn"};
	vector<vector<char>> board;
	for(auto each:inp)
	{
		vector<char> tmp;
		for(int i = 0; i < each.size(); ++i)
		{
			tmp.push_back(each[i]);
		}
		board.push_back(tmp);
	}
	
	cout<<board;

	vector<string> words = {"nanes", "anes", "anesis"};
	//vector<string> words = {"oath","pea","eat","rain"};
	
	//vector<vector<char>> board = {{'a','a'}};
	//vector<string> words = {"a"};

	vector<string> found = solveFindWords(board, words);
	cout<<found;
}

vector<string> findWords::solveFindWords(vector<vector<char>>& board, vector<string>& words)
{
	TrieNode* root = buildTrie(words);

	vector<string> res;
	for(int i = 0; i < board.size(); ++i)
	{
		for(int j = 0; j < board[i].size(); ++j)
		{
			backTracking(board, i, j, root, res);
		}
	}
	return res;
}

void findWords::backTracking(vector<vector<char>>& board, int x, int y, TrieNode* node, vector<string>& res)
{
	char c = board[x][y];
	if(c == '#' || node->next[c-'a'] == NULL)
		return;
	node = node->next[c-'a'];

	if(!node->word.empty())
	{
		res.push_back(node->word);
		node->word.clear();
	}

	board[x][y] = '#';
	for(int i = 0; i < 4; ++i)
	{
		int newx = x+dirs[i].first;
		int newy = y+dirs[i].second;
		if(newx < 0 || newx == board.size() || newy < 0 || newy == board[0].size())
			continue;
		backTracking(board, newx, newy, node, res);
	}
	board[x][y] = c;
}

findWords::TrieNode* findWords::buildTrie(vector<string>& words)
{
	TrieNode* root = new TrieNode();
	for(auto word:words)
	{
		TrieNode* n = root;
		for(int i = 0; i < word.size(); ++i)
		{
			int idx = word[i]-'a';			
			if(n->next[idx] == NULL)
				n->next[idx] = new TrieNode();
			n = n->next[idx];
		}
		n->word = word;
	}
	return root;
}
