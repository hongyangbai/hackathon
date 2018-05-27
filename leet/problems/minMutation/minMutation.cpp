#include "minMutation.h"

void minMutation::solve()
{
	vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
	cout<<solveMinMutation("AACCGGTT", "AAACGGTA", bank)<<endl;
}

int minMutation::solveMinMutation(string start, string end, vector<string>& bank)
{
	int res = 0;
	queue<string> q;
	char genes[4] = {'A', 'C', 'G', 'T'};
	q.push(start);
	while(!q.empty())
	{
		int n = q.size();
		for(int k = 0; k < n; ++k)
		{
			string mut = q.front();
			if(mut == end)
				return res;

			q.pop();
			for(int i = 0; i < mut.size(); ++i)
			{
				char c = mut[i];
				for(int j = 0; j < 4; ++j)
				{
					mut[i] = genes[j];
					auto it = find(bank.begin(), bank.end(), mut);
					if(it != bank.end())
					{
						cout<<mut<<endl;
						q.push(mut);
						bank.erase(it);
					}
					mut[i] = c;
				}
			}
		}
		++res;
	}

	return res;
}
