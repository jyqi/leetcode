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
  int maxdis;
  int maxdepth;
};

class Solution {
public:
  RESULT solve(TreeNode *root) {
    if(root == NULL) {
      RESULT empty = {INT_MIN, 0};
      return empty;
    }
    RESULT lres = solve(root->left);
    RESULT rres = solve(root->right);
    RESULT res;
    res.maxdepth = max(lres.maxdepth, rres.maxdepth) + root->val;
    res.maxdepth = max(0, res.maxdepth);
    res.maxdis = max(lres.maxdis, rres.maxdis);
    res.maxdis = max(res.maxdis, lres.maxdepth + rres.maxdepth + root->val);
    return res;

  }
  int maxPathSum(TreeNode* root) {
    if(!root) {
      return 0;
    }
    RESULT res;
    res = solve(root);
    return res.maxdis;
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
  TreeNode *tree = new TreeNode(0);
  tree->left = new TreeNode(2);
  tree->right = new TreeNode(3);
  tree->right->left = new TreeNode(4);
  tree->right->right = new TreeNode(5);
	Solution s;
	cout << s.maxPathSum(tree) << endl;
	return 0;
}