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

ListNode* makeLinkedList(vector<int>& nums)
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
