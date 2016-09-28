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
	ListNode *reverse(ListNode *head) {
		ListNode *pre = NULL;
		while(head) {
			ListNode *tmp = head->next;
			head->next = pre;
			pre = head;
			head = tmp;
		}
		return pre;
	}

    ListNode* rotateRight(ListNode* head, int k) {
    	if(!head || k < 1) {
    		return head;
    	}    	
    	ListNode *left, *right, *cur;
  		ListNode *pre = head;
  		ListNode *after = head;
  		for(int i = 0; i < k; i++) {
  			if(after) {
  				after = after->next;	
  			}
  			else {
  				return NULL;
  			}
  		}
  		while(after->next) {
  			after = after->next;
  			pre = pre->next;
  		}
  		right = pre->next;
  		pre->next = NULL;
  		left = head;
  		left = reverse(left);
  		right = reverse(right);
  		cur = left;
  		while(cur->next) {
  			cur = cur->next;
  		}
  		cur->next = right;
  		head = reverse(left);
  		return head;
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
	ListNode *list = createList(5);
	Solution s;
	ListNode *res = s.rotateRight(list, 2);
	while(res) {
		cout << res->val << endl;
		res = res->next;
	}
	return 0;
}