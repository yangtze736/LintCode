/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4) Output: 7 -> 0 -> 8

分析
	给定两个链表，返回其相加的结果。注意链表是倒序的，即第一位是个位。
	342 + 465 = 807
 */

#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {  }
};

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *res = new ListNode(0);
		ListNode *cur = res;
		int carry = 0;
		while (l1 || l2) {
			int n1 = l1 ? l1->val : 0;
			int n2 = l2 ? l2->val : 0;
			int sum = n1 + n2 + carry;
			carry = sum / 10;
			cur->val = sum % 10;
			if (l1) l1 = l1->next;
			if (l2) l2 = l2->next;
			if (l1 || l2) {
				cur->next = new ListNode(0);
				cur = cur->next;
			}
		}
		//最高位进位
		if (carry) cur->next = new ListNode(1);
		return res;
	}
};

int main()
{
	ListNode *p1 = new ListNode(2);
	p1->next = new ListNode(4);
	p1->next->next = new ListNode(8);

	ListNode *p2 = new ListNode(5);
	p2->next = new ListNode(6);
	p2->next->next = new ListNode(4);

	Solution solu;
	ListNode *ret = solu.addTwoNumbers(p1, p2);

	ListNode *p = ret;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;

	while (p1 != NULL) {ListNode *p = p1; p1 = p1->next; delete p;}
	while (p2 != NULL) {ListNode *p = p2; p2 = p2->next; delete p;}
	while (ret != NULL) {ListNode *p = ret; ret = ret->next; delete p;}
	
	return 0;
}
