#pragma once

#include "utils.h"

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class LinkedList
{
	ListNode* head;
public:
	void insert(ListNode *node);
};