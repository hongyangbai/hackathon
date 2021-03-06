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
	int j = l;
	for(int i = l; i <= r; ++i)
	{
		if(nums[i] < nums[p])
			swap(nums[i], nums[j++]);
	}

	nums.insert(nums.begin()+j, nums[p]);
	nums.erase(nums.begin()+p+1);

	return j;
}

void quickSortRecursive(vector<int>& nums, int l, int r)
{
	if(l >= r)	return;

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

void heapify(vector<int>& nums, int idx, int end)
{
	if(idx > end)	return;

	int l = idx*2 + 1;
	int r = idx*2 + 2;

	int smallest = idx;
	if(l <= end && nums[l] < nums[smallest])	smallest = l;
	if(r <= end && nums[r] < nums[smallest])	smallest = r;

	if(smallest != idx)
	{
		swap(nums[idx], nums[smallest]);
		heapify(nums, smallest, end);
	}
}

void makeHeap(vector<int>& nums)
{
	for(int i = nums.size()/2; i >= 0; --i)
		heapify(nums, i, nums.size()-1);
}

void heapSort(vector<int>& nums)
{
	makeHeap(nums);
	cout<<nums;

	vector<int> sortednums;
	for(int i = nums.size()-1; i >= 0; --i)
	{
		sortednums.push_back(nums[0]);
		nums[0] = nums[i];
		heapify(nums, 0, i);
	}
	nums = sortednums;
}

void sortKSorted(vector<int>& nums, int k)
{
	vector<int> heap(nums.begin(), nums.begin()+k);
	vector<int> sortednums;
	makeHeap(heap);

	for(int i = k; i < nums.size(); ++i)
	{
		sortednums.push_back(heap[0]);
		heap[0] = nums[i];
		heapify(heap, 0, k);
	}

	for(int i = k-1; i >= 0; --i)
	{
		sortednums.push_back(heap[0]);
		heap[0] = heap[i];
		heapify(nums, 0, i);
	}

	nums = sortednums;
}

void insertionSort(vector<int>& nums)
{
	for(int i = 1, j = 0; i < nums.size(); ++i)
	{
		for(int k = 0; k <= j; ++k)
		{
			if(nums[k] > nums[i])
			{
				nums.insert(nums.begin()+k, nums[i]);
				nums.erase(nums.begin()+i+1);
				break;
			}
		}
		++j;
	}
}
