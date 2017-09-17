#include "findLonelyPixel.h"

void findLonelyPixel::solve()
{
	vector<vector<char>> picture = {{'B', 'W', 'B'},
									{'W', 'B', 'W'},
									{'B', 'W', 'W'}};

	cout<<solveFindLonelyPixel(picture)<<endl;
}

int findLonelyPixel::dfs(vector<vector<char>>& picture, int x, int y, int diri)
{
	int pixels = 0;
	char p = picture[x][y];
	if(picture[x][y] == 'B')
		++pixels;
	picture[x][y] = 'Z';

	int newx = x+dirs[diri].first;
	int newy = y+dirs[diri].second;

	if(newx>=0 && newy>=0 && newx < picture.size() && newy < picture[0].size() && picture[newx][newy] != 'Z')
		pixels += dfs(picture, newx, newy, diri);

	picture[x][y] = p;

	return pixels;
}

int findLonelyPixel::solveFindLonelyPixel(vector<vector<char>>& picture)
{
	int res = 0;

	int n = picture.size();
	if(n == 0)	return res;
	int m = picture[0].size();
	if(m == 0)	return res;
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(picture[i][j] == 'B')
			{
				int num = 0;
				picture[i][j] = 'Z';
				for(int diri = 0; diri < 4; ++diri)
 					num += dfs(picture, i, j, diri);
				if(num == 0)
					++res;
				picture[i][j] = 'B';
				cout<<i<<" "<<j<<" "<<num<<endl;
			}
		}
	}

	return res;
}
