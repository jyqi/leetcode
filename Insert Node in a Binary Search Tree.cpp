#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "model.h"
using namespace std;

class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
      if(!root) {
        return node;
      }
      TreeNode *cur = root;
      while(cur) {
        if(cur->val <= node->val) {
          if(cur->right) {
            cur = cur->right;
          }
          else {
            cur->right = node;
            break;
          }
        }
        else if(cur->val > node->val) {
          if(cur->left) {
            cur = cur->left;
          }
          else {
            cur->left = node;
            break;
          }
        }
      }
      return root;
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
  bfsCodec code;
  string res1 = code.serialize(tree);
  cout << res1 << endl;
  Solution s;
  TreeNode *node = new TreeNode(5);
  TreeNode *root = s.insertNode(tree, node);
  
  string res = code.serialize(root);
  cout << res << endl;
  return 0;
}