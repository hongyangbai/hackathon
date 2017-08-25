#include "numMatrix.h"

numMatrix::numMatrix()
{
	/*vector<vector<int>> matrix = {{1,2,3},
							      {4,5,6},
								  {7,8,9}};*/
	
	vector<vector<int>> matrix;
	
	init(matrix);
}

void numMatrix::solve()
{
	//cout<<sumRegion(0,1,2,1)<<endl;
}

void numMatrix::init(vector<vector<int>> matrix)
{
	if(matrix.size() == 0)	return;
	if(matrix[0].size() == 0) return;
	accum = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
	accum = matrix;
	for(int i = 0; i < matrix.size(); ++i)
	{
		if(i > 0)
			accum[i][0] = accum[i-1][0]+matrix[i][0];

		for(int j = 1; j < matrix[i].size(); ++j)
		{
			if(i == 0)
				accum[i][j] = accum[i][j-1]+matrix[i][j];
			else
				accum[i][j] = accum[i-1][j] + accum[i][j-1] - accum[i-1][j-1] + matrix[i][j];
		}
	}
}
    
int numMatrix::sumRegion(int row1, int col1, int row2, int col2)
{
	if(row1 == 0 && col1 == 0)
		return accum[row2][col2];
	else if(row1 == 0)
		return accum[row2][col2] - accum[row2][col1-1];
	else if(col1 == 0)
		return accum[row2][col2] - accum[row1-1][col2];
	else
		return accum[row2][col2] - accum[row2][col1-1] - accum[row1-1][col2] + accum[row1-1][col1-1];
}
