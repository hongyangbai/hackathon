#include "findMedianSortedArrays.h"

void findMedianSortedArrays::solve()
{
	vector<int> nums1 = {1,3,5,7,9};
	vector<int> nums2 = {2,4,6,8};
	cout<<solveFindMedianSortedArrays(nums1, nums2)<<endl;
}

double findMedianSortedArrays::solveFindMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int m = nums1.size();
	int n = nums2.size();

	if(m > n)
		return solveFindMedianSortedArrays(nums2, nums1);

	int ileft = 0;
	int iright = m;
	int halflen = (n+m+1)/2;

	while(ileft <= iright)
	{
		int i = (ileft+iright)/2;
		int j = halflen-i;

		if(i > 0 && nums1[i-1] > nums2[j])
			iright = i-1;
		else if(i < m && nums2[j-1]>nums1[i])
			ileft = i+1;
		else
		{
			int maxleft;
			if(i == 0)
				maxleft = nums2[j-1];
			else if(j == 0)
				maxleft = nums1[i-1];
			else
				maxleft = max(nums1[i-1],nums2[j-1]);

			int minright;
			if(i == m)
				minright = nums2[j];
			else if(j == n)
				minright = nums1[i];
			else 
				minright = min(nums1[i], nums2[i]);

			if((m+n)%2 == 1)
				return maxleft;
			else
				return (maxleft+minright)/2;
		}
	}

	return -1;
}
