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
    ListNode* insertionSortList(ListNode* head) {
    	ListNode *dummy = new ListNode(-1);
    	dummy->next = head;
    	ListNode *cur1, *cur2, *last, *tmp;
     	for(cur1 = head; cur1 != NULL; ) {
     		if(cur1->next && cur1->next->val < cur1->val) {
     			//tmp = cur1->next->next;
	     		last = dummy;
	     		while(last->next && last->next->val <= cur1->next->val) {
	     			last = last->next;
	     		}
	     		tmp = last->next;
	     		last->next = cur1->next;
	     		cur1->next = cur1->next->next;
	     		last->next->next = tmp;
     		}
     		else {
     			cur1 = cur1->next;
     		}
     	}
     	return dummy->next;   
    }
};

ListNode *createList(int len) {
	ListNode *dummy = new ListNode(-1);
	ListNode *last = dummy;
	for(int i = len; i >= 0; i--) {
		last->next = new ListNode(i);
		ListNode *tmp = last->next;
		last = last->next;
	} 
	return dummy->next;
}

int main() {
	ListNode *head = createList(5);
	Solution s;
	head = s.insertionSortList(head);
	while(head) {
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}