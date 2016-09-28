#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
	void splitList(ListNode* head, ListNode *&l1, ListNode *&l2) {
		ListNode *slow = head;
		ListNode *fast = head->next;
		while(fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		l2 = slow->next;
		slow->next = NULL;
		l1 = head;
	}

	ListNode *merge(ListNode *l1, ListNode *l2) {
		ListNode *dummy = new ListNode(-1);
		ListNode *last = dummy;
		while(l1 && l2) {
			if(l1->val < l2->val) {
				last->next = l1;
				l1 = l1->next;
			}
			else {
				last->next = l2;
				l2 = l2->next;
			}
			last = last->next;
		}
		if(l1) {
			last->next = l1;
		}
		if(l2) {
			last->next = l2;
		}
		return dummy->next;
	}

    ListNode* sortList(ListNode* head) {
    	if(!head || !head->next) {
    		return head;
    	}
    	ListNode *left, *right;
    	splitList(head, left, right);
		left = sortList(left);
		right = sortList(right);    	
		return merge(left, right);
    }
};

int main() {
	ListNode *head = new ListNode(3);
	ListNode *tmp = head;
	tmp->next = new ListNode(2);
	tmp = tmp->next;
	tmp->next = new ListNode(5);
	tmp = tmp->next;
	tmp->next = new ListNode(1);
	tmp = tmp->next;
	tmp->next = new ListNode(4);
	tmp = tmp->next;
	tmp->next = NULL;
	Solution s;
	head = s.sortList(head);
	while(head) {
		cout << head->val << endl;
		head = head->next;
	}
}