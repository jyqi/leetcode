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
    TreeNode* solve(vector<int> &nums, int begin, int end) {
        if(begin > end) return null;
        int mid = (begin + end) / 2;
        TreeNode *res = new TreeNode(nums[mid]);
        res->left = solve(nums, begin, mid - 1);
        res->right = solve(nums, mid + 1, end);
        return res;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        TreeNode *res;
        if(len == 0) return res;
        res = solve(nums, 0, len - 1);
        return res;
    }
};