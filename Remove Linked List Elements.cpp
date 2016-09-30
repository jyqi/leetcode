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
	Recursive
    ListNode* removeElements(ListNode* head, int val) {
		if(!head) {
			return NULL;
		}        
		if(head->val == val) {
			return removeElements(head->next, val);
		}
		else {
			head->next = removeElements(head->next, val);
			return head;
		}
    }
    */
    ListNode* removeElements(ListNode* head, int val) {
    	if(!head) {
    		return NULL;
    	}
    	ListNode *dummy = new ListNode(-1);
    	ListNode *last = dummy;
    	last->next = head;
    	while(head) {
    		if(head->val == val) {
    			last->next = head->next;
    			delete head;
    			head = last->next;
    			continue;
    		}
    		last = last->next;
    		head = head->next;
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
	ListNode *list = createList(4);
	Solution s;
	ListNode *res = s.removeElements(list, 2);
	while(res) {
		cout << res->val << endl;
		res = res->next;
	}
	return 0;
}

