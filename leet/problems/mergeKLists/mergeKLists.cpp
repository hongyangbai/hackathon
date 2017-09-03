#include "mergeKLists.h"

void mergeKLists::solve()
{
	LinkedList l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(4);

	l1.print();

	LinkedList l2;
	l2.insert(3);
	l2.insert(5);
	l2.insert(8);

	LinkedList l3;
	l3.insert(6);
	l3.insert(9);
	l3.print();

	LinkedList l4;
	l4.insert(7);

	vector<ListNode*> lists = {l1.head, l2.head, l3.head, l4.head};

	ListNode* head = solveMergeKLists(lists);
	while(head)
	{
		printf("%d ->", head->val);
		head = head->next;
	}
	cout<<endl;
}

ListNode* mergeKLists::solveMergeKLists(vector<ListNode*>& lists)
{
	if(lists.size() == 0)
		return NULL;
	if(lists.size() == 1)
		return lists[0];
	return recursive(lists, 0, lists.size()-1);
}

ListNode* mergeKLists::merge(ListNode* a, ListNode* b)
{
	ListNode* newhead = NULL;
	ListNode* cur = NULL;
	while(a || b)
	{
		ListNode* n = NULL;
		if(a && b)
		{
			if(a->val>b->val)
			{
				n = new ListNode(b->val);
				b = b->next;
			}
			else
			{
				n = new ListNode(a->val);
				a = a->next;
			}
		}
		else if(a)
		{
			n = new ListNode(a->val);
			a = a->next;
		}
		else if(b)
		{
			n = new ListNode(b->val);
			b = b->next;
		}

		if(n)
		{
			if(newhead)
			{
				cur->next = n;
				cur = n;
			}
			else
			{
				cur = n;
				newhead = n;
			}
		}
	}
	return newhead;
}

ListNode* mergeKLists::recursive(vector<ListNode*>& lists, int l, int r)
{
	if(l == r && l >= 0 && l < lists.size())
		return lists[l];

	if(r - l == 1)
		return merge(lists[l], lists[r]);

	return merge(recursive(lists, l, (l+r)/2), recursive(lists, (l+r)/2+1, r));

	return NULL;
}
