#include <iostream>
#include <map>
using namespace std;

/**
 * Definition for singly-linked list.*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
    	if(!head || !head->next) return head;
    	map<int, bool> hash; 
    	hash[head->val] = true;
		ListNode *tmp = head;
		while(tmp->next) {
			if(hash.find(tmp->next->val) != hash.end()) {
				ListNode *junk = tmp->next;			//保存当前指针，便于后面释放内存
				tmp->next = tmp->next->next;
				delete junk;		//删除指针，防止内存泄露
				junk = NULL;
			}
			else {
				hash[tmp->next->val] = true;
				tmp = tmp->next;
			}
		}
		return head;
    }
};

int main() {
	ListNode *a = new ListNode(2);
	a->next = new ListNode(2);
	a->next->next = new ListNode(1);
	a->next->next->next = new ListNode(2);
	Solution s;
	ListNode *res = s.deleteDuplicates(a);
	while(res) {
		cout << res->val << endl;
		res = res->next;
	}
	return 0;
}