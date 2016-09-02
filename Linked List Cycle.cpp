/*
Given a linked list, determine if it has a cycle in it.

Example
Given -21->10->4->5, tail connects to node index 1, return true

Challenge
Follow up:
Can you solve it without using extra space?
*/
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
    bool hasCycle(ListNode *head) {
    	if(!head || !head->next) return false;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next) {
        	fast = fast->next->next;
        	slow = slow->next;
        	if(fast == slow) return true;
        }
        return false;
    }
};

int main() {
	ListNode *a = new ListNode(1);
	a->next = new ListNode(2);
	a->next->next = a;
	Solution s;
	cout << s.hasCycle(a) << endl;
	return 0;
}
