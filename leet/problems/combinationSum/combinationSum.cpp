#include "combinationSum.h"

void combinationSum::solve()
{
	vector<int> nums = {1,2,3};
	cout<<solveCombinationSum4(nums, 4);
}

void combinationSum::backTracking(vector<int>& candidates, int idx, int target, vector<int> subres, vector<vector<int>>& res)
{
	if(target < 0)
		return;
	if(target == 0)
	{
		res.push_back(subres);
		return;
	}

	for(int i = idx; i < candidates.size(); ++i)
	{
		if(i == idx || candidates[i] != candidates[i-1])
		{
			subres.push_back(candidates[i]);
			backTracking(candidates, i+1, target-candidates[i], subres, res);
			subres.pop_back();
		}
	}
}

void combinationSum::backTracking4(vector<int>& candidates, int idx, int target, vector<int> subres, vector<vector<int>>& res)
{
	if(target < 0)
		return;
	if(target == 0)
	{
		res.push_back(subres);
		return;
	}

	for(int i = 0; i < candidates.size(); ++i)
	{
		subres.push_back(candidates[i]);
		backTracking4(candidates, i, target-candidates[i], subres, res);
		subres.pop_back();
	}
}

void combinationSum::backTracking(int idx, int k, int n, vector<int> subres, vector<vector<int>>& res)
{
	if(n < 0)
		return;
	if(n == 0 && k == 0)
	{
		res.push_back(subres);
		return;
	}

	for(int i = idx; i < 10; ++i)
	{
		subres.push_back(i);
		backTracking(i+1, k-1, n-i, subres, res);
		subres.pop_back();
	}
}

vector<vector<int>> combinationSum::solveCombinationSum3(int k, int n)
{
	vector<vector<int>> res;
	vector<int> subres;
	backTracking(1, k, n, subres, res);
	return res;
}

vector<vector<int>> combinationSum::solveCombinationSum4(vector<int>& candidates, int target)
{
	vector<vector<int>> res;
	vector<int> subres;
	backTracking4(candidates, 0, target, subres, res);
	return res;
}

vector<vector<int>> combinationSum::solveCombinationSum(vector<int>& candidates, int target)
{
	vector<vector<int>> res;
	vector<int> subres;
	sort(candidates.begin(), candidates.end());
	backTracking(candidates, 0, target, subres, res);
	return res;
}
