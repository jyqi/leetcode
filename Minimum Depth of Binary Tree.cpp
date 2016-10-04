#include "Model.h"
using namespace std;

class Solution {
public:
	void solve(TreeNode *root, int &res, int depth) {
		if(!root->left && !root->right) {
			if(res > depth) {
				res = depth;
			}
			return;
		}
		if(root->left) {
			solve(root->left, res, depth + 1);
		}
		if(root->right) {
			solve(root->right, res, depth + 1);	
		}
	}
    int minDepth(TreeNode* root) {
    	if(!root) {
    		return 0;
    	}
    	int res = INT_MAX;
    	solve(root, res, 1);	    
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
	cout << s.minDepth(tree) << endl;
	return 0;
}