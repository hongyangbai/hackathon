#include "Array.h"

int findSecondSmallest(vector<int> nums)
{
	int first = INT_MAX;
	int second = INT_MAX;
	for(int i = 0; i < nums.size(); ++i)
	{
		if(nums[i] < first)
		{
			second = first;
			first = nums[i];
		}
		else if(nums[i] < second && first != nums[i])
			second = nums[i];
	}

	return second == INT_MAX ? -1 : second;
}
