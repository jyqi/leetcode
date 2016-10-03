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


class Solution {
public:
  bool isBalanced(TreeNode* root, int *depth = 0) {
    if(root == NULL) {
      *depth = 0;
      return true;
    }
    int left, right;
    if(isBalanced(root->left, &left) && isBalanced(root->right, &right)) {
      int diff = left - right;
      //cout << "--" << diff << endl;
      if(diff <= 1 && diff >= -1) {
        if(depth != NULL) {
          *depth = 1 + (left > right ? left : right); 
        }
        //cout << *depth << endl;
        return true;
      }
    }
    return false;
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
	TreeNode *tree = buildTree(1, val);
  // TreeNode *tree = new TreeNode(0);
  // tree->left = new TreeNode(2);
  // tree->right = new TreeNode(3);
  // tree->right->left = new TreeNode(4);
  // tree->right->right = new TreeNode(5);
	Solution s;
	cout << s.isBalanced(tree) << endl;
	return 0;
}