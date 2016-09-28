#include <iostream>
#include <stack>
using namespace std;
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
    bool isPalindrome(ListNode* head) {
    	if(!head) return true;
        stack<int> s;
        ListNode *cur = head;
        while(cur) {
        	s.push(cur->val);
        	cur = cur->next;
        }
        ListNode *cur2 = head;
        while(!s.empty()) {
        	if(s.top() != cur2->val) {
        		return false;
        	} 
        	s.pop();
        	cur2 = cur2->next;
        }
        return true;
    }
};