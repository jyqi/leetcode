#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "model.h"
using namespace std;

class Solution {
public:
    TreeNode *solve(vector<int> &nums, int start, int end) {
      if(start > end) {
        return NULL;
      }
      int mid = start + (end - start) / 2;
      TreeNode *root = new TreeNode(nums[mid]);
      root->left = solve(nums, start, mid - 1);
      root->right = solve(nums, mid + 1, end);
      return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
      int len = nums.size();
      TreeNode *root;
      root = solve(nums, 0, len - 1);
      return root;
    }
};

TreeNode *buildTree(int depth, int val) {
	TreeNode *root = new TreeNode(val);
	if(depth == 0) {
		return root;
	}
	root->left = buildTree(depth - 1, val - 1);
	root->right = buildTree(depth - 1, val + 1);
	return root;
}

int main() {
  Solution s;
  //int val = 1;
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  vector<int> v(arr, arr + 7);
  TreeNode *res = s.sortedArrayToBST(v);
  bfsCodec code;
  string str = code.serialize(res);
  cout << str << endl;
  return 0;
}