#include "findMaximumXOR.h"

void findMaximumXOR::solve()
{
	vector<int> nums = {8,4,2,5};
	cout<<solveFindMaximumXOR(nums)<<endl;
}

int findMaximumXOR::solveFindMaximumXOR(vector<int>& nums)
{
	int mask = 0;
	int res = 0;
	for(int i = 31; i >= 0; --i)
	{
		mask |= (1<<i);
		cout<<"i: "<<i<<" and mask: "<<mask<<endl;
		unordered_set<int> ht;
		for(auto num:nums)
			ht.insert(num&mask);
		for(auto it = ht.begin(); it != ht.end(); ++it)
			cout<<*it<<endl;
		int tmp = res | (1<<i);
		for(auto it = ht.begin(); it != ht.end(); ++it)
		{
			if(ht.find(tmp ^ *it) != ht.end())
			{
				res = tmp;
				break;
			}
		}
		cout<<"res: "<<res<<" and tmp: "<<tmp<<endl;
	}

	return res;
}
