#include <iostream>
#include <vector>
#include <stack>
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
	/*
	Recursive
	void solve(TreeNode* root, vector<int> &res) {
		if(!root) {
			return;
		}
		res.push_back(root->val);
		solve(root->left, res);
		solve(root->right, res);
	}
	*/
    vector<int> preorderTraversal(TreeNode* root) {
  		vector<int> res;
  		if(!root) {
  			return res;
  		}
  		stack<TreeNode *> s;
  		TreeNode *cur;
  		s.push(root);
  		while(!s.empty()) {
  			cur = s.top();
  			s.pop();
  			res.push_back(cur->val);
  			if(cur->right) {
  				s.push(cur->right);
  			}
  			if(cur->left) {
  				s.push(cur->left);
  			}
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
	TreeNode *tree = buildTree(2, val);
	Solution s;
	std::vector<int> res;
	res = s.preorderTraversal(tree);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	return 0;
}