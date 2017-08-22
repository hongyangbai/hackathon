#include "utils.h"
#include "Solution.h"
#include "complexNumberMultiply.h"
#include "singleNonDuplicate.h"
#include "countBattleships.h"
#include "reconstructQueue.h"

using namespace std;

extern const char* homedir;

class LeetRunner
{
	Solution* createNewSolution(const char *pname);
public:
	void solve(const char *pname);
};
