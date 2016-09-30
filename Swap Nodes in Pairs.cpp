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
	/*
	Iteration
    ListNode* swapPairs(ListNode* head) {
		if(!head || !head->next) return head;
		ListNode *dummy = new ListNode(-1);
		ListNode *last = dummy;
		last->next = head;
		ListNode *cur = head;
		while(cur && cur->next) {
			ListNode *tmp = cur->next->next;
			last->next = cur->next;
			cur->next = tmp;
			last->next->next = cur;
			last = cur;
			cur = cur->next;
		}
		return dummy->next;
    }
    */
    ListNode* swapPairs(ListNode* head) {
    	if(!head || !head->next) return head;
    	ListNode *after = head->next;
    	head->next = swapPairs(after->next);
    	after->next = head;
    	return after;
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
	ListNode *list = createList(4);
	Solution s;
	ListNode *res = s.swapPairs(list);
	while(res) {
		cout << res->val << endl;
		res = res->next;
	}
	return 0;
}