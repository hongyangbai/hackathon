#include "Solution.h"

Solution* Solution::s = 0;

Solution* Solution::instance()
{
	if(s == NULL)
		s = new Solution();
	return s;
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

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
	return NULL;
}


string replaceWords(vector<string>& dict, string sentence)
{

}
