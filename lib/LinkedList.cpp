#include "LinkedList.h"

LinkedList::~LinkedList()
{
	ListNode* cur = head;
	while(cur != NULL)
	{
		ListNode* next = cur->next;
		delete cur;
		cur = next;
	}
	head = NULL;
	tail = NULL;
}

void LinkedList::insert(ListNode* node)
{
}

void LinkedList::print()
{
	ListNode* cur = head;
	while(cur != NULL)
	{
		if(cur->next == NULL)
			printf("%d\n", cur->val);
		else
			printf("%d -> ", cur->val);
		cur = cur->next;
	}
}

void LinkedList::insert(int val)
{
	ListNode* newnode = new ListNode(val);
	if(tail)
		tail->next = newnode;
	else
		head = newnode;

	tail = newnode;
}
