#include "Solution.h"
//#include "print.h"

class findMaxForm : public Solution
{
	int solveFindMaxForm(vector<string>& strs, int m, int n);
	pair<int, int> getCount(const string& s);
public:
	void solve();
};
