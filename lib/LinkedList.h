#pragma once

#include "utils.h"

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	ListNode() : val(0), next(NULL) {}
};

inline ListNode* makeLinkedList(vector<int>& nums)
{
	if(nums.size() == 0)	return NULL;

	ListNode* head = new ListNode(nums[0]);
	ListNode* prev = head;
	for(int i = 1; i < nums.size(); ++i)
	{
		ListNode* cur = new ListNode(nums[i]);
		
		prev->next = cur;
		prev = cur;
	}
	return head;
}

class LinkedList
{
public:
	ListNode* head;
	ListNode* tail;

	LinkedList() : head(NULL), tail(NULL) {}
	~LinkedList();

	void insert(ListNode *node);
	void insert(int val);
	void print();
};
