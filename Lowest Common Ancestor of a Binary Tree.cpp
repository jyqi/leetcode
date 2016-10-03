#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

struct RESULT {
  TreeNode *node;
  bool isAncestor;
};

class Solution {
public:

    RESULT solve(TreeNode *root, TreeNode *p, TreeNode *q) {
      if(root == NULL) {
        RESULT empty = {NULL, false};
        return empty;
      }
      if(root == p && root == q) {
        RESULT res = {root, true};
        return res;
      }
      RESULT rx = solve(root->left, p, q);
      if(rx.isAncestor) {
        return rx;
      }
      RESULT ry = solve(root->right, p, q);
      if(ry.isAncestor) {
        return ry;
      }
      if(rx.node != NULL && ry.node != NULL) {
        RESULT res = {root, true};
        return res;
      }
      else if(root == p || root == q) {
        bool isAncestor = rx.node != NULL || ry.node != NULL ? true : false;
        RESULT res = {root, isAncestor};
        return res;
      }
      else {
        RESULT res = {rx.node ? rx.node : ry.node, false};
      }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      RESULT res = solve(root, p, q);
      if(res.isAncestor) {
        return res.node;
      }
      return NULL;
    }
};

TreeNode *buildTree(int depth, int &val) {
	TreeNode *root = new TreeNode(val);
	if(depth == 0) {
		return root;
	}
	root->left = buildTree(depth - 1, ++val);
	root->right = buildTree(depth - 1, ++val);
	return root;
}

int main() {
	int val = 1;
	// TreeNode *tree = buildTree(2, val);
  TreeNode *tree = new TreeNode(1);
  tree->left = new TreeNode(2);
  tree->right = new TreeNode(2);
  // tree->right->left = new TreeNode(4);
  // tree->right->right = new TreeNode(5);
	Solution s;
	cout << s.lowestCommonAncestor(tree, tree->left, tree->right) << endl;
	return 0;
}