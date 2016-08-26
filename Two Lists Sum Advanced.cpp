/*
Given two numbers represented by two linked lists, write a function that returns sum list.
The sum list is linked list representation of addition of two input numbers.

Example

Input:
  First  List: 5->6->3  // represents number 563
  Second List: 8->4->2  // represents number 842
Output
  Resultant list: 1->4->0->5  // represents number 1405

Challenge

Not allowed to modify the lists.
Not allowed to use explicit extra space.
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
	void push(ListNode *&head, int data) {
		ListNode *newNode = new ListNode(data);
		newNode->next = head;
		head = newNode;
	}

	int getsize(ListNode *head) {
		int count = 0;
		while(head) {
			count++;
			head = head->next;
		}
		return count;
	}

	void swap(ListNode* &l1, ListNode* &l2) {
		ListNode *tmp = l1;
		l1 = l2;
		l2 = tmp;
	}

	ListNode *addSameSize(ListNode *l1, ListNode *l2, int &carry) {
		if(!l1) return NULL;
		int sum;
		ListNode *res = (ListNode*)malloc(sizeof(ListNode));
		res->next = addSameSize(l1->next, l2->next, carry);
		sum = l1->val + l2->val + carry;
		carry = sum / 10;
		res->val = sum % 10;
		return res;
	}
	void addRemain(ListNode *l1, ListNode *end, int &carry, ListNode *&res) {
		int sum;
		if(l1 != end) {
			addRemain(l1->next, end, carry, res);
			sum = l1->val + carry;
			carry = sum / 10;
			sum = sum % 10;
			push(res, sum);
		}
	}

	 ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
	 	if(!l1) return l2;
	 	if(!l2) return l1;
	 	int size1 = getsize(l1);
	 	int size2 = getsize(l2);
	 	int diff = abs(size1 - size2);
	 	if(size1 < size2) {
	 		swap(l1, l2);
	 	}
	 	//cout << l1->val << endl;
	 	//cout << l2->val << endl;

	 	ListNode *cur = l1;
	 	ListNode *res;
	 	int carry = 0;
	 	for(int i = 0; i < diff; i++) cur = cur->next;
	 	res = addSameSize(cur, l2, carry);
	 	//cout << res->val << endl;
	 	addRemain(l1, cur, carry, res);
	 	if(carry) push(res, carry);
	 	return res;
	 }
};

int main() {
	Solution s;
	ListNode *l1 = new ListNode(2);
	//l1->next = new ListNode(2);
	//l1->next->next = new ListNode(5);
	ListNode *l2 = new ListNode(9);
	l2->next = new ListNode(9);
	l2->next->next = new ListNode(8);
	ListNode *res;
	res = s.addTwoNumbers(l1, l2);
	while(res) {
		cout << res->val << endl;
		res = res->next;
	}
	return 0;
}

