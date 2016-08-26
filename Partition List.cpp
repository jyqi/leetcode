#include <iostream>
using namespace std;

/*
Given a linked list and a value x, partition it such that all nodes
less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes
in each of the two partitions.

For example,
Given 1->4->3->2->5->2->null and x = 3,
return 1->2->2->4->3->5->null.
*/
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* partition_tmp(ListNode* head, int x) {
    	if(!head || !head->next) return head;
		ListNode *leftdummy = new ListNode(-1);
		ListNode *left = leftdummy;
		ListNode *rightdummy = new ListNode(-1);
		ListNode *right = rightdummy;
		ListNode *node = head;
		while(node) {
			if(node->val < x) {
				left->next = node;
				left = left->next;
			}
			else {
				right->next = node;
				right = right->next;
			}
			node = node->next;
		}
		right->next = NULL;
		left->next = rightdummy->next;
		return leftdummy->next;
    }
    //in-place
    ListNode* partition(ListNode* head, int x) {
    	ListNode *dummy = new ListNode(0);
    	dummy->next = head;
    	ListNode *small = dummy;
    	ListNode *big = dummy;
    	while(head) {
    		ListNode *next = head->next;
    		if(head->val < x) {
    			if(small->next == head) {
    				small = head;	//first node
    			}
    			else {
    				ListNode *tmp = small->next;
    				small->next = head;
    				head->next = tmp;
    				small = head;
    				if(big != dummy) {
    					big->next = next;
    				}
    			}
    		}
    		else {
    			big = head;
    		}
    		head = next;
    	}
    	return dummy->next;
    }
};

int main() {
	Solution s;
	ListNode *a = new ListNode(1);
	a->next = new ListNode(4);
	a->next->next = new ListNode(3);
	a->next->next->next = new ListNode(2);
	ListNode *head = s.partition(a, 3);
	while(head) {
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}
