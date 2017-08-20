#include "countBattleships.h"

void countBattleships::solve()
{
	vector<vector<char>> board = {{'X','.','.','X'},
								  {'.','.','.','X'},
								  {'X','.','.','X'}};
	int res = solveCountBattleships(board);
	cout<<res<<endl;
}

int countBattleships::solveCountBattleships(vector<vector<char>>& board)
{ 
	int n = board.size();
	if(n == 0)	return 0;
	int m = board[0].size();
	if(m == 0) return 0;

	int count = 0;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(board[i][j] == 'X')
			{
				dfs(board, i, j, n, m, -1);
				++count;
			}
		}
	}

	return count;
}

void countBattleships::dfs(vector<vector<char>>& board, int x, int y, int n, int m, int dir)
{
	board[x][y] = '.';
	if(dir == -1 || dir == 1)
	{
		if(x>0 && board[x-1][y] == 'X')
			dfs(board, x-1, y, n, m, 1);
		if(x < (n-1) && board[x+1][y] == 'X')
			dfs(board, x+1, y, n, m, 1);
	}
	if(dir == -1 || dir == 2)
	{
		if(y>0 && board[x][y-1] == 'X')
			dfs(board, x, y-1, n, m, 2); 
		if(y < (m-1) && board[x][y+1] == 'X')
			dfs(board, x, y+1, n, m, 2); 
	}
}
