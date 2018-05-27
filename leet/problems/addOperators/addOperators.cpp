#include "addOperators.h"

void addOperators::solve()
{
	cout<<solveAddOperators("1242", 16)<<endl;
}

vector<pair<int, string>> addOperators::recursive(string num, int target, int s, int e)
{
	if(s < 0 || e >= num.size() || s > e)	return vector<pair<int, string>>();
	if(s == e)	return {{atoi(num.substr(s,1).c_str()), num.substr(s,1)}};

	vector<pair<int, string>> res;
	for(int i = s; i < e; ++i)
	{
		vector<pair<int, string>> left = recursive(num, target, s, i);
		vector<pair<int, string>> right = recursive(num, target, i+1, e);
		
		
		for(auto& l:left)
		{
			for(auto& r:right)
			{
				//cout<<l.first<<" "<<l.second<<endl;
				//cout<<r.first<<" "<<r.second<<endl;
				if((l.second.size() == 1 || l.second[l.second.size()-2] == '*') && (r.second.size() == 1 || r.second[1] == '*'))
					res.push_back({l.first*r.first, l.second+"*"+r.second});
				res.push_back({l.first+r.first, l.second+"+"+r.second});
				res.push_back({l.first-r.first, l.second+"-"+r.second});
			}
		}
	}
	
	string numcpy;
	int i = 0;
	while(i <= e)
	{
		if(num[i] != '0')
			numcpy += num[i];
		++i;
	}
	if(numcpy != "")
		res.push_back({atoi(num.substr(s, e-s+1).c_str()), num.substr(s, e-s+1)});

	return res;
}

vector<string> addOperators::solveAddOperators(string num, int target)
{
	if(num.empty())	return vector<string>();

	vector<string> res;
	
	vector<pair<int, string>> ret = recursive(num, target, 0, num.size()-1);
	unordered_set<string> ht;
	for(auto& r:ret)
	{
		if(r.first == target && ht.find(r.second) == ht.end())	
		{
			res.push_back(r.second);
			ht.insert(r.second);
		}
	}

	return res;
}
