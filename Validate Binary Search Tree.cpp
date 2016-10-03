#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "model.h"
using namespace std;

class Solution {
public:
    bool solve(TreeNode *root, long long lval, long long rval) {
      if(!root) {
        return true;
      }
      if(root->val <= lval || root->val >= rval) {
        return false;
      }
      return solve(root->left, lval, root->val) && solve(root->right, root->val, rval);
    }

    bool isValidBST(TreeNode* root) {
        if(!root) {
          return true;
        }
        return solve(root, LLONG_MIN, LLONG_MAX);
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
  int val = 1;
  TreeNode *tree = buildTree(1, val);
  Solution s;
  cout << s.isValidBST(tree) << endl;
  return 0;
}