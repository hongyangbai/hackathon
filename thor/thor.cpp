#include "Solution.h"

using namespace std;

int main(int argc, char *argv[])
{	
	vector<vector<int>> pairs = {{1,2},{2,3},{3,4}};
	cout<<Solution::instance()->findLongestChain(pairs)<<endl;
	return 0;
}
