#include "nextGreaterElements.h"
void nextGreaterElements::solve()
{
	vector<int> nums1 = {1,2,1};
	vector<int> nums2 = {6,5,4,3,2,1,7};
	vector<int> nums3;

	//cout<<solveNextGreaterElement(nums1, nums2);
	cout<<solveNextGreaterElements(nums3);
}

vector<int> nextGreaterElements::solveNextGreaterElements(vector<int>& nums)
{
	vector<int> res(nums.size(), -1);
	if(nums.empty())	return res;
	vector<pair<int, int>> stk;
	for(int i = 0; i < nums.size(); ++i)
	{
		while(!stk.empty() && stk.back().first < nums[i])
		{
			res[stk.back().second] = nums[i];
			stk.pop_back();
		}
		stk.push_back(make_pair(nums[i], i));
	}

	for(int i = 0; i < nums.size()-1; ++i)
	{
		while(nums[i] > stk.back().first)
		{
			res[stk.back().second] = nums[i];
			stk.pop_back();
		}
	}
	return res;
}

vector<int> nextGreaterElements::solveNextGreaterElement(vector<int>& findNums, vector<int>& nums)
{
	vector<int> stk;
	unordered_map<int, int> mp;
	for(auto num:findNums)
		mp[num] = -1;
	for(auto num:nums)
	{
		while(!stk.empty() && num > stk.back())
		{
			if(mp.find(stk.back()) != mp.end())
				mp[stk.back()] = num;
			stk.pop_back();
		}
		stk.push_back(num);
	}
	vector<int> res;
	for(auto num:findNums)
		res.push_back(mp[num]);
	return res;
}
