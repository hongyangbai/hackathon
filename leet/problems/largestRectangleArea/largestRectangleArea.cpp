#include "largestRectangleArea.h"

void largestRectangleArea::solve()
{
	vector<int> heights = {1,3,3,3,1};
	//vector<int> heights = {1,3,2};
	cout<<solveLargestRectangleArea(heights)<<endl;
}

int largestRectangleArea::solveLargestRectangleArea(vector<int>& heights)
{
	int res = 0;

	vector<int> idx;
	heights.push_back(0);

	for(int i = 0; i < heights.size(); ++i)
	{
		while(idx.size()>0 && heights[idx.back()] >= heights[i])
		{
			int h = heights[idx.back()];
			idx.pop_back();
			
			int l = idx.size() == 0 ? -1:idx.back();
			res = max(res, h*(i-l-1));
		}

		cout<<res<<endl;

		idx.push_back(i);
	}

	return res;
}
