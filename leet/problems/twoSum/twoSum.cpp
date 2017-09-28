#include "twoSum.h"

void twoSum::solve()
{
	vector<int> nums = {-1,0,1,2,-1,-4};
	cout<<solve3sum(nums)<<endl;
}

vector<vector<int>> twoSum::solve3sum(vector<int>& nums)
{
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	for(int i = 0; i < nums.size(); ++i)
	{
		int target = -nums[i];
		int left = i + 1;
		int right = nums.size()-1;
		while(left < right)
		{
			if((nums[left]+nums[right])<target)
				++left;
			else if((nums[left]+nums[right])>target)
				--right;
			else
			{
				vector<int> subs;
				subs.push_back(nums[i]);
				subs.push_back(nums[left]);
				subs.push_back(nums[right]);
				res.push_back(subs);
				while(left < right && nums[left] == subs[1]) ++left;
				while(left < right && nums[right] == subs[2]) --right;
			}

		}

		while(i < (nums.size()-1) && nums[i+1] == nums[i]) ++i;
	}

	return res;
}

int twoSum::numPair(vector<int>& nums, int k)
{
	unordered_map<int, int> ht;
	int counter = 0;
	for(int i = 0; i < nums.size(); ++i)
	{
		if(ht.find(nums[i]) == ht.end())
			ht[k-nums[i]] = i;
		else
			++counter;
	}

	return counter;
}
