#include <iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next) return head;
        if(m > n) return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *node = dummy;
        for(int i = 1; i < m; i++) {
        	if(node == NULL) return NULL;
        	else {
        		node = node->next;
        	}
        }
        ListNode *preNode = node;
        ListNode *tailNode = node->next;
        ListNode *nNode = cNode, *postNode = nNode->next;
        for(int i = m; i < n; i++) {
        	if(postNode == NULL) return NULL;
        	ListNode *tmp = postsNode->next;
        	postNode->next = nNode;
        	nNode = postNode;
        	postNode = tmp;
        }
        preNode->next = nNode;
        tailNode->next = postNode;
        return dummy->next;
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
	a->next->next->next->next = new ListNode(5);
	Solution s;
	ListNode *res = s.reverseBetween(a, 2, 4);
	while(res) {
		cout << res->val << endl;
		res = res->next;
	}
	return 0;
}
