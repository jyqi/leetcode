/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

Subscribe to see which companies asked this question
*/




//To determine whether a list has a cycle
//set two pointer, p, q; let p walk one step once time; let q walk two step once time;
// if there are a cycle, then p,q must meet each other.  


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
    bool hasCycle(ListNode *head) {
        ListNode *p = head;
        ListNode *q = head;
        while(p != NULL && q != NULL) {
            if(p->next == NULL) break;
            p = p->next->next;
            q = q->next;
            if(p == NULL || q == NULL) break;
            if(p == q) return true;
        }
        return false;
    }
};