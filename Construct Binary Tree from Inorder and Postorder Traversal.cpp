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
    int findIndex(vector<int> &inorder, int beg, int end, int tar) {
      for(int i = 0; i <= end; i++) {
        if(inorder[i] == tar) {
          return i;
        }
      }
      return -1;
    }
    TreeNode *solve(vector<int> &inorder, int ibeg, int iend, vector<int> &postorder, int pbeg, int pend) {
      if(ibeg > iend || pbeg > pend) {
        return NULL;
      }
      TreeNode *root = new TreeNode(postorder[pend]);
      int cur = findIndex(inorder, ibeg, iend, root->val);
      root->left = solve(inorder, ibeg, cur - 1, postorder, pbeg, pbeg + cur - ibeg - 1);
      root->right = solve(inorder, cur + 1, iend, postorder, pbeg + cur - ibeg, pend - 1);
      return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      if(inorder.empty() || postorder.empty() || inorder.size() != postorder.size()) {
        return NULL;
      }   
      int len = inorder.size();
      TreeNode *res = solve(inorder, 0, len - 1, postorder, 0, len - 1);
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
  int arr2[] = {1, 3, 2};
  vector<int> v1(arr1, arr1 + 3);
  vector<int> v2(arr2, arr2 + 3); 
  Solution s;
  TreeNode *res = s.buildTree(v1, v2);
  queue<TreeNode*> q;
  if(res) {
    q.push(res);
  }
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