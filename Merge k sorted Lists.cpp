#include <iostream>
#include <vector>
using namespace std;


 //* Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
	ListNode *merge(ListNode *l1, ListNode *l2) {
		ListNode *dummy = new ListNode(-1);
		ListNode *last = dummy;
		while(l1 != NULL && l2 != NULL) {
			if(l1->val < l2->val) {
				last->next = l1;
				l1 = l1->next;
				last = last->next;
			}
			else {
				last->next = l2;
				l2 = l2->next;
				last = last->next;
			}
		}
		if(l1) {
			last->next = l1;
		}
		if(l2) {
			last->next = l2;
		}
		return dummy->next;
	}

	ListNode *solve(vector<ListNode*> &lists, int start, int end) {
		if(start == end) {
			return lists[start];
		}
		if(end - start == 1) {
			return merge(lists[start], lists[end]);
		}
		int mid = (start + end) / 2;
		ListNode *l1 = solve(lists, start, mid);
		ListNode *l2 = solve(lists, mid + 1, end);
		return merge(l1, l2);
	}

    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	ListNode *res = NULL;
    	int len = lists.size();
    	if(len == 0) return NULL;
    	return solve(lists, 0, len - 1);

    }
};

int main() {

}