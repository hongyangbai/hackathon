#include "updateBoard.h"

void updateBoard::solve()
{
	vector<vector<char>> board = {{'E', 'E', 'E', 'E', 'E'},
								  {'E', 'E', 'M', 'E', 'E'},
								  {'E', 'E', 'E', 'E', 'E'},
								  {'E', 'E', 'E', 'E', 'E'}};
	cout<<board;
	vector<int> click = {1,2};
	board = solveUpdateBoard(board, click);
	cout<<endl;
	cout<<board;
}

void updateBoard::recursive(vector<vector<char>>& board, int x, int y)
{
	int minecount = 0;
	
	// Do BFS
	if(board[x][y] == 'E')
	{
		vector<pair<int, int>> rec;
		board[x][y] = 'B';
		for(int i = 0; i < dirs.size(); ++i)
		{
			int newx = x+dirs[i].first;
			int newy = y+dirs[i].second;
			if(newx < 0 || newx == board.size() || newy < 0 || newy == board[0].size())
				continue;
			if(board[newx][newy] == 'M')
				++minecount;
			else if(board[newx][newy] == 'E')
				rec.push_back(make_pair(newx, newy));
		}
		if(minecount > 0)
			board[x][y] = '1' + minecount - 1;
		else
		{
			for(auto each:rec)
				recursive(board, each.first, each.second);
		}
	}

}

vector<vector<char>> updateBoard::solveUpdateBoard(vector<vector<char>>& board, vector<int>& click)
{
	vector<vector<char>> res = board;
	int n = board.size();
	if(n == 0)	return res;
	int m = board[0].size();
	if(m == 0) 	return res;

	if(res[click[0]][click[1]] == 'M')
		res[click[0]][click[1]] = 'X';
	else
		recursive(res, click[0], click[1]);

	return res;
}
