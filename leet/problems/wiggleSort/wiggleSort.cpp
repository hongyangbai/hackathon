#include "wiggleSort.h"

void wiggleSort::solve()
{
	//vector<int> nums = {3,2,1,4,6,5};
	vector<int> nums = {2,1,1};
	solveWiggleSort2(nums);
	cout<<nums;
}

void wiggleSort::solveWiggleSort2(vector<int>& nums)
{
	vector<int> sorted = nums;
	sort(sorted.begin(), sorted.end());
	
	for(int i = 0, j = 0, k = (nums.size()-1)/2+1; i < nums.size(); ++i)
	{
		nums[i] = sorted[i%2 ? k++:j++];		
	}
}

void wiggleSort::solveWiggleSort(vector<int>& nums)
{
	for(int i = 1; i < nums.size(); ++i)
	{
		if(i % 2 && nums[i] < nums[i-1])
			swap(nums[i], nums[i-1]);
		if(!(i % 2) && nums[i] > nums[i-1])
			swap(nums[i], nums[i-1]);
	}
}
