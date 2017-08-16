#include "Solution.h"

Solution* Solution::s = 0;

Solution* Solution::instance()
{
	if(s == NULL)
		s = new Solution();
	return s;
}

void Solution::run(const char* pname)
{
	DIR *dir;
	struct dirent *ent;
	bool found = false;

	char ppath[100];
	sprintf(ppath, "%s%s", homedir, "/work/hackathon/leet/problems/");
	vector<string> availpnames;
	if ((dir = opendir (ppath)) != NULL) {
		while ((ent = readdir (dir)) != NULL) 
		{
			if(strcmp(".", ent->d_name) == 0 || strcmp("..", ent->d_name) == 0)
				continue;
			availpnames.push_back(string(ent->d_name));
			if(strcmp(ent->d_name, pname) == 0)
				found = true;
		}
		closedir (dir);
	}

	if(found)
		printf("Running solution for [%s]:\n", pname);
	else
	{
		printf("Error: problem solution not created yet, available problems:\n");
		for(int i = 0; i < availpnames.size(); ++i)
			printf("%d. %s\n", i+1, availpnames[i].c_str());
	}
}

int Solution::singleNonDuplicate(vector<int>& nums)
{
	if(nums.empty())	return 0;
	int l = 0;
	int r = nums.size();
	int i = (l+r)/2;

	while(1)
	{
		i = (l+r)/2;
		if(i == 0 && nums[i+1] != nums[i])
			break;
		else if(i == nums.size()-1 && nums[i-1] != nums[i])
			break;
		else if(i > 0 && i < (nums.size()-1) && (nums[i] != nums[i-1] && nums[i] != nums[i+1]))
			break;

		if(nums[i-1] == nums[i])
		{
			if((i-l) % 2 == 0)
				r = i-2;
			else
				l = i+1;
		}

		if(nums[i+1] == nums[i])
		{
			if((i-l)%2 == 0)
				l = i+2;
			else
				r = i-1;
		}
	}
	
	return nums[i];
}

TreeNode* Solution::buildTree(vector<int>& inorder, vector<int>& postorder)
{
	return NULL;
}

string Solution::replaceWords(vector<string>& dict, string sentence)
{
	string res;
	istringstream iss(sentence);
	vector<string> tokens;
	copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));
	for(int i = 0; i < tokens.size(); ++i)
	{
		int suc = -1;
		int shortest = INT_MAX;
		for(int j = 0; j < dict.size(); ++j)
		{
			if(tokens[i].substr(0, dict[j].length()) == dict[j])
			{
				if(dict[j].length() < shortest)
				{
					shortest = dict[j].length();
					suc = j;
				}
			}
		}
		if(suc > -1)
			res += dict[suc];
		else
			res += tokens[i];
		res += " ";
	}

	return res.substr(0, res.length()-1);
}

bool Solution::pairComp(vector<int> a, vector<int> b)
{
	return (a[1] == b[1] ? a[0] < b[0] : a[1]<b[1]);
}

int Solution::findLongestChain(vector<vector<int>>& pairs)
{
	int counter = 0;
	vector<int> pre = pairs[0];
	sort(pairs.begin(), pairs.end(), pairComp);
	for(int i = 0; i < pairs.size(); ++i)
	{
		if(i == 0 || pairs[i][0]>pre[1])
		{
			++counter;
			pre = pairs[i];
		}
	}

	return counter;
}

void Solution::backTracking(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur, int s)
{
	if(cur.size() > 1)
		res.push_back(cur);

	unordered_set<int> uni;
	for(int i = s; i < nums.size(); ++i)
	{
		if(s > 0 && nums[i] < nums[s-1])	continue;
		if(uni.find(nums[i]) == uni.end())
		{
			uni.insert(nums[i]);
			cur.push_back(nums[i]);
			backTracking(nums, res, cur, i+1);
			cur.pop_back();
		}
	}
}

vector<vector<int>> Solution::findSubsequences(vector<int>& nums)
{
	vector<int> cur;
	vector<vector<int>> res;
	backTracking(nums, res, cur, 0);
	return res;
}

void dfs(int target, vector<int>& nums, int s, int& res)
{
	if(s == nums.size())
	{
		if(target == 0)
			++res;
		return;
	}
	
	dfs(target-nums[s], nums, s+1, res);
	dfs(target+nums[s], nums, s+1, res);
}

int Solution::findTargetSumWays(vector<int>& nums, int S)
{
	int res = 0;
	dfs(S, nums, 0, res);
	return res;
}
