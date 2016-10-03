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
  
  //use stack
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        stack<vector<int> > s;
        if(!root) {
          return res;
        }
        vector<int> tmp;
        TreeNode *cur;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
          tmp.clear();
          int len = q.size();
          for(int i = 0; i < len; i++) {
            cur = q.front();
            q.pop();
            if(cur->left) {
              q.push(cur->left);
            }
            if(cur->right) {
              q.push(cur->right);
            }
            tmp.push_back(cur->val);
          }
          s.push(tmp);
        }
        while(!s.empty()) {
          res.push_back(s.top());
          s.pop();
        }
        return res;
    }
    
    /*
    reverse
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
      vector<vector<int> > res;
      if(!root) {
        return res;
      }
      vector<int> tmp;
      queue<TreeNode *> q;
      q.push(root);
      TreeNode *cur;
      while(!q.empty()) {
        tmp.clear();
        int len = q.size();
        for(int i = 0; i < len; i++) {
          cur = q.front();
          q.pop();
          tmp.push_back(cur->val);
          if(cur->left) {
            q.push(cur->left);
          }
          if(cur->right) {
            q.push(cur->right);
          }
        }
        res.insert(res.begin(), tmp);
      }
      return res;
    }
    */
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
	Solution s;
	vector<vector<int> > res;
	res = s.levelOrderBottom(tree);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
	}
	return 0;
}