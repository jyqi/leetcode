#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* deleteDuplicates1(ListNode* head) {
    	if(!head || !head->next) return head;
		ListNode *dummy = new ListNode(0);
		//ListNode *pre = NULL;
		dummy->next = head;
		ListNode *node = dummy;
		while(node->next && node->next->next) {
			if(node->next->val == node->next->next->val) {
				int delval = node->next->val;
				while(node->next && delval == node->next->val) {
					ListNode *tmp = node->next;
					node->next = node->next->next;
					delete tmp;
				}
				
			}
			else {
				node = node->next;
			}
		}
		return dummy->next;
    }

    ListNode* deleteDuplicates(ListNode* head) {
    	if(!head || !head->next) return head;
    	ListNode *dummy = new ListNode(-1);
    	dummy->next = head;
    	ListNode *p1 = dummy;
    	//ListNode *head = head;
    	while(head) {
    		bool dup = false;
    		while(head->next && head->val == head->next->val) {
    			ListNode *tmp = head;
    			head = head->next;
    			delete tmp;
    			dup = true;
    		}
    		if(dup) {
    			ListNode *tmp = head;
    			head = head->next;
    			delete tmp;
    			continue;
    		}
    		p1->next = head;
    		p1 = p1->next;
    		head = head->next;
    	}
    	p1->next = head;
    	return dummy->next;

    }
};

int main() {
	ListNode *a = new ListNode(1);
	a->next = new ListNode(2);
	a->next->next = new ListNode(2);
	Solution s;
	ListNode *res = s.deleteDuplicates(a);
	while(res) {
		cout << res->val << endl;
		res = res->next;
	}
	return 0;
}