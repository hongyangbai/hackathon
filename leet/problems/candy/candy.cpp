#include "candy.h"

void candy::solve()
{
	//vector<int> ratings = {1,2,3,4,5,4,3,2,1};
	vector<int> ratings = {1,2,1};

	cout<<solveCandy(ratings)<<endl;
}
int candy::solveCandy(vector<int>& ratings)
{
	int n = ratings.size();
	vector<int> nums(n, 1);

	for(int i = 1; i < n; ++i)
	{
		if(ratings[i] > ratings[i-1])
			nums[i] = nums[i-1]+1;
	}

	cout<<nums;

	for(int i = n-2; i >= 0; --i)
	{
		if(ratings[i] > ratings[i+1])
			nums[i] = max(nums[i+1]+1, nums[i]);
	}

	cout<<nums;

	int candies = 0;
	for(auto num:nums)
		candies += num;

	return candies;

}
