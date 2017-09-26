#include "Solution.h"

class uniqueSubstring : public Solution
{
	void backTracking(string s, int k, int i, string sub, vector<string>& res);
	vector<string> solveUniqueSubstring(string s, int k);
public:
	void solve();
};
