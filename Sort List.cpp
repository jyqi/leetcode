#include <iostream>
using namespace std;

//分割节点时，要将前面链表最后设为NULL，否则死循环
//合并两个链表时，使用递归更简洁
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
	void SplitList(ListNode *head, ListNode *&head1, ListNode *&head2) {
		if(head == NULL || head->next == NULL) {
			head1 = head;
			head2 = NULL;
			return;
		}
		ListNode *slow, *fast;
		slow = head;
		fast = head->next;
		while(fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		head1 = head;
		head2 = slow->next;
		slow->next = NULL;
	}

	ListNode* merge(ListNode *head1, ListNode *head2)
	{
	    ListNode *helper = new ListNode(0);
	    helper->next = head1;
	    ListNode *pre = helper;
	    while(head1!=NULL && head2!=NULL)
	    {
	        if(head1->val<head2->val)
	        {
	            head1 = head1->next;
	        }
	        else
	        {
	            ListNode *next = head2->next;
	            head2->next = pre->next;
	            pre->next = head2;
	            head2 = next;
	        }
	        pre = pre->next;
	    }
	    if(head2!=NULL)
	    {
	        pre->next = head2;
	    }
	    return helper->next;
	}

	ListNode* mergeList(ListNode *head1, ListNode *head2) {
		if(!head1) return head2;
		if(!head2) return head1;

		ListNode *res;
		if(head1->val <= head2->val) {
			res = head1;
			res->next = mergeList(head1->next, head2);
		}
		else {
			res = head2;
			res->next = mergeList(head1, head2->next);
		}
		return res;
	}

    ListNode* sortList(ListNode* head) {
    	//cout << head->val << endl;
    	if(head == NULL || head->next == NULL) return head;
    	ListNode *head1;
    	ListNode *head2;
    	SplitList(head, head1, head2);
    	head1 = sortList(head1);
    	head2 = sortList(head2);
    	return merge(head1, head2);
    }
};

int main() {
	ListNode *head = new ListNode(3);
	ListNode *tmp = head;
	tmp->next = new ListNode(2);
	tmp = tmp->next;
	tmp->next = new ListNode(5);
	tmp = tmp->next;
	tmp->next = new ListNode(1);
	tmp = tmp->next;
	tmp->next = new ListNode(4);
	tmp = tmp->next;
	tmp->next = NULL;
	Solution s;
	head = s.sortList(head);
	while(head) {
		cout << head->val << endl;
		head = head->next;
	}
}