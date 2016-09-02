#include <iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* reverseList1(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *pre = NULL;
        while(head) {
        	ListNode *tmp = head->next;
        	head->next = pre;
        	pre = head;
        	head = tmp;
        }
        return pre;
    }

    ListNode *reverseList(ListNode *head) {
    	if(!head || !head->next) return head;
    	ListNode *newHead = reverseList(head->next);
    	head->next->next = head;
    	head->next = NULL;
    	return newHead;
    }
};

int main() {
	ListNode *a = new ListNode(1);
	a->next = new ListNode(2);
	a->next->next = new ListNode(3);
	a->next->next->next = new ListNode(4);
	Solution s;
	ListNode *res = s.reverseList(a);
	while(res) {
		cout << res->val << endl;
		res = res->next;
	}
	return 0;
}
