#include "climbStairs.h"

void climbStairs::solve()
{
	cout<<solveClimbStairs(5)<<endl;
}

int climbStairs::solveClimbStairs(int n)
{
	if(n <= 1) return n;
	if(n == 2) return 2;
	if(n == 3) return 3;

	//return solveClimbStairs(n-1)+solveClimbStairs(n-2)+solveClimbStairs(n-3);
	
	int onestep = 3;
	int twostep = 2;
	int threestep = 1;
	int allsteps = 0;

	for(int i = 3; i < n; ++i)
	{
		allsteps = onestep+twostep+threestep;
		threestep = twostep;
		twostep = onestep;
		onestep = allsteps;
	}

	return allsteps;
}
