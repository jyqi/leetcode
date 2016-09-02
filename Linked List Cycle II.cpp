/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Example
Given -21->10->4->5, tail connects to node index 1，return node 10

Challenge
Follow up:
Can you solve it without using extra space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    	if(!head || !head->next) return head;
    	ListNode *slow = head;
    	ListNode *fast = head;
    	while(fast && fast->next) {
    		slow = slow->next;
    		fast = fast->next->next;
    		if(slow == fast) {
    			slow = head;
    			while(slow != fast) {
    				slow = slow->next;
    				fast = fast->next;
    			}
    			return slow;
    		}
    	}
    	return NULL;
        
    }
};