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
    bool isPalindrome(ListNode* head) {
        ListNode *slow, *fast;
        slow = head;
        fast = head->next;
        while(fast && fast->next) {
        	fast = fast->next->next;
        	slow = slow->next;
        }
        ListNode *p = head;
        ListNode *q = slow->next;
        ListNode *end = NULL;
        while(q) {
        	ListNode *tmp = q->next;
        	q->next = end;
        	end = q;
        	q = tmp;
        }
        while(head && end) {
        	if(head->val != end->val) return false;
        	head = head->next;
        	end = end->next;
        }
        if(head || end) return false;
        return true;
    }
};

int main() {
	ListNode *head = new ListNode(3);
	ListNode *tmp = head;
	tmp->next = new ListNode(2);
	tmp = tmp->next;
	tmp->next = new ListNode(1);
	tmp = tmp->next;
	tmp->next = new ListNode(2);
	tmp = tmp->next;
	tmp->next = new ListNode(3);
	tmp = tmp->next;
	tmp->next = NULL;
	Solution s;
	cout << s.isPalindrome(tmp) << endl;
	
}