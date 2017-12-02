#include "canPartitionKSubsets.h"

void canPartitionKSubsets::solve()
{
	vector<int> nums = {1,1,2,4};
	solveCanPartitionKSubsets(nums, 4) ? cout<<"true"<<endl : cout<< "false"<<endl;
}

bool canPartitionKSubsets::partitionRecursive(vector<int>&nums, int idx, vector<int>& subset, int subidx, int subsum, int n, vector<bool>& taken)
{
	if(subset[subidx] == subsum)
	{
		if(subidx == subset.size()-2)	return true;
		return partitionRecursive(nums, 0, subset, subidx+1, subsum, n, taken);
	}

	for(int i = idx; i < n; ++i)
	{
		if(taken[i])	continue;
		if(subset[subidx]+nums[i] <= subsum)
		{
			subset[subidx] += nums[i];
			taken[i] = true;
			bool rec = partitionRecursive(nums, i+1, subset, subidx, subsum, n, taken);
			taken[i] = false;
			subset[subidx] -= nums[i];
			if(rec) 	return true;
		}
	}

	return false;
}

bool canPartitionKSubsets::solveCanPartitionKSubsets(vector<int>& nums, int k)
{
	int n = nums.size();
	if(n < k)	return false;
	if(k == 1)	return true;
	int numsum = accumulate(nums.begin(), nums.end(), 0);
	if(numsum % k != 0)	return false;
	int subsum = numsum/k;

	vector<int> subset(k, 0);
	vector<bool> taken(n, false);
	return partitionRecursive(nums, 0, subset, 0, subsum, n, taken);
}
