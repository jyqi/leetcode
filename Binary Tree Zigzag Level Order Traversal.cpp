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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    
      vector<vector<int> > res;      
      if(!root) {
          return res;
      }
      vector<int> tmp;
      deque<TreeNode *> dq;
      dq.push_back(root);
      TreeNode *cur;
      bool flag = true;
      while(!dq.empty()) {
        tmp.clear();
        int size = dq.size();
        for(int i = 0; i < size; i++) {
          if(flag) {
            cur = dq.front();
            if(cur->left) {
              dq.push_back(cur->left);
            }
            if(cur->right) {
              dq.push_back(cur->right);
            }
            tmp.push_back(cur->val);
            dq.pop_front();
          }
          else {
            cur = dq.back();
            if(cur->right) {
              dq.push_front(cur->right);
            }
            if(cur->left) {
              dq.push_front(cur->left);
            }
            tmp.push_back(cur->val);
            dq.pop_back();
          }
        }
        flag = !flag;
        res.push_back(tmp);
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
  int val = 1;
  TreeNode *tree = buildTree(3, val);
  Solution s;
  vector<vector<int> > res;
  res = s.zigzagLevelOrder(tree);
  for(int i = 0; i < res.size(); i++) {
    for(int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}