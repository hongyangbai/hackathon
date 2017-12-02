#include "maxProfit.h"

void maxProfit::solve()
{
	
}

int maxProfit::solveMaxProfit(vector<int>& prices, int fee)
{
	int n = prices.size();
	if(n < 2)	return 0;
	vector<int> hold(n, 0);
	vector<int> sold(n, 0);

	hold[0] = -prices[0];

	for(int i = 1; i < prices.size(); ++i)
	{
		hold[i] = max(hold[i-1], sold[i-1]-prices[i]);
		sold[i] = max(sold[i-1], hold[i-1]+prices[i] - fee);
	}

	return sold.back();
}
