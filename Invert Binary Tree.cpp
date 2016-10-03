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
  /*
  Recursive
    TreeNode* invertTree(TreeNode* root) {
      if(!root) {
        return NULL;
      }      
      TreeNode *tmp = root->left;
      root->left = invertTree(root->right);
      root->right = invertTree(tmp);
      return root;
    }
    */
    TreeNode* invertTree(TreeNode* root) {
      if(!root) {
        return NULL;
      }
      stack<TreeNode *> s;
      TreeNode *cur;
      s.push(root);
      while(!s.empty()) {
        cur = s.top();
        s.pop();
        TreeNode *tmp = cur->left;
        cur->left = cur->right;
        cur->right = tmp;
        if(cur->left) {
          s.push(cur->left);
        }
        if(cur->right) {
          s.push(cur->right);
        }
      }
      return root;
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
	cout << s.invertTree(tree) << endl;
	return 0;
}