#include "removeKdigits.h"
void removeKdigits::solve()
{
	cout<<solveRemoveKdigits("10", 1)<<endl;
	cout<<solveRemoveKdigits("1234567890", 9)<<endl;
	cout<<solveRemoveKdigits("112", 1)<<endl;
	cout<<solveRemoveKdigits("32123", 3)<<endl;
	cout<<solveRemoveKdigits("1002", 4)<<endl;
}
string removeKdigits::solveRemoveKdigits(string num, int k)
{
	int digit = num.size()-k;
	vector<int> stk;
	for(int i = 0; i < num.size(); ++i)
	{
		while(!stk.empty() && stk.back() > num[i] && k > 0)
		{
			stk.pop_back();
			--k;
		}
		stk.push_back(num[i]);
	}

	string res;
	for(int j = 0; j < digit; ++j)
		res += stk[j];
	int i = 0;
	while(i < res.size() && stk[i]== '0')
		++i;

	return i == res.size() ? "0" : res.substr(i, res.size()-i);
}
