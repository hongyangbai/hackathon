#include "Solution.h"

class kSubstring : public Solution
{
	vector<string> solveKSubstring(string s, int k);
	void backTracking(string& s, int idx, int k, string& curs, vector<string>& res);
public:
	void solve();
};
