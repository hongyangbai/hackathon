#include "findMaxLength.h"

void findMaxLength::solve()
{
	//vector<int> nums = {1,0,1,0,0,0};
	//vector<int> nums = {1,1,1,0,1,0,1,1,0,0};
	vector<int> nums = {1,0};
	cout<<solveFindMaxLength(nums)<<endl;
}

int findMaxLength::solveFindMaxLength(vector<int>& nums)
{
	for(int i = 0; i < nums.size(); ++i)
		nums[i] = nums[i] == 0 ? -1:1;

	int maxlen = 0;
	unordered_map<int, int> mp;
	mp[0] = -1;
	int cursum = 0;
	for(int i = 0; i < nums.size(); ++i)
	{
		cursum += nums[i];
		if(mp.find(cursum) != mp.end())
			maxlen = max(maxlen, i - mp[cursum]);
		else
			mp[cursum] = i;
	}
	return maxlen;
}
