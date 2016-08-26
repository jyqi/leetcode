/*
You have two numbers represented by a linked list, where each node contains a single digit.
The digits are stored in reverse order, such that the 1’s digit is at the head of the list.
Write a function that adds the two numbers and returns the sum as a linked list.

Example
Given two lists, 3->1->5->null and 5->9->2->null, return 8->0->8->null
*/
#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
	 ListNode *addLists(ListNode *l1, ListNode *l2) {
	 	if(!l1) return l2;
	 	if(!l2) return l1;
	 	ListNode *dummy = new ListNode(-1);
	 	ListNode *p = dummy;
	 	p->next = l1;
	 	ListNode *q = l1;
	 	int sum = 0;
	 	int carry = 0;
	 	while(l1 && l2) {
	 		sum = l1->val + l2->val + carry;
	 		l1->val = sum % 10;
	 		carry = sum / 10;
	 		l1 = l1->next;
	 		p = p->next;
	 		l2 = l2->next;
	 	}
	 	if(l2) {
	 		p->next = l2;
	 		l1 = p->next;
	 	}
	 	while(l1) {
	 		sum = l1->val + carry;
	 		l1->val = sum % 10;
	 		carry = sum / 10;
	 		l1 = l1->next;
	 		p = p->next;
	 	}
	 	if(carry) {
	 		p->next = new ListNode(carry);
	 	}
	 	return dummy->next;
	 }
};

int main() {
	Solution s;
	ListNode *l1 = new ListNode(3);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(5);
	ListNode *l2 = new ListNode(5);
	l2->next = new ListNode(9);
	l2->next->next = new ListNode(3);
	ListNode *res;
	res = s.addLists(l1, l2);
	while(res) {
		cout << res->val << endl;
		res = res->next;
	}
	return 0;
}

