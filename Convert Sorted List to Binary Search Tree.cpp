#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "model.h"
using namespace std;

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
      if(!head) {
        return NULL;
      }
      if(!head->next) {
        return new TreeNode(head->val);
      }
      ListNode *pre = NULL;
      ListNode *slow = head, *fast = head;
      while(fast && fast->next) {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
      }
      TreeNode *root = new TreeNode(slow->val);
      pre->next = NULL;
      root->left = sortedListToBST(head);
      root->right = sortedListToBST(slow->next);
      return root;
    }
};

ListNode *createList(int len) {
  ListNode *dummy = new ListNode(-1);
  ListNode *last = dummy;
  for(int i = 1; i <= len; i++) {
    last->next = new ListNode(i);
    last = last->next;
  }
  return dummy->next;
}

int main() {
  Solution s;
  ListNode *l = createList(7);
  TreeNode *res = s.sortedListToBST(l);
  bfsCodec code;
  string str = code.serialize(res);
  cout << str << endl;
  return 0;
}