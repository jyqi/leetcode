#include "Model.h"
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<TreeNode*> generateTrees(int start, int end) {
		vector<TreeNode*> res;
		if(start > end) {
			res.push_back(NULL);
		}
		for(int i = start; i <= end; i++) {
			vector<TreeNode*> left = generateTrees(start, i - 1);
			vector<TreeNode*> right = generateTrees(i + 1, end);
			for(int j = 0; j < left.size(); j++) {
				for(int k = 0; k < right.size(); k++) {
					TreeNode *root = new TreeNode(i);
					root->left = left[j];
					root->right = right[k];
					res.push_back(root);
				}
			}
		}
		return res;
	}
    vector<TreeNode*> generateTrees(int n) {
    	vector<TreeNode *> res;
    	if(n < 1) {
    		return res;
    	}
        return generateTrees(1, n);
        
    }
};

int main() {
	Solution s;
	bfsCodec ff;
	vector<TreeNode *> res;
	res = s.generateTrees(3);
	for(int i = 0; i < res.size(); i++) {
		cout << ff.serialize(res[i]) << endl;
	}
	return 0;
}