#include "findUnsortedSubarray.h"

void findUnsortedSubarray::solve()
{
	//vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
	vector<int> nums = {2, 3, 4, 8, 10, 9, 15};
	//vector<int> nums = {1,2,3,3,3};
	//vector<int> nums = {1,3,2,2,2};
	
	cout<<solveFindUnsortedSubarray(nums)<<endl;
}

int findUnsortedSubarray::solveFindUnsortedSubarray(vector<int>& nums)
{
	int minv = INT_MAX;
	int maxv = INT_MIN;

	int j = 0;
	int i = -1;
	for(int l = 0, r = nums.size()-1; r>=0; --r, ++l)
	{
		maxv = max(nums[l], maxv);
		if(maxv != nums[l]) i = l;

		minv = min(nums[r], minv);
		if(minv != nums[r]) j = r;
	}
	cout<<i<<" "<<j<<endl;
	return i-j+1;
}

