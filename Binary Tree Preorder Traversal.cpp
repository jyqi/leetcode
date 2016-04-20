/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

Subscribe to see which companies asked this question
*/

//Simple Binary tree traverse problem
//pre-order: root->left->right
//in-order: left->root->right
//post-order: left->right->root



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
    void pre_order(vector<int> &res, TreeNode* root) {
        if(root == NULL) return;
        res.push_back(root->val);
        pre_order(res, root->left);
        pre_order(res, root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        pre_order(res, root);
        return res;
    }
};