/*
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
*/

//A simple simulated problem in binary tree
//Using recursion to solve this

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
    void do_invert(TreeNode* root) {
        if(root == NULL) return;
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        do_invert(root->left);
        do_invert(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        do_invert(root);
        return root;
    }
};