#include "Solution.h"

using namespace std;

int main(int argc, char *argv[])
{	
	Solution *s = Solution::instance();
	vector<int> nums = {1,2,2};
	cout<<s->singleNonDuplicate(nums)<<endl;
	return 0;
}
