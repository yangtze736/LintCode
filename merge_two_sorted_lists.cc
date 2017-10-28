/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes
of the first two lists.
 */

#include<vector>
#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode *dummy = new ListNode(-1);
		ListNode *head = dummy;

		while( l1 != nullptr && l2 != nullptr ) {
			if( l1->val <= l2->val ) {
				dummy->next = l1;
				dummy = dummy->next;
				l1 = l1->next;
			} else {
				dummy->next = l2;
				dummy = dummy->next;
				l2 = l2->next;
			}
		}

		dummy->next = l1 ? l1 : l2; 
		return head->next;
	}
};

int main()
{
	ListNode *p1 = new ListNode(2);
	p1->next = new ListNode(3);
	p1->next->next = new ListNode(4);
	p1->next->next->next = new ListNode(8);

	ListNode *p2 = new ListNode(1);
	p2->next = new ListNode(3);
	p2->next->next = new ListNode(5);
	p2->next->next->next = new ListNode(10);

	Solution solu;
	ListNode *ret = solu.mergeTwoLists(p1, p2);

	while( ret != nullptr ) {
		cout << ret->val << " ";
		ret = ret->next;
	}
	cout << endl;

	// delete something todo
	return 0;
}


