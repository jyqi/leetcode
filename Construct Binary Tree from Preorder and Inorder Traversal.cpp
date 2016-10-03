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
    bool gInvalid = false;
    TreeNode *solve(vector<int> &preorder, int pbeg, int pend, vector<int> &inorder, int ibeg, int iend) {
      if(pbeg > pend) {
        return NULL;
      }
      if(pbeg == pend) {
        return new TreeNode(preorder[pbeg]);
      }
      TreeNode *root = new TreeNode(preorder[pbeg]);
      int cur = 0;
      for(cur = ibeg; cur <= iend; cur++) {
        if(root->val == inorder[cur]) {
          break;
        }
      }
      if(cur > iend) {
        gInvalid = true;
        return NULL;
      }
      int len = cur - ibeg;
      root->left = solve(preorder, pbeg + 1, pbeg + len, inorder, ibeg, ibeg + len - 1);
      root->right = solve(preorder, pbeg + len + 1, pend, inorder, ibeg + len + 1, iend);
      return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      if(preorder.size() != inorder.size() || preorder.empty() || inorder.empty()) {
        return NULL;
      }        
      int len = preorder.size();
      TreeNode *res = solve(preorder, 0, len - 1, inorder, 0, len - 1);
      if(gInvalid) {
        return NULL;
      }
      return res;
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
  int arr1[] = {1, 2, 3};
  int arr2[] = {2, 1, 3};
  vector<int> v1(arr1, arr1 + 2);
  vector<int> v2(arr2, arr2 + 2);	
  Solution s;
	TreeNode *res = s.buildTree(v1, v2);
  queue<TreeNode*> q;
  q.push(res);
  while(!q.empty()) {
    TreeNode *cur = q.front();
    q.pop();
    cout << cur->val << endl;
    if(cur->left) {
      q.push(cur->left);
    }
    if(cur->right) {
      q.push(cur->right);
    }
  }
	return 0;
}