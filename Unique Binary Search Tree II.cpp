#include <iostream>
#include <vector>

using namespace std;


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
    	if(n == 0) return vector<TreeNode*>();
     	return solve(1, n);   
    }
    vector<TreeNode*> solve(int begin, int end) {
    	vector<TreeNode*> res;
    	if(begin > end) res.push_back(NULL);
    	else {
    		for(int i = begin; i <= end; i++) {
    			vector<TreeNode*> left = solve(begin, i - 1);
    			vector<TreeNode*> right = solve(i + 1, end);
    			for(int l = 0; l < left.size(); l++) {
    				for(int r = 0; r < right.size(); r++) {
    					TreeNode *root = new TreeNode(i);
    					root->left = left[l];
    					if(root->left) printf("left:%d\n", root->left->val);
    					root->right = right[r];
    					if(root->right) printf("right:%d\n", root->right->val);
    					res.push_back(root);
    				}
    			}
    		}
    	}
    	return res;
    }
};

int main() {
	Solution s;
	vector<TreeNode*> res;
	res = s.generateTrees(3);
	return 0;
}