#include "Solution.h"
#include "LinkedList.h"

class mergeKLists : public Solution
{
	ListNode* solveMergeKLists(vector<ListNode*>& lists);
	ListNode* recursive(vector<ListNode*>& lists, int l, int r);
	ListNode* merge(ListNode* a, ListNode* b);
public:
	void solve();
};
