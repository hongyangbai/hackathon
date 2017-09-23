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

inline ListNode* makeLinkedList(vector<int>& nums);

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
