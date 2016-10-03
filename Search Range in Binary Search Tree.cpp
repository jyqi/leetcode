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
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    void solve(TreeNode *root, int k1, int k2, vector<int> &v) {
      if(root == NULL) {
        return;
      }
      solve(root->left, k1, k2, v);
      if(root->val >= k1 && root->val <= k2) {
        //cout << root->val << endl;
        v.push_back(root->val);
      }
      solve(root->right, k1, k2, v);
    }

    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
      vector<int> res;
      solve(root, k1, k2, res);
      return res;
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
  TreeNode *tree = buildTree(3, val);
  Solution s;
  vector<int> res;
  res = s.searchRange(tree, 1, 15);
  for(int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }
  return 0;
}