#include <iostream>
using namespace std;

/**
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

Example
For example,
Given 1->2->3->4->null, reorder it to 1->4->2->3->null.

*/
 //* Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
	ListNode *reverse(ListNode *list) {
		ListNode *pre = NULL;
		while(list) {
			ListNode *tmp = list->next;
			list->next = pre;
			pre = list;
			list = tmp;
		}
		return pre;
	}

	ListNode *merge(ListNode *l1, ListNode *l2) {
		ListNode *dummy = new ListNode(-1);
		ListNode *last = dummy;
		bool flag = true;
		while(l1 && l2) {
			if(flag) {
				last->next = l1;
				l1 = l1->next;
				flag = !flag;
			}
			else {
				last->next = l2;
				l2 = l2->next;
				flag = !flag;
			}
			last = last->next;
		}
		if(l2) {
			last->next = l2;
		}
		return dummy->next;
	}

    void reorderList(ListNode* head) {
  	     if(!head || !head->next) return;
  	     ListNode *slow = head;
  	     ListNode *fast = head->next;
  	     while(fast->next && fast->next->next) {
  	     	slow = slow->next;
  	     	fast = fast->next->next;
  	     }
  	     ListNode *l1 = head;
  	     ListNode *l2 = slow->next;
  	     slow->next = NULL;
  	     l2 = reverse(l2);
  	     head = merge(l1, l2);
  	     return;
    }
};

ListNode *createList(int len) {
	ListNode *dummy = new ListNode(-1);
	ListNode *last = dummy;
	for(int i = 1; i <= len; i++) {
		last->next = new ListNode(i);
		last = last->next;
	}
	return dummy->next;
}
int main() {
	ListNode *l = createList(4);
	Solution s;
	s.reorderList(l);
	while(l) {
		cout << l->val << endl;
		l = l->next;
	}
	return 0;
}