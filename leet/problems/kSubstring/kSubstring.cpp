#include "kSubstring.h"

void kSubstring::solve()
{
	string s = "abc";
	cout<<solveKSubstring(s, 3);

}
void kSubstring::backTracking(string& s, int idx, int k, string& curs, vector<string>& res)
{
	if(k == 0)
	{
		res.push_back(curs);	
		return;
	}

	for(int i = idx; i < s.size(); ++i)
	{
		curs += s[i];
		backTracking(s, i+1, k-1, curs, res);
		curs = curs.substr(0, curs.size()-1);
	}
}

vector<string> kSubstring::solveKSubstring(string s, int k)
{
	vector<string> res;	
	string curs;
	backTracking(s, 0, k, curs, res);
	return res;
}
