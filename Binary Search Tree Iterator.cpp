#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "model.h"
using namespace std;

class BSTIterator {
private:
  stack<TreeNode *> s;
  TreeNode *cur;

public:
    BSTIterator(TreeNode *root) {
      cur = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
      return cur != NULL || !s.empty();
    }

    /** @return the next smallest number */
    int next() {
      while(cur != NULL) {
        s.push(cur);
        cur = cur->left;
      }
      cur = s.top();
      s.pop();
      TreeNode *node = cur;
      cur = cur->right;
      return node->val;
    }
};

TreeNode *buildTree(int depth, int val) {
  TreeNode *root = new TreeNode(val);
  if(depth == 0) {
    return root;
  }
  root->left = buildTree(depth - 1, val - 1);
  root->right = buildTree(depth - 1, val + 1);
  return root;
}

int main() {
  TreeNode *tree = buildTree(3, 5);
  bfsCodec code;
  string str = code.serialize(tree);
  cout << str << endl;
  BSTIterator it(tree);
  while(it.hasNext()) {
    cout << it.next() << endl;
  }
  return 0;
}