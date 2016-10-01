#include <iostream>
using namespace std;

 // Definition of ListNode
  class ListNode {
  public:
      int val;
      ListNode *next;
      ListNode(int val) {
          this->val = val;
          this->next = NULL;
      }
  };

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        if(!head) return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *pre = dummy;
        dummy->next = head;
        ListNode *cur = dummy;
        for(int i = 0; i < n; i++) {
        	cur = cur->next;
          if(cur == NULL) return head;
        }
        while(cur->next) {
        	pre = pre->next;
        	cur = cur->next;
        }
        ListNode *tmp = pre->next;
        if(tmp == NULL) pre->next = NULL;
        else pre->next = pre->next->next;
        delete tmp;
        tmp = NULL;
        return dummy->next;
    }
};

int main() {
	ListNode *a = new ListNode(1);
	a->next = new ListNode(2);
	a->next->next = new ListNode(3);
	Solution s;
	ListNode *res = s.removeNthFromEnd(a, 5);
	while(res) {
		cout << res->val << endl;
    res = res->next;
	}
	return 0;
}
