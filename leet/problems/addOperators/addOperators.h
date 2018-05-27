#include "Solution.h"

class addOperators : public Solution
{
	vector<pair<int, string>> recursive(string num, int target, int l, int r);
	vector<string> solveAddOperators(string num, int target);
public:
	void solve();
};
