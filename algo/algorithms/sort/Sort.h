#include "utils.h"
#include "print.h"

using namespace std;

// Merge Sort
vector<int> mergeSort(vector<int> nums);
vector<int> merge(vector<int> num1, vector<int> num2);
vector<int> partition(vector<int> nums, int l, int r);

// Heap Sort
void heapSort(vector<int>& nums);

// Bubble Sort
void bubbleSort(vector<int>& nums);

// Quick Sort
void quickSort(vector<int>& nums);

// Sort k-sorted
vector<int> sortKSorted(vector<int>& nums, int k);

// Insertion Sort
void insertionSort(vector<int>& nums);
