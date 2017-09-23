#include "addTwoNumbers.h"

void addTwoNumbers::solve()
{
	vector<int> num1 = {7,2,4,3};
	vector<int> num2 = {3, 5,6,4};
	ListNode* head1 = makeLinkedList(num1);
	ListNode* head2 = makeLinkedList(num2);

	cout<<head1;
	cout<<head2;

	cout<<solveAddTwoNumbers(head1, head2);
}

ListNode* addTwoNumbers::solveAddTwoNumbers(ListNode* l1, ListNode* l2)
{
	vector<int> stk1, stk2;

	while(l1)
	{
		stk1.push_back(l1->val);
		l1 = l1->next;
	}
	while(l2)
	{
		stk2.push_back(l2->val);
		l2 = l2->next;
	}

	ListNode* prev = NULL;

	int carry = 0;

	while(!stk1.empty() || !stk2.empty())
	{
		int cursum = 0;
		if(!stk1.empty())	
		{
			cursum += stk1.back();
			stk1.pop_back();
		}

		if(!stk2.empty())
		{
			cursum += stk2.back();
			stk2.pop_back();
		}

		
		ListNode* cur = new ListNode((cursum+carry) % 10);
		cur->next = prev;
		prev = cur;

		carry = (cursum+carry)>=10 ? 1:0;
	}

	ListNode* head = prev;
	if(carry > 0)
	{
		head = new ListNode(carry);
		head->next = prev;
	}

	return head;
}
