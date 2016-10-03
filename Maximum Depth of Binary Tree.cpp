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
  /*recursive
    int maxDepth(TreeNode* root) {
      if(!root) {
        return 0;
      }
      int left = maxDepth(root->left);
      int right = maxDepth(root->right);
      return left > right ? left + 1 : right + 1;
    }
    */
    /*
    confuse
    int maxDepth(TreeNode* root) {
      if(!root) {
        return 0;
      }
      stack<TreeNode *> s;
      TreeNode *cur, *pre = NULL;
      bool noChild, visited;
      s.push(root);
      int depth = 0;
      while(!s.empty()) {
        if(s.size() > depth) {
          depth = s.size();
        }
        cur = s.top();
        noChild = false;
        visited = false;
        if(!cur->left && !cur->right) {
          noChild = true;
        }
        
        if(pre && pre == cur->left) {
          if(cur->right) {
            s.push(cur->right);  
          }
          else {
            visited = true;
          }
        }
        else if(pre && pre == cur->right) {
          visited = true;
        }
        else {
          if(cur->left) {
            s.push(cur->left);
          }
          else if(cur->right) {
            s.push(cur->right);
          }
        } 
        if(noChild || visited) {
          pre = cur;
          s.pop();
        }
      }
      return depth;
    }
    */
    int maxDepth(TreeNode* root) {
      if(root == NULL) {
        return 0;
      }
      TreeNode *cur = NULL, *pre = NULL;    //函数内一定要初始化！
      stack<TreeNode *> s;
      s.push(root);
      int depth = 0;
      while(!s.empty()) {
        cur = s.top();
        if(!pre || pre->left == cur || pre->right == cur) {
          if(cur->left) {
            s.push(cur->left);
          }
          else if(cur->right) {
            s.push(cur->right);
          }
        }
        else if(pre == cur->left) {
          if(cur->right) {
            s.push(cur->right);
          }
        }
        else {
          s.pop();
        }
        pre = cur;
        if(s.size() > depth) {
          depth = s.size();
        }
      }
      return depth;
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
	// TreeNode *tree = buildTree(3, val);
  TreeNode *tree = new TreeNode(0);
  // tree->left = new TreeNode(2);
  // tree->right = new TreeNode(3);
  // tree->right->left = new TreeNode(4);
  // tree->right->right = new TreeNode(5);
	Solution s;
	cout << s.maxDepth(tree) << endl;
	return 0;
}