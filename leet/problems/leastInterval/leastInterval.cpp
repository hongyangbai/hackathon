#include "leastInterval.h"

void leastInterval::solve()
{
	vector<char> tasks = {'A','A','A','B','B','B'};
	//vector<char> tasks = {'A','A','A','B','C','D'};
	cout<<solveLeastInterval(tasks, 2)<<endl;
}

int leastInterval::solveLeastInterval(vector<char>& tasks, int n)
{
	unordered_map<char, int> ht;

	int maxcount = 0;
	for(auto c:tasks)
	{
		++ht[c];
		maxcount = max(ht[c], maxcount);
	}

	int res = 0;
	int nummax = 0;
	for(auto it = ht.begin(); it != ht.end(); ++it)
	{
		if(it->second == maxcount)
			++nummax;
	}
		
	return max((int)tasks.size(), (maxcount-1)*(n+1)+nummax);
}
