#include "Sort.h"

vector<int> merge(vector<int> num1, vector<int> num2)
{
	vector<int> nums(num1.size()+num2.size());
	int i = 0; 
	int j = 0;
	
	int k = 0;
	while(i < num1.size() || j < num2.size())
	{
		if(i < num1.size() && j < num2.size())
		{
			if(num1[i] < num2[j])
				nums[k++] = num1[i++];
			else
				nums[k++] = num2[j++];
		}
		else if(i == num1.size())
		{
			nums[k++] = num2[j++];
		}
		else
		{
			nums[k++] = num1[i++];
		}
	}
	return nums;
}

vector<int> partition(vector<int> nums, int l, int r)
{
	if(l == r)
		return vector<int>(nums.begin()+l, nums.begin()+r+1);
	else
		return merge(partition(nums, l,(l+r)/2),  partition(nums, (l+r)/2+1, r));

}

vector<int> mergeSort(vector<int> nums)
{
	return partition(nums, 0, nums.size()-1);
}

int partition(vector<int>& nums, int l, int r, int p)
{
	int j = l-1;
	for(int i = l; i <= r; ++i)
	{
		if(nums[i] <= nums[p])
		{
			++j;
			swap(nums[j], nums[i]);
		}
	}
	nums.insert(nums.begin()+j+1, nums[p]);
	nums.erase(nums.begin()+p+1);
	return j+1;
}

void quickSortRecursive(vector<int>& nums, int l, int r)
{
	if(r < l)	return;

	int p = partition(nums, l, r-1, r);
	quickSortRecursive(nums, l, p-1);
	quickSortRecursive(nums, p+1, r);
}

void quickSort(vector<int>& nums)
{
	quickSortRecursive(nums, 0, nums.size()-1);
}

void bubbleSort(vector<int>& nums)
{

	for(int i = nums.size(); i >= 0; --i)
	{
		for(int j = 1; j < i; ++j)
		{
			if(nums[j] < nums[j-1])
				swap(nums[j],nums[j-1]);
		}
	}
}	

void heapify(vector<int>& nums, int n, int i)
{
	int l = 2*i + 1;
	int r = 2*i + 2;

	int largest = i;

	largest = (l<n && nums[l]>nums[largest]) ? l:largest;
	largest = (r<n && nums[r]>nums[largest]) ? r:largest;
		
	if(largest != i)
	{
		swap(nums[i], nums[largest]);
		heapify(nums, n, largest);
	}
}

void heapSort(vector<int>& nums)
{
	for(int i = nums.size()/2; i >= 0; --i)
		heapify(nums, nums.size(), i);
	for(int i = nums.size()-1; i>=0; --i)
	{
		swap(nums[i], nums[0]);
		heapify(nums, i, 0);
	}
			
}
