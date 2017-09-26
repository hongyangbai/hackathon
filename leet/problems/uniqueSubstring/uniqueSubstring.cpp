#include "uniqueSubstring.h"

void uniqueSubstring::solve()
{
	string s("caaab");

	cout<<solveUniqueSubstring(s, 2);
}

void uniqueSubstring::backTracking(string s, int k, int i, string sub, vector<string>& res)
{
	if(sub.size() == k)
	{
		res.push_back(sub);
		return;
	}

	for(int j = i; j < s.size(); ++j)
	{
		if(j == 0 || s[j] != s[j-1])
		backTracking(s, k, j+1, sub+s[j], res);
	}
}

vector<string> uniqueSubstring::solveUniqueSubstring(string s, int k)
{
	vector<string> res;
	string sub;
	backTracking(s, k, 0, sub, res);
	sort(res.begin(), res.end());
	return res;
}
