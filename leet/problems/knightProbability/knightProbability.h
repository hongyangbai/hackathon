#include "Solution.h"

class knightProbability : public Solution
{
	double findProbability(int x, int y, int k);
	double solveKnightProbability(int N, int K, int r, int c);
public:
	void solve();
};
