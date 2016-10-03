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

class Solution {
public:
    RESULT getDiameter(TreeNode *root) {
      if(root == NULL) {
        RESULT tmp = {0, 0};
        return tmp;
      }
      RESULT lres = getDiameter(root->left);
      RESULT rres = getDiameter(root->right);
      RESULT res;
      res.nmaxDepth = max(lres.nmaxDepth, rres.nmaxDepth) + 1;
      //res.nmaxDepth = max(0, res.nmaxDepth);
      res.nmaxPath = max(lres.nmaxPath, max(rres.nmaxPath, lres.nmaxDepth + rres.nmaxDepth + 1));
      return res;
    }

    int diameter(TreeNode *root) {
      RESULT res = getDiameter(root);
      return res.nmaxPath;
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
	  TreeNode *tree = buildTree(2, val);
  // TreeNode *tree = new TreeNode(1);
  // tree->left = new TreeNode(2);
  // tree->right = new TreeNode(2);
  // tree->right->left = new TreeNode(4);
  // tree->right->right = new TreeNode(5);
	Solution s;
	cout << s.diameter(tree) << endl;
	return 0;
}