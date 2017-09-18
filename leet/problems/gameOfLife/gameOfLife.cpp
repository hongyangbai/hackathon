#include "gameOfLife.h"

void gameOfLife::solve()
{
	/*vector<vector<int>> board = {{1,0,0,1},
								 {1,1,0,0},
								 {0,1,0,1},
								 {1,1,1,0}};*/
	vector<vector<int>> board = {{1,1},
								 {1,0}};
	cout<<board;
	solveGameOfLife(board);
	cout<<"----------"<<endl;
	cout<<board;
}

void gameOfLife::solveGameOfLife(vector<vector<int>>& board)
{
	int n = board.size();
	if(n == 0)	return;
	int m = board[0].size();
	if(m == 0)	return;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			// Check all the neighbors
			
			int cnt = 0;

			for(int I = max(0, i-1); I < min(n,i+2); ++I)
			{
				for(int J = max(0, j-1); J < min(m, j+2); ++J)
				{
					cnt += board[I][J] & 1;
				}
			}

			cnt -= board[i][j] & 1;

			cout<<cnt<<endl;

			if(cnt == 3)
				board[i][j] |= 2;

			if(cnt == 2 && (board[i][j]&1) == 1)
				board[i][j] |= 2;
		}
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			board[i][j] >>= 1;
		}
	}
}
