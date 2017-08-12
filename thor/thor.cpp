#include "solution.h"

using namespace std;

int singleNonDuplicate(vector<int>& nums);

int main(int argc, char *argv[])
{	
	//vector<int> nums = {1,1,2,3,3,4,4,8,8};
	vector<int> nums = {3,3,7,7,10,11,11};
	cout<<singleNonDuplicate(nums)<<endl;
	return 0;
}
