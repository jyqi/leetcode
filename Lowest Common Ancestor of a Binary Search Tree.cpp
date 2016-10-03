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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(!root || !p || !q) {
        return NULL;
      }
      while(root) {
        if(p->val < root->val && q->val < root->val) {
          root = root->left;
        }
        else if(p->val > root->val && q->val > root->val) {
          root = root->right;
        }
        else {
          return root;
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
  TreeNode *tree = new TreeNode(2);
  tree->left = new TreeNode(2);
  tree->right = new TreeNode(3);
  tree->right->left = new TreeNode(4);
  tree->right->right = new TreeNode(5);
	Solution s;
	cout << s.maxPathSum(tree) << endl;
	return 0;
}