#include "Solution.h"

class canPartitionKSubsets : public Solution
{
	bool solveCanPartitionKSubsets(vector<int>& nums, int k);
	bool partitionRecursive(vector<int>&nums, int i, vector<int>& subset, int subi, int subsum, int n, vector<bool>& taken);
public:
	void solve();
};
