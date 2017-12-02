#include "kthSmallest.h"

void kthSmallest::solve()
{
	vector<vector<int>> matrix = {{1,5,9},
								   {10,11,13},
								   {12,13,15}};

	cout<<solveKthSmallest(matrix, 6)<<endl;
}

int kthSmallest::solveKthSmallest(vector<vector<int>>& matrix, int k)
{
	int n = matrix.size();
	if(n == 0)	return NAN;
	if(matrix[0].size() == 0)	return NAN;
	
	struct Element
	{
		int i,j;
		int val;
		Element(int i, int j, int val) : i(i), j(j), val(val) {}
		bool operator<(const Element& b) const 	  {	return this->val > b.val;	}
	};

	priority_queue<Element> heap;
	
	for(int i = 0; i < n; ++i)
		heap.push(Element(0, i, matrix[0][i]));
	while(k-- > 1)
	{
		int i = heap.top().i;
		int j = heap.top().j;
		
		heap.pop();
		if(j < (n-1))
			heap.push(Element(i+1, j, matrix[i+1][j]));
	}
	return heap.top().val;
}
