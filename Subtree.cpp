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
  int nmaxDepth;
  int nmaxPath;
  
};

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
     bool judge(TreeNode *p, TreeNode *q) {
      if(!p && !q) {
        return true;
      }
      if(!p || !q) {
        return false;
      }
      if(p->val != q->val) {
        return false;
      }
      return judge(p->left, q->left) && judge(p->right, q->right);
     }
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
      if(T2 == NULL) {
        return true;
      }
      if(T1 == NULL) {
        return false;
      }
      return judge(T1, T2) || isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
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
	  TreeNode *tree1 = buildTree(3, val);
    val = 1;
    TreeNode *tree2 = buildTree(1, val);
  // TreeNode *tree = new TreeNode(1);
  // tree->left = new TreeNode(2);
  // tree->right = new TreeNode(2);
  // tree->right->left = new TreeNode(4);
  // tree->right->right = new TreeNode(5);
	Solution s;
	cout << s.isSubtree(tree1, tree2) << endl;
	return 0;
}