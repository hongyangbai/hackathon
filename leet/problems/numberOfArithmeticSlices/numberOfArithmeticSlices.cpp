#include "numberOfArithmeticSlices.h"

void numberOfArithmeticSlices::solve()
{
	vector<int> nums = {1,2,3,8,9,10};
	cout<<solveNumberOfArithmeticSlices(nums)<<endl;
}

int numberOfArithmeticSlices::solveNumberOfArithmeticSlices(vector<int>& A)
{
	int n = A.size();
	if(n == 0)	return 0;
	int diff = NAN;
	int len = 0;
	A.push_back(INT_MAX);

	int res = 0;

	for(int i = 1; i < A.size(); ++i)
	{
		if(i == 1)	
		{
			diff = A[i]-A[i-1];
			len = 2;
			continue;
		}
		
		if(A[i] - A[i-1] == diff)
			++len;
		else if(len > 2)
		{
			int N = len;
			res += (N*N - 3*N + 2)/2;
			diff= A[i]-A[i-1];
			len = 2;
		}
		else
		{
			diff = A[i]-A[i-1];
		}
		cout<<diff<<' '<<len<<endl;
	}

	A.pop_back();
	return res;
}
